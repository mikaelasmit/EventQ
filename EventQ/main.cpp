
#include <string>
#include <queue>
#include <iostream>
#include <ctime>

using namespace std;  // This is to make available the names of things defined in the standard library.

// Make an Event Class
 class event {
 public:
	 event() : time(0) {}; //class constructor
 	
 	double time; //define time - make private eventually.
 	void (*p_fun)(); //function pointer - make private eventually.
 };


 // Define operator() for comparison class
 struct timeComparison {
 	bool operator()(const event *lhs, const event *rhs) const {
 		return lhs->time > rhs->time;}};


// To be used with funciton pointer - to output 'Event' (e.g. tested) and related events
void theTest(){
	cout << "Tested." << endl;}
 

// To set up events getting dates
int HIVInfection(int min, int max){
	return rand()%(max-min+1)+min;}

int Death(int min, int max){
	return rand()%(max-min+1)+min;}

int Period(int min, int max){
	return rand()%(max-min+1)+min;}

// Run Main moedl
int main()
{
	srand(time(NULL));
	
	cout << "Hello, Mikaela!" << endl;

	//Declare our priority Q
	priority_queue<event*, vector<event*>, timeComparison> iQ;	


	//Create new event.
	event * HivTest = new event;
	HivTest->time = HIVInfection(7,13);
	HivTest->p_fun = &theTest;
	iQ.push(HivTest);
	

	// To give other events a date using random numbers between min and max
	int DeathNext;
	DeathNext=Death(1,10);

	int PeriodNext;
	PeriodNext=Period(2,20);


	// To check what these dates are to proof EventQ
	cout << "The date of HIV Infection is " << HivTest->time << " years" << endl;
	cout << "The date of Death is " << DeathNext << " years"<< endl;
	cout << "The date of the next period is " << PeriodNext << " years" << endl;
	
	cout << "The size of the event queue is " << iQ.size() << endl;
	
	//// Add events	
	//eventQ.push(HIVInfectionNext);
	//cout << "The next event will happen at " << eventQ.top() << endl;
	//
	//eventQ.push(DeathNext);
	//cout << "The next event will happen at " << eventQ.top() << endl;
	//
	//eventQ.push(PeriodNext);
	//cout << "The next event will happen at " << eventQ.top() << endl;

	//// Remove top events
	//eventQ.pop();
	//cout << "The next event will happen at " << eventQ.top() << endl;

	//eventQ.pop();
	//cout << "The next event will happen at " << eventQ.top() << endl;

	cout << iQ.top()->time << endl;
	
	iQ.top()->p_fun();
	
	cin.get();
	return 0;
}