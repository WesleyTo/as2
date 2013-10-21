#include "Intersect.h"
#include <vector>
#include <iostream>

Intersect::Intersect() {
	hit = false;
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


// Working, tests commented out
/*
int main() {
	Intersect::Intersect i = *new Intersect::Intersect();
	if(i.isHit()) {
		std::cout<<"INCORRECT! hit is true.\n\n";
	}
	else {
		std::cout<<"CORRECT! hit is false.\n\n";
		i.setHit(true);
	}
	if(i.isHit()) {
		std::cout<<"CORRECT! hit is true.\n\n";
	}
	else {
		std::cout<<"INCORRECT! hit is false.\n\n";
	}
	std::vector<float> ptest(3);
	ptest[0] = 0;
	ptest[1] = 1;
	ptest[2] = 2;
	i.setPoint(ptest);
	std::vector<float> p = i.getPoint();
	std::cout<< "[" << p[0] << ", " << p[1] << ", " << p[2] << "]\n";
}
*/