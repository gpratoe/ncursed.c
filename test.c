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
    
    fb_init(40,20);
    vec2 points[3] = {{1,-1},{-1,-1},{0.0,1}};

    do{
        fb_clear('_');
        rast_triangle(points[0],points[1],points[2]);
        fb_push(COLS/2 - 20,LINES/2-10);
        rotate_points(points, i);
        
    }while(getch() != 'q');
    
    fb_destroy();
    endwin();
    return 0;
}