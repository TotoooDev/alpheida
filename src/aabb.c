#include <aabb.h>
#include <stdlib.h>

AABB* aabb_new(float x, float y, float width, float height) {
    AABB* aabb = (AABB*)malloc(sizeof(AABB));

    aabb->x = x;
    aabb->y = y;
    aabb->width = width;
    aabb->height = height;

    return aabb;
}

void aabb_delete(AABB* aabb) {
    free(aabb);
}

bool aabb_intersect(AABB* a, AABB* b) {
    return
        (a->x < b->x + b->width  && a->x + a->width  > b->x) &&
        (a->y < b->y + b->height && a->y + a->height > b->y);
}

IntersectionAxis aabb_get_intersection_axis(AABB* a, AABB* b) {
    if (a->y + a->height > b->y)
        return INTERSECTION_AXIS_POSITIVE_Y;
    if (b->y + b->height > a->y)
        return INTERSECTION_AXIS_NEGATIVE_Y;
    if (a->x + a->width > b->x)
        return INTERSECTION_AXIS_NEGATIVE_X;
    if (b->x + b->width > a->x)
        return INTERSECTION_AXIS_POSITIVE_X;
    return INTERSECTION_AXIS_NONE;
}

