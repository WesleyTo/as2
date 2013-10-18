#include <vector>
#include "linAlg.h"

std::vector<float> generate(float dist, float u, float v, std::vector<float> basisU, std::vector<float> basisV, std::vector<float> basisW) {
	return retVec( vAdd(vScale( (-1.0 * dist), basisW), vAdd(vScale(u, basisU), vScale(v, BasisV) ) ) );
}