
#include "Geometry.h"
#include <cmath>
#include <limits>
#include <exception>

Point3D::Point3D(const double x = 0, const double y = 0, const double z = 0) : x_(x), y_(y), z_(z)
{

}

Point3D::Point3D(const Point3D& other) : x_(other.x_), y_(other.y_), z_(other.z_) {}

Point3D Point3D::operator+(const Point3D& other) const
{
	Point3D sum;
	sum.x_ = this->x_ + other.x_;
	sum.y_ = this->y_ + other.y_;
	sum.z_ = this->z_ + other.z_;
	return sum;
}

Point3D Point3D::operator-(const Point3D& other) const
{
	Point3D sub;
	sub.x_ = this->x_ - other.x_;
	sub.y_ = this->y_ - other.y_;
	sub.z_ = this->z_ - other.z_;
	return sub;
}

Point3D Point3D::operator*(const double skalar) const
{
	Point3D mult;
	mult.x_ = this->x_ * skalar;
	mult.y_ = this->y_ * skalar;
	mult.z_ = this->z_ * skalar;
	return mult;
}

Point3D Point3D::operator/(const double skalar) const
{
	if (std::abs(skalar) > std::numeric_limits<double>::epsilon()) {
		Point3D div;
		div.x_ = this->x_ / skalar;
		div.y_ = this->y_ / skalar;
		div.z_ = this->z_ / skalar;
		return div;
	}
	throw std::exception("division by zero");
}

double Point3D::operator*(const Point3D& other) const
{
	double skalarProduct;
	skalarProduct = this->x_ * other.x_ + this->y_ * other.y_ + this->z_ * other.z_;
	return skalarProduct;
}
