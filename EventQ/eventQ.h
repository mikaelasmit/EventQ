//
//  Created by Mikaela Smit on 30/10/2014.
//  Copyright (c) 2014 Mikael Smit. All rights reserved.
//

#ifndef eventQ_h							// If not defined then defines it  # are pre-compiler definitions
#define eventQ_h				

#include <stdio.h>							// Not sure what this one does - CHECK
#include <queue>							// Needed for the priorityQ

using namespace std;

// Miki Notes: 'const' stands for constant and keep the input elements unchanged
// [...] the position in which it is applied changed its usage 

//// --- DEFINE THE COMPARISON CLASS AND DEFINE OPERATOR() ---
struct timeComparison {bool operator()(const event *lhs, const event *rhs) const;};		

// Miki Note: could include the priority Q (at the moment in eventQ class) 
// [...] to make it globally available and use POP/PUSH/SIZE instead of ADD/GETTOP/SIZE


//// --- CREATING EVENTQ ---
class eventQ{
public:

	eventQ();								// Constructor
	//~eventQ();							// Jack included this deconstructor - CHECK USAGE OF DECONSTRUCTORS
	
	// Miki Note: This is elements of the priorityQ defined by Jack to be removed in next version
	// [...] consider using later on if needed
	void Add(event * const theEvent);		// Miki Note: This allows to make an event pointer to 'theEvent' used e.g. in iQ.push(theEvent)

	int Size() const;						

	event * GetTop();
		
	void RemoveTop();
	
	priority_queue<event*, vector<event*>, timeComparison> iQ;
	
};

#endif		

