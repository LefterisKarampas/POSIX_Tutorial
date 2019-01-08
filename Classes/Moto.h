#ifndef _MOTO_H_
#define _MOTO_H_
#include "Vehicle.h"

class Moto : public Vehicle{
public:
	Moto(string,int,int);
	~Moto();
	void Vehicle_Info();
	bool operator==(const Moto &) const;
};

#endif
