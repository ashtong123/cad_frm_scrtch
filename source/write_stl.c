#include "write_stl.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

void write_triangles_stl_ascii(triangle *triangles, int triangle_count)
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
		float_to_scientific_notation(triangles[i].vnorm.ijk[0], s1);
		float_to_scientific_notation(triangles[i].vnorm.ijk[1], s2);
		float_to_scientific_notation(triangles[i].vnorm.ijk[2], s3);
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
		float_to_scientific_notation(triangles[i].vx1.ijk[0], s1);
		float_to_scientific_notation(triangles[i].vx1.ijk[1], s2);
		float_to_scientific_notation(triangles[i].vx1.ijk[2], s3);
		fprintf(fp, "%s %s %s\n\t\t", s1, s2, s3);
		free(s1);
		free(s2);
		free(s3);
		//vertices vx2
		fputs("vertex ", fp);
		s1 = malloc(100);
		s2 = malloc(100);
		s3 = malloc(100);
		float_to_scientific_notation(triangles[i].vx2.ijk[0], s1);
		float_to_scientific_notation(triangles[i].vx2.ijk[1], s2);
		float_to_scientific_notation(triangles[i].vx2.ijk[2], s3);
		fprintf(fp, "%s %s %s\n\t\t", s1, s2, s3);
		free(s1);
		free(s2);
		free(s3);
		//vertices vx3
		fputs("vertex ", fp);
		s1 = malloc(100);
		s2 = malloc(100);
		s3 = malloc(100);
		float_to_scientific_notation(triangles[i].vx3.ijk[0], s1);
		float_to_scientific_notation(triangles[i].vx3.ijk[1], s2);
		float_to_scientific_notation(triangles[i].vx3.ijk[2], s3);
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

void write_triangles_stl_bin(triangle *triangles, uint32_t triangle_count)
{
	FILE *fp;
	fp = fopen(".\\models\\cube.stl", "w");
	//write header
	uint8_t *header = malloc(80);
	fwrite(header, sizeof(uint8_t), 80, fp);
	//write triangle count
	fwrite(&triangle_count, sizeof(uint32_t), 1, fp);
	uint16_t attr_byte_count = 0;

	for(int i = 0; i < triangle_count; ++i) {
		//write normal vector
		fwrite(&triangles[i].vnorm, sizeof(float), 3, fp);
		//write point 1
		fwrite(&triangles[i].vx1, sizeof(float), 3, fp);
		//write point 2
		fwrite(&triangles[i].vx2, sizeof(float), 3, fp);
		//write point 3
		fwrite(&triangles[i].vx3, sizeof(float), 3, fp);
		//write attribute byte count
		fwrite(&attr_byte_count, sizeof(uint16_t), 1, fp);
	}
	return;
}

void float_to_scientific_notation(float d, char *s)
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