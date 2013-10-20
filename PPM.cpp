#include "PPM.h"
#include <sstream>
#include <iostream>
#include <fstream>

PPM::PPM(int h, int w, int m){
	height = h;
	width = w;
	maxVal = m;
	std::stringstream s;
	s<<"P3\n"<<width<<" "<<height<<"\n"<<maxVal<<"\n";
	header = s.str();			
	pixels = new Pixel[height*width];
	pixelCount = 0;
}

int PPM::getPxCount() const{
	return wPos;
}

int PPM::getW() const {
	return width;
}

int PPM::getH() const {
	return height;
}

void PPM::addPixel(Pixel p){
	
	pixels[pixelCount] = p;
	pixelCount++;
}

Pixel PPM::getPixel(int x, int y) {
	return pixels[y+x*y];
}

void PPM::save(std::string name) {
	std::ofstream newFile;
	std::stringstream ss;
	ss<<name<<".ppm";
	newFile.open("test.ppm");
	newFile<<header;
	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			newFile<<" "<<pixels[(h*w)+w].toStr();
		}
		newFile<<"\n";
	}
	newFile.close();
}
		
		
int main() {
	PPM* p = new PPM(640, 480, 255);
	int val;
	for (int h = 0; h< 480; h++) {
		for (int w =0; w<640; w++) {
			val = std::min(255, (int)255*(w/(*p).getW()));
			(*p).addPixel(*(new Pixel::Pixel(val, val, val)));
		}	
	}
	(*p).save("output.ppm");

}