
#include <string>
#include <queue>
#include <iostream>
#include <ctime>

using namespace std;  // This is to make available the names of things defined in the standard library.

int HIVInfection(int min, int max)
{
	return rand()%(max-min+1)+min;
}

int Death(int min, int max)
{
	return rand()%(max-min+1)+min;
}

int Period(int min, int max)
{
	return rand()%(max-min+1)+min;
}


int main()
{
	srand(time(NULL));
	
	cout << "Hello, Mikaela!" << endl;
	
	// To give each event a date using random numbers between min and max
	int HIVInfectionNext;
	HIVInfectionNext=HIVInfection(7,13);

	int DeathNext;
	DeathNext=Death(1,10);

	int PeriodNext;
	PeriodNext=Period(2,20);

	// To check what these dates are to proof EventQ
	cout << "The date of HIV Infection is " << HIVInfectionNext << " years" << endl;
	cout << "The date of Death is " << DeathNext << " years"<< endl;
	cout << "The date of the next period is " << PeriodNext << " years" << endl;

	
	// Event Q definition
	priority_queue<double, vector<double>, greater<double> > eventQ;

	// Add events	
	eventQ.push(HIVInfectionNext);
	cout << "The next event will happen at " << eventQ.top() << endl;
	
	eventQ.push(DeathNext);
	cout << "The next event will happen at " << eventQ.top() << endl;
	
	eventQ.push(PeriodNext);
	cout << "The next event will happen at " << eventQ.top() << endl;

	// Remove top events
	eventQ.pop();
	cout << "The next event will happen at " << eventQ.top() << endl;

	eventQ.pop();
	cout << "The next event will happen at " << eventQ.top() << endl;
	
	cin.get();
	return 0;
}