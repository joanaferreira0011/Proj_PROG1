#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    string fileName;
    ifstream f;
    string line;

    // Read the file name //
    cout << "File name ? ";
    cin >> fileName;

    // Open the file; exit program if the file couldn't be opened
    f.open(fileName);
    if (!f.is_open())
        { cerr << "File " << fileName << " not found !\n";
        return(1); }


    return 0;}
