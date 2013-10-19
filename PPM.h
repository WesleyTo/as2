#include <sstream>
class PPM

typedef struct{
	int r;
	int g;
	int b;
	pixel() {
		r = 0;
		g = 0;
		b = 0;
	}
	pixel(int x, int y, int z) {
		r = x;
		g = y;
		b = z;
	}
	toStr() {
		std::stringstream s;
		s<<r<<" "<<g<<" "<<b;
		return s.str();
	}
} pixel;

class PPM {
	public:
		PPM(int height, int width, maxVal=255);
		void addPixel(pixel p);
		void save(string name);
		pixel getPixel(int x, int y);
	private:
		string header;
		int height;
		int width;
		int wPos;
		int hPos;
		pixel pixels[][];
}