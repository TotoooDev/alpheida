#include <engine/event.h>
#include <engine/platform/platform.h>
#include <engine/log.h>
#include <stdlib.h>

#define EVENT_FUNCTIONS_SIZE 64
#define EVENT_MAX_WAITING 128
#define MAX_EVENT_STRUCT_SIZE sizeof(MouseMovedEvent)

static EventFunction event_functions[EVENT_FUNCTIONS_SIZE];
static void* user_pointers[EVENT_FUNCTIONS_SIZE];
static u32 num_event_functions = 0;

static void* event_pool[EVENT_MAX_WAITING];
static EventType waiting_event_types[EVENT_MAX_WAITING];
static u32 num_waiting_events = 0;

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

    for (u32 i = 0; i < num_waiting_events; i++) {
        event_type = waiting_event_types[i];
        event = event_pool[i];
        for (u32 i = 0; i < num_event_functions; i++)
            event_functions[i](event, event_type, user_pointers[i]);
    }
    num_waiting_events = 0;

    while ((event_type = platform_process_events(event)) != EVENT_TYPE_NONE) {
        for (u32 i = 0; i < num_event_functions; i++)
            event_functions[i](event, event_type, user_pointers[i]);
    }

    event_delete(event);
}

void event_add_function(void* user_pointer, EventFunction function) {
    log_assert(num_event_functions < EVENT_FUNCTIONS_SIZE, "failed to add event function! the array is not big enough.\n");
    event_functions[num_event_functions] = function;
    user_pointers[num_event_functions] = user_pointer;
    num_event_functions++;
}

void event_send_event(EventType event_type, void* event) {
    log_assert(num_event_functions < EVENT_FUNCTIONS_SIZE, "failed to add event to waiting pool! the array is not big enough.\n");
    event_pool[num_waiting_events] = event;
    waiting_event_types[num_waiting_events] = event_type;
    num_waiting_events++;
}
