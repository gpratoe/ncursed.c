#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <math.h>

#include "include/vector.h"
#include "include/rasterizer.h"
#include "include/fbuffer.h"

void rotate_points(vec2 p[3], float angle)
{
    for (int i = 0; i < 3; i++)
    {
        float x = p[i].x;
        float y = p[i].y;
        p[i].x = cosf(angle) * x - sinf(angle) * y;
        p[i].y = sinf(angle) * x + cosf(angle) * y;
    }
}

int main(void)
{
    float i = 0.0001;
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr,TRUE);
    curs_set(0);
    
    fb_init(COLS,LINES);
    vec2 points[3] = {{0.5,-0.5},{-0.5,-0.5},{0.0,0.5}};

    do{
        fb_clear(' ');
        rast_triangle(points[0],points[1],points[2]);
        fb_push(0,0);
        rotate_points(points, i);
        
    }while(getch() != 'q');
    
    fb_destroy();
    endwin();
    return 0;
}