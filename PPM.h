#include <sstream>
#include "Pixel.h"


class PPM {
	public:
		PPM(int, int, int);
		void addPixel(Pixel);
		void save(std::string);
		Pixel getPixel(int x, int y);
		int getWPos();
		int getHPos();
		int getPxCount();
		Pixel* pixels;
	private:
		std::string header;
		int height;
		int width;
		int wPos;
		int hPos;
};