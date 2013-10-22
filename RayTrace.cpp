#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <math.h>  
//#include "linAlg.h"
#include "Ray.h"
#include "PPM.h"
#include "Pixel.h"
#include <list>
#include "Sphere.h"
#include "Light.h"
#include <algorithm>
#include <math.h>
#include <fstream>
#include "Triangle.h"
#include "Vertex.h"
#include "Intersect.h"



Light::Light(float x1, float y1, float z1, float r1, float g1, float b1)
{
   x = x1;
   y = y1;
   z = z1;
   r = r1;
   g = g1;
   b = b1;
}

float Light::getX(){
  return x;
}

float Light::getY(){
  return y;
}

float Light::getZ(){
  return x;
}

float Light::getR(){
  return r;
}
float Light::getG(){
  return g;
}
float Light::getB(){
  return b;
}

void Light::print() {
	std::cout<<"lgt [" << x << ", " << y << ", " << z << ", " << r << ", " << g << ", " << b <<"]\n";

}




float vDot(std::vector<float> a, std::vector<float> b) {
	return a.at(0)*b.at(0) + a.at(1)*b.at(1) + a.at(1)*b.at(1);
}

std::vector<float> vSub(std::vector<float> a, std::vector<float> b) {
	std::vector<float> retVec(3);
	retVec[0] = a.at(0)-b.at(0);
	retVec[1] = a.at(1)-b.at(1);
	retVec[2] = a.at(2)-b.at(2);
	return retVec;
}

std::vector<float> vAdd(std::vector<float> a, std::vector<float> b) {
	std::vector<float> retVec(3);
	retVec[0] = a.at(0)+b.at(0);
	retVec[1] = a.at(1)+b.at(1);
	retVec[2] = a.at(2)+b.at(2);
	return retVec;
}

std::vector<float> vScale(float scalar, std::vector<float> a) {
	std::vector<float> retVec(3);
	retVec[0] = a.at(0)*scalar;
	retVec[1] = a.at(1)*scalar;
	retVec[2] = a.at(2)*scalar;
	return retVec;
}


// component-wise multiplication of a 3D vector
std::vector<float> vMult(std::vector<float> a, std::vector<float> b) {
	std::vector<float> retVec(3);
	retVec[0] = a.at(0)*b.at(0);
	retVec[1] = a.at(1)*b.at(1);
	retVec[2] = a.at(2)*b.at(2);
	return retVec;
}

std::vector<float> vCross(std::vector<float> a, std::vector<float> b) {
	std::vector<float> retVec(3);
	retVec[0] = a.at(1)*b.at(2)-a.at(2)*b.at(1);
	retVec[1] = a.at(2)*b.at(0)-a.at(0)*b.at(2);
	retVec[2] = a.at(0)*b.at(1)-a.at(1)*b.at(0);
	return retVec;
}

void vPrint(std::vector<float> a) {
	std::cout<<"vec ["<<a.at(0)<<", "<<a.at(1)<<", "<<a.at(2)<<"]\n";
}

float magnitude(std::vector<float> a) {
	return a.at(0)*a.at(0)+a.at(1)*a.at(1)+a.at(2)*a.at(2);
}

std::vector<float> normalize(std::vector<float> a) {
	std::vector<float> retVec(3);
	float mag = magnitude(a);
	retVec[0] = a.at(0)/mag;
	retVec[1] = a.at(1)/mag;
	retVec[2] = a.at(2)/mag;
	return retVec;
}



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


PPM::PPM(int h, int w, int m){
	height = h;
	width = w;
	maxVal = m;
	std::stringstream s;
	s<<"P3\n"<<width<<" "<<height<<"\n"<<maxVal<<"\n";
	header = s.str();			
	pixels = new Pixel::Pixel[height*width];
	pixelCount = 0;
}

int PPM::getPxCount() const{
	return wPos;
}

int PPM::getW() const {
	return width;
}

int PPM::getH() const {
	return height;
}

