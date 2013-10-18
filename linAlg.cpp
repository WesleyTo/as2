#include <vector>
#include <iostream>


float vDot(vector<float> a, vector<float> b) {
	return a.at(0)*b.at(0) + a.at(1)*b.at(1) + a.at(1)*b.at(1);
}

vector<float> vSub(vector<float> a, vector<float> b) {
	vector<float> retVec(3);
	float vals[] = {a.at(0)-b.at(0), a.at(1)-b.at(0), a.at(2)-b.at(2)};
	retVec.assign(vals, vals+3);
	free(vals);
	return retVec;
}

vector<float> vAdd(vector<float> a, vector<float> b) {
	vector<float> retVec(3);
	float vals[] = {a.at(0)+b.at(0), a.at(1)+b.at(0), a.at(2)+b.at(2)};
	retVec.assign(vals, vals+3);
	free(vals);
	return retVec;
}

vector<float> vScale(float scalar, vector<float> a) {
	vector<float> retVec(3);
	float vals[] = {a.at(0)*scalar, a.at(1)*scalar, a.at(2)*scalar};
	retVec.assign(vals, vals+3);
	free(vals);
	return retVec;
}


// component-wise multiplication of a 3D vector
vector<float> vMult(vector<float> a, vector<float> b) {
	vector<float> retVec(3);
	float vals[] = {a.at(0)*b.at(0), a.at(1)*b.at(0), a.at(2)*b.at(2)};
	retVec.assign(vals, vals+3);
	free(vals);
	return retVec;
}

vector<float> vCross(vector<float> a, vector<float> b) {
	vector<float> retVec(3);
	float vals[] = {a.at(1)*b.at(2)-a.at(2)*b.at(1), a.at(2)*b.at(0)-a.at(0)*b.at(2), a.at(0)*b.at(1)-a.at(1)*b.at(0)};
	retVec.assign(vals, vals+3);
	free(vals);
	return retVec;
}

void vPrint(vector<float> a) {
	cout<<"[ "<<a.at(0)<<" "<<a.at(1)<<" "<<a.at(2)<<" ]";
}

float magnitude(vector<float> a) {
	return a.at(0)*a.at(0)+a.at(1)*a.at(1)+a.at(2)*a.at(2);
}

vector<float> normalize(vector<float> a) {
	vector<float> retVec(3);
	float mag = magnitude(a);
	float vals[] = {a.at(0)/mag, a.at(1)/mag, a.at(2)/mag};
	retVec.assign(vals, vals+3);
	free(vals);
	return retVec;
}