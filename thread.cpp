#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::mutex mtx;
std::condition_variable cv;
bool ready = false;
int count = 0;


void calc(int x, int y,char op){
	std::unique_lock<std::mutex> lck(mtx);
  	while (!ready) cv.wait(lck);
	switch(op){
		case '+': 
			cout << "Result: " << x + y << endl;
			break;
		case '-':
			cout << "Result: " << x - y << endl;
			break;
		case '*':
			cout << "Result: " << x * y << endl;
			break;
	}
	count++;
	ready = false;
}

void go() {
  	while(count < 3){
	  std::unique_lock<std::mutex> lck(mtx);
	  ready = true;
	  cv.notify_all();
	}
}



int main(int argc, char const *argv[])
{
	std::thread t1(calc,1,2,'+');
	std::thread t2(calc,1,2,'-');
	std::thread t3(calc,1,2,'*');

	cout << std::boolalpha << t1.joinable() << endl;
	std::thread g(go);
	t1.join();
	t2.join();
	t3.join();
	g.join();
	
	return 0;
}