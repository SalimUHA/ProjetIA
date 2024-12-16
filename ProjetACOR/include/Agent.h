#ifndef AGENT_H
#define AGENT_H


#include <vector>
#include <iostream>

class Agent {
public:
	Agent();
	Agent(std::vector<double>& solution);
	Agent& operator=(const Agent& other);
	void set_solution(std::vector<double>& solution);
	void set_fitness(double fitness);
	double getfitness() const;
	std::vector<double> getsolution() const;
private:
	std::vector<double> d_solution;
	double d_fitness;
};

#endif // AGENT_H
