/*
 * Utils.h
 *
 *  Created on: Mar 30, 2020
 *      Author: guest
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <cstdlib>
#include <random>

bool yesOrNo(double probabilityOfYes);
void writeHouseholdToFile(vector<vector<Person*>> outputVector, char* name);
void writeWorkplacesToFile(vector<vector<Person*>> outputVector, char* name);
void writeSchoolsToFile(vector<vector<Person*>> outputVector, char* name);
void writeToFile(string data, char* name);



template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
	std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
	std::advance(start, dis(g));
	return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	return select_randomly(start, end, gen);
}

#endif



