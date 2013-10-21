#ifndef LINALG_H
#define LINALG_H

#include <vector>

float* vDot(std::vector<float> *, std::vector<float> *);

std::vector<float> vSub(std::vector<float> *, std::vector<float> *);

std::vector<float> vAdd(std::vector<float> *, std::vector<float> *);

std::vector<float> vScale(float*, std::vector<float> *);

std::vector<float> vMult(std::vector<float> *, std::vector<float> *);

std::vector<float> vCross(std::vector<float> *, std::vector<float> *) ;

void vPrint(std::vector<float> *);

float* magnitude(std::vector<float> *);

std::vector<float> normalize(std::vector<float> *);

#endif