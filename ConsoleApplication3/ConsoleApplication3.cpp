// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/* For clarity I'll write a few functions, 
   therefore these vars need to have a global scope */

char c; //Controls the user interaction
int floorWidth, floorLength; // in feet
int tileSideLength; // in inches
float tileCost; // in dollars and cents

void IntroduceYourself() {
	cout << "Hello World!\n";
	cout << "My name is Eduardo Fernandez" << endl;
}

void EnterValues() {
	//Then we ask the user to enter the values
	cout << "Enter the floor length (in feet): ";
	cin >> floorLength;

	cout << "Enter the floor width (in feet): ";
	cin >> floorWidth;
}

char Menu(){
	// This function asks the user for the value of c
	// which control the program flow
	cout << "Enter \"q\" to quit: " << endl;
	cout << "Enter \"1\" to compute the tiles needed: " << endl;

	cin >> c;
	return c;
}

int main()
{
	IntroduceYourself();

	do {
		c = Menu();
	} while ( (c != 'q') && (c != 'Q') );
	
    return 0;
}

