/*
 * Person.cpp
 *
 *  Created on: Mar 28, 2020
 *      Author: guest
 */

#include <iostream>
#include "Person.h"
#include <string>
#include "Enumerated_Types.h"
#include "Utils.h"

using namespace std;

//Person::Person(int _id, int _age, double _incubationTime, State _state,
//		Location _currentLocation) {
//	this->age = _age;
//	this->currentLocation = _currentLocation;
//	this->currentState = _state;
//	this->id = _id;
//	this->incubationTime = _incubationTime;
//
//}

Person::Person(int _id) {
	this->id = _id;
}

void Person::setStatus(Status s) {
	this->currentStatus = s;
}

void Person::setState(State s) {
	this->currentState = s;
}

//string Person::toString() {
//	string idStr = to_string(this->id) + "\t" + "\t" + "\t";
//	string ageStr = to_string(this->age) + "\t" + "\t" + "\t";
//	string timeOfInfectionStr = to_string(this->time_of_infection) + "\t" + "\t" + "\t";
//	string stateStr = stateToString(this->currentState) + "\t" + "\t" + "\t";
//	string statusStr = statusToString(currentStatus) + "\t" + "\t" + "\t";
//	string locationStr = locationToString(this->currentLocation) + "\t" + "\t" + "\t";
//	string str = "Person id: " + idStr + " age: " + ageStr
//			+ " time of infection: " + timeOfInfectionStr + " state: "
//			+ stateStr + " status: " + statusStr + " Location: " + locationStr;
//	return str;
//}

string Person::toString() {
	string idStr = to_string(this->id) + "\t" + "\t" ;
	string timeOfInfectionStr = to_string(this->time_of_infection) + "\t" + "\t";
	string stateStr = stateToString(this->currentState) + "\t" + "\t";
	string statusStr = statusToString(currentStatus) + "\t" + "\t";
	string locationStr = locationToString(this->currentLocation) + "\t" + "\t";
	string str = "Person id: " + idStr + " time of infection: " + timeOfInfectionStr + " state: "
			+ stateStr + " status: " + statusStr + " Location: " + locationStr;
	return str;
}

void Person::meet(Person* person, int sim_time) {
	if (this->currentState == Susceptible) {
		switch (person->currentState) {
		case Susceptible:
			return;
		case Exposed:
			return;
		case Infectious:
			this->currentState = Exposed;
			this->time_of_infection = sim_time;
			return;
		default:
			return;
		}
	}

	else if (this->currentState == Exposed) {
		return;
	}

	else if (this->currentState == Infectious) {
		switch (person->currentState) {
		case Susceptible:
			person->currentState = Exposed;
			person->time_of_infection = sim_time;
			return;
		case Exposed:
			return;
		case Infectious:
			return;
		default:
			return;
		}
	} else {
		return;
	}
}


void Person::individual_disease_progression() {
	if (this->currentState == Exposed
			and this->exposed_minute_count
					< (exposedDayCount * hoursPerDay)) {
		this->exposed_minute_count++;
	}

	else if (this->currentState == Exposed
			and this->exposed_minute_count
					== (exposedDayCount * hoursPerDay)) {
		this->currentState = Infectious;
	}

	else if (this->currentState == Infectious
			and this->infectious_minute_count
					< (infectiousDayCount * hoursPerDay)) {
		this->infectious_minute_count++;
	}

	else if (this->currentState == Infectious
			and this->infectious_minute_count
					== (infectiousDayCount * hoursPerDay)) {
		this->currentState = Recovered;
	}
}

void Person::updateCurrentLocation(int sim_time) {
	int currentTime = sim_time % hoursPerDay;
	if (currentTime >= 21 || currentTime <= 8) {
		this->currentLocation = atHome;
		return;
	}
	if (this->currentStatus == other) {
		//flip a coin and set it to home or community
		if (yesOrNo(50)) {
			this->currentLocation = atHome;
		} else {
			this->currentLocation = inCommunity;
		}
		return;
	}

	if (currentTime >= 9 && currentTime <= 17) {
		//check the status and update the location
		if (currentStatus == student) {
			this->currentLocation = atSchool;
			return;
		} else {
			this->currentLocation = atWork;
			return;
		}
	}

	else {
		//flip a coin and set it to home or community
		if (yesOrNo(50)) {
			this->currentLocation = atHome;
		} else {
			this->currentLocation = inCommunity;
		}
	}

}

string Person::getHomeConnections(){
	string str = "home connections are: \n";
	for (auto & person : homeConnections) {
	    str += "id: " + to_string(person->id) + "\n";
	}
	return str;
}

string Person::getSchoolConnections(){
	string str = "school connections are: \n";
	for (auto & person : schoolConnections) {
	    str += "id: " + to_string(person->id) + "\n";
	}
	return str;
}

string Person::getWorkConnections(){
	string str = "work connections are: \n";
	for (auto & person : workConnections) {
	    str += "id: " + to_string(person->id) + "\n";
	}
	return str;
}

void Person::addToHomeConnections(Person* person) {
	this->homeConnections.push_back(person);
}

void Person::addToSchoolConnections(Person* person) {
	this->schoolConnections.push_back(person);
}

void Person::addToWorkConnections(Person* person) {
	this->workConnections.push_back(person);
}






















