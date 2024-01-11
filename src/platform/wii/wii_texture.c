#include <platform/config.h>

#ifdef SHRIMP_WII

#include <texture.h>
#include <platform/wii/wii_texture.h>
#include <log.h>
#include <gccore.h>
#include <stdlib.h>

#include <shrimp.h>
#include <shrimp_tpl.h>

static int num_textures_created = 0;

typedef struct Texture {
    GXTexObj texture;
} Texture;

Texture* texture_new(const char* filename) {
    Texture* texture = (Texture*)malloc(sizeof(Texture));

    TPLFile file;
    log_assert(TPL_OpenTPLFromMemory(&file, (void*)shrimp_tpl, shrimp_tpl_size) != -1, "failed to open image %s!", filename);
    log_assert(TPL_GetTexture(&file, 0, &(texture->texture)) != -1, "failed to create texture object for image %s!\n", filename);
    TPL_CloseTPLFile(&file);

    num_textures_created++;

    return texture;
}

void texture_delete(Texture* texture) {
    free(texture);
}

GXTexObj wiitexture_get_texture_object(Texture* texture) {
    return texture->texture;
}

#endif
