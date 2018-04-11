#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstddef>
#include <algorithm>

using namespace std;

// --- Algorithm that orders the vector --- //
void sort(vector<string> &v1) 
{
	// Sort elements in their range (start to finish)
	sort(v1.begin(), v1.end());  
}


// --- Algorithm that removes duplicate words --- //
void remove_duplicates(vector<string> &v1)
{
	// Considering that the vector is already in order
	v1.erase(unique(v1.begin(), v1.end()), v1.end()); // Remove duplicate words in their range (start to finish)
	
}

//separate words:
// receives lines with ';' from vector_line
void separate_words(string line, vector<string> &words)
{
    int i=0;
    int first=0;
    while (i<line.length())
        {if (line.at(i)== ';' || line.at(i)== ' ')
            {words.push_back(line.substr(first, i-first+1));
            first= i+2;
            i=i+2;}
        else
                i++;}
}

void vector_line(string line, vector<string> &words)  //returns a vector with words from line
{   int i=0;
    vector<int> index;  //vector that stores index of capital letters in the string
    if (!line.empty())
    /// make index vector ///
    {while (i< line.length())
            if (!(isupper(line.at(i)) || line.at(i)== ';' || line.at(i)== ' '))
               break;
            else if (line.find(';')== string::npos)
                words.push_back(line);
            else
                separate_words(line, words);


    }

    /// check for words in the index vector ///


}


//extract from dictionary
void extract(string dictionary_file_name, vector<string> &word_list_v)
    {
    string line;
    int number_of_words= word_list_v.size();
    ifstream dictionary(dictionary_file_name);

    // Open the file; exit program if the file couldn't be opened
    dictionary.open(dictionary_file_name);
    if (!dictionary.is_open())
        { cerr << "File " << "dictionary" << " not found !\n"; }

        while (!dictionary.eof())
        {   getline(dictionary, line);
            vector_line(line, word_list_v);
        }
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

	
	/* 
	cout << "Number of simple words" << " = " << word_list_v.size << endl;
	cout << "Sorting words " << "..." << endl;
	
	// Sort vector
	sort(word_list_v); 

	cout << "Removing duplicate words " << "..." << endl;

	// Delete repeated vector words
	remove_duplicates(word_list_v);

	cout << "Number of non-duplicate simple words" << " = " << word_list_v.size << endl;

	cout << "Saving words into file " << dictionary_file_name << " ..." << endl;

		// chamar funcao que faz istoo ...... (APAGAR)

	cout << "End of processing." << endl;
	*/
	return 0;}
