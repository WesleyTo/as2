#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <math.h>  
#include "linAlg.h"
#include "Ray.h"
#include "PPM.h"
#include "Pixel.h"
#include <list>
#include "Sphere.h"
#include "Light.h"
#include <algorithm>
#include <math.h>
#include <fstream>
#include "Triangle.h"
#include "Vertex.h"
#include "Intersect.h"
#include "Shaders.h"
#include <list>

/*
void loadScene(std::string file) {

  //store variables and set stuff at the end
  int width, height;
  std::string fname = "output.bmp";
  
  //Camera values
  std::vector<float> lookAt(3);
  std::vector<float> lookFrom(3);
  std::vector<float> up(3);
  float fov;
  
  // store values for shape objects
  // initialize in loop below
  std::vector<Sphere::Sphere> spheres;
  std::vector<Vertex::Vertex> vertices;
  std::vector<Triangle::Triangle> tris;
  
  // store lights
  std::vector<Light::Light> lights;
  

  std::ifstream inpfile(file.c_str());
  if(!inpfile.is_open()) {
    std::cout << "Unable to open file" << std::endl;
  } else {
    std::string line;
    //MatrixStack mst;

    while(inpfile.good()) {
      std::vector<std::string> splitline;
      std::string buf;

      std::getline(inpfile,line);
      std::stringstream ss(line);

      while (ss >> buf) {
        splitline.push_back(buf);
      }
      //Ignore blank lines
      if(splitline.size() == 0) {
        continue;
      }

      //Ignore comments
      if(splitline[0][0] == '#') {
        continue;
      }

      //Valid commands:
      //size width height
      //  must be first command of file, controls image size
      else if(!splitline[0].compare("size")) {
        width = atoi(splitline[1].c_str());
        height = atoi(splitline[2].c_str());
      }
      //maxdepth depth
      //  max # of bounces for ray (default 5)
      else if(!splitline[0].compare("maxdepth")) {
        // maxdepth: atoi(splitline[1].c_str())
      }
      //output filename
      //  output file to write image to 
      else if(!splitline[0].compare("output")) {
        fname = splitline[1];
      }

      //camera lookfromx lookfromy lookfromz lookatx lookaty lookatz upx upy upz fov
      //  speciﬁes the camera in the standard way, as in homework 2.
      else if(!splitline[0].compare("camera")) {
        // lookfrom:
        	lookFrom[0] = atof(splitline[1].c_str());
        	lookFrom[1] = atof(splitline[2].c_str());
        	lookFrom[2] = atof(splitline[3].c_str());
        // lookat:
            lookAt[0] = atof(splitline[4].c_str());
        	lookAt[1] = atof(splitline[5].c_str());
        	lookAt[2] = atof(splitline[6].c_str());
        // up:
            up[0] = atof(splitline[7].c_str());
        	up[1] = atof(splitline[8].c_str());
        	up[2] = atof(splitline[9].c_str());        
		// FOV
        	fov = atof(splitline[10].c_str());
      }

      //sphere x y z radius
      //  Deﬁnes a sphere with a given position and radius.
      else if(!splitline[0].compare("sphere")) {
			x: atof(splitline[1].c_str())
			y: atof(splitline[1].c_str())
			z: atof(splitline[1].c_str())
			r: atof(splitline[4].c_str())
        // Create new sphere:
			spheres.push_back(Sphere::Sphere(r, x, y, z));
        //   Store 4 numbers
        //   Store current property values
        //   Store current top of matrix stack
      }
      //maxverts number
      //  Deﬁnes a maximum number of vertices for later triangle speciﬁcations. 
      //  It must be set before vertices are deﬁned.
      else if(!splitline[0].compare("maxverts")) {
        // Care if you want
        // Here, either declare array size
        // Or you can just use a STL std::vector, in which case you can ignore this
      }
      //maxvertnorms number
      //  Deﬁnes a maximum number of vertices with normals for later speciﬁcations.
      //  It must be set before vertices with normals are deﬁned.
      else if(!splitline[0].compare("maxvertnorms")) {
        // Care if you want
      }
      //vertex x y z
      //  Deﬁnes a vertex at the given location.
      //  The vertex is put into a pile, starting to be numbered at 0.
      else if(!splitline[0].compare("vertex")) {
			x = atof(splitline[1].c_str()),
			y = atof(splitline[2].c_str()),
			z = atof(splitline[3].c_str()));
        // Create a new vertex with these 3 values, store in some array
			vertices.emplace_back(x, y, z);
      }
      //vertexnormal x y z nx ny nz
      //  Similar to the above, but deﬁne a surface normal with each vertex.
      //  The vertex and vertexnormal set of vertices are completely independent
      //  (as are maxverts and maxvertnorms).
      else if(!splitline[0].compare("vertexnormal")) {
        // x: atof(splitline[1].c_str()),
        // y: atof(splitline[2].c_str()),
        // z: atof(splitline[3].c_str()));
        // nx: atof(splitline[4].c_str()),
        // ny: atof(splitline[5].c_str()),
        // nz: atof(splitline[6].c_str()));
        // Create a new vertex+normal with these 6 values, store in some array
      }
      //tri v1 v2 v3
      //  Create a triangle out of the vertices involved (which have previously been speciﬁed with
      //  the vertex command). The vertices are assumed to be speciﬁed in counter-clockwise order. Your code
      //  should internally compute a face normal for this triangle.
      else if(!splitline[0].compare("tri")) {
			v1 = vertices.at(atoi(splitline[1].c_str());
			v2 = vertices.at(atoi(splitline[2].c_str()));
			v3 = vertices.at(atoi(splitline[3].c_str()));
        // Create new triangle:
			tris.emplace_back(v1, v2, v3);
        //   Store pointer to array of vertices
        //   Store 3 integers to index into array
        //   Store current property values
        //   Store current top of matrix stack
      }
      //trinormal v1 v2 v3
      //  Same as above but for vertices speciﬁed with normals.
      //  In this case, each vertex has an associated normal, 
      //  and when doing shading, you should interpolate the normals 
      //  for intermediate points on the triangle.
      else if(!splitline[0].compare("trinormal")) {
        // v1: atof(splitline[1].c_str())
        // v2: atof(splitline[2].c_str())
        // v3: atof(splitline[3].c_str())
        // Create new triangle:
        //   Store pointer to array of vertices (Different array than above)
        //   Store 3 integers to index into array
        //   Store current property values
        //   Store current top of matrix stack
      }

      //translate x y z
      //  A translation 3-std::vector
      else if(!splitline[0].compare("translate")) {
        // x: atof(splitline[1].c_str())
        // y: atof(splitline[2].c_str())
        // z: atof(splitline[3].c_str())
        // Update top of matrix stack
      }
      //rotate x y z angle
      //  Rotate by angle (in degrees) about the given axis as in OpenGL.
      else if(!splitline[0].compare("rotate")) {
        // x: atof(splitline[1].c_str())
        // y: atof(splitline[2].c_str())
        // z: atof(splitline[3].c_str())
        // angle: atof(splitline[4].c_str())
        // Update top of matrix stack
      }
      //scale x y z
      //  Scale by the corresponding amount in each axis (a non-uniform scaling).
      else if(!splitline[0].compare("scale")) {
        // x: atof(splitline[1].c_str())
        // y: atof(splitline[2].c_str())
        // z: atof(splitline[3].c_str())
        // Update top of matrix stack
      }
      //pushTransform
      //  Push the current modeling transform on the stack as in OpenGL. 
      //  You might want to do pushTransform immediately after setting 
      //   the camera to preserve the “identity” transformation.
      else if(!splitline[0].compare("pushTransform")) {
        //mst.push();
      }
      //popTransform
      //  Pop the current transform from the stack as in OpenGL. 
      //  The sequence of popTransform and pushTransform can be used if 
      //  desired before every primitive to reset the transformation 
      //  (assuming the initial camera transformation is on the stack as 
      //  discussed above).
      else if(!splitline[0].compare("popTransform")) {
        //mst.pop();
      }

      //directional x y z r g b
      //  The direction to the light source, and the color, as in OpenGL.
      else if(!splitline[0].compare("directional")) {
        // x: atof(splitline[1].c_str()),
        // y: atof(splitline[2].c_str()),
        // z: atof(splitline[3].c_str()));
        // r: atof(splitline[4].c_str()),
        // g: atof(splitline[5].c_str()),
        // b: atof(splitline[6].c_str()));
        // add light to scene...
      }
      //point x y z r g b
      //  The location of a point source and the color, as in OpenGL.
      else if(!splitline[0].compare("point")) {
        // x: atof(splitline[1].c_str()),
        // y: atof(splitline[2].c_str()),
        // z: atof(splitline[3].c_str()));
        // r: atof(splitline[4].c_str()),
        // g: atof(splitline[5].c_str()),
        // b: atof(splitline[6].c_str()));
        // add light to scene...
      }
      //attenuation const linear quadratic
      //  Sets the constant, linear and quadratic attenuations 
      //  (default 1,0,0) as in OpenGL.
      else if(!splitline[0].compare("attenuation")) {
        // const: atof(splitline[1].c_str())
        // linear: atof(splitline[2].c_str())
        // quadratic: atof(splitline[3].c_str())
      }
      //ambient r g b
      //  The global ambient color to be added for each object 
      //  (default is .2,.2,.2)
      else if(!splitline[0].compare("ambient")) {
        // r: atof(splitline[1].c_str())
        // g: atof(splitline[2].c_str())
        // b: atof(splitline[3].c_str())
      }

      //diﬀuse r g b
      //  speciﬁes the diﬀuse color of the surface.
      else if(!splitline[0].compare("diffuse")) {
        // r: atof(splitline[1].c_str())
        // g: atof(splitline[2].c_str())
        // b: atof(splitline[3].c_str())
        // Update current properties
      }
      //specular r g b 
      //  speciﬁes the specular color of the surface.
      else if(!splitline[0].compare("specular")) {
        // r: atof(splitline[1].c_str())
        // g: atof(splitline[2].c_str())
        // b: atof(splitline[3].c_str())
        // Update current properties
      }
      //shininess s
      //  speciﬁes the shininess of the surface.
      else if(!splitline[0].compare("shininess")) {
        // shininess: atof(splitline[1].c_str())
        // Update current properties
      }
      //emission r g b
      //  gives the emissive color of the surface.
      else if(!splitline[0].compare("emission")) {
        // r: atof(splitline[1].c_str())
        // g: atof(splitline[2].c_str())
        // b: atof(splitline[3].c_str())
        // Update current properties
      } else {
        std::cerr << "Unknown command: " << splitline[0] << std::endl;
      }
    }

    inpfile.close();
  }

	//more variables
	std::vector<float> camDir = vSub(lookAt, lookFrom);
	std::vector<float> camBasisW = vScale(-1.0, camDir);
	std::vector<float> camBasisU = vCross(camBasisW, up);
	std::vector<float> camBasisV = vCross(camBasisU, camBasisW);
	float distance = 1.0;
	float planeHeight = tan(fov/2.0);
	float planeWidth = 0.0;
	float vertSpace = (2.0 * planeWidth)/width;
	float horizSpace = (2.0 * planeHeight)/height;
	
	Ray::Ray ray = new Ray();
	Intersect::Intersect itsct = new Intersect::Intersect();
	std::vector<float> intersection(3);
	PPM::PPM output = new PPM(height, width);


	// Ray-trace loop
	for (float w=0; w<width; w++) {
		for (float h=0; h<height; h++) {
			// pixel positions
			float u = (-1.0 * planeWidth) + horizSpace * (w+0.5);
			float v = (-1.0 * planeHeight) + vertSpace * (h+0.5);
			
			//generate ray from h, w, camera, etc...
			ray.setEye(lookFrom);
			ray.setPoint(lookAt);
			ray.initCamDir();
			
			//calculate intersections for each object
			pixel *p = new pixel(0, 0, 0);
			
			
			//for (int i = 0; i < numSpheres; i++) {
			for(std::vector<Sphere::Sphere>::iterator sphereIt = spheres.begin(); sphereIt != myvector.end(); ++it) {
				// assume numSpheres is an int >= 0
				// assume spheres is an array of Sphere objects
				itsct = spheres.at(sphereIt).intersect(ray);
				if (itsct.hit) {
				  intersection = ray.project(itsct.point);
				  
				  vector<float> cameraVector = ray.getDir();//get the vector
                                  vector<float> surfaceNormal = HELP! calculate surface Normal of shape
                            
				  float scale = 2 * vDot(cameraVector, surfaceNormal)
                                  vector<float> n = scale(scale, surfaceNormal)
				  vector<float> reflect = cameraVector - n;

                                  vector<float> reflectedLocation
				  
													  //shade and store values in image output
					// for every light
						// calculate shading for object point
						// add values to pixel vector
					//if depth > 0
						//calculate shadows and reflections for that ray and surface point
						// shade appropriately
						// add values to pixel vector
						//(*p).add(//returned shade values//);
				}
			//save pixel to image
			output.addPixel((*p).copy());
			//reset pixel
			(*p).reset();
		}
	}
	//save output file
	output.save(file);
	
}

*/

