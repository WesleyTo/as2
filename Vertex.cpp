#include <vector>
#include "Vertex.h"
#include <iostream>

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
	
	std::vector<float> Vertex::sub(Vertex v) {
		std::vector<float> a(3);
		a[0] = x-v.getX();
		a[1] = y-v.getY();
		a[2] = z-v.getZ();
		return a;
	}
	
	std::vector<float> Vertex::toVec() {
		std::vector<float> n(3);
		n[0] = x;
		n[1] = y;
		n[2] = z;
		return n;
	}
	void Vertex::print() {
		std::cout<<"vtx ["<< x << ", " << y << ", " << z << "]\n";
	}

//Working
/*
int main() {
	Vertex::Vertex a = *new Vertex::Vertex(0,0,0);
	Vertex::Vertex b = *new Vertex::Vertex(1,0,0);
	Vertex::Vertex c = *new Vertex::Vertex(0,1,0);
	a.print();
	a = a.sub(b);
	a.print();
	std::vector<float> d = c.toVec();
	std::cout<<"vec ["<< d[0] << ", " << d[1] << ", " << d[2] << "]\n";
	Vertex::Vertex e = *new Vertex::Vertex(d);
	e.print();	
}
*/
