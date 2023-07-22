#include "Geometry.h"

std::ostream& Point3D::Write(std::ostream& os) const
{
	return os << "Point3D:(" << x_ << ", " << y_ << ", " << z_<<")";
}

std::istream& Point3D::Read(std::istream& is)
{
	double x = 0;
	double y = 0;
	double z = 0;

	is >> x >> y >> z;

	if (is) {
		x_ = x;
		y_ = y;
		z_ = z;
	}

	return is;
}

Point3D::Point3D(const double x, const double y, const double z) : x_(x), y_(y), z_(z) {}

Point3D::Point3D(const Point3D& other) : x_(other.x_), y_(other.y_), z_(other.z_) {}

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

double Point3D::Length() const
{
	return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

Point2D Point3D::ToXY() const
{
	return Point2D(GetX(), GetY());
}

Point2D Point3D::ToYZ() const
{
	return Point2D(GetY(), GetZ());
}

Point2D Point3D::ToXZ() const
{
	return Point2D(GetX(), GetZ());
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

Geometry* Segment3D::IntersectByPoint(const Segment3D& other) const
{
	
	double lambd1 = (other.Direction().GetX() != 0) ? (Direction().GetX() / other.Direction().GetX()) : 0;
	double lambd2 = (other.Direction().GetY() != 0) ? (Direction().GetY() / other.Direction().GetY()) : 0;
	double lambd3 = (other.Direction().GetZ() != 0) ? (Direction().GetZ() / other.Direction().GetZ()) : 0;

	if (std::abs(lambd1 - lambd2) > std::numeric_limits<double>::epsilon()) {
		Line2D pr_first(start_.ToXY(),end_.ToXY());
		Line2D pr_second(-other.start_.ToXY(), -other.end_.ToXY());

		Point2D* solution = pr_first.Intersect(pr_second);

		if (abs(Direction().GetZ() * solution->GetX() - solution->GetY() * other.Direction().GetZ() + 
					start_.GetZ() -other.start_.GetZ()) < std::numeric_limits<double>::epsilon())
		{
			Point3D result = Point3D(other.start_) + other.Direction() * solution->GetY();
			return &result;
		}
	}

	if (std::abs(lambd2 - lambd3) > std::numeric_limits<double>::epsilon()) {
		Line2D pr_first(start_.ToYZ(), end_.ToYZ());
		Line2D pr_second(-other.start_.ToYZ(), -other.end_.ToYZ());

		Point2D* solution = pr_first.Intersect(pr_second);

		if (abs(Direction().GetX() * solution->GetX() - solution->GetY() * other.Direction().GetX() +
			start_.GetX() - other.start_.GetX()) < std::numeric_limits<double>::epsilon())
		{
			Point3D result = Point3D(other.start_) + other.Direction() * solution->GetY();
			return &result;
		}
	}

	if (std::abs(lambd1 - lambd3) > std::numeric_limits<double>::epsilon()) {
		Line2D pr_first(start_.ToXZ(), end_.ToXZ());
		Line2D pr_second(-other.start_.ToXZ(), -other.end_.ToXZ());

		Point2D* solution = pr_first.Intersect(pr_second);

		if (abs(Direction().GetY() * solution->GetX() - solution->GetY() * other.Direction().GetY() +
			start_.GetY() - other.start_.GetY()) < std::numeric_limits<double>::epsilon())
		{
			Point3D result = Point3D(other.start_) + other.Direction() * solution->GetY();
			return &result;
		}
	}
}

Geometry* Segment3D::IntersectBySegment(const Segment3D& other) const
{
	if (start_ == other.end_)
		return new Point3D(start_);
}

bool Segment3D::IsIdentical(const Segment3D& other) const
{
	Segment3D secant = { start_, other.start_ };
	if (((Direction() ^ secant.Direction()) == Point3D::zero()) &&
		((other.Direction() ^ secant.Direction()) == Point3D::zero()))
		return true;
	return false;
}

std::ostream& Segment3D::Write(std::ostream& os) const
{
	return os << "Segment3D:{(" << start_.GetX() << ", " << start_.GetY() << ", " << start_.GetZ() << "), (" 
								<< end_.GetX() << ", " << end_.GetY() << ", " << end_.GetZ() << ")}";
}

std::istream& Segment3D::Read(std::istream& is)
{
	double x1 = 0;
	double y1 = 0;
	double z1 = 0;
	double x2 = 0;
	double y2 = 0;
	double z2 = 0;

	is >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

	if (is) {
		start_.SetX(x1);
		start_.SetY(y1);
		start_.SetZ(z1);
		end_.SetX(x2);
		end_.SetY(y2);
		end_.SetZ(z2);
	}

	return is;
}

Segment3D::Segment3D(const Point3D& start, const Point3D& end) : start_(start), end_(end)
{
}

Segment3D::Segment3D(const Segment3D& other)
{
}

InterTypes Segment3D::CheckIntersection(const Segment3D& other) const
{
	//This condition means that the vectors do not lie in the same plane
	if (Point3D::mixedProduct(Direction(), other.Direction(), other.start_ - start_) > std::numeric_limits<double>::epsilon()) {
		return InterTypes::Screw;
	}	
		
	if ((Direction() ^ other.Direction()) == Point3D::zero()) {
		if(IsIdentical(other))
			return InterTypes::BySegment;
		return InterTypes::Parallel;
	}

	return InterTypes::ByPoint;


}

Point3D Segment3D::Direction() const
{
	return end_ - start_;
}

bool Segment3D::IsDot() const
{
	if (start_ == end_) {
		return true;
	}
	return false;
}

double Segment3D::DistanceBetween(const Segment3D& other) const
{
	InterTypes type = CheckIntersection(other);
	switch (type)
	{
	case Screw:
		return abs((other.start_ - start_) * (Direction() ^ other.Direction())) / (Direction() ^ other.Direction()).Length();
	case Parallel:
		return abs((start_ - other.start_) * Direction()) / abs((Direction().Length()));
	case ByPoint:
	case BySegment:
		return 0;
	default:
		break;
	}

}

Geometry* Segment3D::Intersect(const Segment3D& other) const
{
	InterTypes type = CheckIntersection(other);
	Geometry* result = nullptr;
	switch (type) {
	case ByPoint:
		result = IntersectByPoint(other);
		break;
	case BySegment:
		result = IntersectBySegment(other);
		break;
	}
	return result;

}

std::ostream& operator<<(std::ostream& os, InterTypes type)
{
	if (os) {
		switch (type)
		{
		case DoesntIntersect:
			os << "Doesn`t intersect";
			break;
		case Screw:
			os << "Segments are screw";
			break;
		case Parallel:
			os << "Segmnets are parallel";
			break;
		case ByPoint:
			os << "Segmnets intersects by point";
			break;
		case BySegment:
			os << "Segmnets intersects by segment";
			break;
		default:
			break;
		}
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const Geometry& obj)
{
	obj.Write(os);
	return os;
}

std::istream& operator>>(std::istream& is, Geometry& obj)
{
	obj.Read(is);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Point3D& point)
{
	return os << "Point3D (" << point.GetX() << ", " << point.GetY() << ", " << point.GetZ() << ")";
}

std::istream& operator>>(std::istream& is, Point3D& point)
{
	double x = 0;
	double y = 0;
	double z = 0;
	is >> x >> y >> z;
	if (is) {
		point.SetX(x);
		point.SetY(y);
		point.SetZ(z);
	}
	return is;
}

std::ostream& Point2D::Write(std::ostream& os) const
{
	return os << "Point2D: (" << x_ << ", " << y_ << ")";
}

std::istream& Point2D::Read(std::istream& is)
{
	double x = 0;
	double y = 0;

	is >> x >> y;

	if (is) {
		x_ = x;
		y_ = y;
	}

	return is;
}

Point2D::Point2D(const double x, const double y) : x_(x), y_(y)
{
}

Point2D::Point2D(const Point2D& other) : x_(other.x_), y_(other.y_)
{
}

double Point2D::GetX() const
{
	return x_;
}

double Point2D::GetY() const
{
	return y_;
}

void Point2D::SetX(double x)
{
	x_ = x;
}

void Point2D::SetY(double y)
{
	y_ = y;
}

Point2D Point2D::operator+(const Point2D& other) const
{
	Point2D sum;
	sum.x_ = x_ + other.x_;
	sum.y_ = y_ + other.y_;
	return sum;
}

Point2D Point2D::operator-(const Point2D& other) const
{
	Point2D sub;
	sub.x_ = x_ - other.x_;
	sub.y_ = y_ - other.y_;
	return sub;
}

Point2D Point2D::operator-() const
{
	return Point2D(-GetX(), -GetY());
}

Point2D Point2D::operator*(const double skalar) const
{
	Point2D mult;
	mult.x_ = x_ * skalar;
	mult.y_ = y_ * skalar;
	return mult;
}

Point2D Point2D::operator/(const double skalar) const
{
	if (std::abs(skalar) > std::numeric_limits<double>::epsilon()) {
		Point2D div;
		div.x_ = x_ / skalar;
		div.y_ = y_ / skalar;
		return div;
	}
	throw std::exception("division by zero");
}

bool Point2D::operator==(const Point2D& other) const
{
	if (std::abs(x_ - other.x_) < std::numeric_limits<double>::epsilon() &&
		std::abs(y_ - other.y_) < std::numeric_limits<double>::epsilon())
		return true;

	return false;
}

double Point2D::operator*(const Point2D& other) const
{
	double skalarProduct;
	skalarProduct = x_ * other.x_ + y_ * other.y_;
	return skalarProduct;
}

double Point2D::PseudoSkalarProduct(const Point2D& other) const
{
	return Length() * other.Length() * std::sin(AngleBetween(other));
}

double Point2D::AngleBetween(const Point2D& other) const
{
	return std::acos(*this * other/(Length() * other.Length()));
}

double Point2D::Length() const
{
	return std::sqrt(x_ * x_ + y_ * y_);
}

Point2D Point2D::zero()
{
	return Point2D();
}

std::ostream& Line2D::Write(std::ostream& os) const
{
	return os << "Line2D: Direction - (" << Direction() << "), through a" << start_;
}
std::istream& Line2D::Read(std::istream& is)
{
	return is;
}


Line2D::Line2D(const Point2D& start, const Point2D& end) : start_(start), end_(end)
{
}

Line2D::Line2D(const Segment2D& segment) : start_(segment.GetStart()), end_(segment.GetEnd())
{
}

Point2D Line2D::Direction() const
{
	return start_ - end_;
}

Point2D* Line2D::Intersect(const Line2D& other) const
{
	double det = Direction().GetX() * other.Direction().GetY() - Direction().GetY() * other.Direction().GetX();

	if (abs(det) < std::numeric_limits<double>::epsilon()) {
		return nullptr;
	}

	Point2D right = other.start_ - start_;

	double C = right.GetX();
	double F = right.GetY();

	double x = (C * other.Direction().GetY() - other.Direction().GetX() * F) / det;
	double y = (Direction().GetX() * F - C * Direction().GetY()) / det;

	return new Point2D(x, y);

	/*
	const double A = 5, B = 4, C = 13;
	const double D = 2, E = 3, F = 8;

	const double det = A * E - B * D;

	const double X = (C * E - B * F) / det;
	const double Y = (A * F - C * D) / det;
	*/

}

Point2D* Segment2D::IntersectByPoint(const Segment2D& other) const
{
	return nullptr;
}

Segment2D Segment2D::IntersectBySegment(const Segment2D& other) const
{
	return Segment2D((1,1), (2,2));
}

std::ostream& Segment2D::Write(std::ostream& os) const
{
	return os << "Segment2D:{(" << start_.GetX() << ", " << start_.GetY() << "), (" << end_.GetX() << ", " << end_.GetY() << ")}";
}

std::istream& Segment2D::Read(std::istream& is)
{
	double x1 = 0;
	double y1 = 0;
	double x2 = 0;
	double y2 = 0;

	is >> x1 >> y1 >> x2 >> y2;

	if (is) {
		start_.SetX(x1);
		start_.SetY(y1);
		end_.SetX(x2);
		end_.SetY(y2);
	}

	return is; 
}

Segment2D::Segment2D(const Point2D& start, const Point2D& end)
{
}

Segment2D::Segment2D(const Segment2D& other)
{
}

const Point2D& Segment2D::GetStart() const
{
	return start_;
}

const Point2D& Segment2D::GetEnd() const
{
	return start_;
}

Point2D Segment2D::Direction() const
{
	return end_ - start_;
}

InterTypes Segment2D::CheckIntersect(const Segment2D& other) const
{
	if (Direction().PseudoSkalarProduct(other.start_ - start_) *
		Direction().PseudoSkalarProduct(other.end_ - start_) *
		other.Direction().PseudoSkalarProduct(start_ - other.start_) *
		other.Direction().PseudoSkalarProduct(end_ - other.start_)
	> 0);
		//return true;

	//return false;
	return InterTypes::ByPoint;
}

Geometry* Segment2D::Intersect(const Segment2D& other) const
{
	if(!this->CheckIntersect(other))
		return nullptr;

	return IntersectByPoint(other);
}

double Segment2D::Length() const
{
	return std::sqrt((start_.GetX() - end_.GetX()) * (start_.GetX() - end_.GetX()) +
					(start_.GetY() - end_.GetY()) * (start_.GetY() - end_.GetY()));
}