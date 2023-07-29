#pragma once

#include <utility>
#include <cmath>
#include <limits>
#include <exception>
#include <iostream>
#include <string>

enum InterTypes {
	DoesntIntersect = -1,// <-- ne nuzhno?
	Screw = 0,
	Parallel,
	ByPoint,
	BySegment //that meanings segments lie on same line and maybe intersects
};

std::ostream& operator<<(std::ostream& os, InterTypes type);

class Geometry
{
	
	virtual std::ostream& Write(std::ostream& os) const = 0;
	virtual std::istream& Read(std::istream& is) = 0;

protected:
	static double& GetEpsilon();

public:

	friend std::ostream& operator<<(std::ostream& os, const Geometry& obj);
	friend std::istream& operator>>(std::istream& is, Geometry& obj);

	static void SetPrecision(const double precision);

};

class Point2D : public Geometry
{
private:

	double x_;
	double y_;

	virtual std::ostream& Write(std::ostream& os) const override;
	virtual std::istream& Read(std::istream& is) override;

public:


	Point2D(const double x = 0, const double y = 0);
	Point2D(const Point2D& other);

	double GetX() const;

	double GetY() const;

	void SetX(double x);

	void SetY(double y);

	Point2D operator+(const Point2D& other) const;

	Point2D operator-(const Point2D& other) const;
	Point2D operator-() const;

	Point2D operator*(const double skalar) const;

	Point2D operator/(const double skalar) const;

	bool operator==(const Point2D& other) const;

	double operator*(const Point2D& other) const;

	double PseudoSkalarProduct(const Point2D& other) const;

	double AngleBetween(const Point2D& other) const;

	double Length() const;

	static Point2D zero();

};

class Point3D : public Geometry
{

	double x_;
	double y_;
	double z_;

	virtual std::ostream& Write(std::ostream& os) const override;
	virtual std::istream& Read(std::istream& is) override;

public:

	friend std::ostream& operator<<(std::ostream& os, const Point3D& point);
	friend std::istream& operator>>(std::istream& is, Point3D& point);
	
	Point3D(const double x = 0, const double y = 0, const double z = 0);
	Point3D(const Point3D& other);

	double GetX() const { return x_; }

	double GetY() const { return y_; }

	double GetZ() const { return z_; }

	void SetX(double x) { x_ = x; }

	void SetY(double y) { y_ = y; }

	void SetZ(double z) { z_ = z; }

	Point3D operator+(const Point3D& other) const;

	Point3D operator-(const Point3D& other) const;
	Point3D operator-() const;

	Point3D operator*(const double skalar) const;
	double operator*(const Point3D& other) const;
	friend Point3D operator*(const double skalar, const Point3D& point);

	Point3D operator/(const double skalar) const;

	Point3D operator^(const Point3D& other) const;

	bool operator==(const Point3D& other) const;
	

	static double mixedProduct(const Point3D& a, const Point3D& b, const Point3D& c);

	static Point3D zero();

	double Length() const;

	Point2D ToXY() const;
	Point2D ToYZ() const;
	Point2D ToXZ() const;

};

class Segment2D : public Geometry
{
	Point2D start_;
	Point2D end_;

	Point2D * IntersectByPoint(const Segment2D & other) const;

	Segment2D IntersectBySegment(const Segment2D & other) const;

	virtual std::ostream& Write(std::ostream& os) const override;
	virtual std::istream& Read(std::istream& is) override;

public:

	Segment2D(const Point2D& start, const Point2D& end);
	Segment2D(const Segment2D& other);

	const Point2D& GetStart() const;
	const Point2D& GetEnd() const;

	Point2D Direction() const;

	InterTypes CheckIntersect(const Segment2D& other) const;

	Geometry* Intersect(const Segment2D& other) const;

	double Length() const;

};

class Segment3D : public Geometry 
{
	
	Point3D start_;
	Point3D end_;

	Geometry* IntersectByPoint(const Segment3D& other) const;

	Geometry* IntersectBySegment(const Segment3D& other) const;

	bool IsIdentical(const Segment3D& other) const;

	virtual std::ostream& Write(std::ostream& os) const override;
	virtual std::istream& Read(std::istream& is) override;

public:
	
	Segment3D(const Point3D& start, const Point3D& end);
	Segment3D(const Segment3D& other);
	InterTypes CheckIntersection(const Segment3D& other) const;

	Point3D Direction() const;

	bool IsDot() const;

	double DistanceBetween(const Segment3D& other) const;

	Geometry* Intersect(const Segment3D& other) const;

	double Length() const;

	bool Contains(const Point3D& point) const;

};

class Line2D : public Geometry
{
	Point2D start_;
	Point2D end_;

	virtual std::ostream& Write(std::ostream& os) const override;
	virtual std::istream& Read(std::istream& is) override;

public:
	Line2D(const Point2D& start, const Point2D& end);
	Line2D(const Segment2D& segment);

	Point2D Direction() const;

	Point2D* Intersect(const Line2D& other) const;
};

class Line3D : public Geometry
{
	Point3D origin_;
	Point3D direction_;

	virtual std::ostream& Write(std::ostream& os) const override;
	virtual std::istream& Read(std::istream& is) override;

public:
	Line3D(const Point3D& origin, const Point3D& direction);
	Point3D* Intersect(const Line3D& other) const;
	
};
