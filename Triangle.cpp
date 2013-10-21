#include "Triangle.h"
#include "Ray.h"

Triangle(Vertex::Vertex va, Vertex::Vertex vb, Vertex::Vertex vc) {
	v1 = va;
	v2 = vb;
	v3 = vc;
	/*
	bounds = new boundingBox::boundingBox();
	bounds.setMinX(std::min(v1.getX(), v2.getX(), v3.getX());
	bounds.setMaxX(std::max(v1.getX(), v2.getX(), v3.getX());
	bounds.setMinY(std::min(v1.getY(), v2.getY(), v3.getY());
	bounds.setMaxY(std::max(v1.getY(), v2.getY(), v3.getY());
	bounds.setMinZ(std::min(v1.getZ(), v2.getZ(), v3.getZ());
	bounds.setMaxZ(std::max(v1.getZ(), v2.getZ(), v3.getZ());
	*/
}

Vertex::Vertex Triangle::getVertex(int n) const{
	if (n == 0) {
		return v1;
	}
	else if (n == 1) {
		return v2;
	}
	else if (n == 2){
		return v3;
	}
}

/*
boundingBox::boundingBox getBounds() const {
	return bounds;
}
*/

std::vector<float> getNormal() const {
	return normal;
}
		
Intersect::intersect intersect(Ray r) {
	Intersect::Intersect ret = new Intersect::Intersect();
	float a = v1.getX() - v2.getX();
	float b = v1.getY() - v2.getY();
	float c = v1.getZ() - v2.getZ();
	float d = v1.getX() - v3.getX();
	float e = v1.getY() - v3.getY();
	float f = v1.getZ() - v3.getZ();
	float g = r.getDir().at(0);
	float h = r.getDir().at(1);
	float i = r.getDir().at(2);
	float j = v1.getX() - r.getEye().at(0);
	float k = v1.getY() - r.getEye().at(1);
	float l = v1.getZ() - r.getEye().at(2);
	float eiminushf = e*i - h*f;
	float gfminusdi = g*f - d*i;
	float dhminuseg = d*h - e*g;
	float akminusjb = a*k - j*b;
	float jcminusal = j*c - a*l;
	float blminuskc = b*l - k*c;
	float m = a*(eiminushf) + b*(gfminusdi) + c*(dhminuseg);
	float beta = (j*(eiminushf) + k*(gfminusdi) + l*(dhminuseg))/m;
	if (beta < 0) {return ret;}
	float gamma = (i*(akminusjb) + h*(jcminusal) + g*(blminuskc))/m;
	if (gamma < 0 || beta+gamma > 1) {return ret;}
	float t = (-1)*(f*(akminusjb) + e*(jcminusal) + d*(blminuskc))/m;
	std::vector<float> p;
	p = vAdd(vAdd(v1, vScale(beta, vSub(v2, v1))), vScale(gamme, vSub(v3, v1)));
	ret.setPoint(p);
	
	return ret;
}