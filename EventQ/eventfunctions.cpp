//
//  Created by Mikaela Smit on 03/11/2014.
//  Copyright (c) 2014 Mikaela Smit. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "eventfunctions.h"

using namespace std;


//// --- FUNCTIONS FOR EVENTS ---
// --- HIV Testing ---
void TellMyHivDate(){									
	cout << "I just got an HIV test.  " << endl;}

double GetDateOfHIVInfection(int min, int max){			
	return rand()%(max-min+1)+min;}


// --- Date of Death ---
void RellMyDeathDate(){									
	cout << "I just died.  "  << endl;}

double GetDateOfDeath(int min, int max){				
	return rand()%(max-min+1)+min;}


// --- Birthday ---
void TellMyBirthDate(){									
	cout << "I just had my birthdya on the " << endl;}

double GetDateOfBirthday(int min, int max){				
	return rand()%(max-min+1)+min;}

	