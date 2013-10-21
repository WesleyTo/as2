#include <vector>
#include "Vertex.h"

	Vertex::Vertex(std::vector<float> v) {
		x = v.at(0);
		y = v.at(1);
		z = v.at(2);
	}
	Vertex::Vertex(float a, float b, float c) {
		x = a;
		y = b;
		z = c;
	}
	bool Vertex::equals(Vertex::Vertex v){
		return (x==v.getX() && y==v.getY() && z==v.getZ());
	}
	float Vertex::getX() const{
		return x;
	}
	
	float Vertex::getY() const{
		return y;
	}
	
	float Vertex::getZ() const{
		return z;
	}

} vertex;