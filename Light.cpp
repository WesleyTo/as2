#include "Light.h"
#include <iostream>

Light::Light(int t, float x1, float y1, float z1, float r1, float g1, float b1)
{	type = t;   x = x1;
   y = y1;
   z = z1;
   r = r1;
   g = g1;
   b = b1;
}
int Light::getType(){
  return type;}

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

//Working
/*
int main() {
	Light::Light n = *new Light::Light(1, 1, 0, 0.5, 0.5, 0.5);
	n.print();
}
*/
