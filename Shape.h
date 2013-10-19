#include <vector>
#include "Ray.h"

class Sphere;
class Polygon;

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
		x = v[0];
		y = v[1];
		z = v[2];
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
	bool tangent = false;
	std::vector<float> t1 = NULL;
	std::vector<float> t2 = NULL;
} intersect;


class Sphere {
	public:
		Sphere(float r, std::vector<float> p);
		float getRadius();
		std::vector<float> getPos();
		void setRadius(float r);
		void setPos(std::vector<float>);
		intersect intersect(Ray);
	private:
		float radius;
		std::vector<float> position;
}

class Polygon {
	public:
		Polygon(int size);
		boundingBox getBounds();
		void addVertex(vertex);
		void replaceVertex(vertex, vertex);
		int size();
		void resize(int n);
		void setBounds(vertex);
		void resetBounds();
		intersect intersect(Ray);
	private:
		int size;
		boundingBox bounds;
		vertex vertices[];
		int vertexCount;
}
	