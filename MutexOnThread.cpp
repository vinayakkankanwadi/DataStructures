#include<thread>
#include<string>
#include<mutex>
#include <iostream>

using namespace std;

std::mutex mu;

void ccout(string msg,int id)
{
	mu.lock();
	cout<< msg<<id<<endl;
	mu.unlock();
}

void function1()
{
	for(int i=0;i>-10;i--)
		ccout(string("From t1"),i);
}

int main()
{
	std::thread t1(function1);

	for (int i=0;i<10;i++)
		ccout(string("From main"),i);

	t1.join();
}
