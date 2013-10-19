#include "PPM.h"
#include <sstream>
#include <iostream>
#include <fstream>

class PPM{
		PPM:PPM(int h, int w, int m){
			height = h;
			width = w;
			maxVal = m;
			std::stringstream s;
			s<<"P3\n"<<width<<" "<<height<<"\n"<<maxVal<<"\n";
			header = s.str();			
			pixels = new Pixel[height*width];
			pixelCount = 0;
		}
		
		int getPxCount() {
			return wPos;
		}
		
		int getW() const {
			return width;
		}
		
		int getH() const {
			return height;
		}
		
		void addPixel(Pixel p){
			
			pixels[pixelCount] = p;
			pixelCount++;
		}
		
		pixel getPixel(int x, int y) {
			return pixels[x][y];
		}
		
		void save(std::string name) {
			ofstream newFile;
			newFile.open(name+".ppm");
			newFile<<header;
			for (int h = 0; h < height; h++) {
				for (int w = 0; w < width; w++) {
					newFile<<" "<<pixels[(h*w)+w].toStr();
				}
				newFile<<"\n";
			}
			newFile.close()
		}
};
		
		
int main() {
	PPM p = new PPM(640, 480, 255);
	int val;
	for (int h = 0; h< 480; h++) {
		for (int w =0; w<640; w++) {
			val = std::min(255, (int)w/2);
			p.addPixel(new Pixel(val, val, val));
		}	
	}
	p.save("output.ppm");

}