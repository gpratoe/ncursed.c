#include <ncurses.h>
#include <stdlib.h>
#include <memory.h>

#include "include/fbuffer.h"

//TODO: Double buffering

typedef struct fb_t
{
    unsigned char *buff_1;
    unsigned char *buff_2;
    int width;
    int height;

}framebuffer;

framebuffer fb;

void fb_init(int WIDTH, int HEIGHT)
{
    fb.buff_1 = calloc((WIDTH*HEIGHT)+1,sizeof(unsigned char));
    fb.buff_2 = calloc((WIDTH*HEIGHT)+1,sizeof(unsigned char));
    fb.width = WIDTH;
    fb.height = HEIGHT;

    memset(fb.buff_1,'\0',fb.width*fb.height+1);
}

void fb_clear(unsigned char color)
{
    memset(fb.buff_1,color,fb.width*fb.height+1);
}

void set_pixel(int x, int y, unsigned char color)
{
    fb.buff_1[(y * fb.width + x)] = color;
}

void fb_push(int off_x, int off_y)
{
    int fwidth = fb.width + off_x;
    int fheight = fb.height + off_y;
    
    for (int j = off_y; j < fheight; j++)
    {
        for (int i = off_x; i < fwidth; i++)
        {
            int index = (j-off_y)*fb.width + (i-off_x);
            
            unsigned char color = fb.buff_1[index];
            
            mvaddch(j,i,color);
        }
    }
    
}

int fb_width()
{
    return fb.width;
}

int fb_height()
{
    return fb.height;
}

void fb_destroy()
{
    free(fb.buff_1);
    free(fb.buff_2);
}