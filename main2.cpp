﻿// Program 2 - Playing with words

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstddef>
#include <algorithm>

using namespace std;


int main()
{
	int option;

	ifstream arq("procdic");



	cout << "Choose one of the following options: " << endl; // Shows on the screen the available options
	cout << "Option 1: Verify that the word belongs to the word list " << endl;
	cout << "Option 2: Guess a randomly chosen word from the list " << endl;
	cout << "Option 3: Show all words with a certain set of letters given by the user " << endl;
	cout << "Option 4: A set of letters are given, for the user to construct a word and check if it belongs to the list " << endl;
	cout << "Option 5: Ask the user for a string with wildcard characters, and shows all words matching the string requested " << endl;

	cin >> option; // The user enters an option

		switch (option) //incomplete
		{
		case 1:
			function1;
			break;
		case 2:
			function2;
			break;
		case 3:
			function3;
			break;
		case 4:
			function4;
			break;
		case 5:
			function5;
			break;
		default:
			cout << "Option is invalid" << endl;
                }


	return 0;}

