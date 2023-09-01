#ifndef CAMERA_H_
#define CAMERA_H_

#include "matrix4.h"

typedef struct camera_t *camera;

camera cam_new();

void cam_set_view(camera cam);

void cam_set_proj(camera cam, float fov, float ar, float znear, float zfar);

void cam_move(camera cam, vec3 position);

void cam_rotate(camera cam, vec3 up, vec3 right, vec3 forward);

m44 cam_get_view(camera cam);

m44 cam_get_proj(camera cam);

void cam_destroy(camera cam);

vec3 cam_get_pos(camera cam);

#endif //CAMERA_H_