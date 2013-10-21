#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

class Vertex {
	public:
		Vertex();
		Vertex(std::vector<float>);
		Vertex(float, float, float);
		bool equals(Vertex);
		std::vector<float> sub(Vertex);
		float getX() const;
		float getY() const;
		float getZ() const;		
		std::vector<float> toVec();		
	private:
		float x;
		float y;
		float z;
};
#endif