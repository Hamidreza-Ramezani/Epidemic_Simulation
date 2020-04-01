/*
 * Person.h

 *
 *  Created on: Mar 28, 2020
 *      Author: guest
 */

#include <string>
#include "Enumerated_Types.h"
#include <vector>

#ifndef PERSON_H_
#define PERSON_H_

using namespace std;

//costants:

const int minutesPerDay = 24 * 60;
const int hoursPerDay = 24;
const double exposedDayCount = 5.1;
const int infectiousDayCount = 10;

//extern int minutesPerDay;
//extern int hoursPerDay;
//extern double exposedDayCount;
//extern int infectiousDayCount;


class Person {

public:
	int id;
	int age;
	float incubationTime;
	int time_of_infection = -1;
	State currentState;
	Location currentLocation;
	vector<Person*> homeConnections;
	vector<Person*> schoolConnections;
	vector<Person*> workConnections;
    long long exposed_minute_count = 0;
    long long infectious_minute_count = 0;
	string toString();
	Status currentStatus;
	void setStatus(Status s);
	void setState(State s);
	void updateCurrentLocation(int sim_time);

	void addToHomeConnections(Person* person);
	void addToSchoolConnections(Person* person);
	void addToWorkConnections(Person* person);
	void individual_disease_progression();
	void meet(Person* person, int sim_time);
	string getHomeConnections();
	string getWorkConnections();
	string getSchoolConnections();
	Person(int id);

};

#endif /* PERSON_H_ */
