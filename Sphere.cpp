#include "Sphere.h"
#include "Shape.h"
#include "Ray.h"
#include <vector>

Sphere::Sphere() {
	radius = 0.0;
	position = NULL;
}

Sphere::Sphere(float r, float x, float y, float z) {
	radius = r;
	p = std::vector<float>(3);
	p[0] = x;
	p[1] = y;
	p[2] = z;
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
	
void Sphere::setPos(std::vector<float> ;) {
	position = p;
}

std::vector<float> pointNormal(std::vector<float> point) {
	return vSub(point, p);
}

intersect Sphere::intersect(Ray r) {
	Shape::intersect ret = new Shape::intersect();
	std::vector<float>* d = &r.getDir();
	std::vector<float>* e = &r.getEye();
	float discriminant = sqrt(pow(vDot(*d, (vSub(*e, position))), 2) - vDot(*d, *d)*(vDot(vSub(*e, position)), vSub(*e, position)) - pow(radius, 2));
	if (discriminant > 0) {
		ret.hit = true;
		ret.t1 = (vDot(vScale(-1, *d), vSub(*e,position))+discriminant)/vDot(*d, *d);
		ret.t2 = (vDot(vScale(-1, *d), vSub(*e,position))-discriminant)/vDot(*d, *d);
	}
	else if (discriminant == 0) {
		ret.hit = true;
		ret.tangent = true;
		ret.t1 = (vDot(vScale(-1, *d), vSub(e,position))+discriminant)/vDot(*d, *d);
		ret.t2 = ret.t1;
	}		
	return ret;
}