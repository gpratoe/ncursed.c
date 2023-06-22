#ifndef MATRIX4_H_
#define MATRIX4_H_

#include "vector.h"

typedef struct m44_t{
    float m00,m01,m02,m03,
          m10,m11,m12,m13,
          m20,m21,m22,m23,
          m30,m31,m32,m33;
}m44;

m44 m4identity();

m44 m4add(m44 a, m44 b);

m44 m4sub(m44 a, m44 b);

m44 m4mul(m44 a, m44 b);

m44 m4negate(m44 a);

m44 m4scale(m44 a, vec3 scale);

m44 m4rotate(m44 m, vec3 axis, float angle);

m44 m4proj(float fov, float ar, float znear, float zfar);

m44 m4translate(m44 a, vec3 v);

m44 m4lookat(vec3 eye, vec3 target, vec3 up);

vec4 m4transform(m44 a, vec4 v);

float m4det(m44 a);

#endif //MATRIX4_H_