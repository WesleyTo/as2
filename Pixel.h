#ifndef PIXEL_H
#define PIXEL_H


class Pixel {
	public:
		Pixel();
		Pixel(int, int, int);
		std::string toStr();
		Pixel copy();
		void reset();
		void add(Pixel);
		int getR();
		int getG();
		int getB();
		void setR(int);
		void setG(int);
		void setB(int);
		void print();
	
	private:
		int r;
		int g;
		int b;
};

#endif