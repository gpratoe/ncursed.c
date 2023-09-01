#include <stdlib.h>

#include "include/camera.h"
#include "include/vector.h"

struct camera_t
{
    vec3 position;
    vec3 up;
    vec3 right;
    vec3 forward;
    m44 rotation;
    m44 translation;
    m44 view;
    m44 proj;

    float fov,ar,znear,zfar;
};

camera cam_new()
{
    camera cam;
    cam = malloc(sizeof(struct camera_t));
    cam->position = v3create(0,0,0);
    cam->forward = v3create(0,0,1);
    cam->up = v3create(0,1,0);
    cam->right = v3create(1,0,0);
    cam->view = m4identity();
    cam->proj = m4identity();

    return cam; 
}

void cam_move(camera cam, vec3 position)
{
    cam->position = position;
}

void cam_rotate(camera cam, vec3 up, vec3 right, vec3 forward)
{
    cam->up = up;
    cam->forward = forward;
    cam->right = right;

}

void cam_set_view(camera cam)
{
    cam->translation = m4identity();
    cam->translation.m30 = cam->position.x;
    cam->translation.m31 = cam->position.y;
    cam->translation.m32 = cam->position.z;
    cam->rotation = m4identity();
    cam->rotation.m00 = cam->right.x;
    cam->rotation.m01 = cam->up.x;
    cam->rotation.m02 = cam->forward.x;
    cam->rotation.m10 = cam->right.y;
    cam->rotation.m11 = cam->up.y;
    cam->rotation.m12 = cam->forward.y;
    cam->rotation.m20 = cam->right.z;
    cam->rotation.m21 = cam->up.z;
    cam->rotation.m22 = cam->forward.z;
    cam->view = m4mul(cam->translation,cam->rotation);
}

void cam_set_proj(camera cam, float fov, float ar, float znear, float zfar)
{
    cam->fov = fov;
    cam->ar = ar;
    cam->znear = znear;
    cam->zfar = zfar;
    
    cam->proj = m4proj(fov,ar,znear,zfar);
}

m44 cam_get_view(camera cam)
{
    return cam->view;
}

m44 cam_get_proj(camera cam)
{
    return cam->proj;
}

void cam_destroy(camera cam)
{
    free(cam);
    cam = NULL;
}

vec3 cam_get_pos(camera cam)
{
    return cam->position;
}