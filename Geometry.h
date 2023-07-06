
class Geometry
{

};

class Point3D : public Geometry
{
	double x_;
	double y_;
	double z_;

	Point3D(const double x = 0, const double y = 0, const double z = 0);

	Point3D operator+(const Point3D& other) const;

	Point3D operator-(const Point3D& other) const;

	Point3D operator*(const double skalar) const;

	Point3D operator*(const Point3D& other) const;


};
