#include <game/main_scene.h>
#include <engine/event.h>
#include <engine/platform/input.h>
#include <engine/app.h>
#include <engine/platform/fs.h>
#include <stdlib.h>

void mainscene_on_event(void* e, EventType event_type, void* user_pointer) {
    if (event_type == EVENT_TYPE_BUTTON_DOWN) {
        ButtonDownEvent* event = (ButtonDownEvent*)e;
        switch (event->button) {
        case JOY_PLUS:
            app_quit();
            break;
        default:
            break;
        }
    }
}

MainScene* mainscene_new() {
    MainScene* scene = (MainScene*)malloc(sizeof(MainScene));

    PhysicsWorld* world = physics_new();
    scene->scene = scene_new_physics(world);

    scene_set_background(scene->scene, background_new(texture_new(fs_get_path_romfs("images/shrimp.png")), 0, 0));

    scene->shrimp = shrimp_new(scene->scene);

    vec2 pos = {0.0f, 0.0f};
    vec2 scale = {10000.0f, 10.0f};
    scene->ground = sprite_new_color(pos, scale, color_magenta());
    PhysicsObject* ground_physics = physics_add_physics_object(world, scene->ground);
    ground_physics->takes_gravity = false;
    ground_physics->filter = physics_set_all_filters();

    scene_add_sprite(scene->scene, scene->shrimp->sprite);
    scene_add_sprite(scene->scene, scene->ground);

    event_add_function(NULL, mainscene_on_event);

    return scene;
}

void mainscene_delete(MainScene* scene) {
    sprite_delete(scene->ground);
    shrimp_delete(scene->shrimp);
    scene_delete(scene->scene);
    free(scene);
}
