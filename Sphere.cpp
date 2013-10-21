#include "Sphere.h"
#include "Intersect.h"
#include "Ray.h"
#include <vector>
#include <iostream>
#include <math.h>

Sphere::Sphere(float r, float x, float y, float z) {
	radius = r;
	position = std::vector<float>(3);
	position[0] = x;
	position[1] = y;
	position[2] = z;
}

Sphere::Sphere(float r, std::vector<float> p) {
	radius = r;
	position = p;
}

float Sphere::getRadius() const{
	return radius;
}

std::vector<float> Sphere::getPos() const{
	return position;
}

void Sphere::resize(float r) {
	radius = r;
}
	
void Sphere::setPos(std::vector<float> p) {
	position = p;
}

std::vector<float> Sphere::pointNormal(std::vector<float> point) {
	return vSub(&point, &position);
}

Intersect::Intersect Sphere::intersect(Ray r) {
	Intersect::Intersect ret = *new Intersect::Intersect();
	std::vector<float> d = r.getDir();
	std::vector<float> e = r.getEye();
	std::vector<float> eminusp = vSub(&e, &position);
	float ddotd = *vDot(&d, &d);
	float discriminant = sqrt(*vDot(&d, &eminusp)**vDot(&d, &eminusp) - ddotd*(*vDot(&eminusp, &eminusp) - radius*radius));
	if (discriminant >= 0) {
		ret.setHit(true);
		float scalar = -1.0f;
		float * scale = &scalar;
		std::vector<float> scaled = vScale(scale, &d);
		ret.setPoint(r.project((*vDot(&scaled, &eminusp)+discriminant)/ddotd));
	}	
	return ret;
}


int main() {

std::vector<float> p(3);
	p[0] = 0;
	p[1] = 0;
	p[2] = 0;
	std::vector<float> e(3);
	e[0] = 0;
	e[1] = 0;
	e[2] = 3;
	Sphere::Sphere s = *new Sphere::Sphere(1, p);
	Ray::Ray r = *new Ray::Ray(e, p);
	if (s.intersect(r).getHit()) {
		std::cout<<"OKAY\n";	
	}
}