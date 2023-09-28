#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ncurses.h>

#include "include/rasterizer.h"
#include "include/fbuffer.h"


#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

char *depth = " ._=@A$#";

unsigned char r_color = '#';

void set_color(unsigned char color)
{
    r_color = color;
}

bool is_in_triangle(vec2 p, vec2 p1, vec2 p2, vec2 p3)
{
    vec2 v1 = v2sub(p2,p1);
    vec2 v2 = v2sub(p,p1);
    float w0 = v2cross(v1,v2);

    v1 = v2sub(p3,p2);
    v2 = v2sub(p,p2);
    float w1 = v2cross(v1,v2);

    v1 = v2sub(p1,p3);
    v2 = v2sub(p,p3);
    float w2 = v2cross(v1,v2);

    return (w0 < 0.1 && w1 < 0.1 && w2 < 0.1) || (w0 > -0.1 && w1 > -0.1 && w2 > -0.1); // check for same sign to account for all the triangle faces
}


void rast_triangle(const vec3 v1,const vec3 v2,const vec3 v3) // vertices must be in clockwise order
{
    int h_width = fb_width()/2;
    int h_height = fb_height()/2;
    vec2 vr1 = v2create(v1.x*h_width + h_width,-(v1.y)*h_height + h_height);
    vec2 vr2 = v2create(v2.x*h_width + h_width,-(v2.y)*h_height + h_height);
    vec2 vr3 = v2create(v3.x*h_width + h_width,-(v3.y)*h_height + h_height);

    int x_min = (int)MAX(0,floor(MIN(MIN(vr1.x,vr2.x),vr3.x)));
    int y_min = (int)MAX(0,floor(MIN(MIN(vr1.y,vr2.y),vr3.y)));
    int x_max = (int)MIN(h_width*2,ceil(MAX(MAX(vr1.x,vr2.x),vr3.x)));
    int y_max = (int)MIN(h_height*2,ceil(MAX(MAX(vr1.y,vr2.y),vr3.y)));

    vec2 p;

    for (int j = y_min; j < y_max; j++)
    {
        for (int i = x_min; i < x_max; i++)
        {
            p = v2create(i,j);
            if(is_in_triangle(p,vr1,vr2,vr3)) 
            {
                set_pixel(i,j,r_color);
            }
            //else set_pixel(i,j,'.');
        }
    }
}
