//
//  Created by Mikaela Smit on 30/10/2014.
//  Copyright (c) 2014 Mikaela Smit. All rights reserved.
//

#ifndef event_h					// If not defined then defines it  # are pre-compiler definitions
#define event_h					

#include <stdio.h>

 class event {
 public:

	event();					//class constructor
 	
 	double time;	

 	void (*p_fun)();			// Function pointer - when an event is called in the Q it can point to what functions need to be executed
								// [...] e.g. If patient gets pos HIVTest tell him to schedule GP appointment
								// Jack notes: - make private eventually. - function to what to excexute when event happens
};

#endif 





