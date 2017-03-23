#include <list>
#include <iostream>

using namespace std;

int main()
{
	list<int> mylist = {5,2,9};
	mylist.push_back(6);
	mylist.push_front(4);

	for(list<int>::iterator itr = mylist.begin();itr!=mylist.end();++itr)
		cout<< *itr<< " ";
	cout<< "\n";

	list<int>::iterator itr = find(mylist.begin(),mylist.end(),2);
	mylist.insert(itr,8);
	for(list<int>::iterator itr = mylist.begin();itr!=mylist.end();++itr)
		cout<< *itr<< " ";
	cout<< "\n";

	itr++;
	mylist.erase(itr);
	for(list<int>::iterator itr = mylist.begin();itr!=mylist.end();++itr)
		cout<< *itr<< " ";
	cout<< "\n";

	return 0;
}
