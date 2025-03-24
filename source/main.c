#include <stdio.h>
#include <stdlib.h>
#include "vector_ops.h"
#include "triangle_ops.h"
#include "write_stl.h"

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
	int i;
	//vertices of a unit cube
	vector vertices[8];
	//each vertex can be the binary value of i, eg:
	//eg: v[0] = (0, 0, 0)
	//    v[1] = (0, 0, 1)
	//    v[2] = (0, 1, 0)
	//    v[3] = (0, 1, 1)
	//    etc.. 
	for(i = 0; i < 8; i++) {
		vertices[i].i = i & 1; 
		vertices[i].j = (i & 2) >> 1;
		vertices[i].k = (i & 4) >> 2;
		printf("vertex %d x: %.2f, y: %.2f, z: %.2f\n", i, vertices[i].i, vertices[i].j, vertices[i].k);
	}
	
	//create triangles for unit cube
	triangle triangles[12];
	
	triangles[0].vx1 = vertices[0];
	triangles[0].vx2 = vertices[1];
	triangles[0].vx3 = vertices[5];
	
	triangles[1].vx1 = vertices[0];
	triangles[1].vx2 = vertices[5];
	triangles[1].vx3 = vertices[4];
	
	triangles[2].vx1 = vertices[1];
	triangles[2].vx2 = vertices[3];
	triangles[2].vx3 = vertices[7];
	
	triangles[3].vx1 = vertices[1];
	triangles[3].vx2 = vertices[7];
	triangles[3].vx3 = vertices[5];

	triangles[4].vx1 = vertices[3];
	triangles[4].vx2 = vertices[2];
	triangles[4].vx3 = vertices[6];
	
	triangles[5].vx1 = vertices[3];
	triangles[5].vx2 = vertices[6];
	triangles[5].vx3 = vertices[7];
	
	triangles[6].vx1 = vertices[2];
	triangles[6].vx2 = vertices[0];
	triangles[6].vx3 = vertices[4];

	triangles[7].vx1 = vertices[2];
	triangles[7].vx2 = vertices[4];
	triangles[7].vx3 = vertices[6];	

	triangles[8].vx1 = vertices[1];
	triangles[8].vx2 = vertices[0];
	triangles[8].vx3 = vertices[3];		

	triangles[9].vx1 = vertices[0];
	triangles[9].vx2 = vertices[2];
	triangles[9].vx3 = vertices[3];	

	triangles[10].vx1 = vertices[4];
	triangles[10].vx2 = vertices[5];
	triangles[10].vx3 = vertices[7];
	
	triangles[11].vx1 = vertices[4];
	triangles[11].vx2 = vertices[7];
	triangles[11].vx3 = vertices[6];
	//Produce normal unit vector for each triangle
	for(i = 0; i < 12; ++i) {
		triangle_generate_normal_vector(&triangles[i]);
		printf("triangle: %d has normal vector: ", i);
		print_vector(triangles[i].vnorm);
	}

	//Write triangles and normal vectors to .stl file
	write_triangles_stl(triangles, 12);
	//char *s = malloc(100);
	//float_to_scientific_notation(110.250, s);
	//printf("%s\n", s);
	return 0;
}

