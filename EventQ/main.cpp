//
//	Mikaela Event Queue Model
//
//  Created by Mikaela Smit on 30/10/2014.
//	Modified by Mikaela Smit on 05/11/2014.  
//  Copyright (c) 2014 Mikael Smit. All rights reserved.
//


// To Do List
// 1. Develop MakingPatients to include simple distributions (e.g. age from uniform, etc) - DONE
// 2. Develop EventQ and play around with it - DONE
// 3. Insert events into the EventQ, e.g. HIV Infection, Death and Birthdays - DONE
// 4. Seperate EventQ into deifferent .h and .cpp files - TOOK A FILE BUT DONE
// 5. Insert a global time into the model to record time - DONE
// 6. Add global time to EventQ - DONE
// 6. Make birthdays recurrent using function pointers and global time - DONE
// 7. Merge MakingPatients and EventQ code to make events happen to two different patients
// 8. Link death to age using a simple linear equation (increased age=increased death)
// 9. Give patients a birth date from age
// 10. Include better mortality function 
// 10. Add a stop time to the model
// 11. Remove repeated queue code from main() in EventQ and make it into a self-contained loop until model stop time
// 12. Check that age distribution and mortality fits Kenyan data.  
 

#include <string>
#include <queue>
#include <iostream>
#include <ctime>
#include "event.h"
#include "eventQ.h"
#include "eventfunctions.h"

using namespace std;									


// Miki Notes: When defining pointers in main file: 
// 1. Define pointer outside the 'main' function						e.g double *p_GT;	
// 2. Define the thing it is pointing to inside the 'main' function		e.g. double GlobalTime=0;
// 3. define the location the pointer is pointing to					e.g. p_GT=&GlobalTime;	


//// --- FUNCTIONS RELATED TO EVENTS ---
double *p_GT;														// Pointer to global time
priority_queue<event*, vector<event*>, timeComparison> *p_PQ;		// Pointer to event queue so as to be able to push-in/pop-out new events that are ocurreing
																	// [...] as a result of 'primary' events in the queue, e.g. recurrent birthdays


//// ---  RUN THE MAIN MODEL ---
int main()
{

	double GlobalTime=0;											// Define Global Time and set it to 0 at the beginning of the model
	p_GT=&GlobalTime;												// Define the location the pointer to Global time is pointing to
	
	srand(time(NULL));												// Random Number generator using PC time
	
	cout << "Hello, Mikaela!" << endl;								// Check if model is running
	priority_queue<event*, vector<event*>, timeComparison> iQ;
	
	p_PQ=&iQ;														// Define pointer to priority queue
	
	//// --- ADD EVENTS TO EVENT_Q ---	
	event * HivTest = new event;									// --- HIV Testing ---
	HivTest->time = GetDateOfHIVInfection(2,4);
	HivTest->p_fun = &TellMyHivDate;
	
	event * DeathDate = new event;									// --- Death ---
	DeathDate->time = GetDateOfDeath(7,13);
	DeathDate->p_fun = &TellMyDeathDate;

	event * BirthdayDate = new event;								// --- Birthday ---
	BirthdayDate->time = GetDateOfBirthday(1,2);
	BirthdayDate->p_fun = &TellMyBirthDate;				
	
	
	
	//// --- EVENT QUEUE ---
	//eventQ mainQ;													// Define event queue
	//eventQ::iQ mainQ;
	
	iQ.push(HivTest);												// Add HIVTest to queue
	iQ.push(DeathDate);												// Add Death to queue
	iQ.push(BirthdayDate);											// Add Birthday to queue

	
	// --- GIVE OUTPUT OF QUEUE AS IT PROGRESSES ---

	// To check what these dates are to proof EventQ
	cout << "Lets check the dates given to primary events: " << endl;
	cout << endl << "The date of HIV Infection is " << HivTest->time << " years after the start of model." << endl;
	cout << "The date of Death is " << DeathDate->time << " years after the start of model."<< endl;
	cout << "The date of my next birthday is " << BirthdayDate->time << " years after the start of model." << endl;

	// Lets check the queue
	cout << endl <<"Characteristics of the event queue:" << endl;
	cout << "The event at the top of the queue will ocurr  " << iQ.top()->time << " years after the start of model." << endl;
	cout << "The size of the event queue is " << iQ.size() << endl;
	
	// Lets check global time
	cout << endl << "The Global Time at the start of the model is " << GlobalTime << endl;
	GlobalTime=iQ.top()->time;										// Update Global time to make functions below correct

	// Lets run event queue and output it
	// Miki Note: always update Global Time at the right point in the event queue to ensure that p_GT
	// [...] is using the right Global Time in the functions that are called when an event happens.  
	cout << endl << "An event has just ocurred.  " << endl;
	cout << "It is " << iQ.top()->time << " years after the start of the model and "; iQ.top()-> p_fun();
	GlobalTime=iQ.top()->time;
	cout << endl << "Global Time after this event is " << GlobalTime << endl;
	
	iQ.pop();
	cout << endl << "An event has been removed from the queue.  " << endl;

	GlobalTime=iQ.top()->time;										// Update Global time to make functions below correct
	cout << endl << "An event has just ocurred.  " << endl;
	cout << "It is " << iQ.top()->time << " years after the start of the model and "; iQ.top()-> p_fun();
	GlobalTime=iQ.top()->time;
	cout << endl << "Global Time after this event is " << GlobalTime << endl;
	
	iQ.pop();
	cout << endl << "An event has been removed from the queue.  " << endl;

	GlobalTime=iQ.top()->time;										// Update Global time to make functions below correct
	cout << endl << "An event has just ocurred.  " << endl;
	cout << "It is " << iQ.top()->time << " years after the start of the model and "; iQ.top()-> p_fun();
	GlobalTime=iQ.top()->time;
	cout << endl << "Global Time after this event is " << GlobalTime << endl;
	
	iQ.pop();
	cout << endl << "An event has been removed from the queue.  " << endl;

	GlobalTime=iQ.top()->time;										// Update Global time to make functions below correct
	cout << endl << "An event has just ocurred.  " << endl;
	cout << "It is " << iQ.top()->time << " years after the start of the model and "; iQ.top()-> p_fun();
	GlobalTime=iQ.top()->time;
	cout << endl << "Global Time after this event is " << GlobalTime << endl;
	
	
	cin.get();
	return 0;
}