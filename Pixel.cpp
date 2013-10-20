#include <sstream>
#include <algorithm>
#include <iostream>
#include "Pixel.h"


Pixel::Pixel() {
	r = 0;
	g = 0;
	b = 0;
}

Pixel::Pixel(int x, int y, int z) {
	r = x;
	g = y;
	b = z;
}

std::string Pixel::toStr() {
	std::stringstream s;
	s<<r<<" "<<g<<" "<<b;
	return s.str();
}

Pixel Pixel::copy() {
	Pixel *p = new Pixel();
	(*p).setR(r);
	(*p).setG(g);
	(*p).setB(b);
	return *p;
}

void Pixel::reset() {
	r = 0;
	g = 0;
	b = 0;
}

void Pixel::add(Pixel p) {
	(*this).setR(r+p.getR());
	(*this).setG(g+p.getG());
	(*this).setB(b+p.getB());
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
	r = std::min(red, 255);
}

void Pixel::setG(int green) {
	g = std::min(green, 255);
}

void Pixel::setB(int blue) {
	b = std::min(blue, 255);
}

void Pixel::print() {
	std::cout<<"pix ["<<r<<", "<<g<<", "<<b<<"]\n";
}

int main() {
	Pixel::Pixel *p = new Pixel::Pixel(255, 255, 255);
	Pixel::Pixel *black = new Pixel::Pixel(0,0,0);
	(*p).print();
	(*black).print();
	(*black).add((*p));
	(*black).print();

}