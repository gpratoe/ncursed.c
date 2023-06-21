#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <math.h>
#include <unistd.h>

#include "include/vector.h"
#include "include/rasterizer.h"
#include "include/fbuffer.h"
#include "include/quaternion.h"

#define PI 3.141592

void rotate_points(vec3 points[3], quat rotation)
{
    for (int j = 0; j < 3; j++)
    {
        points[j] = qrotate_vec(points[j],rotation);
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

    vec3 points[3] = {{-0.5,0.5,0},{0.5,0.5,0},{0,-0.5,0}};
        
    quat rotation = qcreate_rotation(0.01,1,0,1);
    
    do{
        fb_clear(' ');
        rast_triangle(v3tov2(points[0]),v3tov2(points[1]),v3tov2(points[2]));
        fb_push(0,0);
        fb_swap();

        rotate_points(points, rotation);

        usleep(10000);
    }while(getch() != 'q');
    
    fb_destroy();
    endwin();
    return 0;
}