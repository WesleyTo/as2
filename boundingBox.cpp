#include "boundingBox.h"
#include <iostream>
#include "Ray.h"

boundingBox::boundingBox() {
	minX = 0;
	maxX = 0;
	minY = 0;
	maxY = 0;
	minZ = 0;
	maxZ = 0;
}

boundingBox::getMinX() const {return minX;}
boundingBox::getMaxX() const {return maxX;}
boundingBox::getMinY() const {return minY;}
boundingBox::getMaxY() const {return maxY;}
boundingBox::getMinZ() const {return minZ;}
boundingBox::getMaxZ() const {return maxZ;}
boundingBox::setMinX(float n) {minX = n;}
boundingBox::setMaxX(float n) {maxX = n;}
boundingBox::setMinY(float n) {minY = n;}
boundingBox::setMaxY(float n) {maxY = n;}
boundingBox::setMinZ(float n) {minZ = n;}
boundingBox::setMaxZ(float n) {maxZ = n;}

/*bool boundingBox::intersect(Ray) {
	return false;
}*/

void boundingBox::print() {
	cout<<"box ["<< minX << ", " << maxX << ", " << minY << ", " << maxY << ", " << minZ << ", " << maxZ << "]\n";
}