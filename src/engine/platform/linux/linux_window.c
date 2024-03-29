#include <engine/platform/config.h>
#ifdef SHRIMP_LINUX

#include <engine/graphics/window.h>
#include <engine/config.h>
#include <engine/log.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#define AUDIO_FREQUENCY 48000
#define NUM_CHANNELS 2

typedef struct Window {
    SDL_Window* window;
    SDL_GLContext* context;
} Window;

// global varibales (bad practice i know) (number of fucks given: 0)
static u32 num_windows = 0;

void window_init_sdl() {
    log_assert(SDL_Init(SDL_INIT_EVERYTHING) == 0, "failed to initialize sdl! sdl error: %s\n", SDL_GetError());
    log_assert(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP) != 0, "failed to initialize sdl image! img error: %s\n", IMG_GetError());
    log_assert(Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MID | MIX_INIT_OPUS) != 0, "failed to initialize sdl mixer! mix error: %s", Mix_GetError());
    log_assert(Mix_OpenAudio(AUDIO_FREQUENCY, AUDIO_FORMAT, AUDIO_NUM_CHANNELS, AUDIO_CHUNK_SIZE) != -1, "failed to open audio device! mix error: %s\n", Mix_GetError());    

    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    SDL_JoystickEventState(SDL_ENABLE);
    SDL_JoystickOpen(0);

    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
}

Window* window_new(const char* title, i32 width, i32 height) {
    // Initialize SDL if this is the first window
    if (num_windows <= 0) {
        window_init_sdl();
    }
    
    Window* window = (Window*)malloc(sizeof(Window));

    window->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );
    log_assert(window->window != NULL, "failed to create window! sdl error: %s\n", SDL_GetError());

    window->context = SDL_GL_CreateContext(window->window);
    log_assert(window->context != NULL, "failed to initialize opengl context! sdl error: %s\n", SDL_GetError());

    num_windows++;
    return window;
}

void window_delete(Window* window) {
    SDL_DestroyWindow(window->window);
    free(window);

    num_windows--;
    
    // If there is no window left, quit SDL
    if (num_windows <= 0) {
        Mix_CloseAudio();
        Mix_Quit();
        IMG_Quit();
        SDL_Quit();
    }
}

void window_present(Window* window) {
    SDL_GL_SwapWindow(window->window);
}

u32 window_get_width(Window* window) {
    u32 width;
    SDL_GetWindowSize(window->window, &width, NULL);
    return width;
}

u32 window_get_height(Window* window) {
    u32 height;
    SDL_GetWindowSize(window->window, NULL, &height);
    return height;
}

SDL_Window* linuxwindow_get_native_window(Window* window) {
    return window->window;
}

#endif
