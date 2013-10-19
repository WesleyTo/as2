class Pixel;


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
	
	private:
		int r;
		int g;
		int b;
};