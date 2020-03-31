#include <string>
#pragma once

using namespace std;

enum Location {
	atHome, atSchool, atWork, inCommunity, atHospital
};

inline string locationToString(Location location) {
	switch (location) {
	case atHome:
		return "atHome";
	case atSchool:
		return "atSchool";
	case atWork:
		return "atWork";
	case atHospital:
		return "atHospital";
	default:
		return "inCommunity";
	}
}

enum State {
	Susceptible, Exposed, Infectious, Recovered
};

inline string stateToString(State state) {
	switch (state) {
	case Susceptible:
		return "Susceptible";
	case Exposed:
		return "Exposed";
	case Infectious:
		return "Infectious";
	default:
		return "Recovered";
	}
}

enum Status {student, employee, other};

inline string statusToString(Status status) {
	switch (status) {
	case student:
		return "student";
	case employee:
		return "employee";
	default:
		return "other";
	}
}

//employment rate = 75
//There are currently 10,320,811 full and part time pupils
//There are currently 32,770 schools in the UK
//2.4 milion students higher education

//pupils = 15 percent

//all students = 20 percent
