class Pixel


class Pixel {
	public:
		Pixel();
		Pixel(int, int, int);
		string toStr();
		pixel copy();
		void reset();
		void add(pixel);
	
	private:
		int r;
		int g;
		int b;
}