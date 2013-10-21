#include "boundingBox.h"
#include <iostream>

boundingBox::boundingBox() {
	minX = 0;
	maxX = 0;
	minY = 0;
	maxY = 0;
	minZ = 0;
	maxZ = 0;
}
void boundingBox::print() {
	cout<<"box ["<< minX << ", " << maxX << ", " << minY << ", " << maxY << ", " << minZ << ", " << maxZ << "]\n";
}