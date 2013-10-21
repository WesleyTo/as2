#include <vector>
#include <iostream>
#include "Light.h"

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
