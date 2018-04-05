#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// --- Algorithm that orders the vector --- 
void sort(vector<string> v1) 
{
	sort(v1.begin(), v1.end());  // Sort elements in their range (start to finish)
}


int main() {
    
	sort(v1);
	string dictionary_file_name;
    ifstream dictionary;
    string line;

    //INTERFACE
    cout << "EXTRACTION OF WORD LIST FROM DICTIONARY" << endl <<"======================================="<< endl;

    // Read the file name //
    cout << "Dictionary file ? ";
    cin >> dictionary_file_name;

    // Open the file; exit program if the file couldn't be opened
    dictionary.open(dictionary_file_name);
    if (!dictionary.is_open())
        { cerr << "File " << dictionary_file_name << " not found !\n";
        return(1); }

	return 0;}