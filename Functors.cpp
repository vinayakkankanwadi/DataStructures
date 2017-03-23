#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <int val>
void addVal (int i)
{
	cout<< val + i << endl;
}

void add2(int i)
{
	cout<< i+2<<endl;
}

int main()
{
	vector <int > vec = {2,3,4,5};
	for_each(vec.begin(),vec.end(),add2);
	for_each(vec.begin(),vec.end(),addVal<2>);
}
