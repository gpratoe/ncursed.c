#include <math.h>

#include "include/matrix4.h"

m44 m4identity()
{
    m44 ret = {1,0,0,0,
               0,1,0,0,
               0,0,1,0,
               0,0,0,1};
    return ret;
}

m44 m4add(m44 a, m44 b)
{
    m44 ret;
    ret.m00 = a.m00 + b.m00;
    ret.m01 = a.m01 + b.m01;
    ret.m02 = a.m02 + b.m02;
    ret.m03 = a.m03 + b.m03;
    ret.m10 = a.m10 + b.m10;
    ret.m11 = a.m11 + b.m11;
    ret.m12 = a.m12 + b.m12;
    ret.m13 = a.m13 + b.m13;
    ret.m20 = a.m20 + b.m20;
    ret.m21 = a.m21 + b.m21;
    ret.m22 = a.m22 + b.m22;
    ret.m23 = a.m23 + b.m23;
    ret.m30 = a.m30 + b.m30;
    ret.m31 = a.m31 + b.m31;
    ret.m32 = a.m32 + b.m32;
    ret.m33 = a.m33 + b.m33;    

    return ret;
}

m44 m4sub(m44 a, m44 b)
{
    m44 ret;
    ret.m00 = a.m00 - b.m00;
    ret.m01 = a.m01 - b.m01;
    ret.m02 = a.m02 - b.m02;
    ret.m03 = a.m03 - b.m03;
    ret.m10 = a.m10 - b.m10;
    ret.m11 = a.m11 - b.m11;
    ret.m12 = a.m12 - b.m12;
    ret.m13 = a.m13 - b.m13;
    ret.m20 = a.m20 - b.m20;
    ret.m21 = a.m21 - b.m21;
    ret.m22 = a.m22 - b.m22;
    ret.m23 = a.m23 - b.m23;
    ret.m30 = a.m30 - b.m30;
    ret.m31 = a.m31 - b.m31;
    ret.m32 = a.m32 - b.m32;
    ret.m33 = a.m33 - b.m33;    

    return ret;
}

m44 m4mul(m44 a, m44 b)
{
    m44 ret;
    ret.m00 = a.m00*b.m00+a.m01*b.m10+a.m02*b.m20+a.m03*b.m30;
    ret.m01 = a.m00*b.m01+a.m01*b.m11+a.m02*b.m21+a.m03*b.m31;
    ret.m02 = a.m00*b.m02+a.m01*b.m12+a.m02*b.m22+a.m03*b.m32;
    ret.m03 = a.m00*b.m03+a.m01*b.m13+a.m02*b.m23+a.m03*b.m33;
    
    ret.m10 = a.m10*b.m00+a.m11*b.m10+a.m12*b.m20+a.m13*b.m30;
    ret.m11 = a.m10*b.m01+a.m11*b.m11+a.m12*b.m21+a.m13*b.m31;
    ret.m12 = a.m10*b.m02+a.m11*b.m12+a.m12*b.m22+a.m13*b.m32;
    ret.m13 = a.m10*b.m03+a.m11*b.m13+a.m12*b.m23+a.m13*b.m33;

    ret.m20 = a.m20*b.m00+a.m21*b.m10+a.m22*b.m20+a.m23*b.m30;
    ret.m21 = a.m20*b.m01+a.m21*b.m11+a.m22*b.m21+a.m23*b.m31;
    ret.m22 = a.m20*b.m02+a.m21*b.m12+a.m22*b.m22+a.m23*b.m32;
    ret.m23 = a.m20*b.m03+a.m21*b.m13+a.m22*b.m23+a.m23*b.m33;

    ret.m30 = a.m30*b.m00+a.m31*b.m10+a.m32*b.m20+a.m33*b.m30;
    ret.m31 = a.m30*b.m01+a.m31*b.m11+a.m32*b.m21+a.m33*b.m31;
    ret.m32 = a.m30*b.m02+a.m31*b.m12+a.m32*b.m22+a.m33*b.m32;
    ret.m33 = a.m30*b.m03+a.m31*b.m13+a.m32*b.m23+a.m33*b.m33;

    return ret;
}

m44 m4negate(m44 a)
{
    m44 ret;

    ret.m00 = -a.m00;
    ret.m01 = -a.m01;
    ret.m02 = -a.m02;
    ret.m03 = -a.m03;

    ret.m10 = -a.m10;
    ret.m11 = -a.m11;
    ret.m12 = -a.m12;
    ret.m13 = -a.m13;

    ret.m20 = -a.m20;
    ret.m21 = -a.m21;
    ret.m22 = -a.m22;
    ret.m23 = -a.m23;

    ret.m30 = -a.m30;
    ret.m31 = -a.m31;
    ret.m32 = -a.m32;
    ret.m33 = -a.m33;

    return ret;
}

vec4 m4transform(m44 a, vec4 v)
{
    vec4 ret;
    
    ret.x = a.m00*v.x+a.m01*v.y+a.m02*v.z+a.m03*v.w;
    ret.y = a.m10*v.x+a.m11*v.y+a.m12*v.z+a.m13*v.w;
    ret.z = a.m20*v.x+a.m21*v.y+a.m22*v.z+a.m23*v.w;
    ret.w = a.m30*v.x+a.m31*v.y+a.m32*v.z+a.m33*v.w;

    return ret;
}

