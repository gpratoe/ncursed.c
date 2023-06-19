#include <stdlib.h>
#include <math.h>

#include "include/vector.h"
/*Vector 3*/
vec3 v3create(float x, float y, float z)
{
    vec3 v;
    v.x = x;
    v.y = y;
    v.z = z;

    return v;
}

float v3mag(vec3 v)
{
    return (float)sqrt((double)v.x*v.x + v.y*v.y + v.z*v.z);
}


vec3 v3add(vec3 v1, vec3 v2)
{
    vec3 v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    v.z = v1.z + v2.z;

    return v; 
}

vec3 v3sub(vec3 v1, vec3 v2)
{
    vec3 v;
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    v.z = v1.z - v2.z;

    return v; 
}

vec3 v3mul(vec3 v1, vec3 v2)
{
    vec3 v;
    v.x = v1.x * v2.x;
    v.y = v1.y * v2.y;
    v.z = v1.z * v2.z;
}

vec3 v3cross(vec3 v1, vec3 v2)
{
    vec3 v;
    v.x = (v1.y*v2.z - v1.z*v2.y);
    v.y = (v1.z*v2.x - v1.x*v2.z);
    v.z = (v1.x*v2.y - v1.y*v2.x);
    return v;
}

vec3 v3scale(vec3 v, float k)
{
    vec3 ret;
    ret.x = v.x * k;
    ret.y = v.y * k;
    ret.z = v.z * k;

    return ret; 
}

vec3 v3normalize(vec3 v)
{
    vec3 ret;
    float mag = v3mag(v);
    ret.x = v.x/mag;
    ret.y = v.y/mag;
    ret.z = v.z/mag;
    
    return ret;
}

vec3 v3negate(vec3 v)
{
    vec3 ret;
    ret.x = -v.x;
    ret.y = -v.y;
    ret.z = -v.z;
    
    return ret;
}

float v3dot(vec3 v1, vec3 v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

float v3angle(vec3 v1, vec3 v2)
{
    float point = v3dot(v1,v2);
    float v1m = v3mag(v1);
    float v2m = v3mag(v2);

    return (float)acos((double)point /(v1m*v2m));
}

/*Vector 2*/

vec2 v2create(float x, float y)
{
    vec2 v;
    v.x = x;
    v.y = y;

    return v;
}

float v2mag(vec2 v)
{
    return (float)sqrt((double)v.x*v.x + v.y*v.y);
}


vec2 v2add(vec2 v1, vec2 v2)
{
    vec2 v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;

    return v; 
}

vec2 v2sub(vec2 v1, vec2 v2)
{
    vec2 v;
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    return v; 
}

vec2 v2mul(vec2 v1, vec2 v2)
{
    vec2 v;
    v.x = v1.x * v2.x;
    v.y = v1.y * v2.y;
}

float v2cross(vec2 v1, vec2 v2)
{
    return (v1.x*v2.y - v1.y*v2.x);
}

vec2 v2scale(vec2 v, float k)
{
    vec2 ret;
    ret.x = v.x * k;
    ret.y = v.y * k;

    return ret; 
}

vec2 v2normalize(vec2 v)
{
    vec2 ret;
    float mag = v2mag(v);
    ret.x = v.x/mag;
    ret.y = v.y/mag;
    
    return ret;
}

vec2 v2negate(vec2 v)
{
    vec2 ret;
    ret.x = -v.x;
    ret.y = -v.y;
    return ret;
}

float v2dot(vec2 v1, vec2 v2)
{
    return v1.x*v2.x + v1.y*v2.y;
}

float v2angle(vec2 v1, vec2 v2)
{
    float point = v2dot(v1,v2);
    float v1m = v2mag(v1);
    float v2m = v2mag(v2);

    return (float)acos((double)point /(v1m*v2m));
}