void PPM::addPixel(Pixel p){
	
	pixels[pixelCount] = p;
	pixelCount++;
}

Pixel PPM::getPixel(int x, int y) {
	return pixels[y+x*y];
}

void PPM::save(std::string name) {
	std::ofstream newFile;
	std::stringstream ss;
	ss<<name<<".ppm";
	newFile.open("test.ppm");
	newFile<<header;
	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			newFile<<" "<<pixels[(h*w)+w].toStr();
		}
		newFile<<"\n";
	}
	newFile.close();
}




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
	camDir[0] = point[0] - eye[0];
	camDir[1] = point[1] - eye[1];
	camDir[2] = point[2] - eye[2];
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
	std::vector<float> k(3);
	k[0] = t*camDir[0];
	k[1] = t*camDir[1];
	k[2] = t*camDir[2];
	std::vector<float> a(3);
	a[0] = eye[0] + k[0];
	a[1] = eye[1] + k[1];
	a[2] = eye[2] + k[2];
	return a;

}


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
	std::vector<float> s(3);
	s[0] = point[0] - position[0];
	s[1] = point[1] - position[1];
	s[2] = point[2] - position[2];
	return s;
}

Intersect Sphere::intersect(Ray r) {
	Intersect::Intersect ret = *new Intersect::Intersect();
	std::vector<float> d = r.getDir();
	std::vector<float> e = r.getEye();
	std::vector<float> eminusp(3);
	eminusp[0] = e[0] - position[0];
	eminusp[1] = e[1] - position[1];
	eminusp[2] = e[2] - position[2];
	float ddotd = d[0]*d[0]+d[1]*d[1]+d[2]*d[2];
	float empdot = eminusp[0]*eminusp[0] + eminusp[1]*eminusp[1] + eminusp[2]*eminusp[2];
	float ddoteminusp = d[0]*eminusp[0] + d[1]*eminusp[1] + d[2]*eminusp[2];
	float discriminant = sqrt(ddoteminusp * ddoteminusp - ddotd*(empdot - radius*radius));
	if (discriminant >= 0) {
		ret.setHit(true);
		float scalar = -1.0f;
		float * scale = &scalar;
		std::vector<float> scaled(3);
		scaled = vScale(-1, d);
		//scaled[0] = d[0]*(-1);
		//scaled[1] = d[1]*(-1);
		//scaled[2] = d[2]*(-1);
		float sdotemp = scaled[0]*eminusp[0] + scaled[1]*eminusp[1] + scaled[2]*eminusp[2];
		ret.setPoint(r.project((sdotemp+discriminant)/ddotd));
	}	
	return ret;
}




Triangle::Triangle(Vertex va, Vertex vb, Vertex vc) {
	Vertex::Vertex v1 = va;
	Vertex::Vertex v2 = vb;
	Vertex::Vertex v3 = vc;
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
	return v1;
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
	std::vector<float> p(3);
	std::vector<float> vec1 = v1.toVec();
	std::vector<float> vec2 = v2.toVec();
	std::vector<float> vec3 = v3.toVec();
	p[0] = vec1[0] + (vec2[0] - vec1[0])*beta + (vec3[0] - vec1[0])*gamma;
	p[1] = vec1[1] + (vec2[1] - vec1[1])*beta + (vec3[1] - vec1[1])*gamma;
	p[2] = vec1[2] + (vec2[2] - vec1[2])*beta + (vec3[2] - vec1[2])*gamma;
	ret.setPoint(vec1);
	
	return ret;
}


Vertex::Vertex() {
	x = 0;
	y = 0;
	z = 0;
}

Vertex::Vertex(std::vector<float> v) {
	x = v.at(0);
	y = v.at(1);
	z = v.at(2);
}
Vertex::Vertex(float a, float b, float c) {
	x = a;
	y = b;
	z = c;
}
bool Vertex::equals(Vertex::Vertex v){
	return (x==v.getX() && y==v.getY() && z==v.getZ());
}
float Vertex::getX() const{
	return x;
}

