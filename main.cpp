#include "Geometry.h"
#include <iostream>

int main() {

	//Testing the Point2D functionality
	/*Point2D p2_A;
	p2_A.SetX(0);
	p2_A.SetY(-1);
	std::cout << p2_A.GetX() << " " << p2_A.GetY() << std::endl;
	std::cout << p2_A << std::endl;

	Point2D p2_B;
	std::cin >> p2_B;
	std::cout << p2_B << std::endl;

	std::cout << p2_A + p2_B << std::endl;

	std::cout << p2_A - p2_B << std::endl;

	std::cout << p2_A * p2_B << std::endl;

	double skalar;

	std::cin >> skalar;

	std::cout << p2_B  * skalar << std::endl;

	std::cout << p2_B / skalar << std::endl;

	std::cout << -p2_B << std::endl;

	std::cout << Point2D::zero() << std::endl;

	std::cout << (p2_A == p2_B) << std::endl;

	std::cout << (p2_B ==  p2_B) << std::endl;*/

	//Testing the Segment2D functionality
	Segment2D _AB{ (0,0),(1,1) };
	Segment2D _CD{ (0,1),(1,0) };

	std:: cout << _AB.CheckIntersect(_CD);
	
	//Testing the Line2D functionality

	//Testing the Point3D functionality
	Point3D A;

	Point3D B;
	B.SetX(1);
	B.SetY(1);
	B.SetZ(1);

	//std::cout << B.GetX() << " " << B.GetY() << " " << B.GetZ() << std::endl;

	Point3D C(1, 0, 0);
	Point3D D(0, 1, 1);

	//Testing the Segment3D functionality

	Segment3D AB(A, B);
	Segment3D CD(C, D);

	std::cout << AB.DistanceBetween(CD);

	Geometry* inter = AB.Intersect(CD);




	//Testing the Line3D functionality
}