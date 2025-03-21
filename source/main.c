#include <stdio.h>
#include <math.h>

typedef struct vector {
	double i;
	double j;
	double k;
} vector;

void print_vector(vector v);
void cross_product(vector v1, vector v2, vector *v1_x_v2);
void normalize_vector(vector *v);
void scale_vector(vector *v, double scale);
double vector_magnitude(vector v);

int main()
{
	vector my_vector;
	my_vector.i = 1.5;
	my_vector.j = 2.0;
	my_vector.k = 0.0;
	
	vector my_vector2;
	my_vector2.i = 0.8;
	my_vector2.j = 2.7;
	my_vector2.k = 0.0;
	
	vector v1_x_v2;
	cross_product(my_vector, my_vector2, &v1_x_v2);
	print_vector(my_vector);
	print_vector(my_vector2);
	printf("The cross product of v1 and v2: ");
	print_vector(v1_x_v2);
	printf("The normalized cross product of v1 and v2: ");
	normalize_vector(&v1_x_v2);
	print_vector(v1_x_v2);
	return 0;	
}

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
