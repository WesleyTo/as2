#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <iostream>

class boundingBox{

	public:
		boundingBox();
		void print();
		void setMinX() const;
		void setMaxX() const;
		void setMinY() const;
		void setMaxY() const;
		void setMinZ() const;
		void setMaxZ() const;
		float getMinX(float);
		float getMaxX(float);
		float getMinY(float);
		float getMaxY(float);
		float getMinZ(float);
		float getMaxZ(float);
		//bool intersect(Ray);
		
	private:
		float minX;
		float maxX;
		float minY;
		float maxY;
		float minZ;
		float maxZ;

}
#endif