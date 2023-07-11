#include "MathUtil.h"

std::pair<double, double>* MathUtil::SolveSystemWithTwoVariables(const double A, const double B, const double C, const double D, const double E, const double F)
{
	//Ax + By = C
	//Dx + Ey = F
	//Ax + By = C
	double det = A * E - B * D;
	if (abs(det) < std::numeric_limits<double>::epsilon()) {
		return nullptr;
	}
	const double X = (C * E - B * F) / det;
	const double Y = (A * F - C * D) / det;

	return new std::pair<double, double>(X, Y);
}

