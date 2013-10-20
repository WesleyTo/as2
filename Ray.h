#ifndef RAY_H
#define RAY_H

#include <vector>

class Ray;


class Ray {
	public:
		Ray();
		Ray(std::vector<float> e, std::vector<float> p);
		void setEye(std::vector<float> e);
		void setPoint(std::vector<float> p);
		void initCamDir();
		std::vector<float> getEye() const;
		std::vector<float> getPoint() const;
		std::vector<float> project(float t);
		std::vector<float> getDir() const;
		
	private:
		std::vector<float> eye;
		std::vector<float> point;
		std::vector<float> camDir;
}

#endif