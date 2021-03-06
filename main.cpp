#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstddef>
#include <algorithm>

using namespace std;

// --- Algorithm that orders the vector --- //
void sort(vector<string> &v1) {
	// Sort elements in their range (start to finish)
	sort(v1.begin(), v1.end());
}


// --- Algorithm that removes duplicate words --- //
void remove_duplicates(vector<string> &v1) {
	// Considering that the vector is already in order
	v1.erase(unique(v1.begin(), v1.end()), v1.end()); // Remove duplicate words in their range (start to finish)
}

//separate words:
// receives lines with ';' from vector_line
void separate_words(const string &line, vector<string> &word_list_v) {
	unsigned int i = 0;
	unsigned int first = 0;
	while (i < line.length()) {
		if (i == (line.length() - 1)) {
			word_list_v.push_back(line.substr(first, i - first + 1));
			i++;
		} else {
			if (line.at(i) == ';' || line.at(i) == ' ') {
				word_list_v.push_back(line.substr(first, i - first));
				first = i + 2;
				i = i + 2;
			} else
				i++;
		}
	}
}


bool has_headlines(const string &line)  //check if the line has headlines, called by vector_line
{
	unsigned int i = 0;
	if (!line.empty()) {
		while (i < line.length()) {
			if (isupper(line.at(i)) || line.at(i) == ';' || line.at(i) == ' ')
				i++;
			else break;
		}
	} else
		return false;
	
	if (i == line.length())
		return true;
}

bool check_if_up_space(const string &line) //check if all ar uppercase or space
{
	unsigned int i = 0;
	while (i < line.length()) {
		if (isupper(line.at(i)) || line.at(i) == ' ')
			i++;
		else
		    return false;
	}
	return true;

	
}


void vector_line(const string &line, vector<string> &word_list_v)  //returns a vector with words from line
{
	if (has_headlines(line) && (line.find(' ') == string::npos))
		word_list_v.push_back(line);
	
	if (has_headlines(line) &&
	    (!(check_if_up_space(line)) && (line.find('\'') == string::npos) && (line.find(';') != string::npos)))
		/* {if (!(check_if_up_space(line))  //check if all ar uppercase or space and discard if true
		  { if (line.find(';') != string::npos)
				 /* word_list_v.push_back(line);
			 else  */
		separate_words(line, word_list_v);
}


//extract from dictionary
void extract(const string &dictionary_file_name, vector<string> &word_list_v) {
	string line;
	
	ifstream dictionary(dictionary_file_name);
	
	// Open the file; exit program if the file couldn't be opened
	// dictionary.open(dictionary_file_name);
	if (!dictionary.is_open()) 
	{ 
		cerr << "File " << "dictionary" << " not found !\n";
		exit(1);
	}
	
	while (!dictionary.eof()) {
		getline(dictionary, line);
		vector_line(line, word_list_v);
	}
	
	dictionary.close();
}

void write_to_file(const string &word_list_file_name, vector<string> vector, int max) {
	ofstream file(word_list_file_name);
	int i = 1;
	
	while (i < max) {
		file << vector[i] << endl;
		i++;
	}
	
	file.close();
	
}

int main() {
	string dictionary_file_name;
	string word_list_file_name;
	string line;
	vector<string> word_list_v;
	
	//INTERFACE HEADLINE
	cout << "EXTRACTION OF WORD LIST FROM DICTIONARY" << endl << "=======================================" << endl;
	
	// Read the file name //
	cout << "Dictionary file ? ";
	cin >> dictionary_file_name;
	cout << "Word list file ? ";
	cin >> word_list_file_name;
	
	extract(dictionary_file_name, word_list_v);
	//int number_of_words= word_list_v.size();
	//cout<< number_of_words;
	// Read the word_list file name //
	
	
	
	cout << "Extracting simple words from file" << dictionary_file_name << endl << "," << "begining with letter...";
	
	
	cout << "Number of simple words" << " = " << word_list_v.size() - 1 << endl;
	cout << "Sorting words " << "..." << endl;
	
	//Sort vector
	sort(word_list_v);
	
	cout << "Removing duplicate words " << "..." << endl;
	
	// Delete repeated vector words
	remove_duplicates(word_list_v);
	
	cout << "Number of non-duplicate simple words" << " = " << word_list_v.size() - 1 << endl;
	
	cout << "Saving words into file " << word_list_file_name << " ..." << endl;
	write_to_file(word_list_file_name, word_list_v, word_list_v.size());
	
	
	cout << "End of processing." << endl;
	
	return 0;
}
