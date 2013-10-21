
#ifndef SHADERS_H
#define SHADERS_H
#include "Light.h"
#include "Pixel.h"

class Shaders {

    public:
         Shaders();
	 void addLight(Light);
	 Pixel pixelLight(int, int);
	 Pixel ambient(std::vector<float>);
	 Pixel diffuse(std::vector<float>, std::vector<float>, std::vector<float>, std::vector<float>);
	 Pixel specular(std::vector<float>, std::vector<float>, std::vector<float>, std::vector<float>, std::vector<float>);
	 int hasShadow(int, int, Light);
    private:
	 vector<Light> lights;
	 int lightSize;
	 int numLights;
	 //we also need a vector<Polygon> of all the shapes in the scene
};

#endif
