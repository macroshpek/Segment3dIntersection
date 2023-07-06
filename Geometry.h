#pragma once

#include <utility>

class Geometry
{

};

class Point3D : public Geometry
{

	double x_;
	double y_;
	double z_;

public:
	
	Point3D(const double x, const double y, const double z);
	Point3D(const Point3D& other);

	double GetX() const;

	double GetY() const;

	double GetZ() const;

	double SetX(double x);

	double SetY(double y);

	double SetZ(double z);

	Point3D operator+(const Point3D& other) const;

	Point3D operator-(const Point3D& other) const;

	Point3D operator*(const double skalar) const;

	Point3D operator/(const double skalar) const;

	Point3D operator^(const Point3D& other) const;

	bool operator==(const Point3D& other) const;
	
	double operator*(const Point3D& other) const;

	static double mixedProduct(const Point3D& a, const Point3D& b, const Point3D& c);

	static Point3D zero();


};

class Segment3D : public Geometry 
{
	
	Point3D start_;
	Point3D end_;

	Point3D IntersectByPoint(const Segment3D& other) const;

	Segment3D IntersectBySegment(const Segment3D& other) const;

	std::pair<double, double> SolveSystemWithTwoVariables(const double A, const double B, const double C, const double D, const double E, const double F);

public:

	Point3D Direction() const;

	Geometry* Intersect(const Segment3D& other) const;

};
