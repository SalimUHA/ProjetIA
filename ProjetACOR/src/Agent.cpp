#include "Agent.h"
Agent::Agent()
{
}

Agent::Agent(std::vector<double>& solution) : d_solution(solution)
{

}

Agent& Agent::operator=(const Agent& other)
{
	if (this != &other) {
		std::vector<double> solution = other.getsolution();
		this->set_solution(solution);
		this->set_fitness(other.getfitness());
	}
	return *this;
}

void Agent::set_solution(std::vector<double>& solution)
{
	d_solution = solution;
}



std::vector<double> Agent::getsolution() const
{
	return d_solution;
}

double Agent::getfitness() const
{
	return d_fitness;
}



void Agent::set_fitness(double fitness)
{
	d_fitness = fitness;
}
