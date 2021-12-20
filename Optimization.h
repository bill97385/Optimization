#pragma once


class NewtonMethod {

public:
	NewtonMethod(double fx_0, double fx_1, double fx_2, double dx);
	int IterLimit = 100;
	double eps = 1e-08;
	double Iteration(double initVal);

private:
	double _fx_0, _fx_1, _fx_2, _dx;
};



class GradientDescent {

public:
	GradientDescent(double fx_0, double fx_1, double dx);
	int IterLimit = 100;
	double eps = 1e-08;
	double LearningRate = 0.01;
	double Iteration(double initVal);
private:
	double _fx_0, _fx_1, _dx;
};

double Derivative(double fx_0, double fx_1, double dx)
{
	return (fx_1 - fx_0) / dx;
}


double SecondDerivative(double fx_0, double fx_1, double fx_2, double dx)
{
	return (fx_2 - 2 * fx_1 + fx_0) / (dx * dx);
}

double NewtonEstimateMove(double x_0, double fx_0, double fx_1, double fx_2, double dx)
{
	return x_0 - (Derivative(fx_0, fx_1, dx) / SecondDerivative(fx_0, fx_1, fx_2, dx));
}

double GradientDescentEstimateMove(double x_0, double fx_0, double fx_1, double dx, double LearningRate)
{
	return x_0 + LearningRate * Derivative(fx_0, fx_1, dx);
}