#include "Intersect.h"
#include <vector>

Intersect::Intersect() {
	hit = false;
	point = NULL;
}
void Intersect::setHit(bool h) {
	hit = h;
}

void Intersect::setPoint(std::vector<float> p) {
	point = p;
}

bool Intersect::isHit() const {
	return hit;
}

std::vector<float> Intersect::getPoint() const{
	return point;
}