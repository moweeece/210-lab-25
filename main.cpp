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
#include <algorithm>
using namespace std;
using namespace std::chrono;


// function declarations
void readData(const string&, vector<string>&, list<string>&, set<string>&);
void sortData(vector<string>&, list<string>&);
void insertData(vector<string>&, list<string>&, set<string>&);
void deleteData(vector<string>&, list<string>&, set<string>&);


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
    readData(fileName, vec1, list1, set1);               // call readData function and pass the name of the file and each container type
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    // Read time output
    cout << setw(15) << "Read" << setw(15) << duration.count() << setw(15) << duration.count() << setw(15) << duration.count() << endl;

    // Sort Data
    auto start = high_resolution_clock::now();
    sortData(vec1, list1);                               // call sortData function and pass vector and list (no set since set is already sorted)
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    // Sort time output
    cout << setw(15) << "Sort" << setw(15) << duration.count() << setw(15) << duration.count() << setw(15) << duration.count() << endl;

    // Insert Data
    auto start = high_resolution_clock::now();
    insertData(vec1, list1, set1);                      // call insertData function to insert data to each container type
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    // Insert time output
    cout << setw(15) << "Insert" << setw(15) << duration.count() << setw(15) << duration.count() << setw(15) << duration.count() << endl;

    // Delete Data
    auto start = high_resolution_clock::now();
    deleteData(vec1, list1, set1);                     // call the deleteData function to delete data from each container type
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


// function to read data and add to the container
void readData(const string& filename, vector<string>& vecRead, list<string>& listRead, set<string>& setRead)
{
    // open the file
    ifstream file(filename);
    string tempCode;

    // check if file is opened
    if (!file.is_open())
    {
        cerr << "Error Opening the file." << endl;
        return;   // exit the function
    }

    // read the code from the file and insert it into each container type
    while (file >> tempCode)
    {
        vecRead.push_back(tempCode);
        listRead.push_back(tempCode);
        setRead.insert(tempCode);
    }

    // close the file
    file.close();
}

// function to sort data (only for vector and list)
void sortData(vector<string>& vecSort, list<string>& listSort)
{
    // sort the vector
    sort(vecSort.begin(), vecSort.end());

    // sort the list
    listSort.sort();

}

// function to insert data
void insertData(vector<string>& vecInsert, list<string>& listInsert, set<string>& setInsert)
{
    string insertCode = "TESTCODE";
    // find middle of a vector and a list
    size_t vectorMiddleInsert = vecInsert.size() / 2;   // vector size divided by 2 for estimated middle position
    auto listMiddleInsert = next(listInsert.begin(), listInsert.size() / 2);  // iterator traverse from the beginning of the list to the middle of the list

    // set inserts in the correct order so no need to find the middle
    
    // insert the test code
    vecInsert.insert(vecInsert.begin() + vectorMiddleInsert, insertCode);
    listInsert.insert(listMiddleInsert, insertCode);
    setInsert.insert(insertCode);
}

// function to delete data
void deleteData(vector<string>& vecDelete, list<string>& listDelete, set<string>& setDelete)
{
    // find middle of a vector and a list
    size_t vectorMiddleDelete = vecDelete.size() / 2;   // vector size divided by 2 for estimated middle position
    auto listMiddleDelete = next(listDelete.begin(), listDelete.size() / 2);  // iterator traverse from the beginning of the list to the middle of the list

    // insert the middle-ish element
    vecDelete.erase(vecDelete.begin() + vectorMiddleDelete);
    listDelete.erase(listMiddleDelete);

}