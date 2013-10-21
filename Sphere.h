#ifndef SPHERE_H
#define SPHERE_H

#include <vector>

class Sphere {
	public:
		Sphere(float, float, float, float);
		Sphere(float r, std::vector<float> p);
		float getRadius() const;
		std::vector<float> getPos() const;
		void setRadius(float r);
		void setPos(std::vector<float>);
		Shape::intersect intersect(Ray);
		std::vector<float> pointNormal(std::vector<float>);
	private:
		float radius;
		std::vector<float> position;
}

#endif