#pragma once
#include <utility>
#include <limits>

class MathUtil
{

public:
	static std::pair<double, double>* SolveSystemWithTwoVariables(const double A, const double B, const double C, 
																  const double D, const double E, const double F);

};

