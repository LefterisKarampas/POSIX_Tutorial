// bad_alloc standard exception
#include <iostream>
#include <exception>
using namespace std;

class myexception: public exception
{
	virtual const char* what() const throw()
	{
		return "My exception happened";
	}
} myex;

int main () {
	try
	{
		int* myarray= new int[100000000000];
	}
	catch (exception& e)
	{
		cout << "Standard exception: " << e.what() << endl;
	}

	try{
		throw myex;
	}
	catch(exception &e){
		cout << e.what() << endl;
	}
	return 0;
}