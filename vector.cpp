#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(10);
	vec.push_back(50);
	vec.push_back(40);

	vector<int>::iterator itr1=vec.begin();
	vector<int>::iterator itr2=vec.end();

	for(vector<int>::iterator itr=itr1;itr!=itr2;++itr)
		cout << *itr<< " ";

	sort(itr1,itr2);
	for(vector<int>::iterator itr=itr1;itr!=itr2;++itr)
		cout << *itr<< " ";
}
