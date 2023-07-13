#include "Geometry.h"
#include <iostream>

int main() {
	Point3D A;

	Point3D B;
	B.SetX(1);
	B.SetY(1);
	B.SetZ(1);

	std::cout << B.GetX() << " " << B.GetY() << " " << B.GetZ() << std::endl;

	Point3D C(1, 0, 0);
	Point3D D(1, 1, 1);

	Segment3D AB(A, B);
	Segment3D CD(C, D);

	Point3D* inter = (Point3D*)AB.Intersect(CD);

	std::cout << inter->GetX() << " " << inter->GetY() << " " << inter->GetZ();

	Point2D ner;

	
	std::cin >> ner;

	std::cout << ner;
}