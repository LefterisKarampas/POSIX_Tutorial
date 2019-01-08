#include "Vehicle.h"


Vehicle::Vehicle(string id,int top,int wheels):ID(id),top_speed(top),num_wheels(wheels){
	cout << "Vehicle created!" << endl;
}

Vehicle::~Vehicle(){
	cout << "Vehicle destroyed!" << endl;
}

string Vehicle::Vehicle_GetID(){
	return this->ID;
}


int Vehicle::Vehicle_TopSpeed(){
	return this->top_speed;
}

int Vehicle::Vehicle_NumWheels(){
	return this->num_wheels;
};

