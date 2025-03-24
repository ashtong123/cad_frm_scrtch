#include "write_stl.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void write_triangles_stl(triangle *triangles, int triangle_count)
{
	FILE *fp;
	char *s1;
	char *s2;
	char *s3;
	fp = fopen(".\\models\\cube.stl", "w");
	fputs("solid cube\n", fp);
	for(int i = 0; i < triangle_count; ++i) {
		//facet normal
		fputs("facet normal ", fp);
		s1 = malloc(100);
		s2 = malloc(100);
		s3 = malloc(100);
		float_to_scientific_notation(triangles[i].vnorm.i, s1);
		float_to_scientific_notation(triangles[i].vnorm.j, s2);
		float_to_scientific_notation(triangles[i].vnorm.k, s3);
		fprintf(fp, "%s %s %s\n\t", s1, s2, s3);
		free(s1);
		free(s2);
		free(s3);
		fputs("outer loop\n\t\t", fp);
		//vertices vx1
		fputs("vertex ", fp);
		s1 = malloc(100);
		s2 = malloc(100);
		s3 = malloc(100);
		float_to_scientific_notation(triangles[i].vx1.i, s1);
		float_to_scientific_notation(triangles[i].vx1.j, s2);
		float_to_scientific_notation(triangles[i].vx1.k, s3);
		fprintf(fp, "%s %s %s\n\t\t", s1, s2, s3);
		free(s1);
		free(s2);
		free(s3);
		//vertices vx2
		fputs("vertex ", fp);
		s1 = malloc(100);
		s2 = malloc(100);
		s3 = malloc(100);
		float_to_scientific_notation(triangles[i].vx2.i, s1);
		float_to_scientific_notation(triangles[i].vx2.j, s2);
		float_to_scientific_notation(triangles[i].vx2.k, s3);
		fprintf(fp, "%s %s %s\n\t\t", s1, s2, s3);
		free(s1);
		free(s2);
		free(s3);
		//vertices vx3
		fputs("vertex ", fp);
		s1 = malloc(100);
		s2 = malloc(100);
		s3 = malloc(100);
		float_to_scientific_notation(triangles[i].vx3.i, s1);
		float_to_scientific_notation(triangles[i].vx3.j, s2);
		float_to_scientific_notation(triangles[i].vx3.k, s3);
		fprintf(fp, "%s %s %s\n\t", s1, s2, s3);
		free(s1);
		free(s2);
		free(s3);
		fputs("endloop\n", fp);
		fputs("endfacet\n", fp);
	}
	fputs("endsolid cube", fp);
	return;
}

void float_to_scientific_notation(double d, char *s)
{
	int exp = 0;
	int sign;
	//printf("converting %.3f from float to scinot\n", d);
	if(d == 0.0) {
		sprintf(s, "%.3fe%d", d, exp);
		return;
	}
	if(d < 0.0) {
		sign = 1;
		d *= -1;
	}
	
	while(d >= 10.0) {
		//printf("%.3f\n", d);
		d /= 10.0;
		exp++;
	}
	while(d < 1.0) {
		//printf("%.3f\n", d);
		d *= 10.0;
		exp--;
	}
	
	if(sign)
		d *= -1;
	
	sprintf(s, "%.3fe%d", d, exp);
	return;
}