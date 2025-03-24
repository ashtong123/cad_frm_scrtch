#ifndef VECTOR_OPS_H
#define VECTOR_OPS_H

//TYPE DEFS
typedef struct vector {
	double i;
	double j;
	double k;
} vector;

//FUNCTIONS
void print_vector(vector v);
void cross_product(vector v1, vector v2, vector *v1_x_v2);
void normalize_vector(vector *v);
void scale_vector(vector *v, double scale);
double vector_magnitude(vector v);
void vector_subtract(vector v1, vector v2, vector *v1_minus_v2);

#endif