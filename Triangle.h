#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Vertex.h"
#include "Intersect.h"
#include "Ray.h"

class Triangle {
	public:
		Triangle(Vertex::Vertex, Vertex::Vertex, Vertex::Vertex);
		Vertex getVertex(int) const;
		std::vector<float> getNormal() const;
		Intersect intersect(Ray);
	private:
		Vertex::Vertex v1;
		Vertex::Vertex v2;
		Vertex::Vertex v3;
		std::vector<float> normal;
};

#endif