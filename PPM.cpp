#include "PPM.h"
#include <sstream>
#include <iostream>
#include <fstream>


using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}

class PPM {
		PPM(int h, int w, int m=255){
			height = h;
			width = w;
			maxVal = m;
			std::stringstream s;
			s<<"P3\n"<<width<<" "<<height<<"\n"<<maxVal<<"\n";
			header = s.str();
			pixel pixels[][] = new pixel[height][width];
			wPos = 0;
			hPos = 0;
		}
		
		void addPixel(pixel p){
			pixels[hPos][wPos] = p;
			wPos++;
			if (wPos == width) {
				wPos = 0;
				hPos++;
			}
		}
		
		pixel getPixel(int x, int y) {
			return pixels[x][y];
		}
		
		void save(string name) {
			ofstream newFile;
			newFile.open(name+".ppm");
			newFile<<header;
			for (int h = 0; h < height; h++) {
				for (int w = 0; w < width; w++) {
					newFile<<" "<<pixels[h][w].toStr();
				}
				newFile<<"\n";
			}
			newFile.close()
		}
}