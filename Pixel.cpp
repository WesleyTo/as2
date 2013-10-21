#include <sstream>
#include <algorithm>
#include <iostream>
#include "Pixel.h"
#include <math.h>


Pixel::Pixel() {
	r = 0;
	g = 0;
	b = 0;
}

Pixel::Pixel(int x, int y, int z) {
	r = fmin(x, 255);
	g = fmin(y, 255);
	b = fmin(z, 255);
}

Pixel::Pixel(float x, float y, float z) {
	r = fmin(255, round(255*x));
	g = fmin(255, round(255*y));
	b = fmin(255, round(255*z));

}

std::string Pixel::toStr() {
	std::stringstream s;
	s<<r<<" "<<g<<" "<<b;
	return s.str();
}

Pixel Pixel::copy() {
	Pixel *p = new Pixel();
	p->setR(r);
	p->setG(g);
	p->setB(b);
	return *p;
}

void Pixel::reset() {
	r = 0;
	g = 0;
	b = 0;
}

void Pixel::add(Pixel p) {
	this->setR(r+p.getR());
	this->setG(g+p.getG());
	this->setB(b+p.getB());
}

int Pixel::getR() {
	return r;
}

int Pixel::getG() {
	return g;
}

int Pixel::getB() {
	return b;
}

void Pixel::setR(int red) {
	r = fmin(red, 255);
}

void Pixel::setG(int green) {
	g = fmin(green, 255);
}

void Pixel::setB(int blue) {
	b = fmin(blue, 255);
}

void Pixel::print() {
	std::cout<<"pix ["<<r<<", "<<g<<", "<<b<<"]\n";
}

int main() {
	Pixel::Pixel p = *new Pixel::Pixel(255, 255, 255);
	Pixel::Pixel black = *new Pixel::Pixel(0,0,0);
	Pixel::Pixel pfloat = *new Pixel::Pixel(1.0f, 0.9f, 0.05f);
	Pixel::Pixel pmax = *new Pixel::Pixel(2.0f, 1.0f, 0.5f);
	p.print();
	black.print();
	black.add(p);
	black.print();
	pfloat.print();
	pmax.print();

}