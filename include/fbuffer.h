#ifndef FBUFFER_H_
#define FBUFFER_H_

void fb_init(int WIDTH, int HEIGHT);

void fb_swap();

void set_pixel(int x, int y, unsigned char color);

void fb_push(int off_x, int off_y);

void fb_clear(unsigned char color);

int fb_width();

int fb_height();

void fb_destroy();
#endif //FBUFFER_H_