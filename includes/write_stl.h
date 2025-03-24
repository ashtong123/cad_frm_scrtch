#ifndef WRITE_STL_H
#define WRITE_STL_H

#include "triangle_ops.h"

void write_triangles_stl(triangle *triangles, int triangle_count);
void float_to_scientific_notation(double d, char *s);
#endif