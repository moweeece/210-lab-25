// COMSC-210 | Mauricio Espinosa | Lab 25
// IDE Used: Visual Studio Code & Github

#include <iostream>
#include <chrono>
#include <vector>    // for vector
#include <list>      // for list
#include <set>       // for set
#include <fstream>   // for reading files
#include <iomanip>   // for setw()
#include <string>
using namespace std;
using namespace std::chrono;


// function declarations
void readData();
void sortData();
void insertData();
void deleteData();


int main() {
    // vector, list, and set declarations
    vector<string> vec1;
    list<string> list1;
    set<string> set1;

    const string fileName = "codes.txt";

    // header output
    cout << setw(15) << "Operation" << setw(15) << "Vector" << setw(15) << "List" << setw(15) << "Set" << endl;

    // Reading Data
    auto start = high_resolution_clock::now();
    readData();                                       // finish this code
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    // Read time output
    cout << setw(15) << "Read" << setw(15) << duration.count() << setw(15) << duration.count() << setw(15) << duration.count() << endl;

    // Sort Data
    auto start = high_resolution_clock::now();
    sortData();                                       // finish this code
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    // Sort time output
    cout << setw(15) << "Sort" << setw(15) << duration.count() << setw(15) << duration.count() << setw(15) << duration.count() << endl;

    // Insert Data
    auto start = high_resolution_clock::now();
    insertData();                                       // finish this code
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    // Insert time output
    cout << setw(15) << "Insert" << setw(15) << duration.count() << setw(15) << duration.count() << setw(15) << duration.count() << endl;

    // Delete Data
    auto start = high_resolution_clock::now();
    deleteData();                                       // finish this code
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    // Delete time output
    cout << setw(15) << "Delete" << setw(15) << duration.count() << setw(15) << duration.count() << setw(15) << duration.count() << endl;
     

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/


// reading

// sorting

// inserting

// deleting