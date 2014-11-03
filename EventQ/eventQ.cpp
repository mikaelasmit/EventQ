//
//  Created by Mikaela Smit on 30/10/2014.
//  Copyright (c) 2014 Mikael Smit. All rights reserved.
//

#include "event.h"
#include "eventQ.h"

//// --- USE TIME COMPARISON AND OPERATOR ---
bool timeComparison::operator()(const event *lhs, const event *rhs) const{
	return lhs->time > rhs->time;}
 	
//// --- CLASS (EVENTQ) CONSTRUCTOR ---- 
eventQ::eventQ()
{
	// Miki Note: can use this to define dummy values - see patients.cpp
}

// Miki Notes: Jack also included a deconstructor - CHECK USAGE 
// Define deconstructor 
// eventQ::~eventQ()
// {}


//// --- FUNCTIONS TO ASSIGN ELEMENTS OF EVENTQ ---
// Miki Notes: these self-defined elements are used by Jack - remove in next version!
void eventQ::Add(event * const theEvent)		// --- Make an ADD event element ---
{
	iQ.push(theEvent);
	return;
;}

event * eventQ::GetTop()						// --- Make a TOP event element ---
{
	event * theEvent = iQ.top();
	return theEvent;
;}
											
int eventQ::Size() const						// --- Make a SIZE event element ---				
{												// Note that this is used differently in COUT statements than POP and TOP
	return iQ.size();
;}

void eventQ::RemoveTop()						// --- Make a POP event element ---	
{
	iQ.pop();
;}
