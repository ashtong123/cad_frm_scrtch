#include <stdio.h>
#include <stdlib.h>
#include "vector_ops.h"
#include "triangle_ops.h"
#include "write_stl.h"
#include "shapes.h"
#include <stdint.h>

int main()
{
	//create a polygonal mesh of a unit cube, space for 12 triangles
	//must be allocated on the heap
	triangle *triangles = malloc(sizeof(triangle)*12);
	unit_cube(triangles);
	//Write mesh triangles and normal vectors to .stl file
	write_triangles_stl_bin(triangles, 12);
	return 0;
}

