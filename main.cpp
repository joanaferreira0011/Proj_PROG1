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
void separate_words(string line, vector<string> &word_list_v)
{
    int i=0;
    int first=0;
    while (i<line.length())
    {if (i==(line.length()-1))
        {word_list_v.push_back(line.substr(first, i-first+1));
        i++;}
        else
        {if (line.at(i)== ';' || line.at(i)== ' ')
            {word_list_v.push_back(line.substr(first, i-first));
            first= i+2;
            i=i+2;}
        else
                i++;}}
}


bool has_headlines (string line)  //check if the line has headlines, called by vector_line
{int i=0;
    if (!line.empty())
       {while (i< line.length())
            { if (isupper(line.at(i)) || line.at(i)== ';' || line.at(i)== ' ')
                    i++;
                else break; }}
    else
        return false;

    if (i==line.length())
        return true;
}

bool check_if_up_space(string line) //check if all ar uppercase or space
{
    int i=0;
    while (i< line.length())
     {if (isupper(line.at(i)) || line.at(i)== ' ' )
        i++;
        else
            break;}

    if (i==line.length())
        return true;
    else return false;

}


void vector_line(string line, vector<string> &word_list_v)  //returns a vector with words from line
{   if (has_headlines(line) && (line.find(' ') == string::npos))
        word_list_v.push_back(line);

    if(has_headlines(line) && (!(check_if_up_space(line)) &&(line.find('\'') == string::npos) && (line.find(';') != string::npos)))
       /* {if (!(check_if_up_space(line))  //check if all ar uppercase or space and discard if true
         { if (line.find(';') != string::npos)
                /* word_list_v.push_back(line);
            else  */
                separate_words(line, word_list_v);
}



//extract from dictionary
void extract(string dictionary_file_name, vector<string> &word_list_v)
    {
    string line;

    ifstream dictionary(dictionary_file_name);

    // Open the file; exit program if the file couldn't be opened
   // dictionary.open(dictionary_file_name);
    if (!dictionary.is_open())
        { cerr << "File " << "dictionary" << " not found !\n"; }

        while (!dictionary.eof())
        {   getline(dictionary, line);
            vector_line(line, word_list_v);
        }

    //cout<< word_list_v[0];
    }


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
    //int number_of_words= word_list_v.size();
    //cout<< number_of_words;
    // Read the word_list file name //
    //cout << "Word list file ? ";
   // cin >> word_list_file_name;


    cout << "Extracting simple words from file" << dictionary_file_name << endl << "," << "begining with letter...";


	cout << "Number of simple words" << " = " << word_list_v.size() << endl;
	cout << "Sorting words " << "..." << endl;
	
	//Sort vector
	sort(word_list_v); 

	cout << "Removing duplicate words " << "..." << endl;

	// Delete repeated vector words
	remove_duplicates(word_list_v);

	cout << "Number of non-duplicate simple words" << " = " << word_list_v.size() << endl;

	cout << "Saving words into file " << dictionary_file_name << " ..." << endl;

		// chamar funcao que faz istoo ...... (APAGAR)

	cout << "End of processing." << endl;
    int i= 0;
	while(i<word_list_v.size())
    {cout << word_list_v[i] << endl;
	    i++;
    }
	return 0;}
