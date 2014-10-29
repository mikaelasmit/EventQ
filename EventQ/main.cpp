
#include <string>
#include <queue>
#include <iostream>

using namespace std;  // This is to make available the names of things defined in the standard library.

int main()
{
	cout << "Hello, Mikaela!" << endl;
	
	priority_queue<double, vector<double>, greater<double> > eventQ;
	
	double HIVInfection = 10;
	
	eventQ.push(HIVInfection);
	
	cout << "The next event will happen at " << eventQ.top() << endl;
	
	double Death = 20;
	
	eventQ.push(Death);
	
	cout << "The next event will happen at " << eventQ.top() << endl;
	
	double Period = 5;
	
	eventQ.push(Period);
	
	cout << "The next event will happen at " << eventQ.top() << endl;

	cin.get();

	return 0;
}