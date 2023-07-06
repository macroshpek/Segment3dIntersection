
#include "Geometry.h"
#include <cmath>
#include <limits>
#include <exception>
#include <utility>

Point3D::Point3D(const double x = 0, const double y = 0, const double z = 0) : x_(x), y_(y), z_(z) {}

Point3D::Point3D(const Point3D& other) : x_(other.x_), y_(other.y_), z_(other.z_) {}

double Point3D::GetX() const
{
	return x_;
}

double Point3D::GetY() const
{
	return y_;
}

double Point3D::GetZ() const
{
	return z_;
}

double Point3D::SetX(double x)
{
	x_ = x;
}

double Point3D::SetY(double y)
{
	y_ = y;
}

double Point3D::SetZ(double z)
{
	z_ = z;
}

Point3D Point3D::operator+(const Point3D& other) const
{
	Point3D sum;
	sum.x_ = x_ + other.x_;
	sum.y_ = y_ + other.y_;
	sum.z_ = z_ + other.z_;
	return sum;
}

Point3D Point3D::operator-(const Point3D& other) const
{
	Point3D sub;
	sub.x_ = x_ - other.x_;
	sub.y_ = y_ - other.y_;
	sub.z_ = z_ - other.z_;
	return sub;
}

Point3D Point3D::operator*(const double skalar) const
{
	Point3D mult;
	mult.x_ = x_ * skalar;
	mult.y_ = y_ * skalar;
	mult.z_ = z_ * skalar;
	return mult;
}

Point3D Point3D::operator/(const double skalar) const
{
	if (std::abs(skalar) > std::numeric_limits<double>::epsilon()) {
		Point3D div;
		div.x_ = x_ / skalar;
		div.y_ = y_ / skalar;
		div.z_ = z_ / skalar;
		return div;
	}
	throw std::exception("division by zero");
}

double Point3D::operator*(const Point3D& other) const
{
	double skalarProduct;
	skalarProduct = x_ * other.x_ + y_ * other.y_ + z_ * other.z_;
	return skalarProduct;
}

double Point3D::mixedProduct(const Point3D& a, const Point3D& b, const Point3D& c)
{
	return a * (b ^ c);
}

Point3D Point3D::zero()
{
	return Point3D();
}

Point3D Point3D::operator^(const Point3D& other) const {
	Point3D vecMult;
	vecMult.x_ = y_ * other.z_ - z_ * other.y_;
	vecMult.y_ = z_ * other.x_ - x_ * other.z_;
	vecMult.z_ = x_ * other.y_ - y_ * other.x_;
	return vecMult;
}

bool Point3D::operator==(const Point3D& other) const
{
	if (std::abs(x_ - other.x_) < std::numeric_limits<double>::epsilon() &&
		std::abs(y_ - other.y_) < std::numeric_limits<double>::epsilon() &&
		std::abs(z_ - other.z_) < std::numeric_limits<double>::epsilon())
		return true;

	return false;
}

Point3D Segment3D::IntersectByPoint(const Segment3D& other) const
{
	double lambd1 = (other.Direction().GetX() != 0) ? (Direction().GetX() / other.Direction().GetX()) : 0;
	double lambd2 = (other.Direction().GetY() != 0) ? (Direction().GetY() / other.Direction().GetY()) : 0;
	double lambd3 = (other.Direction().GetZ() != 0) ? (Direction().GetZ() / other.Direction().GetZ()) : 0;

	/*if (std::abs(lambd1 - lambd2) > std::numeric_limits<double>::epsilon()) {
		double det = Direction().GetX() * (-other.Direction().y) - Direction().y * (-other.Direction().GetX());
		if (det != 0) {
			double X = ((-start_.GetX() + other.start_.GetX()) * (-other.Direction().y) - (-other.Direction().GetX()) * (-start_.y + other.start_.y)) / det;
			double Y = (this->direction().x * (-this->start.y + other.start.y) - this->direction().y * (-this->start.x + other.start.x)) / det;
			if (this->direction().z * X - Y * other.direction().z == -this->start.z + other.start.z) {
				return dot{ other.start } + other.direction() * Y;
			}
			else {
				throw std::exception("doesn`t intersect");
			}
		}

	}

	if (lambd2 != lambd3) {
		double det = this->direction().y * (-other.direction().z) - this->direction().z * (-other.direction().y);
		if (det != 0) {
			double X = ((-this->start.y + other.start.y) * (-other.direction().z) - (-other.direction().y) * (-this->start.z + other.start.z)) / det;
			double Y = (this->direction().y * (-this->start.z + other.start.z) - this->direction().z * (-this->start.y + other.start.y)) / det;
			if (this->direction().x * X - Y * other.direction().x == -this->start.x + other.start.x) {

				return dot{ other.start } + other.direction() * Y;
			}
			else {
				throw std::exception("doesn`t intersect");
			}
		}

	}

	if (lambd1 != lambd3) {
		double det = this->direction().x * (-other.direction().z) - this->direction().z * (-other.direction().x);
		if (det != 0) {
			double X = ((-this->start.x + other.start.x) * (-other.direction().z) - (-other.direction().z) * (-this->start.x + other.start.x)) / det;
			double Y = (this->direction().z * (-this->start.x + other.start.x) - this->direction().z * (-this->start.x + other.start.x)) / det;
			if (this->direction().y * X - Y * other.direction().y == -this->start.y + other.start.y) {
				std::cout << "intersect";
				return dot{ other.start } + other.direction() * Y;
			}
			else {
				throw std::exception("doesn`t intersect");
			}
		}

	}*/
}

Segment3D Segment3D::IntersectBySegment(const Segment3D& other) const
{
	return Segment3D();
}

std::pair<double, double> Segment3D::SolveSystemWithTwoVariables(const double A, const double B, const double C, const double D, const double E, const double F)
{
	//Ax + By = C
	//Dx + Ey = F
	double det = A * E - B * D;
	if (abs(det) < std::numeric_limits<double>::epsilon()) {
		//return nullptr;
	}
	const double X = (C * E - B * F) / det;
	const double Y = (A * F - C * D) / det;

	//std::pair<double, double>* solution = new std::make_pair<double, double>(X, Y);
	return std::pair<double, double>();
}

Point3D Segment3D::Direction() const
{
	return end_ - start_;
}

Geometry* Segment3D::Intersect(const Segment3D& other) const
{
	if (Point3D::mixedProduct(Direction(), other.Direction(), other.start_ - start_) <= std::numeric_limits<double>::epsilon()) {

		if ((Direction() ^ other.Direction()) == Point3D::zero()) {
			//logic about identical or parallel segments
		}

		//std::cout << "segments intersects" << std::endl;
	}
	//std::cout << "segments is skrew" << std::endl;
	return nullptr;
}

