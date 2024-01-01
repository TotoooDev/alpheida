#include <physics.h>
#include <sprite.h>
#include <array.h>

#define PHYSICS_MAX_SPRITES 128

typedef struct PhysicsWorld {
    Array* objects;

    float gravity[2];
} PhysicsWorld;

PhysicsWorld* physics_new() {
    PhysicsWorld* world = (PhysicsWorld*)malloc(sizeof(PhysicsWorld));

    world->objects = array_new(PHYSICS_MAX_SPRITES);

    world->gravity[0] = 0.0f;
    world->gravity[1] = -0.981f;

    return world;
}

void physics_delete(PhysicsWorld* world) {
    for (unsigned int i = 0; i < array_get_num_elements(world->objects); i++) {
        physics_remove_physics_object(world, array_get(world->objects, i));
    }

    array_delete(world->objects);
    free(world);
}

void physics_set_gravity(PhysicsWorld* world, float* gravity) {
    world->gravity[0] = gravity[0];
    world->gravity[1] = gravity[1];
}

void physics_update(PhysicsWorld* world, float timestep) {
    for (unsigned int i = 0; i < array_get_num_elements(world->objects); i++) {
        PhysicsObject* object = array_get(world->objects, i);

        // detect collisions
        bool collision_detected = false;
        for (unsigned int ii = 0; ii < array_get_num_elements(world->objects); ii++) {
            PhysicsObject* other_object = array_get(world->objects, ii);

            if (object == other_object)
                continue;

            collision_detected = aabb_intersect(object->sprite->aabb, other_object->sprite->aabb);
        }
        
        if (!collision_detected) {
            if (object->takes_gravity) {
                // apply gravity
                // i have to subtract from the y axis because for some fucking reason the sdl positive y axis is down (?????)
                object->forces[0] += world->gravity[0];
                object->forces[1] += world->gravity[1];
            }
        }

        // apply forces to velocity
        object->velocity[0] += object->forces[0];
        object->velocity[1] += object->forces[1];
        
        // move the sprite
        object->sprite->aabb->x += (int)object->velocity[0];
        object->sprite->aabb->y -= (int)object->velocity[1];

        // reset forces
        object->forces[0] = 0.0f;
        object->forces[1] = 0.0f;

        if (collision_detected) {
            object->velocity[0] = 0.0f;
            object->velocity[1] = 0.0f;
        }
    }
}

PhysicsObject* physics_add_physics_object(PhysicsWorld* world, Sprite* sprite) {
    PhysicsObject* object = (PhysicsObject*)malloc(sizeof(PhysicsObject));

    object->sprite = sprite;
    object->takes_gravity = true;
    object->forces[0] = 0.0f;
    object->forces[1] = 0.0f;
    object->velocity[0] = 0.0f;
    object->velocity[1] = 0.0f;

    sprite->physics_object = object;

    array_add(world->objects, object);

    return object;
}

void physics_remove_physics_object(PhysicsWorld* world, PhysicsObject* object) {
    array_remove(world->objects, object);
    free(object);
}

