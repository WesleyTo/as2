#include "Triangle.h"
#include "Ray.h"
#include "Intersect.h"
#include <iostream>
#include "Vertex.h"

Triangle::Triangle(Vertex::Vertex va, Vertex::Vertex vb, Vertex::Vertex vc) {
	v1 = va;
	v2 = vb;
	v3 = vc;
	std::vector<float> normal(3);
	normal[0] = (v1.getY()*v2.getZ() - v1.getZ()*v2.getY());
	normal[1] = (v1.getX()*v2.getZ() - v1.getZ()*v2.getX());
	normal[2] = (v1.getX()*v2.getY() - v1.getY()*v2.getX());
}

Vertex Triangle::getVertex(int n) const{
	if (n == 0) {
		return v1;
	}
	else if (n == 1) {
		return v2;
	}
	else if (n == 2){
		return v3;
	}
}

std::vector<float> Triangle::getNormal() const {
	return normal;
}
		
Intersect Triangle::intersect(Ray r) {
	Intersect::Intersect ret = *new Intersect::Intersect();
	float a = v1.getX() - v2.getX();
	float b = v1.getY() - v2.getY();
	float c = v1.getZ() - v2.getZ();
	float d = v1.getX() - v3.getX();
	float e = v1.getY() - v3.getY();
	float f = v1.getZ() - v3.getZ();
	float g = r.getDir().at(0);
	float h = r.getDir().at(1);
	float i = r.getDir().at(2);
	float j = v1.getX() - r.getEye().at(0);
	float k = v1.getY() - r.getEye().at(1);
	float l = v1.getZ() - r.getEye().at(2);
	float eiminushf = e*i - h*f;
	float gfminusdi = g*f - d*i;
	float dhminuseg = d*h - e*g;
	float akminusjb = a*k - j*b;
	float jcminusal = j*c - a*l;
	float blminuskc = b*l - k*c;
	float m = a*(eiminushf) + b*(gfminusdi) + c*(dhminuseg);
	float beta = (j*(eiminushf) + k*(gfminusdi) + l*(dhminuseg))/m;
	if (beta < 0) {return ret;}
	float gamma = (i*(akminusjb) + h*(jcminusal) + g*(blminuskc))/m;
	if (gamma < 0 || beta+gamma > 1) {return ret;}
	float t = (-1)*(f*(akminusjb) + e*(jcminusal) + d*(blminuskc))/m;
	std::vector<float> p;
	
	std::vector<float> vec1 = v1.toVec();
	std::vector<float> vec2 = v2.toVec();
	std::vector<float> vec3 = v3.toVec();
	std::vector<float> sub1 = vSub(&vec2, &vec1);
	std::vector<float> sub2 = vSub(&vec3, &vec1);
	std::vector<float> scaled1 = vScale(&beta, &sub1);
	std::vector<float> scaled2 = vScale(&gamma, &sub2);
	std::vector<float> added1 = vAdd(&vec1, &scaled1);
	p = vAdd(&added1, &scaled2);
	
	ret.setPoint(p);
	
	return ret;
}


int main() {
	Vertex a = *new Vertex::Vertex(0,0,0);
	Vertex b = *new Vertex::Vertex(1,0,0);
	Vertex c = *new Vertex::Vertex(0,1,0);
	Triangle t = *new Triangle::Triangle(a, b, c);
	std::vector<float> p(3);
	p[0] = 0;
	p[1] = 0;
	p[2] = 0;
	std::vector<float> e(3);
	e[0] = 0;
	e[1] = 0;
	e[2] = 3;
	Ray::Ray r = *new Ray::Ray(e, p);
	Intersect i = t.intersect(r);
	if (i.isHit()) {
		std::cout<<"OKAY\n";	
	}
	return 0;
}