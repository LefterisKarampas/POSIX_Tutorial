#include "Car.h"
#include "Moto.h"

int main(int argc, char const *argv[])
{
	Car c("Landa12",200,4);
	Car p("Porsche31",320,4);
	Moto m("GSXR21",300,2);
	bool t = c == p;
	cout << t << endl;
	return 0;
}