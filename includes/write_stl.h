#ifndef WRITE_STL_H
#define WRITE_STL_H

#include "triangle_ops.h"
#include <stdint.h>

void write_triangles_stl_ascii(triangle *triangles, int triangle_count);
void write_triangles_stl_bin(triangle *triangles, uint32_t triangle_count);
void float_to_scientific_notation(float d, char *s);
#endif