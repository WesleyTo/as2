#include <sstream>
#include <algorithm>
#include <iostream>
#include "Pixel.h"
#include "Shaders.h"
#include "Light.h"
#include "linAlg.h"


Shaders::Shaders() {
  numLights = 0;
  std::vector<Light> l(10);
  lightSize = 10;
  lights = l;
  //also need list of Polygons
}

void Shaders::addLight(Light l){
  lights[numLights] = l;
  numLights = numLights + 1;
  if(numLights == lightSize - 1){
    lights.resize(lightSize * 2);
    lightSize = lightSize * 2;
  }
}

Pixel Shaders::pixelLight(int x, int y){
  std::vector<float> color(3);
  for (int i = 0; i < numLights; i++){
    std::Light l = lights[i];
    if(this.hasShadow(x, y, l) == 0){ //if light isn't blocked by another object

      if(l.getType() == 0) { //directional Light
	std::vector<float> lightDir(3);
	lightDir[0] = l.getX();
	lightDir[1] = l.getY();
	lightDir[2] = l.getZ();
	std::vector<float> lightColor(3);
	lightColor[0] = l.getR();
	lightColor[1] = l.getG();
	lightColor[2] = l.getB();      
	
	std::float<vector> amb = this.ambient(lightColor);
	color = vAdd(color, amb);
	
	std::vector<float> diff = this.diffuse(surfaceDir, center, scale(-1,lightDir), lightColor);
	color = vAdd(color, diff);
	
	
	std::vector<float> spec = this.specular(surfaceDir, center, viewer, lightDir, lightColor);
	color = vAdd(color, spec);
      }
      else { //point light
	std::vector<float> lightPos(3);
	lightPos[0] = l.getX();
	lightPos[1] = l.getY();
	lightPos[2] = l.getZ();
	std::vector<float> lightColor(3);
	lightColor[0] = l.getR();
	lightColor[1] = l.getG();
	lightColor[2] = l.getB();      
	std::vector<float> lightDir = vSub(surfaceDir, lightPos);
	
	std::vector<float> a = ambient(lightColor);
	color = vAdd(color, a);
	
	std::vector<float> diff = diffuse(surfaceDir, center, lightDir, lightColor);
	color = vAdd(color, diff);
        
	std::vector<float> spec = specular(surfaceDir, center, viewer, scale(-1,lightDir), lightColor);
	color = vAdd(color, spec);		      
      }
    }
  }
  Pixel pixelColor = new Pixel(color[0], color[1], color[2]);
  return pixelColor;
}


std::vector<float> Shaders::ambient(std::vector<float> lightColor[]){
  return vMult(ka, lightColor);
}

std::vector<float> Shaders::diffuse(std::vector<float> surfaceDir, std::vector<float> center, std::vector<float> lightDir, std::vector<float> lightColor){ 

  std::vector<float> n = normalize(surfaceDir);
  std::vector<float> l = normalize(scale((-1),lightDir));
  float lambert = vDot(n, l);
  // no max function in Ubuntu environment
  if (lambert < 0) {lambert = 0.0;}
  std::vector<float>diff = vMult(kd, lightColor);
  std::vector<float> m(3);
  m[0] = lambert*diff.at(0);
  m[1] = lambert*diff.at(1);
  m[2] = lambert*diff.at(2);

  return m;
}

std::vector<float> Shaders::specular(std::vector<float> surfaceDir, std::vector<float> center, std::vector<float> viewer, std::vector<float> lightDir, std::vector<float> lightColor) {
  std::vector<float> n = normalize(surfaceDir);
  std::vector<float> l = normalize(scale(-1,lightDir));
  //float* r = new float[3]; n and l were initialized like this, but I shortened them
  std::vector<float> r = vSub(scale(2*(vDot(n, l)), n), l);
  std::float rv = vDot(normalize(r), normalize(viewer));

  // no max function in Ubuntu environment
  if (rv < 0) {rv = 0.0;}
  rv = pow(rv, sp);
  
  std::vector<float> spec = vMult(ks, lightColor);
  
  std::vector<float> m(3);
  m[0] = rv*spec[0];
  m[1] = rv*spec[1];
  m[2] = rv*spec[2];
  
  return m;
}

int Shaders::hasShadow(int x, int y, Light l){
  return 1;//1 means blocked, 0 means not blocked
  /*
We need to cycle through the polygons and check if the ray between x and y and
the light intersects one of the polygons. if so return 1 if not return 0
   */
}


 
