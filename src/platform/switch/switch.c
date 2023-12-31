#include <platform/config.h>
#ifdef SHRIMP_SWITCH

#include <config.h>
#include <platform/platform.h>
#include <log.h>
#include <switch.h>

void platform_init() {
    // initialize romfs
    Result result = romfsInit();
    log_assert(R_SUCCEEDED(result), "%08X: failed to initialize switch romfs!\n", result);

#ifdef SHRIMP_DEBUG
    // initialize nxlink for printf debugging
    // https://switch.homebrew.guide/homebrew_dev/app_dev.html#printf-debugging-through-nxlink
    socketInitializeDefault();
    nxlinkStdio();
#endif
}

void platform_update() {

}

void platform_exit() {
#ifdef SHRIMP_DEBUG
    socketExit();
#endif

    romfsExit();
}

#endif

