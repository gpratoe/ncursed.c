#include <ncurses.h>
#include <stdlib.h>
#include <memory.h>

#include "include/fbuffer.h"

//TODO: Double buffering

typedef struct fb_t
{
    unsigned char *buff[2];
    int width;
    int height;

}framebuffer;

framebuffer fb;
unsigned int r_buff, p_buff;

void fb_init(int WIDTH, int HEIGHT)
{
    fb.buff[0] = calloc((WIDTH*HEIGHT)+1,sizeof(unsigned char));
    fb.buff[1] = calloc((WIDTH*HEIGHT)+1,sizeof(unsigned char));
    fb.width = WIDTH;
    fb.height = HEIGHT;
    r_buff = 0;
    p_buff = 1;
    memset(fb.buff[0],'\0',WIDTH*HEIGHT);
    memset(fb.buff[1],'\0',WIDTH*HEIGHT);
}

void fb_swap()
{
    r_buff = !r_buff;
    p_buff = !p_buff;
}

void fb_clear(unsigned char color)
{
    memset(fb.buff[r_buff],color,fb.width*fb.height);
}

void set_pixel(int x, int y, unsigned char color)
{
    fb.buff[r_buff][(y * fb.width + x)] = color;
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
            
            unsigned char color = fb.buff[p_buff][index];
            
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
    free(fb.buff[0]);
    free(fb.buff[1]);
}