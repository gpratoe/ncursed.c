#ifndef RASTERIZER_H_
#define RASTERIZER_H_

#include "vector.h"

void init_fb(int WIDTH, int HEIGHT);

void rast_triangle(vec3 v1, vec3 v2, vec3 v3, unsigned char color);

#endif //RASTERIZER_H_