//===============================================
//     Lights
//===============================================
Light::Light(int t, float x1, float y1, float z1, float r1, float g1, float b1)
{	type = t;   x = x1;
   y = y1;
   z = z1;
   r = r1;
   g = g1;
   b = b1;
}
int Light::getType(){
  return type;}

float Light::getX(){
  return x;
}

float Light::getY(){
  return y;
}

float Light::getZ(){
  return x;
}

float Light::getR(){
  return r;
}
float Light::getG(){
  return g;
}
float Light::getB(){
  return b;
}

void Light::print() {
	std::cout<<"lgt [" << x << ", " << y << ", " << z << ", " << r << ", " << g << ", " << b <<"]\n";

}



//===============================================
//     Linear Algebra Functions
//===============================================

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


//===============================================
//     Pixel
//===============================================

Pixel::Pixel() {
	r = 0;
	g = 0;
	b = 0;
}

Pixel::Pixel(int x, int y, int z) {
	r = fmin(x, 255);
	g = fmin(y, 255);
	b = fmin(z, 255);
}

Pixel::Pixel(float x, float y, float z) {
	r = fmin(255, round(255*x));
	g = fmin(255, round(255*y));
	b = fmin(255, round(255*z));

}

std::string Pixel::toStr() {
	std::stringstream s;
	s<<r<<" "<<g<<" "<<b;
	return s.str();
}

