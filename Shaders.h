#ifndef SHADERS_H
#define SHADERS_H
#include "Light.h"
#include "Pixel.h"
#include "Intersect.h"
#include "Sphere.h"
#include "Triangle.h"

class Shaders {

    public:
		Shaders();
		void addLight(Light);
		void addSphere(Sphere);
		void addTriangle(Triangle);
		Pixel pixelLight(float, float, float);
	    std::vector<float> ambient(std::vector<float>);
	    std::vector<float> diffuse(std::vector<float>, std::vector<float>, std::vector<float>, std::vector<float>);
		std::vector<float> specular(std::vector<float>, std::vector<float>, std::vector<float>, std::vector<float>, std::vector<float>);
		int hasShadow(float, float, float,  Light);
    private:
		std::vector<Light> lights;
		std::vector<Sphere> spheres;
		std::vector<Triangle> triangles;
		int numTriangles;
		int triangleSize;
		int numSpheres;
		int sphereSize;
		int lightSize;
		int numLights;
};

#endif
