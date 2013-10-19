#include <sstream>
class PPM


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