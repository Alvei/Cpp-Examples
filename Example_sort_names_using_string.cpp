/*
 * Example_sort_names_using_string.cpp
 * Sort N names in alphabetical order.
 * Uses double array of characters rather than array of strings.
 * Output the given names and the sorted names in two columns side by side.
 */

#include<iostream>
#include <stdio.h>
#include <string.h>
#define MAXSIZE 20      //Maximum number of names
#define MAXWORDSIZE 20


using namespace std;

int printNameArray(const char name[MAXSIZE][MAXWORDSIZE], const int length);
void getNameArray(string name[], int& n);

int main()
{
    // char name[MAXSIZE][MAXWORDSIZE], tname[MAXSIZE][MAXWORDSIZE], temp[MAXWORDSIZE];
    string name[MAXSIZE], tname[MAXSIZE], temp;
    int n;

    getNameArray(name, n);

    for (int i = 0; i < n; i++) {
        tname[i] = name[i];                  // Keep original copy to print later
    }

    for (int i = 0; i < n - 1 ; i++) {       // Loop across the array of names
        for (int j = i + 1; j < n; j++) {
            //cout << endl << "i = " << i << " j = " << j << " Name[i] = " << name[i] << " Name[j] = " << name[j];

            // String member function .compare() returns 0 when both are equal, if not reverse them
            if (name[i].compare(name[j]) > 0) {
                temp    = name[i];
                name[i] = name[j];
                name[j] = temp;

                // cout << endl; printNameArray(name, n);
            }
        }
    }

    cout << "\n----------------------------------------\n";
    cout << "Input Name \t Sorted names\n";
    cout << "------------------------------------------\n";

    for (int i = 0; i < n; i++) {
       cout << tname[i]<<"\t\t"<< name[i] << endl;
    }
    cout<<"------------------------------------------\n";

    return(0);
}

/*
 * printNameArray:
 * Prints an array of names
 */
int printNameArray(const char name[MAXSIZE][MAXWORDSIZE], const int length) {
    for (int i = 0; i < length; i++) {
        cout << name[i] << endl;
    }
    cout << endl;
    return 0;
}

/*
 * getNameArray:
 * Gets an array of names.
 * Updates the array and the size
 */
void getNameArray(string name[], int& n) {
    cout << "How many to names to sort : ";
    cin >> n;

    cout<<"Enter names ";
    cout<<"\n----------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "Name " << i+1 << " : ";
        cin >> name[i];
    }
}

