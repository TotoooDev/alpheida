#include <engine/graphics/config.h>
#ifdef SHRIMP_GRAPHICS_OPENGL

#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

// The declaration of all the shader sources.
// They are defined in engine/platform/<platform>/shaders.

extern const char* color_vertex_shader_source;
extern const char* color_fragment_shader_source;
extern const char* texture_vertex_shader_source;
extern const char* texture_fragment_shader_source;
extern const char* background_vertex_shader_source;
extern const char* background_fragment_shader_source;
extern const char* text_vertex_shader_source;
extern const char* text_fragment_shader_source;

#endif

#endif
