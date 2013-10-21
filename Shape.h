#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <iostream>



typedef struct
{
	float x;
	float y;
	float z;
	vertex(std::vector<float> v) {
		x = v.at(0);
		y = v.at(1);
		z = v.at(2);
	}
	vertex(float a, float b, float c) {
		x = a;
		y = b;
		z = c;
	}
	bool operator==(const vertex& lhs, const vertex& rhs){
		return (((*lhs).x==(*rhs).x)&&((*lhs).y==(*rhs).y)&&((*lhs).z==(*rhs).z));
	}

} vertex;

typedef struct 
{
	bool hit = false;
	std::vector<float> point = NULL;
} intersect;
#endif	