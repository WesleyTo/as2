#include "Shape.h"

class Triangle {
	public:
		Triangle(Shape::vertex, Shape::vertex, Shape::vertex);
		Shape::vertex getVertex(int) const;
		std::vector<float> getNormal() const;
		Shape::boundingBox getBounds() const;

	private:
		Shape::vertex v1;
		Shape::vertex v2;
		Shape::vertex v3;
		std::vector<float> normal;
		Shape::boundingBox bounds;
}