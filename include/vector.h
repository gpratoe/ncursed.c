#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct vec2_t
{
    float x,y;
}vec2;

typedef struct vec3_t
{
    float x,y,z;
}vec3;

/**
 * @brief Creates a new vec3.
 * 
 * @param x x component
 * @param y y component
 * @param z z component
 *  
 * @return vec3 
 */
vec3 v3create(float x, float y, float z);

/**
 * @brief Adds two vectors.
 * 
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return vec3 
 */
vec3 v3add(vec3 v1, vec3 v2);

/**
 * @brief Substracts two vectors.
 * 
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return vec3 
 */
vec3 v3sub(vec3 v1, vec3 v2);

/**
 * @brief Multiplies v1 by v1, coordenate to coordenate.
 * 
 * @param v1 
 * @param v2 
 * @return vec3 
 */
vec3 v3mul(vec3 v1, vec3 v2);

/**
 * @brief Do a cross product between two vectors.
 * 
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return vec3 
 */
vec3 v3cross(vec3 v1, vec3 v2);


/**
 * @brief Scales the vector by a magnitud of k.
 * 
 * @param v Vector.
 * @param k Magnitud.
 * @return vec3 
 */
vec3 v3scale(vec3 v, float k);

/**
 * @brief Normalizes a vector.
 * 
 * @param v Vector.
 * @return vec3 
 */
vec3 v3normalize(vec3 v);

/**
 * @brief Returns the vector with its components negated.
 * 
 * @param v Vector.
 * @return vec3 
 */
vec3 v3negate(vec3 v);

/**
 * @brief Returns the dot product between the two vectors.
 * 
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return float 
 */
float v3dot(vec3 v1, vec3 v2);

/**
 * @brief Returns the angle between the vectors.
 * 
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return float 
 */
float v3angle(vec3 v1, vec3 v2);

/**
 * @brief Returns the magnitud (or length) of the vector.
 * 
 * @param v Vector.
 * @return float 
 */
float v3mag(vec3 v);


/*Vector 2*/


/**
 * @brief Creates a new vec2.
 * 
 * @param x x component
 * @param y y component
 *  
 * @return vec2 
 */
vec2 v2create(float x, float y);

/**
 * @brief Adds two vectors.
 * 
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return vec2 
 */
vec2 v2add(vec2 v1, vec2 v2);

/**
 * @brief Substracts two vectors.
 * 
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return vec2 
 */
vec2 v2sub(vec2 v1, vec2 v2);

/**
 * @brief Multiplies v1 by v1, coordenate to coordenate.
 * 
 * @param v1 
 * @param v2 
 * @return vec2 
 */
vec2 v2mul(vec2 v1, vec2 v2);

/**
 * @brief Returns z coordenate of its relative 3d vector cross product. 
 * 
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return float 
 */
float v2cross(vec2 v1, vec2 v2);


/**
 * @brief Scales the vector by a magnitud of k.
 * 
 * @param v Vector.
 * @param k Magnitud.
 * @return vec2 
 */
vec2 v2scale(vec2 v, float k);

/**
 * @brief Normalizes a vector.
 * 
 * @param v Vector.
 * @return vec2 
 */
vec2 v2normalize(vec2 v);

/**
 * @brief Returns the vector with its components negated.
 * 
 * @param v Vector.
 * @return vec2 
 */
vec2 v2negate(vec2 v);

/**
 * @brief Returns the dot product between the two vectors.
 * 
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return float 
 */
float v2dot(vec2 v1, vec2 v2);

/**
 * @brief Returns the angle between the vectors.
 * 
 * @param v1 First vector.
 * @param v2 Second vector.
 * @return float 
 */
float v2angle(vec2 v1, vec2 v2);

/**
 * @brief Returns the magnitud (or length) of the vector.
 * 
 * @param v Vector.
 * @return float 
 */
float v2mag(vec2 v);
#endif //VECTOR_H_