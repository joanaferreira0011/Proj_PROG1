// Program 2 - Playing with words

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstddef>
#include <algorithm>
#include <time.h>

using namespace std;

// -------------- Function prototypes -------------- // 

vector<string> getwords(string file_name);
void uppercase_letters(string &word);
void frequency(vector<string> v1, vector<int> &frequencyvector, size_t &bigword);
int lowerfrequency(vector<int> frequencyvector);
bool invalid_input(string word, string word_given);
void find_word(vector <string> v1);
void word_guess(vector <string> v1);
void searchwords(vector <string> v1);
void randomletters(vector <string> v1);
void menu(vector <string> vectorwords);
void usercontinue(vector <string> v1);
bool wildcardMatch(const char *str, const char *strWild);
void option5(vector<string> words, int size);

// ------------------------------------------------- //

int main()
{
	cout << " ............ " << endl;
	cout << " ..  MENU  .. " << endl;
	cout << " ............ " << endl;
	
	cout << "Enter the name of the file, which contains the list of words: ";
	string file_name;
	getline(cin, file_name);
	
	vector<string> vectorwords = getwords(file_name);
	
	cout << "Choose one of the following options: " << endl; // Shows on the screen the available options
	cout << "Option 1: Verify that the word belongs to the word list " << endl;
	cout << "Option 2: Guess a randomly chosen word from the list " << endl;
	cout << "Option 3: Show all words with a certain set of letters given by the user " << endl;
	cout << "Option 4: A set of letters are given, for the user to construct a word and check if it belongs to the list " << endl;
	cout << "Option 5: Ask the user for a string with wildcard characters, and shows all words matching the string requested " << endl;
	cout << "Option 6: Exit the program" << endl;

	menu(vectorwords);

	usercontinue(vectorwords); // For if the user wants to continue

	return 0;}

// -------------- Input File Name ------------------ //

vector<string> getwords(string file_name)  //input a file name, opens file a returns a vector with words from file
{
	string line;
	ifstream dictionary(file_name);
	vector<string> words;

	// Open the file; exit program if the file couldn't be opened
	// dictionary.open(dictionary_file_name);
	if (!dictionary.is_open())
	{
		cerr << "File " << "dictionary" << " not found !\n";
		exit(1);
	}

	while (!dictionary.eof())
	{
		getline(dictionary, line);
		words.push_back(line);
	}

	return words;
}


// --------- Functions used in options --------- //

void uppercase_letters(string &word)
{
	// Will make the entire string in uppercase

	transform(word.begin(), word.end(), word.begin(), toupper);
}

void frequency(vector<string> v1, vector<int> &frequencyvector, size_t &bigword)
{
	//Vector with the frequency of each letter
	for (size_t i = 0; i < v1.size(); i++)
	{
		//Size of the biggest word
		if (bigword < v1[i].length())
			bigword = v1[i].length();

		for (size_t j = 0; j < v1[i].length(); j++)
		{
			frequencyvector[v1[i][j] - 65] = frequencyvector[v1[i][j] - 65]++;
		}
	}
}

int lowerfrequency(vector<int> frequencyvector)
{
	// Letters with lower frequency	
	int min = frequencyvector[0];

	for (size_t i = 1; i < frequencyvector.size(); i++)
	{
		if (min > frequencyvector[i])
			min = frequencyvector[i];
	}

	return min;
}

bool invalid_input(string word, string word_given)
{
	// Make sure the user uses only the given letters or a subset of them

	for (size_t i = 0; i < word.size(); i++)
	{
		if (word_given.find_first_of(word[i]) != -1)
			word_given.erase(word_given.find_first_of(word[i]), 1);
		else
			return true;
	}

	return false;
}

bool wildcardMatch(const char *str, const char *strWild)
{
	// We have a special case where string is empty ("") and the mask is "*".
	// We need to handle this too. So we can't test on !*str here.
	// The loop breaks when the match string is exhausted.
	while (*strWild)
	{
		// Single wildcard character
		if (*strWild == '?')
		{
			// Matches any character except empty string
			if (!*str)
				return false;
			// OK next
			++str;
			++strWild;
		}
		else if (*strWild == '*')
		{
			// Need to do some tricks.
			// 1. The wildcard * is ignored.
			// So just an empty string matches. This is done by recursion.
			// Because we eat one character from the match string,
			// the recursion will stop.
			if (wildcardMatch(str, strWild + 1))
				// we have a match and the * replaces no other character
				return true;
			// 2. Chance we eat the next character and try it again,
			// with a wildcard * match. This is done by recursion.
			// Because we eat one character from the string,
			// the recursion will stop.
			if (*str && wildcardMatch(str + 1, strWild))
				return true;
			// Nothing worked with this wildcard.
			return false;
		}
		else
		{
			// Standard compare of 2 chars. Note that *str might be 0 here,
			// but then we never get a match on *strWild
			// that has always a value while inside this loop.
			if (toupper(*str++) != toupper(*strWild++))
				return false;
		}
	}
	// Have a match? Only if both are at the end...
	return !*str && !*strWild;
}

