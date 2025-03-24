#include <stdio.h>
#include <math.h>
#include "vector_ops.h"



typedef struct vertex {
	double x;
	double y;
	double z;
} vertex;

typedef struct triangle {
	vector vx1;
	vector vx2;
	vector vx3;
	vector vnorm;
} triangle;





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
	
	//vertices of a unit cube
	vector vertices[8];
	//each vertex can be the binary value of i, eg:
	//eg: v[0] = (0, 0, 0)
	//    v[1] = (0, 0, 1)
	//    v[2] = (0, 1, 0)
	//    v[3] = (0, 1, 1)
	//    etc.. 
	for(int i = 0; i < 8; i++) {
		vertices[i].i = i & 1; 
		vertices[i].j = (i & 2) >> 1;
		vertices[i].k = (i & 4) >> 2;
		printf("vertex %d x: %.2f, y: %.2f, z: %.2f\n", i, vertices[i].i, vertices[i].j, vertices[i].k);
	}
	
	triangle triangles[12];
	triangles[0].vx1 = vertices[0];
	triangles[0].vx2 = vertices[1];
	triangles[0].vx3 = vertices[5];
	//check cross product functionality for producing normal vector
	vector v1;
	vector v2;
	vector_subtract(triangles[0].vx2, triangles[0].vx1, &v1); //vector from vertex 1 to vertex 2
	vector_subtract(triangles[0].vx3, triangles[0].vx1, &v2); //vector from vertex 1 to vertex 3
	print_vector(v1);
	print_vector(v2);
	
	//FILE *fp;
	//fp = fopen("model.stl", "w");
	return 0;	
}

