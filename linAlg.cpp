#include <vector>
#include <iostream>
#include "linAlg.h"


float vDot(std::vector<float> a, std::vector<float> b) {
	return a.at(0)*b.at(0) + a.at(1)*b.at(1) + a.at(1)*b.at(1);
}

std::vector<float> vSub(std::vector<float> a, std::vector<float> b) {
	std::vector<float> retVec(3);
	retVec[0] = a.at(0)-b.at(0);
	retVec[1] = a.at(1)-b.at(1);
	retVec[2] = a.at(2)-b.at(2);
	return retVec;
}

std::vector<float> vAdd(std::vector<float> a, std::vector<float> b) {
	std::vector<float> retVec(3);
	retVec[0] = a.at(0)+b.at(0);
	retVec[1] = a.at(1)+b.at(1);
	retVec[2] = a.at(2)+b.at(2);
	return retVec;
}

std::vector<float> vScale(float scalar, std::vector<float> a) {
	std::vector<float> retVec(3);
	retVec[0] = a.at(0)*scalar;
	retVec[1] = a.at(1)*scalar;
	retVec[2] = a.at(2)*scalar;
	return retVec;
}


// component-wise multiplication of a 3D vector
std::vector<float> vMult(std::vector<float> a, std::vector<float> b) {
	std::vector<float> retVec(3);
	retVec[0] = a.at(0)*b.at(0);
	retVec[1] = a.at(1)*b.at(1);
	retVec[2] = a.at(2)*b.at(2);
	return retVec;
}

std::vector<float> vCross(std::vector<float> a, std::vector<float> b) {
	std::vector<float> retVec(3);
	retVec[0] = a.at(1)*b.at(2)-a.at(2)*b.at(1);
	retVec[1] = a.at(2)*b.at(0)-a.at(0)*b.at(2);
	retVec[2] = a.at(0)*b.at(1)-a.at(1)*b.at(0);
	return retVec;
}

void vPrint(std::vector<float> a) {
	std::cout<<"vec ["<<a.at(0)<<", "<<a.at(1)<<", "<<a.at(2)<<"]\n";
}

float magnitude(std::vector<float> a) {
	return a.at(0)*a.at(0)+a.at(1)*a.at(1)+a.at(2)*a.at(2);
}

std::vector<float> normalize(std::vector<float> a) {
	std::vector<float> retVec(3);
	float mag = magnitude(a);
	retVec[0] = a.at(0)/mag;
	retVec[1] = a.at(1)/mag;
	retVec[2] = a.at(2)/mag;
	return retVec;
}



int main(int argc, char* argv[]) {
	std::vector<float> test1(3);
	test1[0] = 1;
	test1[1] = 0;
	test1[2] = 0.5;
	std::vector<float> test2(3);
	test2[0] = 0;
	test2[1] = 1;
	test2[2] = 0.5;
	std::cout<<vDot(test1, test2)<<"\n";
	vPrint(vSub(test1, test2));
	vPrint(vAdd(test1, test2));
	vPrint(vMult(test1, test2));
	vPrint(normalize(test1));
	vPrint(normalize(test2));
	vPrint(vCross(test1, test2));
	vPrint(vScale(-1, test1));
}