Pixel Pixel::copy() {
	Pixel *p = new Pixel();
	p->setR(r);
	p->setG(g);
	p->setB(b);
	return *p;
}

void Pixel::reset() {
	r = 0;
	g = 0;
	b = 0;
}

void Pixel::add(Pixel p) {
	this->setR(r+p.getR());
	this->setG(g+p.getG());
	this->setB(b+p.getB());
}

int Pixel::getR() {
	return r;
}

int Pixel::getG() {
	return g;
}

int Pixel::getB() {
	return b;
}

void Pixel::setR(int red) {
	r = fmin(red, 255);
}

void Pixel::setG(int green) {
	g = fmin(green, 255);
}

void Pixel::setB(int blue) {
	b = fmin(blue, 255);
}

void Pixel::print() {
	std::cout<<"pix ["<<r<<", "<<g<<", "<<b<<"]\n";
}



//===============================================
//     Pixel
//===============================================
PPM::PPM(int w, int h, int m){
	height = h;
	width = w;
	maxVal = m;
	std::stringstream s;
	s<<"P3\n"<<width<<" "<<height<<"\n"<<maxVal<<"\n";
	header = s.str();			
	pixels = new Pixel::Pixel[height * width];
	pixelCount = 0;
}

int PPM::getPxCount() const{
	return wPos;
}