// --------- Options --------- //

void find_word(vector <string> v1)
{
	cout << "Enter a word, to see if it is in the dictionary ";

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
	srand((int)time(NULL));
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

void searchwords(vector <string> v1)
{
	// Displays on the screen the words that are possible with the letters requested

	// user inserts the letter set
	string stringletters;
	cout << "Enter a set of letters to identify the words: ";
	cin >> stringletters;

	uppercase_letters(stringletters);

	vector <string> validwords; // vector containing words that can be formed

	sort(stringletters.begin(), stringletters.end()); // Sort string

	do
	{
		if (binary_search(v1.begin(), v1.end(), stringletters))  // Search Words 
			validwords.push_back(stringletters); // Put in vector

	} while (next_permutation(stringletters.begin(), stringletters.end())); // Make permutations between letters

																			// Show Words

	if (validwords.size() == 0)
		cout << "There are no words in the dictionary with this set of letters" << endl;
	else
	{
		cout << "Words from the dictionary that are formed with the indicated letters" << endl;

		for (size_t i = 0; i < validwords.size(); i++)
			cout << validwords.at(i) << endl;
	}
} //Option3

void randomletters(vector <string> v1)
{
	vector<int> frequencyvector(26); //Vector with the frequency of each letter
	vector<char> larger_set;
	int min, n;
	size_t	bigword = 0;
	char letter = 'A';
	string word, word_given;

	frequency(v1, frequencyvector, bigword);

	min = lowerfrequency(frequencyvector);

	for (size_t i = 0; i < frequencyvector.size(); i++)
	{
		int y = frequencyvector[i] * 2 / min;

		for (int d = 0; d <= y; d++)
			larger_set.push_back(char(letter + i));
	}

	srand((int)time(NULL));

	n = rand() % (bigword - 1); //Number of letter the word is going to have

	for (int i = 0; i <= n; i++)
	{
		int j = rand() % (larger_set.size() - 1);
		word_given = word_given + larger_set[j];
		larger_set.erase(larger_set.begin() + j);
	}

	cout << word_given;

	cout << endl << "Word: ";

	cin >> word;

	uppercase_letters(word);

	while (invalid_input(word, word_given))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Not a valid word!" << endl;
		cout << "Word: ";
		cin >> word;
		uppercase_letters(word);
	}


	if (find(v1.begin(), v1.end(), word) != v1.end())
		cout << "Word found!" << endl;
	else
		cout << "Word not found!" << endl;

} //Option4

void option5(vector<string> words, int size)
{ string wild;
		vector<string> possible_words;
		cout << "Word?: ";
		cin >> wild;
		int i=0;
		while(i< size)
		{if (wildcardMatch ((words.at(i)).c_str(), wild.c_str()))
			{possible_words.push_back(words[i]);
				i++;}
			else
				i++;}
		
		if (possible_words.size()==0)
			cout << "There are no matches.\n";
		else
		{   size_t a=0;
			cout<< "Match with: "<<endl;
			while(a< possible_words.size())
			{cout<<possible_words.at(a)<< endl;
				a++;}
			
		}} //Option5
	
// ---------------  MENU -------------------------- //

void menu(vector <string> vectorwords) // The user enters an option
{

	int option;
	cout << "Enter option ";
	cin >> option; // The user enters an option

	switch (option)
	{
	case 1:
		cout << " ---- OPTION 1 ---- " << endl;
		find_word(vectorwords);
		break;
	case 2:
		cout << " ---- OPTION 2 ---- " << endl;
		word_guess(vectorwords);
		break;
	case 3:
		cout << " ---- OPTION 3 ---- " << endl;
		searchwords(vectorwords);
		break;
	case 4:
		cout << " ---- OPTION 4 ---- " << endl;
		randomletters(vectorwords);
		break;
	case 5:
		cout << " ---- OPTION 5 ---- " << endl;
		option5(vectorwords, vectorwords.size());
		break;
	case 6:
		cout << " End of program " << endl;
		exit(1);
	default:
		cout << "Option is invalid" << endl;
	}
}

void usercontinue(vector <string> v1)
{
	char option;

	cout << "Do you want to continue? Enter 'Y'es or 'N'o ";
	cin >> option;

	while (cin.fail() || option != 'Y' && option != 'y' && option != 'N' && option != 'n')
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid option " << endl;
		cout << "Do you want to continue? Enter 'Y'es or 'N'o ";
		cin >> option;
	}

	while (option == 'Y' || option == 'y')
	{
		menu(v1);
		cout << "Do you want to continue playing? 'Y'es or 'N'o? ";
		cin >> option;

		while (cin.fail() || option != 'Y' && option != 'y' && option != 'N' && option != 'n')
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid option " << endl;
			cout << "Do you want to continue? Enter 'Y'es or 'N'o ";
			cin >> option;
		}
	}
}
