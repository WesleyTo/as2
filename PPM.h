#ifndef PPM_H
#define PPM_H

#include <sstream>
#include <iostream>
#include <fstream>
#include "Pixel.h"

class PPM {
	public:
		PPM(int, int, int);
		void addPixel(Pixel);
		void save(std::string);
		Pixel getPixel(int x, int y);
		int getW() const;
		int getH() const;
		int getPxCount() const;
		Pixel* pixels;
	private:
		std::string header;
		int height;
		int width;
		int wPos;
		int hPos;
		int maxVal;
		int pixelCount;
};

#endif