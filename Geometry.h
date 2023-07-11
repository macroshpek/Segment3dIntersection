#pragma once

#include <utility>
#include "MathUtil.h"

class Geometry
{

};

class Point2D : public Geometry
{
	double x_;
	double y_;

public:

	Point2D(const double x, const double y);
	Point2D(const Point2D& other);

	double GetX() const;

	double GetY() const;

	void SetX(double x);

	void SetY(double y);

	Point2D operator+(const Point2D& other) const;

	Point2D operator-(const Point2D& other) const;

	Point2D operator*(const double skalar) const;

	Point2D operator/(const double skalar) const;

	bool operator==(const Point2D& other) const;

	double operator*(const Point2D& other) const;

	static Point2D zero();

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

	void SetX(double x);

	void SetY(double y);

	void SetZ(double z);

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
		
public:

	Point3D Direction() const;

	Geometry* Intersect(const Segment3D& other) const;

};

class Line2D : public Geometry
{
	Point2D start_;
	Point2D end_;

	Point2D Direction() const;

	Point2D Intersect(const Point2D& other) const;
};