int PPM::getW() const {
	return width;
}

int PPM::getH() const {
	return height;
}

void PPM::addPixel(Pixel p){
	
	pixels[pixelCount] = p;
	pixelCount++;
}

Pixel PPM::getPixel(int x, int y) {
	return pixels[x*y+x];
}

void PPM::save(std::string name) {
	std::ofstream newFile;
	newFile.open("output.ppm");
	newFile<<header;
	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			newFile<<"  "<<w<<" "<< pixels[(h*w) + w].toStr();
		}
		newFile<<"\n";
	}
	newFile.close();
}



//===============================================
//     Ray
//===============================================
Ray::Ray() {}

Ray::Ray(std::vector<float> e, std::vector<float> p) {
	eye = e;
	point = p;
	camDir = vSub(p, e);
}

void Ray::setEye(std::vector<float> e){
	eye = e;
}

void Ray::setPoint(std::vector<float> p) {
	point = p;
}

void Ray::initCamDir() {
	camDir[0] = point[0] - eye[0];
	camDir[1] = point[1] - eye[1];
	camDir[2] = point[2] - eye[2];
}

std::vector<float> Ray::getEye() {
	return eye;
}

std::vector<float> Ray::getPoint() {
	return point;
}

std::vector<float> Ray::getDir(){
	return camDir;
}

