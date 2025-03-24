#include "vector_ops.h"
#include <stdio.h>
#include <math.h>

void print_vector(vector v) {
	printf("i: %.2f | j: %.2f | k: %.2f\n", v.i, v.j, v.k);
}

void cross_product(vector v1, vector v2, vector *v1_x_v2)
{
	v1_x_v2->i = v1.j*v2.k - v1.k*v2.j;
	v1_x_v2->j = v1.k*v2.i - v1.i*v2.k;
	v1_x_v2->k = v1.i*v2.j - v1.j*v2.i;
	return;
}

void normalize_vector(vector *v)
{
	double scale = 1/vector_magnitude(*v);
	//printf("scale: %.2f\n", scale);
	scale_vector(v, scale);
	return;
}

void scale_vector(vector *v, double scale)
{
	v->i *= scale;
	v->j *= scale;
	v->k *= scale;
	return;
}

double vector_magnitude(vector v)
{
	double mag = sqrt(v.i*v.i + v.j*v.j + v.k*v.k);
	printf("magnitude: %.2f\n", mag);
	return mag;
}

void vector_subtract(vector v1, vector v2, vector *v1_minus_v2)
{
	v1_minus_v2->i = v1.i - v2.i;
	v1_minus_v2->j = v1.j - v2.j;
	v1_minus_v2->k = v1.k - v2.k;
	return;
}