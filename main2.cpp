// Program 2 - Playing with words

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstddef>
#include <algorithm>

using namespace std;

void uppercase_letters(string &word)
{
	// Will make the entire string in uppercase

	transform(word.begin(), word.end(), word.begin(), toupper);
}

void find_word(vector <string> v1)
{
	string insert_word;
	cin >> insert_word;

	uppercase_letters(insert_word);

	if (binary_search(v1.begin(), v1.end(), insert_word)) // receives an ordered vector and searches for the given word
	{
		cout << "The word is found in the dictionary " << endl;
	}
	else
	{
		cout << "The word is not found in the dictionary " << endl;
	}
}  //Option 1

void word_guess(vector <string> v1)
{
	// Choose a random word and show
	srand(time(0));
	int indicewordrandom = rand() % v1.size();
	string wordrandom = v1.at(indicewordrandom);

	cout << "A random word from the dictionary was chosen " << endl;

	string shuffledword;

	shuffledword = wordrandom;
	random_shuffle(shuffledword.begin(), shuffledword.end()); // Shuffle one word letters

	cout << "Shuffling the letters: " << shuffledword << endl;

	cout << "Guess the word! " << endl;
	string userword;


	for (int i = 1; i <= 3; i++) // The user has three attempts
	{
		cin >> userword; // the user enters the word
		uppercase_letters(userword); // Make the letters capital

		if (userword == wordrandom) // Hit the word
		{
			cout << "Congratulations, that's the word " << endl;
			break;
		}
		else
		{

			if (i >= 3)
			{
				cout << "Wrong! Try the next! " << endl;
			}
			else {
				cout << "Wrong! Try again " << endl;
				cout << "You have " << 3 - i << " attemps" << endl;
			}
		}
	}
} //Option2


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

