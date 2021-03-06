#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <math.h>  
#include "linAlg.h"
#include "Ray.h"
#include "Shape.h"
#include "PPM.h"
#include "Pixel.h'
#include <list>


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
				  /*
				  vector<float> cameraVector = ray.getDir();//get the vector
                                  vector<float> surfaceNormal = HELP! calculate surface Normal of shape
                            
				  float scale = 2 * vDot(cameraVector, surfaceNormal)
                                  vector<float> n = scale(scale, surfaceNormal)
				  vector<float> reflect = cameraVector - n;

                                  vector<float> reflectedLocation
				  */
													  //shade and store values in image output
					// for every light
						// calculate shading for object point
						// add values to pixel vector
					//if depth > 0
						//calculate shadows and reflections for that ray and surface point
						// shade appropriately
						// add values to pixel vector
						(*p).add(/*returned shade values*/);
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