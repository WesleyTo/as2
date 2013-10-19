#include <vector>

class Ray;


class Ray {
	public:
		Ray();
		Ray(std::vector<float> e, std::vector<float> p);
		void setEye(std::vector<float> e);
		void setPoint(std::vector<float> p);
		void initCamDir();
		std::vector<float> getEye();
		std::vector<float>getPoint();
		std::vector<float> project(float t);
		std::vector<float> getDir();
		
	private:
		std::vector<float> eye;
		std::vector<float> point;
		std::vector<float> camDir;
}