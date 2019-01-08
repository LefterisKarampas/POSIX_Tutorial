#ifndef _CAR_H_
#define _CAR_H_

#include "Vehicle.h"

class Car : public Vehicle{
public:
	Car(string,int,int);
	~Car();
	void Vehicle_Info();
	bool operator==(const Car &) const;
};

#endif