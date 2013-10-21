#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <iostream>

class boundingBox{

	public:
		boundingBox();
		print();

	private:
		float minX;
		float maxX;
		float minY;
		float maxY;
		float minZ;
		float maxZ;

}
#endif