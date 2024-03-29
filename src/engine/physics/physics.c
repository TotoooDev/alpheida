#include <engine/physics/physics.h>
#include <engine/scene/sprite.h>
#include <engine/array.h>
#include <engine/log.h>
#include <stdlib.h>

#define PHYSICS_MAX_SPRITES 128

typedef struct PhysicsWorld {
    Array* objects;

    f32 gravity[2];
} PhysicsWorld;

PhysicsWorld* physics_new() {
    PhysicsWorld* world = (PhysicsWorld*)malloc(sizeof(PhysicsWorld));

    world->objects = array_new(PHYSICS_MAX_SPRITES);

    world->gravity[0] = 0.0f;
    world->gravity[1] = -0.981f;

    return world;
}

void physics_delete(PhysicsWorld* world) {
    for (u32 i = 0; i < array_get_num_elements(world->objects); i++) {
        physics_remove_physics_object(world, array_get(world->objects, i));
    }

    array_delete(world->objects);
    free(world);
}

void physics_set_gravity(PhysicsWorld* world, f32* gravity) {
    world->gravity[0] = gravity[0];
    world->gravity[1] = gravity[1];
}

bool physics_detect_collisions(PhysicsWorld* world, PhysicsObject* object, PhysicsObject** colliding_object) {
    bool collision_detected = false;

    for (u32 i = 0; i < array_get_num_elements(world->objects); i++) {
        PhysicsObject* other_object = array_get(world->objects, i);

        if (object == other_object)
            continue;

        bool accept_collision = (object->filter & other_object->filter) || (object->trigger_filter & other_object->trigger_filter);
        if (!accept_collision)
            continue;

        collision_detected = aabb_intersect(object->aabb, other_object->aabb);
        if (collision_detected) {
            *colliding_object = other_object;
            return true;
        }
    }

    return false;
}

void physics_apply_gravity(PhysicsWorld* world, PhysicsObject* object) {
    if (object->takes_gravity) {
        object->forces[0] += world->gravity[0];
        object->forces[1] += world->gravity[1];
    }
}

void physics_apply_forces(PhysicsObject* object) {
    object->velocity[0] += object->forces[0];
    object->velocity[1] += object->forces[1];
}

void physics_move(PhysicsObject* object, f32 timestep) {
    object->aabb.x += object->velocity[0] * timestep;
    object->aabb.y += object->velocity[1] * timestep;
}

void physics_reset_forces(PhysicsObject* object) {
    object->forces[0] = 0.0f;
    object->forces[1] = 0.0f;
}

void physics_reset_velocity(PhysicsObject* object) {
    object->velocity[0] = 0.0f;
    object->velocity[1] = 0.0f;
}

IntersectionAxis physics_move_intersecting_aabb(AABB* a, AABB* b) {
    IntersectionAxis axis = aabb_get_intersection_axis(*a, *b);

    switch (axis) {
    case INTERSECTION_AXIS_POSITIVE_Y: {
        f32 offset = b->y + b->height - a->y;
        a->y += offset;
        break;
    }

    case INTERSECTION_AXIS_NEGATIVE_Y: {
        f32 offset = a->y + a->height - b->y;
        a->y -= offset;
        break;
    }

    case INTERSECTION_AXIS_POSITIVE_X: {
        f32 offset = a->x + a->width - b->x;
        a->x -= offset;
        break;
    }

    case INTERSECTION_AXIS_NEGATIVE_X: {
        f32 offset = b->x + b->width - a->x;
        a->x += offset;
        break;
    }
       
    case INTERSECTION_AXIS_NONE:
        break;
    }

    return axis;
}

void physics_on_collision(PhysicsObject* object, PhysicsObject* colliding_object) {
    IntersectionAxis axis;
    bool act_as_trigger = (object->is_trigger || colliding_object->is_trigger) || (object->trigger_filter & colliding_object->trigger_filter);
    if (act_as_trigger || !object->moved_by_collision)
        axis = aabb_get_intersection_axis(object->aabb, colliding_object->aabb);
    else
        axis = physics_move_intersecting_aabb(&object->aabb, &colliding_object->aabb);

    if (object->on_collision != NULL)
        object->on_collision(object, colliding_object, axis);

    if (colliding_object->on_collision != NULL)
        colliding_object->on_collision(colliding_object, object, axis);

    if (!act_as_trigger || !object->moved_by_collision)
        physics_reset_velocity(object);
}

void physics_update(PhysicsWorld* world, f32 timestep) {
    // a really bad """""""physics""""""" simulation
    for (u32 i = 0; i < array_get_num_elements(world->objects); i++) {
        PhysicsObject* object = array_get(world->objects, i);
        PhysicsObject* colliding_object = NULL;

        object->aabb.x = object->sprite->pos[0] - object->sprite->scale[0] / 2.0f;
        object->aabb.y = object->sprite->pos[1] - object->sprite->scale[1] / 2.0f;
        object->aabb.width  = object->sprite->scale[0];
        object->aabb.height = object->sprite->scale[1];

        bool collision_detected = physics_detect_collisions(world, object, &colliding_object);

        if (!collision_detected)
            physics_apply_gravity(world, object);

        physics_apply_forces(object);
        physics_move(object, timestep);
        physics_reset_forces(object);

        // re-check collisions after moving the objects
        collision_detected |= physics_detect_collisions(world, object, &colliding_object);
        
        if (collision_detected)
            physics_on_collision(object, colliding_object);

        object->sprite->pos[0] = object->aabb.x + object->aabb.width  / 2.0f;
        object->sprite->pos[1] = object->aabb.y + object->aabb.height / 2.0f;
    }
}

PhysicsObject* physics_add_physics_object(PhysicsWorld* world, Sprite* sprite) {
    PhysicsObject* object = (PhysicsObject*)malloc(sizeof(PhysicsObject));

    object->sprite = sprite;
    object->takes_gravity = true;
    object->moved_by_collision = true;
    object->is_trigger = false;
    object->filter = 0;
    object->trigger_filter = 0;
    object->forces[0] = 0.0f;
    object->forces[1] = 0.0f;
    object->velocity[0] = 0.0f;
    object->velocity[1] = 0.0f;
    object->aabb.x = sprite->pos[0] - sprite->scale[0] / 2.0f;
    object->aabb.y = sprite->pos[1] - sprite->scale[1] / 2.0f;
    object->aabb.width = sprite->scale[0];
    object->aabb.height = sprite->scale[1];
    object->on_collision = NULL;

    sprite->physics_object = object;

    array_add(world->objects, object);

    return object;
}

void physics_remove_physics_object(PhysicsWorld* world, PhysicsObject* object) {
    array_remove(world->objects, object);
    free(object);
}

u32 physics_set_all_filters() {
    return UINT32_MAX;
}

u32 physics_add_filter(u32 num_filter) {
    return 1 << num_filter;
}
