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
	/*Segment2D _AB{ (0,0),(1,1) };
	Segment2D _CD{ (0,1),(1,0) };

	std:: cout << _AB.CheckIntersect(_CD);*/
	
	//Testing the Line2D functionality

	//Testing the Point3D functionality
	Point3D A{ 0,0,0 };
	Point3D B{ 1,1,1 };
	Point3D C{ 0.5,0.5,0.5 };
	Point3D D{ 2,2,2 };
	Point3D E{ 1,0,0 };
	Point3D F{ 2,1,1 };
	Point3D G{ -1,-1,-1 };
	Point3D H{ 0,1,1 };
	Point3D I{ -2,-2,-2 };
	Point3D T{ -1,-2,-2 };
	Point3D O{ -2,-1,-1 };
	
	Segment3D AB{ A,B };
	Segment3D BB{ B,B };
	Segment3D BE{ B,E };
	Segment3D CD{ C,D };
	Segment3D CG{ C,G };
	Segment3D EF{ E,F };
	Segment3D EH{ E,H };
	Segment3D GD{ G,D };
	Segment3D GH{ G,H };
	Segment3D GI{ G,I };
	Segment3D OT{ O,T };
	Segment3D AG{ A,G };
	Segment3D IT{ I,T };
	Segment3D ID{ I,D };

	Geometry::SetPrecision(1);

	std::cout << ID.Contains(A) << std::endl;
	std::cout << ID.Contains({0.0000000000001,0.0000000000002,0.0000000000001}) << std::endl;
	std::cout << ID.Contains(B) << std::endl;
	std::cout << ID.Contains(C) << std::endl; // doesn`t work :ccccc
	std::cout << ID.Contains(D) << std::endl;
	std::cout << *AB.Intersect(CD) << std::endl; //отрезки наложены друг на друга
	std::cout << *AB.Intersect(GD) << std::endl; //один отрезок содержится в другом
	std::cout << *CG.Intersect(ID);
	std::cout << *AB.Intersect(EH) << std::endl; //отрезки пересекаются в одной точке
	std::cout << *AB.Intersect(EF) << std::endl; //отрезки параллельны
	std::cout << *AB.Intersect(GH) << std::endl; //отрезки не пересекаются //-
	std::cout << *GI.Intersect(OT) << std::endl; //точки отрицательны
	std::cout << *GI.Intersect(IT) << std::endl; //doesn`t work
	std::cout << *AB.Intersect(BE) << std::endl; //doesn`t work correct
	std::cout << *BB.Intersect(BB) << std::endl; 
	std::cout << AB.Contains(C) << std::endl;

	/*Point3D A{ 0.9,0,0 };
	Point3D B{ -0.1,-1,0 };
	Point3D C{ 0,-1,0 };
	Point3D D{ -2,0,0 };

	Segment3D AB{ A,B };
	Segment3D CD{ C,D };

	std::cout << *AB.Intersect(CD);*/

	//Testing the Segment3D functionality




	//Testing the Line3D functionality
}