// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
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
	floorLength *= 12; //converting to inches

	cout << "\nEnter the floor width (in feet): ";
	cin >> floorWidth;
	floorWidth *= 12; //converting to inches

	cout << "\nEnter the length of one the tiles (in inches): ";
	cin >> tileSideLength;

	cout << "\nEnter the cost of one the tiles (in dollar and cents): ";
	cin >> tileCost;
}

void calcAndShowValues(){
	//This function computes the values
	int tileArea = pow(tileSideLength, 2); //tile area (inches)

	int area = floorLength * floorWidth; // floor area (feet)

	int intpartLength = (int) (floorLength / tileSideLength); // integer part of (length / tile side) division
	int intpartWidth = (int) (floorWidth / tileSideLength);   // integer part of (width / tile side) division

	int tilesTrimmed = intpartLength + intpartWidth + 1;
	int tilesNotTrimmed = intpartLength * intpartWidth;

	int tilesRequired = tilesTrimmed + tilesNotTrimmed;

	cout << "To tile a floor with an area of " << area/144 << " feet^2" << endl;
	cout << tilesRequired << " tiles are required" << endl;
	cout << tilesNotTrimmed << " tiles not trimmed and " 
		 << tilesTrimmed << " trimmed tiles" << endl;
	cout << "For a total of $" << tilesRequired * tileCost << endl;
}

char Menu(){
	// This function asks the user for the value of c
	// which control the program flow
	cout << "Enter \"q\" to quit: " << endl;
	cout << "Enter \"1\" to try with another values: " << endl;

	cin >> c;
	system("CLS");
	return c;
}

int main()
{
	IntroduceYourself();
	EnterValues();
	calcAndShowValues();

	do {
		c = Menu();
		if (c == '1') {
			EnterValues();
			calcAndShowValues();
			continue;
		}
	} while ( (c != 'q') && (c != 'Q') );
	
    return 0;
}

