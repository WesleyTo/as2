#include <vector>
#include "ray.h"
#include "linAlg.h"

Ray::Ray() {}

Ray::Ray(std::vector<float> e, std::vector<float> p) {
	eye = e;
	point = p;
	camDir = vSub(p, e);
}

void setEye(std::vector<float> e){
	eye = e;
}

void setPoint(std::vector<float> p) {
	point = p;
}

void initCamDir() {
	camDir = vSub(p, e);
}

std::vector<float> getEye() {
	return eye;
}

std::vector<float>getPoint() {
	return point;
}

std::vector<float> getDir() {
	return camDir;
}

std::vector<float> project(float t) {
	return vAdd(e, scale(t, camDir));

}