std::vector<float> Ray::project(float t) {
	std::vector<float> k(3);
	k[0] = t*camDir[0];
	k[1] = t*camDir[1];
	k[2] = t*camDir[2];
	std::vector<float> a(3);
	a[0] = eye[0] + k[0];
	a[1] = eye[1] + k[1];
	a[2] = eye[2] + k[2];
	return a;

}

//===============================================
//     Sphere
//===============================================


Sphere::Sphere(float r, float x, float y, float z) {
	radius = r;
	position = std::vector<float>(3);
	position[0] = x;
	position[1] = y;
	position[2] = z;
}

Sphere::Sphere(float r, std::vector<float> p) {
	radius = r;
	position = p;
}

float Sphere::getRadius() const{
	return radius;
}

std::vector<float> Sphere::getPos() const{
	return position;
}

void Sphere::resize(float r) {
	radius = r;
}
	
void Sphere::setPos(std::vector<float> p) {
	position = p;
}

std::vector<float> Sphere::pointNormal(std::vector<float> point) {
	std::vector<float> s(3);
	s[0] = point[0] - position[0];
	s[1] = point[1] - position[1];
	s[2] = point[2] - position[2];
	return s;
}

Intersect Sphere::intersect(Ray r) {
	Intersect::Intersect ret = *new Intersect::Intersect();
	std::vector<float> d = r.getDir();
	std::vector<float> e = r.getEye();
	std::vector<float> eminusp(3);
	eminusp[0] = e[0] - position[0];
	eminusp[1] = e[1] - position[1];
	eminusp[2] = e[2] - position[2];
	float ddotd = d[0]*d[0]+d[1]*d[1]+d[2]*d[2];
	float empdot = eminusp[0]*eminusp[0] + eminusp[1]*eminusp[1] + eminusp[2]*eminusp[2];
	float ddoteminusp = d[0]*eminusp[0] + d[1]*eminusp[1] + d[2]*eminusp[2];
	float discriminant = sqrt(ddoteminusp * ddoteminusp - ddotd*(empdot - radius*radius));
	if (discriminant >= 0) {
		ret.setHit(true);
		float scalar = -1.0f;
		float * scale = &scalar;
		std::vector<float> scaled(3);
		scaled = vScale(-1, d);
		//scaled[0] = d[0]*(-1);
		//scaled[1] = d[1]*(-1);
		//scaled[2] = d[2]*(-1);
		float sdotemp = scaled[0]*eminusp[0] + scaled[1]*eminusp[1] + scaled[2]*eminusp[2];
		ret.setPoint(r.project((sdotemp+discriminant)/ddotd));
	}	
	return ret;
}



//===============================================
//   Triangle
//===============================================

