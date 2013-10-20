#include <vector>
#include "Ray.h"
#include "linAlg.h"

Ray::Ray() {}

Ray::Ray(std::vector<float> e, std::vector<float> p) {
	eye = e;
	point = p;
	camDir = vSub(p, e);
}

void Ray::setEye(std::vector<float> e){
	eye = e;
}

void Ray::setPoint(std::vector<float> p) {
	point = p;
}

void Ray::initCamDir() {
	camDir = vSub(p, e);
}

std::vector<float> Ray::getEye() const {
	return eye;
}

std::vector<float> Ray::getPoint() const {
	return point;
}

std::vector<float> Ray::getDir() const{
	return camDir;
}

std::vector<float> Ray::project(float t) {
	return vAdd(e, scale(t, camDir));

}