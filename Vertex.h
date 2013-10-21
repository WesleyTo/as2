#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

class Vertex {
	public:
		Vertex();
		Vertex(std::vector<float>);
		Vertex(float, float, float);
		operator==(const vertex*, const vertex*);
	private:
		float x;
		float y;
		float z;
}
#endif