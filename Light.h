#ifndef LIGHT_H
#define LIGHT_H

class Light {
        public:
			Light(float, float, float, float, float, float);
			//std::string toStr();
			float getX();
			float getY();
			float getZ();
			float getR();
			float getG();
			float getB();
        private:
			float x;
			float y;
			float z;
			float r;
			float g;
			float b;
};

#endif
