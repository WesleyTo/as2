#include <vector>
#include "Shape.h"

class Sphere {

	Sphere() {
		radius = 0.0;
		position = NULL;
	}

	Sphere(float r, std::vector<float> p) {
		radius = r;
		position = p;
	}
	
	float getRadius() {
		return radius;
	}
	
	std::vector<float> getPos() {
		return position;
	}
	
	void resize(float r) {
		radius = r;
	}
		
	void setPos(std::vector<float> ;) {
		position = p;
	}
	
	intersect intersect(Ray r) {
		intersect ret = new intersect();
		std::vector<float>* d = &r.getDir();
		std::vector<float>* e = &r.getEye();
		float discriminant = sqrt(pow(vDot(*d, (vSub(*e, position))), 2) - vDot(*d, *d)*(vDot(vSub(*e, position)), vSub(*e, position)) - pow(radius, 2));
		if (discriminant > 0) {
			ret.hit = true;
			ret.t1 = (vDot(vScale(-1, *d), vSub(*e,position))+discriminant)/vDot(*d, *d);
			ret.t2 = (vDot(vScale(-1, *d), vSub(*e,position))-discriminant)/vDot(*d, *d);
		}
		else if (discriminant == 0) {
			ret.hit = true;
			ret.tangent = true;
			ret.t1 = (vDot(vScale(-1, *d), vSub(e,position))+discriminant)/vDot(*d, *d);
			ret.t2 = ret.t1;
		}		
		return ret;
	}
}

class Polygon {

	Polygon(int s) {
		size = s;
		vertices = new vertex[s];
		bounds = new boundingBox();
		vertexCount = 0;
	}
	
	boundingBox getBounds() {
		return bounds;
	}
	
	void addVertex(vertex v) {
		vertices[vertexCount] = v;
		vertexCount++;
		setBounds(v);
	}
	
	// Can be very computationally expensive. Try not to use, if possible.
	void replaceVertex(vertex currVertex, vertex newVertex) {
		for (int i = 0; i< vertexCount; i++) {
			if (vertices[i] == currVertex) {				
				vertices[i] = newVertex;
				if(
					bounds.minX == currVertex.x || 
					bounds.maxX == currVertex.x ||
					bounds.minY == currVertex.y ||
					bounds.maxY == currVertex.y ||
					bounds.minZ == currVertex.z ||
					bounds.maxZ == currVertex.z) {
					resetBounds();
				}
				else {
					setBounds(newVertex);
				}
				break;
			}
		}
	}
	
	void setBounds(vertex v) {
		bounds.minX = min(bounds.minX, v.x);
		bounds.maxX = max(bounds.maxX, v.x);
		bounds.minY = min(bounds.minY, v.y);
		bounds.maxY = max(bounds.maxY, v.y);
		bounds.minZ = min(bounds.minZ, v.z);
		bounds.maxZ = max(bounds.maxZ, v.z);
	}
	
	// should only be called by replaceVertex()
	void resetBounds() {
	vertex* curr;
		for (int i = 0; i<vertexCount; i++) {
			curr = &(vertices[i]);
			setBounds(*curr);
		}
	}
	
	int size() {
		return size;
	}
	
	void resize(int n) {
		size = n;
		vertex newV[] = new vertex[n];
		for (int i = 0; i < vertexCount; i++) {
			newV[i] = vertices[i];
		}
		vertex oldV* = &vertices;
		vertices = newV;
		free(oldV);
	}
	
	//copied and pasted from SPHERE, modify accordingly for polygons.
	intersect intersect(Ray r) {
		intersect ret = new intersect();
		std::vector<float>* d = &r.getDir();
		std::vector<float>* e = &r.getEye();
		float discriminant = sqrt(pow(vDot(*d, (vSub(*e, position))), 2) - vDot(*d, *d)*(vDot(vSub(*e, position)), vSub(*e, position)) - pow(radius, 2));
		if (discriminant > 0) {
			ret.hit = true;
			ret.t1 = (vDot(vScale(-1, *d), vSub(*e,position))+discriminant)/vDot(*d, *d);
			ret.t2 = (vDot(vScale(-1, *d), vSub(*e,position))-discriminant)/vDot(*d, *d);
		}
		else if (discriminant == 0) {
			ret.hit = true;
			ret.tangent = true;
			ret.t1 = (vDot(vScale(-1, *d), vSub(e,position))+discriminant)/vDot(*d, *d);
		}		
		return ret;
	}

}
	