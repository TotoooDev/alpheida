#include <event.h>
#include <platform/platform.h>
#include <log.h>
#include <stdlib.h>

#define EVENT_FUNCTIONS_SIZE 64
#define MAX_EVENT_STRUCT_SIZE sizeof(JoystickMotionEvent)

static EventFunction event_functions[EVENT_FUNCTIONS_SIZE];
static void* user_pointers[EVENT_FUNCTIONS_SIZE];
static unsigned int num_event_functions = 0;

void* event_new() {
    void* event = malloc(MAX_EVENT_STRUCT_SIZE);
    return event;
}

void event_delete(void* event) {
    free(event);
}

void event_update() {
    EventType event_type;
    void* event = event_new();

    do {
        platform_process_events(&event_type, event);
        for (unsigned int i = 0; i < num_event_functions; i++)
            event_functions[i](event, event_type, user_pointers[i]);
    } while (event_type != EVENT_TYPE_NONE);

    event_delete(event);
}

void event_add_function(void* user_pointer, EventFunction function) {
    log_assert(num_event_functions < EVENT_FUNCTIONS_SIZE, "failed to add event function! the array is not big enough.\n");
    event_functions[num_event_functions] = function;
    user_pointers[num_event_functions] = user_pointer;
    num_event_functions++;
}
