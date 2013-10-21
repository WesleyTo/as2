#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

class Vertex {
	public:
		Vertex();
		Vertex(std::vector<float>);
		Vertex(float, float, float);
		equals(Vertex);
		float getX() const;
		float getY() const;
		float getZ() const;				
	private:
		float x;
		float y;
		float z;
}
#endif