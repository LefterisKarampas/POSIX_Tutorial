#include "Moto.h"

Moto::Moto(string id,int top,int wheels):Vehicle(id,top,wheels){
	cout << "Moto Created!" << endl;
}

Moto::~Moto(){

	cout << "Moto destroyed!" << endl;
}

void Moto::Vehicle_Info(){
	cout << "Moto with ID: " << this->ID << " which has " << this->num_wheels; 
	cout << " wheels and Top Speed " << this->top_speed << " Km/h" << endl; 
}

bool Moto::operator==(const Moto &A) const{
	return ((A.ID == this->ID)&&(A.num_wheels == this->num_wheels) &&
		(A.top_speed == this->top_speed));
};