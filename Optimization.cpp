// Optimization.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>
#include <cmath>
#include <functional>

struct NewtonSolver {
	std::function<float(const float)> f;
	std::function<float(const float)> fprime;
	const float tol;
	NewtonSolver(
		float(&arg_f)(const float), float(&arg_fprime)(const float), const float arg_tol) :
		f(arg_f), fprime(arg_fprime), tol(arg_tol) {
	}
	void operator()(float& x) const {
		float old_x = x;
		x -= f(x) / fprime(x);
		std::cout << x << std::endl;
		if (std::abs(x - old_x) < std::abs(x) * tol) {
			return;
		}
		else {
			(*this)(x);
		}
	}
};


float f(const float x) {
	return x * x + 2 * x - 3;
}

float fprime(const float x) {
	return 2 * x + 2;
}

int main()
{
	const float tol = 0.001;
	float x = -1000;
	NewtonSolver newton(f, fprime, tol);
	newton(x);
	std::cout << "Newton answer: " << x << std::endl;

	std::cin.ignore();
}

