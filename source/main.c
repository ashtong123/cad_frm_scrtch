#include <stdio.h>
#include <stdlib.h>
#include "vector_ops.h"
#include "triangle_ops.h"
#include "write_stl.h"
#include "shapes.h"

int main()
{
	/*
	TESTING VECTOR OPS
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
	*/
	
	triangle *triangles = malloc(sizeof(triangle)*12);
	unit_cube(triangles);
	//Write triangles and normal vectors to .stl file
	write_triangles_stl(triangles, 12);
	//char *s = malloc(100);
	//float_to_scientific_notation(110.250, s);
	//printf("%s\n", s);
	return 0;
}

