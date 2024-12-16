#ifndef ACOR_H
#define ACOR_H


#pragma once
#include "Agent.h"
#include "Problem.h"
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>

# define M_PI 3.14159265358979323846

class OriginalACOR {
private:
    int sample_count;
    double intent_factor;
    double zeta;
    int pop_size;
    int epoch;
    std::vector<Agent> pop;
    Problem* d_p;
    Agent g_best;
    Agent g_worst;


public:
    OriginalACOR(int epoch, int pop_size, int sample_count, double intent_factor, double zeta);
    double calculate_fitness(std::vector<double>& solution);
    void generate_population();
    Agent generate_agent();
    Agent generate_empty_agent();
    Agent generate_empty_agent(std::vector<double>& solution);
    int get_index_roulette_wheel_selection(const std::vector<double>& list_fitness);
    std::vector<Agent> get_sorted_population(std::vector<Agent>& pop, const std::string& minmax);
    Agent solve(Problem* probleme );
    std::vector<Agent> get_sorted_and_trimmed_population(std::vector<Agent>& population);
    void evolve(int epoch);
    void track_optimize_step(std::vector<Agent>& population,int epoch, long time);
};

#endif // ACOR_H
