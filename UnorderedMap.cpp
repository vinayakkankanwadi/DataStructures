#include <unordered_map>
#include <iostream>

using namespace std;

int main()
{

	unordered_map<char,string> day = {{'S',"Sunday"},{'M',"Mon"}};
	cout << day['S']<<endl;
	cout<< day.at('S')<<endl;

	day['W']="Wednesday";

	day.insert(make_pair('F',"Friday"));

	if(day.find('M')!=day.end())
		day['M'] = "Monday";

	if(day.find('T')==day.end())
		day['T'] = "Tue";

	for(unordered_map<char,string>::iterator itr=day.begin();itr!=day.end();++itr)
		cout<< itr->first <<" => "<< itr->second <<endl;
}
