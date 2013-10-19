#include <sstream>
#include <algorithm>

class Pixel {
	Pixel() {
		r = 0;
		g = 0;
		b = 0;
	}
	
	Pixel(int x, int y, int z) {
		r = x;
		g = y;
		b = z;
	}

	string toStr() {
		std::stringstream s;
		s<<r<<" "<<g<<" "<<b;
		return s.str();
	}
	
	pixel copy() {
		pixel p = new pixel();
		p.setR(r);
		p.setG(g);
		p.setB(b);
		return p;
	}
	
	void reset() {
		r = 0;
		g = 0;
		b = 0;
	}
	
	void add(pixel p) {
		self.setR(r+p.getR());
		self.setG(g+p.getG());
		self.setB(b+p.getB());
	}
	
	int getR() {
		return r;
	}
	
	int getG() {
		return g;
	}
	
	int getB() {
		return b;
	}
	
	void setR(int red) {
		r = min(red, 255);
	}
	
	void setG(int green) {
		g = min(green, 255);
	}
	
	void setB(int blue) {
		b = min(blue, 255);
	}
	
}