float Vertex::getY() const{
	return y;
}

float Vertex::getZ() const{
	return z;
}

std::vector<float> Vertex::sub(Vertex v) {
	std::vector<float> a(3);
	a[0] = x-v.getX();
	a[1] = y-v.getY();
	a[2] = z-v.getZ();
	return a;
}

std::vector<float> Vertex::toVec() {
	std::vector<float> n(3);
	n[0] = x;
	n[1] = y;
	n[2] = z;
	return n;
}
void Vertex::print() {
	std::cout<<"vtx ["<< x << ", " << y << ", " << z << "]\n";
}




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


int main() {
	Light::Light n = *new Light::Light(1, 1, 0, 0.5, 0.5, 0.5);
	n.print();
	
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
	
	Vertex::Vertex a = *new Vertex::Vertex(0,0,0);
	Vertex::Vertex b = *new Vertex::Vertex(1,0,0);
	Vertex::Vertex c = *new Vertex::Vertex(0,1,0);
	a.print();
	a = a.sub(b);
	a.print();
	std::vector<float> d = c.toVec();
	std::cout<<"vec ["<< d[0] << ", " << d[1] << ", " << d[2] << "]\n";
	Vertex::Vertex e1 = *new Vertex::Vertex(d);
	e1.print();	
	Vertex a1 = *new Vertex::Vertex(0,1,0);
	Vertex b1 = *new Vertex::Vertex(1,-1,0);
	Vertex c1 = *new Vertex::Vertex(-1,-1,0);
	Triangle t = *new Triangle::Triangle(a1,b1,c1);
	p[0] = 0;
	p[1] = 0;
	p[2] = 0;
	std::vector<float> e(3);
	e[0] = 0;
	e[1] = 0;
	e[2] = 3;

	Ray::Ray r = *new Ray::Ray(e, p);
	i = t.intersect(r);
	if (i.isHit()) {
		std::cout<<"Triangle Intersected - OKAY\n";	
	}
	Sphere::Sphere s = *new Sphere::Sphere(1, p);
	if (s.intersect(r).isHit()) {
		std::cout<<"Sphere Intersected - OKAY\n";	
	}

	
	e[0] = 0;
	e[1] = -4;
	e[2] = -4;
	p[0] = 1;
	p[1] = 1;
	p[2] = -1;
	r.setEye(e);
	r.setPoint(p);
	std::cout<<"projected ";
	vPrint(r.project(1.5));
	
	
	PPM* ppm = new PPM(640, 480, 255);
	int val;
	for (int h = 0; h< 480; h++) {
		for (int w =0; w<640; w++) {
			val = std::min(255, (int)255*(w/ppm->getW()));
			ppm->addPixel(*(new Pixel::Pixel(val, val, val)));
		}	
	}
	ppm->save("output");
	
	
	Pixel::Pixel px = *new Pixel::Pixel(255, 255, 255);
	Pixel::Pixel black = *new Pixel::Pixel(0,0,0);
	Pixel::Pixel pfloat = *new Pixel::Pixel(1.0f, 0.9f, 0.05f);
	Pixel::Pixel pmax = *new Pixel::Pixel(2.0f, 1.0f, 0.5f);
	px.print();
	black.print();
	black.add(px);
	black.print();
	pfloat.print();
	pmax.print();
	
	
	std::vector<float> test1(3);
	test1[0] = 1;
	test1[1] = 0;
	test1[2] = 0.5;
	std::vector<float> test2(3);
	test2[0] = 0;
	test2[1] = 1;
	test2[2] = 0.5;
	std::cout<<vDot(test1, test2)<<"\n";
	vPrint(vSub(test1, test2));
	vPrint(vAdd(test1, test2));
	vPrint(vMult(test1, test2));
	vPrint(normalize(test1));
	vPrint(normalize(test2));
	vPrint(vCross(test1, test2));
	vPrint(vScale(-1, test1));
	
	
	return 0;
}
