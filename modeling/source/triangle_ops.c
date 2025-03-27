#include "triangle_ops.h"
#include "vector_ops.h"

void triangle_generate_normal_vector(triangle *t) 
{
	vector v1, v2, vnorm;
	vector_subtract(t->vx2, t->vx1, &v1); //vector from vertex 1 to vertex 2
	vector_subtract(t->vx3, t->vx1, &v2); //vector from vertex 1 to vertex 3
	//print_vector(v1);
	//print_vector(v2);
	cross_product(v1, v2, &vnorm);
	normalize_vector(&vnorm);
	//print_vector(vnorm);
	t->vnorm = vnorm;
	return;
}