#ifndef SPHERE_H
#define SPHERE_H

#include <vector>
#include "Ray.h"
#include "Intersect.h"

class Sphere {
	public:
		Sphere(float, float, float, float);
		Sphere(float r, std::vector<float> p);
		float getRadius() const;
		std::vector<float> getPos() const;
		void setRadius(float r);
		void setPos(std::vector<float>);
		void resize(float);
		Intersect::Intersect intersect(Ray);
		std::vector<float> pointNormal(std::vector<float>);
	private:
		float radius;
		std::vector<float> position;
};

#endif