Triangle::Triangle(Vertex va, Vertex vb, Vertex vc) {
	Vertex::Vertex v1 = va;
	Vertex::Vertex v2 = vb;
	Vertex::Vertex v3 = vc;
	std::vector<float> normal(3);
	normal[0] = (v1.getY()*v2.getZ() - v1.getZ()*v2.getY());
	normal[1] = (v1.getX()*v2.getZ() - v1.getZ()*v2.getX());
	normal[2] = (v1.getX()*v2.getY() - v1.getY()*v2.getX());
}

Vertex Triangle::getVertex(int n) const{
	if (n == 0) {
		return v1;
	}
	else if (n == 1) {
		return v2;
	}
	else if (n == 2){
		return v3;
	}
	return v1;
}

std::vector<float> Triangle::getNormal() const {
	return normal;
}
		
Intersect Triangle::intersect(Ray r) {
	Intersect::Intersect ret = *new Intersect::Intersect();
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
	std::vector<float> p(3);
	std::vector<float> vec1 = v1.toVec();
	std::vector<float> vec2 = v2.toVec();
	std::vector<float> vec3 = v3.toVec();
	p[0] = vec1[0] + (vec2[0] - vec1[0])*beta + (vec3[0] - vec1[0])*gamma;
	p[1] = vec1[1] + (vec2[1] - vec1[1])*beta + (vec3[1] - vec1[1])*gamma;
	p[2] = vec1[2] + (vec2[2] - vec1[2])*beta + (vec3[2] - vec1[2])*gamma;
	ret.setPoint(vec1);
	
	return ret;
}

//===============================================
//     Vertex
//===============================================
Vertex::Vertex() {
	x = 0;
	y = 0;
	z = 0;
}

Vertex::Vertex(std::vector<float> v) {
	x = v.at(0);
	y = v.at(1);
	z = v.at(2);
}
Vertex::Vertex(float a, float b, float c) {
	x = a;
	y = b;
	z = c;
}
bool Vertex::equals(Vertex::Vertex v){
	return (x==v.getX() && y==v.getY() && z==v.getZ());
}
float Vertex::getX() const{
	return x;
}

float Vertex::getY() const{
	return y;
}

float Vertex::getZ() const{
	return z;
}

std::vector<float> Vertex::sub(Vertex v) {
	std::vector<float> a(3);
	a[0] = x-v.getX();
	a[1] = y-v.getY();
	a[2] = z-v.getZ();
	return a;
}

std::vector<float> Vertex::toVec() {
	std::vector<float> n(3);
	n[0] = x;
	n[1] = y;
	n[2] = z;
	return n;
}
void Vertex::print() {
	std::cout<<"vtx ["<< x << ", " << y << ", " << z << "]\n";
}



//===============================================
//     Intersect
//===============================================
Intersect::Intersect() {
	hit = false;
}
void Intersect::setHit(bool h) {
	hit = h;
}

void Intersect::setPoint(std::vector<float> p) {
	point = p;
}

bool Intersect::isHit() const {
	return hit;
}

std::vector<float> Intersect::getPoint() const{
	return point;
}



