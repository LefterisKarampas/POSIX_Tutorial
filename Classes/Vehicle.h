#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include <iostream>

using namespace std;

class Vehicle{
	protected:
		string ID;
		int top_speed;
		int num_wheels;
	public:
		Vehicle(string,int,int);
		~Vehicle();
		string Vehicle_GetID();
		int Vehicle_TopSpeed();
		int Vehicle_NumWheels();
		virtual void Vehicle_Info() = 0;
};

#endif

