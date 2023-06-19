#ifndef RASTERIZER_H_
#define RASTERIZER_H_

#include "vector.h"

void init_fb(int WIDTH, int HEIGHT);

void rast_triangle(vec2 v1, vec2 v2, vec2 v3);

#endif //RASTERIZER_H_