#include <math.h>

#include "include/quaternion.h"

quat qmul(quat q0, quat q1)
{
    quat ret;
    ret.w = q0.w * q1.w - q0.x * q1.x - q0.y * q1.y - q0.z * q1.z;
    ret.x = q0.w * q1.x + q0.x * q1.w + q0.y * q1.z - q0.z * q1.y;
    ret.y = q0.w * q1.y - q0.x * q1.z + q0.y * q1.w + q0.z * q1.x;
    ret.z = q0.w * q1.z + q0.x * q1.y - q0.y * q1.x + q0.z * q1.w;
    return ret;
}

quat qconjugate(quat q)
{
    quat ret = q;
    ret.x *=-1;
    ret.y *=-1;
    ret.z *=-1;

    return ret;
}

quat qinverse(quat q)
{
    quat ret;
    float s_norm = qnorm(q);
    quat qc = qconjugate(q);
    s_norm *= s_norm;
    ret = qscale(qc,(1/s_norm));
    return ret;
}

quat qcreate_rotation(float angle, float x, float y, float z)
{
    quat ret;
    float half_angle = angle * 0.5f;
    float sin_half_angle = sinf(half_angle);
    ret.w = cosf(half_angle);
    ret.x = x * sin_half_angle;
    ret.y = y * sin_half_angle;
    ret.z = z * sin_half_angle;

    return ret;
}

vec3 qrotate_vec3(vec3 v, quat q)
{
    vec3 ret;
    quat vtoq = qcreate(0,v.x,v.y,v.z);
    quat conjugate = qconjugate(q);
    quat res = qmul(q, qmul(vtoq, conjugate));
    ret.x = res.x;
    ret.y = res.y;
    ret.z = res.z;

    return ret;
}

vec4 qrotate_vec4(vec4 v, quat q)
{
    vec4 ret;
    quat vtoq = qcreate(0,v.x,v.y,v.z);
    quat conjugate = qconjugate(q);
    quat res = qmul(q, qmul(vtoq, conjugate));
    ret.x = res.x;
    ret.y = res.y;
    ret.z = res.z;

    return ret;
}