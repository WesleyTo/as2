#ifndef LIGHT_H
#define LIGHT_H

class Light {
        public:
			Light(int, float, float, float, float, float, float);
			//std::string toStr();
			int getType();			
			float getX();
			float getY();
			float getZ();
			float getR();
			float getG();
			float getB();
			void print();
        private:
	  int type;		float x;
			float y;
			float z;
			float r;
			float g;
			float b;
};

#endif
