#include <map>
#include <iostream>

using namespace std;

int main()
{

	map<char,int> mymap;
	mymap.insert(pair<char,int>('a',100));
	mymap.insert(make_pair('z',100));

	map<char,int>::iterator it = mymap.begin();
	mymap.insert(it,pair<char,int>('b',300));

	it = mymap.find('z');
	
	for (it = mymap.begin();it!=mymap.end();it++)
		cout<< (*it).first << " => " << (*it).second<<endl;

}