//===============================================
//     Shaders
//===============================================
/*
Shaders::Shaders() {
  numLights = 0;
  numSpheres = 0;
  numTriangles = 0;
  std::vector<Light> l(10);
  lightSize = 10;
  triangleSize = 10;
  sphereSize = 10;
  lights = l;
  std::vector<Triangle> t(10);
  std::vector<Sphere> s(10);
  triangles = t;
  spheres = s;
}

void Shaders::addLight(Light l){
  lights[numLights] = l;
  numLights = numLights + 1;
  if(numLights == lightSize - 1){
    lights.resize(lightSize * 2);
    lightSize = lightSize * 2;
  }
}
void Shaders::addSphere(Sphere s){
  spheres[numSpheres] = s;
  numSpheres = numSpheres + 1;
  if(numSpheres == sphereSize - 1){
    spheres.resize(sphereSize * 2);
    sphereSize = sphereSize * 2;
  }
}
void Shaders::addTriangle(Triangle t){
  triangles[numTriangles] = t;
  numTriangles = numTriangles + 1;
  if(numTriangles == triangleSize - 1){
    triangles.resize(triangleSize * 2);
    triangleSize = triangleSize * 2;
  }
}

Pixel Shaders::pixelLight(float x, float y, float z){
  std::vector<float> color(3);
  for (int i = 0; i < numLights; i++){
    Light l = lights[i];


      if(l.getType() == 0) { //directional Light
	std::vector<float> lightDir(3);
	lightDir[0] = l.getX();
	lightDir[1] = l.getY();
	lightDir[2] = l.getZ();
	std::vector<float> lightColor(3);
	lightColor[0] = l.getR();
	lightColor[1] = l.getG();
	lightColor[2] = l.getB();      
	
	std::vector<float> amb = this->ambient(lightColor);
	color = vAdd(color, amb);
	if(this->hasShadow(x, y, z, l) == 0){ //if light isn't blocked by another object
	  std::vector<float> diff = this->diffuse(surfaceDir, center, scale(-1,lightDir), lightColor);
	  color = vAdd(color, diff);
	
	
	  std::vector<float> spec = this->specular(surfaceDir, center, viewer, lightDir, lightColor);
	  color = vAdd(color, spec);
	}
      }
      else { //point light
	std::vector<float> lightPos(3);
	lightPos[0] = l.getX();
	lightPos[1] = l.getY();
	lightPos[2] = l.getZ();
	std::vector<float> lightColor(3);
	lightColor[0] = l.getR();
	lightColor[1] = l.getG();
	lightColor[2] = l.getB();      
	std::vector<float> lightDir = vSub(surfaceDir, lightPos);
	
	std::vector<float> a = ambient(lightColor);
	color = vAdd(color, a);
	
	if(this->hasShadow(x, y, l) == 0){ //if light isn't blocked by another object
	  std::vector<float> diff = diffuse(surfaceDir, center, lightDir, lightColor);
	  color = vAdd(color, diff);
        
	  std::vector<float> spec = specular(surfaceDir, center, viewer, scale(-1,lightDir), lightColor);
	  color = vAdd(color, spec);
	}		      
      }
  }
}
  Pixel pixelColor = new Pixel(color[0], color[1], color[2]);
  return pixelColor;
}


std::vector<float> Shaders::ambient(std::vector<float> lightColor[]){
  return vMult(ka, lightColor);
}

std::vector<float> Shaders::diffuse(std::vector<float> surfaceDir, std::vector<float> center, std::vector<float> lightDir, std::vector<float> lightColor){ 

  std::vector<float> n = normalize(surfaceDir);
  std::vector<float> l = normalize(scale((-1),lightDir));
  float lambert = vDot(n, l);
  // no max function in Ubuntu environment
  if (lambert < 0) {lambert = 0.0;}
  std::vector<float>diff = vMult(kd, lightColor);
  std::vector<float> m(3);
  m[0] = lambert*diff.at(0);
  m[1] = lambert*diff.at(1);
  m[2] = lambert*diff.at(2);

  return m;
}

std::vector<float> Shaders::specular(std::vector<float> surfaceDir, std::vector<float> center, std::vector<float> viewer, std::vector<float> lightDir, std::vector<float> lightColor) {
  std::vector<float> n = normalize(surfaceDir);
  std::vector<float> l = normalize(scale(-1,lightDir));
  //float* r = new float[3]; n and l were initialized like this, but I shortened them
  std::vector<float> r = vSub(scale(2*(vDot(n, l)), n), l);
  std::float rv = vDot(normalize(r), normalize(viewer));

  // no max function in Ubuntu environment
  if (rv < 0) {rv = 0.0;}
  rv = pow(rv, sp);
  
  std::vector<float> spec = vMult(ks, lightColor);
  
  std::vector<float> m(3);
  m[0] = rv*spec[0];
  m[1] = rv*spec[1];
  m[2] = rv*spec[2];
  
  return m;
}
*/


