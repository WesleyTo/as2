#ifndef INTERSECT_H
#define INTERSECT_H
#include <vector>

class Intersect{
	private:
		void setHit(bool);
		void setPoint(std::vector<float>);
		bool isHit() const;
		std::vector<float> getPoint() const;
	public:
		bool hit;
		std::vector<float> point;
}

#endif