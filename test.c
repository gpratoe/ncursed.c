#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

#include "include/vector.h"
#include "include/rasterizer.h"
#include "include/fbuffer.h"
#include "include/quaternion.h"
#include "include/matrix4.h"
#include "include/camera.h"

#define PI 3.141592

void rotate_points(vec4 points[3], quat rotation, vec4 dest[3])
{
    for (int j = 0; j < 3; j++)
    {
        dest[j] = qrotate_vec4(points[j],rotation);
    }
}

int main(void)
{
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr,TRUE);
    curs_set(0);
    fb_init(COLS,LINES);

    float angle = PI;

    float asp = COLS/(LINES*2);
    float fov = PI/3;
    float zfar = 400, znear = 0.2;

    vec4 points[3] = {{-2,2,0,1},
                      {2,2,0,1},
                      {0,-2,0,1}};
    vec4 rotated_points[3];
    
    camera cam = cam_new();
    cam_set_proj(cam,fov,asp,znear,zfar);
    cam_move(cam,v3create(0,0,-2));
    cam_set_view(cam);
    m44 viewm = cam_get_view(cam);
    m44 projm = cam_get_proj(cam);
    m44 final;
    quat rotation; 
    
    set_color('0');
    
    do
    {
        final = m4mul(viewm,projm);

        rotation = qcreate_rotation(angle,0,1,0);

        rotate_points(points,rotation,rotated_points);    

        for (int i = 0; i < 3; i++)
        {
            rotated_points[i] = m4transform(final, rotated_points[i]);
            rotated_points[i].x /= rotated_points[i].w;
            rotated_points[i].y /= rotated_points[i].w;
            rotated_points[i].z /= rotated_points[i].w;
        }

        fb_clear(' ');
        rast_triangle(v4tov3(rotated_points[0]), v4tov3(rotated_points[1]), v4tov3(rotated_points[2]));
        fb_push(0, 0);
        fb_swap();

        angle += 0.01f;
        usleep(10000);
    }while(getch() != 'q');

    fb_destroy();
    cam_destroy(cam);
    endwin();
    return 0;
}