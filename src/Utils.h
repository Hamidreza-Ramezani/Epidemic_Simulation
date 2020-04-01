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




#endif



