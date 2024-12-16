
#include <iostream>
#include "ACOR.h"

//Rosenbrock function
double rosenbrock(const std::vector<double>& x) {
    double sum = 0.0;
    for (size_t i = 0; i < x.size() - 1; ++i) {
        double term = 100.0 * pow(x[i + 1] - pow(x[i], 2), 2) + pow(1 - x[i], 2);
        sum += term;
    }
    return sum;
}

//Rastrigin function
double rastrigin(const std::vector<double>& x) {
    size_t n = x.size();
    double A = 10.0;
    double sum = A * n;

    for (size_t i = 0; i < n; ++i) {
        sum += pow(x[i], 2) - A * cos(2 * M_PI * x[i]);
    }

    return sum;
}


//Ackley function
double ackley(const std::vector<double>& x) {
    const double M_E = std::exp(1.0);

    size_t n = x.size();
    double sum1 = 0.0;
    double sum2 = 0.0;

    for (size_t i = 0; i < n; ++i) {
        sum1 += pow(x[i], 2);
        sum2 += cos(2.0 * M_PI * x[i]);
    }

    return -20.0 * exp(-0.2 * sqrt(sum1 / n)) - exp(sum2 / n) + 20.0 + M_E;
}

//schwefel function
double schwefel(const std::vector<double>& x) {
    double sum = 0.0;

    for (size_t i = 0; i < x.size(); ++i) {
        sum += x[i] * sin(sqrt(fabs(x[i])));
    }

    return -sum; // Minimization problem, so negating the result.
}

#include <cmath>


int main()
{
	Problem* p = new Problem{30,-5.12,5.12,schwefel,"min"};
	OriginalACOR acor(10000, 30, 20, 0.5, 1.0);
	Agent g_best = acor.solve(p);
	std::cout << g_best.getfitness();
}
