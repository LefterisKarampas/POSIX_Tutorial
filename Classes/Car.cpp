#include "Car.h"

Car::Car(string id,int top,int wheels):Vehicle(id,top,wheels){
	cout << "Car Created!" << endl;
}

Car::~Car(){

	cout << "Car destroyed!" << endl;
}

void Car::Vehicle_Info(){
	cout << "Car with ID: " << this->ID << " which has " << this->num_wheels; 
	cout << " wheels and Top Speed " << this->top_speed << " Km/h" << endl; 
}

bool Car::operator==(const Car &A) const{
	return ((A.ID == this->ID)&&(A.num_wheels == this->num_wheels) &&
		(A.top_speed == this->top_speed));
};