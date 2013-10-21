#include <vector>
#include "Ray.h"


Ray::Ray() {}

Ray::Ray(std::vector<float> e, std::vector<float> p) {
	eye = e;
	point = p;
	camDir = vSub(&p, &e);
}

void Ray::setEye(std::vector<float> e){
	eye = e;
}

void Ray::setPoint(std::vector<float> p) {
	point = p;
}

void Ray::initCamDir() {
	camDir = vSub(&point, &eye);
}

std::vector<float> Ray::getEye() {
	return eye;
}

std::vector<float> Ray::getPoint() {
	return point;
}

std::vector<float> Ray::getDir(){
	return camDir;
}

std::vector<float> Ray::project(float t) {
	std::vector<float> k = vScale(&t, &camDir);
	return vAdd(&eye, &k);

}

int main() {
	std::vector<float> e(3);
	e[0] = 0;
	e[1] = -4;
	e[2] = -4;
	std::vector<float> p(3);
	p[0] = 1;
	p[1] = 1;
	p[2] = -1;
	Ray::Ray r = Ray::Ray(e, p);
	r.project(1.5);
}