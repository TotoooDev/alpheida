#include <sprite.h>
#include <stdlib.h>

void sprite_default_draw_function(Sprite* sprite, Window* window) {
    // draw the sprite (easy)
    if (sprite->use_color || sprite->texture == NULL)
        window_render_color(window, sprite->color, sprite->aabb);
    else
        window_render_full_texture(window, sprite->texture, sprite->aabb);
}

Sprite* sprite_new(float x, float y, float width, float height, Texture* texture) {
    Sprite* sprite = (Sprite*)malloc(sizeof(Sprite));

    sprite->aabb = aabb_new(x, y, width, height);
    sprite->texture = texture;
    sprite->color = color_magenta();
    sprite->use_color = false;

    sprite->update_function = NULL;
    sprite->draw_function = sprite_default_draw_function;
    sprite->user_pointer = NULL;

    return sprite;
}

Sprite* sprite_new_color(float x, float y, float width, float height, Color color) {
    Sprite* sprite = sprite_new(x, y, width, height, NULL);
    sprite->color = color;
    sprite->use_color = true;
    return sprite;
}

void sprite_delete(Sprite* sprite) {
    aabb_delete(sprite->aabb);
    free(sprite);
}