//===============================================
//     Unit Tests
//===============================================
int main() {
	// set for command line argument -t to run unit tests.
	bool test = true;
	
	if (test) {
		std::cout<<"\n=================\nBegin UNIT TESTS\n=================\n\n";
		Light::Light n = *new Light::Light(0, 1, 1, 0, 0.5, 0.5, 0.5);
		n.print();
	
		Intersect::Intersect i = *new Intersect::Intersect();
		if(i.isHit()) {
			std::cout<<"INCORRECT! hit is true.\n\n";
		}
		else {
			std::cout<<"CORRECT! hit is false.\n\n";
			i.setHit(true);
		}
		if(i.isHit()) {
			std::cout<<"CORRECT! hit is true.\n\n";
		}
		else {
			std::cout<<"INCORRECT! hit is false.\n\n";
		}
		std::vector<float> ptest(3);
		ptest[0] = 0;
		ptest[1] = 1;
		ptest[2] = 2;
		i.setPoint(ptest);
		std::vector<float> p = i.getPoint();
		std::cout<< "[" << p[0] << ", " << p[1] << ", " << p[2] << "]\n";
	
		Vertex::Vertex a = *new Vertex::Vertex(0,0,0);
		Vertex::Vertex b = *new Vertex::Vertex(1,0,0);
		Vertex::Vertex c = *new Vertex::Vertex(0,1,0);
		a.print();
		a = a.sub(b);
		a.print();
		std::vector<float> d = c.toVec();
		std::cout<<"vec ["<< d[0] << ", " << d[1] << ", " << d[2] << "]\n";
		Vertex::Vertex e1 = *new Vertex::Vertex(d);
		e1.print();	
		Vertex a1 = *new Vertex::Vertex(0,1,0);
		Vertex b1 = *new Vertex::Vertex(1,-1,0);
		Vertex c1 = *new Vertex::Vertex(-1,-1,0);
		Triangle t = *new Triangle::Triangle(a1,b1,c1);
		p[0] = 0;
		p[1] = 0;
		p[2] = 0;
		std::vector<float> e(3);
		e[0] = 0;
		e[1] = 0;
		e[2] = 3;

		Ray::Ray r = *new Ray::Ray(e, p);
		i = t.intersect(r);
		if (i.isHit()) {
			std::cout<<"Triangle Intersected - OKAY\n";	
		}
		Sphere::Sphere s = *new Sphere::Sphere(1, p);
		if (s.intersect(r).isHit()) {
			std::cout<<"Sphere Intersected - OKAY\n";	
		}

	
		e[0] = 0;
		e[1] = -4;
		e[2] = -4;
		p[0] = 1;
		p[1] = 1;
		p[2] = -1;
		r.setEye(e);
		r.setPoint(p);
		std::cout<<"projected ";
		vPrint(r.project(1.5));
	
	
		PPM* ppm = new PPM(640, 480, 255);
		int val;
		for (float h = 0; h<480; h++) {
			for (float w =0; w<640; w++) {
				val = h;//std::min(255, (int)((w/639)*255.0f));
				ppm->addPixel(*(new Pixel::Pixel(val, val, val)));
			}	
		}
		ppm->save("output");
		/*
		for (float h = 0; h < 3; h++) {
			for (float w = 0; w< ppm->getW(); w++) {
				std::cout<<w<<" ";
				ppm->getPixel(w, h).print();
			}	
		}
		*/
	
		std::cout<<"End PPM tests\n";
		Pixel::Pixel px = *new Pixel::Pixel(255, 255, 255);
		Pixel::Pixel black = *new Pixel::Pixel(0,0,0);
		Pixel::Pixel pfloat = *new Pixel::Pixel(1.0f, 0.9f, 0.05f);
		Pixel::Pixel pmax = *new Pixel::Pixel(2.0f, 1.0f, 0.5f);
		px.print();
		black.print();
		black.add(px);
		black.print();
		pfloat.print();
		pmax.print();
	
	
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
	
		std::cout<<"\n=================\nEnd UNIT TESTS\n=================\n\n";
		
		return 0;
	}
	else{
		return 0;
	}
}