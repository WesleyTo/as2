class Sphere {
	public:
		Sphere(float r, std::vector<float> p);
		float getRadius() const;
		std::vector<float> getPos() const;
		void setRadius(float r);
		void setPos(std::vector<float>);
		intersect intersect(Ray);
	private:
		float radius;
		std::vector<float> position;
}