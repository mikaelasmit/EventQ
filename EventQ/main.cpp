//
//	Mikaela Event Queue Model
//
//  Created by Mikaela Smit on 30/10/2014.
//  Copyright (c) 2014 Mikael Smit. All rights reserved.
//

#include <string>
#include <queue>
#include <iostream>
#include <ctime>
#include "event.h"
#include "eventQ.h"

using namespace std;				// This is to make available the names of things defined in the standard library.


//// --- FUNCTIONS RELATED TO EVENTS
// Miki Notes: using funciton pointer to output 'Event' (e.g. I just got tested) 
// [...] and related events when an event is called in eventQ

void theTest(){										// --- HIV Testing ---
	cout << "'I just got an HIV test'." << endl;}

void theDeath(){									// --- Death ---
	cout << "'I just died'." << endl;}

void theBirthday(){									// --- Birthday ---
	cout << "'I just had my birthday'." << endl;}
 

//// --- GETTING DATES FOR EVENTS ---
 int HIVInfection(int min, int max){				// --- HIV Testing ---
	return rand()%(max-min+1)+min;}

int Death(int min, int max){						// --- Death ---
	return rand()%(max-min+1)+min;}

int Birthday(int min, int max){						// --- Birthday ---
	return rand()%(max-min+1)+min;}


//// ---  RUN THE MAIN MODEL ---
int main()
{
	srand(time(NULL));								// Random Number generator using PC time
	
	cout << "Hello, Mikaela!" << endl;				// Check if model is running

	
	//// --- CREATING EVENTS AND ADDING THEM (WITH TIME) TO EVENTq
	event * HivTest = new event;					// --- HIV Testing ---
	HivTest->time = HIVInfection(0,5);
	HivTest->p_fun = &theTest;
	
	event * DeathDate = new event;					// --- Death ---
	DeathDate->time = Death(7,13);
	DeathDate->p_fun = &theDeath;
	
	event * BirthdayDate = new event;
	BirthdayDate->time = Birthday(1,5);
	BirthdayDate->p_fun = &theBirthday;				// --- Birthday ---


	//// --- EVENT QUEUE ---
	eventQ mainQ;									// Define event queue

	mainQ.Add(HivTest);								// Add HIVTest to queue
	mainQ.Add(DeathDate);							// Add Death to queue
	mainQ.Add(BirthdayDate);						// Add Birthday to queue

	
	//// --- GIVE OUTPUT OF QUEUE AS IT PROGRESSES ---

	//// To check what these dates are to proof EventQ
	cout << endl << "The date of HIV Infection is at " << HivTest->time << " years after start of model." << endl;
	cout << "The date of Death is " << DeathDate->time << " years after start of model."<< endl;
	cout << "The date of my next birthday is " << BirthdayDate->time << " years after start of model." << endl;

	// Lets check the queue
	cout << endl << "The event at the top of the queue will ocurr  " << mainQ.GetTop()->time << " years after start of model." << endl;
	cout << "The size of the event queue is " << mainQ.Size() << endl;

	cout << endl << "The next event has just ocurred.  It is " << mainQ.GetTop()->time << " years after the start of the model and "; mainQ.GetTop()-> p_fun();
	cout << "The following top event has just been removed from the event queue "; mainQ.GetTop()-> p_fun(); cout  << endl;
	mainQ.RemoveTop();	
	cout << endl << "The next event has just ocurred.  It is " << mainQ.GetTop()->time << " years after the start of the model and "; mainQ.GetTop()-> p_fun();
	cout << "The following top event has just been removed from the event queue "; mainQ.GetTop()-> p_fun(); cout  << endl;
	mainQ.RemoveTop();	
	cout << endl << "The next event has just ocurred.  It is " << mainQ.GetTop()->time << " years after the start of the model and "; mainQ.GetTop()-> p_fun();
		
	cin.get();
	return 0;
}