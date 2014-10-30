
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

class eventQ {
public:
	
	void Add(event * const theEvent);

	size_t Size() const;		//size_t is a type able to represent the size of any object in bytes

	event * GetTop();
		
	void RemoveTop();
	
	priority_queue<event*, vector<event*>, timeComparison> iQ;
	//Can include a currentTime;
	
};


void eventQ::Add(event * const theEvent)
{
	iQ.push(theEvent);
	
	return;
}

event * eventQ::GetTop()
{
	event * theEvent = iQ.top();
	return theEvent;

}

//Define Size()								// Note that this is used differently in COUT statements than POP and TOP
size_t eventQ::Size() const					//const after a function declaration means the function is not allowed to change any class members.
{
	return iQ.size();
}

// Define Queue Size
void eventQ::RemoveTop() 
{
	iQ.pop();
}




// To be used with funciton pointer - to output 'Event' (e.g. tested) and related events
void theTest(){
	cout << "I just got tested." << endl;}

void theDeath(){
	cout << "I just died." << endl;}

void theBirthday(){
	cout << "I just had my birthday." << endl;}
 

// To set up events getting dates
int HIVInfection(int min, int max){
	return rand()%(max-min+1)+min;}

int Death(int min, int max){
	return rand()%(max-min+1)+min;}

int Birthday(int min, int max){
	return rand()%(max-min+1)+min;}

// Run Main moedl
int main()
{
	srand(time(NULL));
	
	cout << "Hello, Mikaela!" << endl;

	
	//Create new event.
	event * HivTest = new event;
	HivTest->time = HIVInfection(0,5);
	HivTest->p_fun = &theTest;
	
	event * DeathDate = new event;
	DeathDate->time = Death(7,13);
	DeathDate->p_fun = &theDeath;
	
	event * BirthdayDate = new event;
	BirthdayDate->time = Birthday(1,5);
	BirthdayDate->p_fun = &theBirthday;

	eventQ mainQ;			// define event queue

	
	mainQ.Add(HivTest);		// Add HIVTest to queue
	mainQ.Add(DeathDate);		// Add HIVTest to queue
	mainQ.Add(BirthdayDate);		// Add HIVTest to queue

	cout << mainQ.GetTop()->time << endl;	// Outout the event at the top of the queue
	
	
	// To check what these dates are to proof EventQ
	cout << "The date of HIV Infection is " << HivTest->time << " years" << endl;
	cout << "The date of Death is " << DeathDate->time << " years"<< endl;
	cout << "The date of my next birthday is " << BirthdayDate->time << " years" << endl;


	// To make the EventQ happen	
	cout << "The size of the event queue is " << mainQ.Size() ;
	cout << endl << "The next event will happen at " << mainQ.GetTop()->time << " years and will be "; mainQ.GetTop()-> p_fun();
	
	mainQ.RemoveTop();
	cout << "The next event will happen at " << mainQ.GetTop()->time << " years and will be "; mainQ.GetTop()-> p_fun();

	mainQ.RemoveTop();
	cout << "The next event will happen at " << mainQ.GetTop()->time << " years and will be "; mainQ.GetTop()-> p_fun();
		

	

	

	cin.get();
	return 0;
}