#ifndef TRIANGLE_OPS_H
#define TRIANGLE_OPS_H

#include "vector_ops.h"

typedef struct triangle {
	vector vx1;
	vector vx2;
	vector vx3;
	vector vnorm;
} triangle;

void triangle_generate_normal_vector(triangle *t);

#endif