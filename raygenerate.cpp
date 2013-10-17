#include <vector>
#include <linAlg.h>

vector<float> generate(vector<float> camPos, vector<float> lookAt) {
	vector<float> camDir = vSub(camPos, lookAt);
	
}