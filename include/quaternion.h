#ifndef QUATERNION_H_
#define QUATERNION_H_

#include "vector.h"

typedef vec4 quat;

#define qadd(q0,q1) v4add((q0),(q1))

#define qsub(q0,q1) v4sub((q0),(q1))

#define qscale(q,s) v4scale((q),(s));

#define qnorm(q) v4mag((q));

#define qnormalize(q) v4normalize((q));

#define qcreate(w,x,y,z) v4create((x),(y),(z),(w));

quat qmul(quat q0, quat q1);

quat qconjugate(quat q);

quat qinverse(quat q);

quat qcreate_rotation(float angle, float x, float y, float z);

vec3 qrotate_vec(vec3 v, quat q);

#endif //QUATERNION_H_