float m4det(m44 a)
{
    float f;

    f = a.m00 * ((a.m11 * a.m22 * a.m33 + a.m12 * a.m23 * a.m31 + a.m13 * a.m21 * a.m32)
            - a.m13 * a.m22 * a.m31
            - a.m11 * a.m23 * a.m32
            - a.m12 * a.m21 * a.m33);
    f -= a.m01 * ((a.m10 * a.m22 * a.m33 + a.m12 * a.m23 * a.m30 + a.m13 * a.m20 * a.m32)
            - a.m13 * a.m22 * a.m30
            - a.m10 * a.m23 * a.m32
            - a.m12 * a.m20 * a.m33);
    f += a.m02 * ((a.m10 * a.m21 * a.m33 + a.m11 * a.m23 * a.m30 + a.m13 * a.m20 * a.m31)
            - a.m13 * a.m21 * a.m30
            - a.m10 * a.m23 * a.m31
            - a.m11 * a.m20 * a.m33);
    f -= a.m03 * ((a.m10 * a.m21 * a.m32 + a.m11 * a.m22 * a.m30 + a.m12 * a.m20 * a.m31)
            - a.m12 * a.m21 * a.m30
            - a.m10 * a.m22 * a.m31
            - a.m11 * a.m20 * a.m32);

    return f;
}

m44 m4rotate(m44 m, vec3 axis, float angle){

    m44 ret;

    float c = (float) cos(angle);
    float s = (float) sin(angle);
    float oneminusc = 1.0f - c;
    float xy = axis.x*axis.y;
    float yz = axis.y*axis.z;
    float xz = axis.x*axis.z;
    float xs = axis.x*s;
    float ys = axis.y*s;
    float zs = axis.z*s;

    float f00 = axis.x*axis.x*oneminusc+c;
    float f01 = xy*oneminusc+zs;
    float f02 = xz*oneminusc-ys;
    float f10 = xy*oneminusc-zs;
    float f11 = axis.y*axis.y*oneminusc+c;
    float f12 = yz*oneminusc+xs;
    float f20 = xz*oneminusc+ys;
    float f21 = yz*oneminusc-xs;
    float f22 = axis.z*axis.z*oneminusc+c;

    float t00 = m.m00 * f00 + m.m10 * f01 + m.m20 * f02;
    float t01 = m.m01 * f00 + m.m11 * f01 + m.m21 * f02;
    float t02 = m.m02 * f00 + m.m12 * f01 + m.m22 * f02;
    float t03 = m.m03 * f00 + m.m13 * f01 + m.m23 * f02;
    float t10 = m.m00 * f10 + m.m10 * f11 + m.m20 * f12;
    float t11 = m.m01 * f10 + m.m11 * f11 + m.m21 * f12;
    float t12 = m.m02 * f10 + m.m12 * f11 + m.m22 * f12;
    float t13 = m.m03 * f10 + m.m13 * f11 + m.m23 * f12;

    ret.m20 = m.m00 * f20 + m.m10 * f21 + m.m20 * f22;
    ret.m21 = m.m01 * f20 + m.m11 * f21 + m.m21 * f22;
    ret.m22 = m.m02 * f20 + m.m12 * f21 + m.m22 * f22;
    ret.m23 = m.m03 * f20 + m.m13 * f21 + m.m23 * f22;
    ret.m00 = t00;
    ret.m01 = t01;
    ret.m02 = t02;
    ret.m03 = t03;
    ret.m10 = t10;
    ret.m11 = t11;
    ret.m12 = t12;
    ret.m13 = t13;

    return ret;
}

m44 m4scale(m44 a, vec3 scale)
{
    m44 ret;

    ret.m00 = a.m00 * scale.x;
    ret.m01 = a.m01 * scale.x;
    ret.m02 = a.m02 * scale.x;
    ret.m03 = a.m03 * scale.x;
    ret.m10 = a.m10 * scale.y;
    ret.m11 = a.m11 * scale.y;
    ret.m12 = a.m12 * scale.y;
    ret.m13 = a.m13 * scale.y;
    ret.m20 = a.m20 * scale.z;
    ret.m21 = a.m21 * scale.z;
    ret.m22 = a.m22 * scale.z;
    ret.m23 = a.m23 * scale.z;

    return ret;
}

m44 m4proj(float fov, float ar, float znear, float zfar)
{
    m44 ret = m4identity();
    ret.m00 = 1/(ar*tan(fov/2));
    ret.m11 = 1/(tan(fov/2));
    ret.m22 = -((zfar+znear)/(zfar-znear));
    ret.m32 = -((2*zfar*znear)/(zfar-znear));
    ret.m23 = -1;

    return ret;
}

m44 m4translate(m44 a, vec3 v)
{
    a.m30 = a.m00 * v.x + a.m10 * v.y + a.m20 * v.z;
    a.m31 = a.m01 * v.x + a.m11 * v.y + a.m21 * v.z;
    a.m32 = a.m02 * v.x + a.m12 * v.y + a.m22 * v.z;
    a.m33 = a.m03 * v.x + a.m13 * v.y + a.m23 * v.z;

    return a;
}