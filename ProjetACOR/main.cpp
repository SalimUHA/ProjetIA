
#include <iostream>
#include "ACOR.h"
#include <fstream>


double rosenbrock(const std::vector<double>& x) {
    double sum = 0.0;
    for (size_t i = 0; i < x.size() - 1; ++i) {
        double term = 100.0 * pow(x[i + 1] - pow(x[i], 2), 2) + pow(1 - x[i], 2);
        sum += term;
    }
    return sum;
}


double rastrigin(const std::vector<double>& x) {
    size_t n = x.size();
    double A = 10.0;
    double sum = A * n;

    for (size_t i = 0; i < n; ++i) {
        sum += pow(x[i], 2) - A * cos(2 * M_PI * x[i]);
    }

    return sum;
}



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


double schwefel(const std::vector<double>& x) {
    double sum = 0.0;

    for (size_t i = 0; i < x.size(); ++i) {
        sum += x[i] * sin(sqrt(fabs(x[i])));
    }

    return -sum;
}

#include <cmath>


int main()
{
    int dimension = 10;
	Problem* p = new Problem{dimension,-5.12,5.12,schwefel,"min"};
	OriginalACOR acor(10000, 30, 20, 0.5, 1.0);
	Agent g_best = acor.solve(p);

	 std::ofstream results_file("resultats_ACOR.txt");
    if (!results_file.is_open())
    {
        std::cout << "Erreur : impossible d'ouvrir le fichier pour ecrire les résultats." << std::endl;
        return 1;
    }

    results_file << "Dimension\tBest Fitness\n";
    results_file << dimension<<"\t";
    results_file << g_best.getfitness();
    results_file << '\n';

	std::cout << g_best.getfitness();


}
