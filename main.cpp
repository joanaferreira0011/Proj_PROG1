#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstddef>
#include <algorithm>

using namespace std;

// --- Algorithm that orders the vector --- 
void sort(vector<string> &v1) 
{
	// Sort elements in their range (start to finish)
	sort(v1.begin(), v1.end());  
}


// --- Algorithm that removes duplicate words ---
void remove_duplicates(vector<string> &v1)
{
	// Considering that the vector is already in order
	v1.erase(unique(v1.begin(), v1.end()), v1.end()); // Remove duplicate words in their range (start to finish)
	
}

void extract(string dictionary_file_name, vector<string> &word_list_v)
    {
    string line;
    int number_of_words=0;
    ifstream dictionary(dictionary_file_name);

    // Open the file; exit program if the file couldn't be opened
    dictionary.open(dictionary_file_name);
    if (!dictionary.is_open())
        { cerr << "File " << "dictionary" << " not found !\n"; }

    while (getline(dictionary, line))
    {if (! (any_of( begin( line ), end( line ), []( char c ) { return ( islower( c ) ); } ) )) //check if uppercase
        {word_list_v.push_back(line);
        number_of_words++;}}


    cout<< number_of_words;}


int main() {
    string dictionary_file_name;
    string word_list_file_name;
    ifstream word_list;
    string line;
    vector<string> word_list_v;

    //INTERFACE HEADLINE
    cout << "EXTRACTION OF WORD LIST FROM DICTIONARY" << endl <<"======================================="<< endl;

    // Read the file name //
    cout << "Dictionary file ? ";
    cin >> dictionary_file_name;


    extract(dictionary_file_name,word_list_v);
    // Read the word_list file name //
    cout << "Word list file ? ";
    cin >> word_list_file_name;

    cout << "Extracting simple words from file" << dictionary_file_name<< endl<< "," << "begining with letter...";

	return 0;}