#include "Problem.h"
#include <windows.h>

Problem::Problem(int _n_vars, double _lb, double _ub, std::function<double( std::vector<double>&)> ss,std::string _min_max):n_vars{ _n_vars }, lb{ _lb }, ub{_ub}, obj_func{ss},min_max(_min_max)
{
}

std::vector<double> Problem::generate_solution()
{
    std::vector<double> solutions(n_vars);
    std::random_device rd;

    std::uniform_real_distribution<double> dis(lb, ub);

    for (int i = 0; i < n_vars; ++i)
    {
        std::mt19937 gen(rd());
        solutions[i] = dis(gen);
    }
    /*
    std::cout << "[ ";
    for (int i = 0; i < solutions.size(); i++) {
        std::cout << solutions[0];
        std::cout << ", ";
    }
    */
    return solutions;
}

double Problem::calculate_fitness(std::vector<double>& solution)
{
    return obj_func(solution);
}

std::vector<double> Problem::correct_solution(std::vector<double>& solution)
{
    std::vector<double> x_new;
    for (int i = 0; i < n_vars; i++)
        x_new.push_back(correct(solution[i]));
    return x_new;
}



double Problem::correct(double value)
{
    if (value < lb)
        return lb;
    else if (value > ub)
        return ub;
    else
        return value;
}

int Problem::n_dims()
{
    return n_vars;
}

std::string Problem::minmax()
{
    return min_max;
}
