#include <iostream>

//Basically ‘const’ applies to whatever is on its immediate left 
//(other than if there is nothing there in which case it applies 
//to whatever is its immediate right)

using namespace std;

const char *Function1()
{ 
	return "Some text";
}

char *Function2()
{ 
	return "Some text";
}

class Example{
private:
	int x;
public:
	Example(int y):x(y){;};
	//void In() const{this->x++;}; // Invalid Read-Only function
	void Up(){this->x++;};
	friend void Change(const Example & E){
		//E.x++;
		cout << E.x << endl;
	}
};


int main(int argc, char const *argv[])
{
	
	const int x = 150; 	//integer constant 

	const int * y;		//variable pointer to a constant integer == int const * y;

	int * const p = new int; 		//constant pointer to a variable integer

	int const * const q = new int; //constant pointer to a constant integer

	//char * str1 = (Function1()[1] = 'a'); 	//Compile Error
	//char * str2 = (Function2()[1] = 'a'); 	//RunTime Error

	Example E(1);
	Change(E);
	delete p;
	delete q;
	return 0;
}