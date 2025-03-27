#include "vector_ops.h"
#include <stdio.h>
#include <math.h>

void print_vector(vector v) {
	printf("i: %.2f | j: %.2f | k: %.2f\n", v.ijk[0], v.ijk[1], v.ijk[2]);
}

void cross_product(vector v1, vector v2, vector *v1_x_v2)
{
	v1_x_v2->ijk[0] = v1.ijk[1]*v2.ijk[2] - v1.ijk[2]*v2.ijk[1];
	v1_x_v2->ijk[1] = v1.ijk[2]*v2.ijk[0] - v1.ijk[0]*v2.ijk[2];
	v1_x_v2->ijk[2] = v1.ijk[0]*v2.ijk[1] - v1.ijk[1]*v2.ijk[0];
	return;
}

void normalize_vector(vector *v)
{
	float scale = 1/vector_magnitude(*v);
	//printf("scale: %.2f\n", scale);
	scale_vector(v, scale);
	return;
}

void scale_vector(vector *v, float scale)
{
	v->ijk[0] *= scale;
	v->ijk[1] *= scale;
	v->ijk[2] *= scale;
	return;
}

float vector_magnitude(vector v)
{
	float mag = sqrt(v.ijk[0]*v.ijk[0] + v.ijk[1]*v.ijk[1] + v.ijk[2]*v.ijk[2]);
	printf("magnitude: %.2f\n", mag);
	return mag;
}

void vector_subtract(vector v1, vector v2, vector *v1_minus_v2)
{
	v1_minus_v2->ijk[0] = v1.ijk[0] - v2.ijk[0];
	v1_minus_v2->ijk[1] = v1.ijk[1] - v2.ijk[1];
	v1_minus_v2->ijk[2] = v1.ijk[2] - v2.ijk[2];
	return;
}