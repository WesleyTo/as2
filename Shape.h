#ifndef SHAPE_H
#define SHAPE_H
#include <vector>

typedef struct
{
  float minX;
  float maxX;
  float minY;
  float maxY;
  float minZ;
  float maxZ;
  boundingBox() {
    minX = 0;
	maxX = 0;
	minY = 0;
	maxY = 0;
	minZ = 0;
	maxZ = 0;
  }
} boundingBox;

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