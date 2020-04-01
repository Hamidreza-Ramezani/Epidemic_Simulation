/*
 * Utils.cpp
 *
 *  Created on: Mar 30, 2020
 *      Author: guest
 */


//#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <random>
#include <string>

#include <fstream>
#include <iostream>
#include "Person.h"

using namespace std;

bool yesOrNo(double probabilityOfYes) {
	return rand() % 100 < (probabilityOfYes);
}

void writeHouseholdToFile(vector<vector<Person*>> outputVector, char* name) {
	ofstream myfile;
	myfile.open(name);
//	char generatedFilesPrefix[12] = "generated/";
//	myfile.open(strcat(generatedFilesPrefix, name));


	string str = "";
	for (auto family : outputVector) {
		str += "family: \n";
		for (auto &person : family) {
			str += "id: " + to_string(person->id) + "\t";
		}
		str += "\n \n \n";
	}
	myfile << str;
	myfile.close();
}

void writeSchoolsToFile(vector<vector<Person*>> outputVector, char* name) {
	ofstream myfile;
	myfile.open(name);
//	char generatedFilesPrefix[12] = "generated/";
//	myfile.open(strcat(generatedFilesPrefix, name));
	string str = "";
	for (auto group : outputVector) {
		str += "school: \n";
		for (auto &person : group) {
			str += "id: " + to_string(person->id) + "\t";
		}
		str += "\n \n \n";
	}
	myfile << str;
	myfile.close();
}


void writeWorkplacesToFile(vector<vector<Person*>> outputVector, char* name) {
	ofstream myfile;
	myfile.open(name);
//	char generatedFilesPrefix[12] = "generated/";
//	myfile.open(strcat(generatedFilesPrefix, name));
	string str = "";
	for (auto colleagues : outputVector) {
		str += "workplace: \n";
		for (auto &person : colleagues) {
			str += "id: " + to_string(person->id) + "\t";
		}
		str += "\n \n \n";
	}
	myfile << str;
	myfile.close();
}

void writeToFile(string data, char* name) {
	ofstream myfile;
	myfile.open(name);
//	char generatedFilesPrefix[12] = "generated/";
//	myfile.open(strcat(generatedFilesPrefix, name));

	myfile << data;
	myfile.close();
}





//bool flip_coin(){
//	random_device rd;
//	uniform_int_distribution<int> distribution(1, 100);
//	mt19937 engine(rd()); // Mersenne twister MT19937
//
//	int value=distribution(engine);
//	if(value > threshold) ...
//}

