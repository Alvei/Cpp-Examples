/*
 * Example_sort_names_using_char.cpp
 *  Sort N names in alphabetical order.
 *  Uses double array of characters rather than array of strings.
 * Output the given names and the sorted names in two columns side by side.
 */

#include<iostream>
#include <stdio.h>
#include <string.h>
#define MAXSIZE 20      //Maximum number of names
#define MAXWORDSIZE 8   //Maximum length of work

using namespace std;

int printNameArray(const char name[MAXSIZE][MAXWORDSIZE], const int length);

int main() {
    char name[MAXSIZE][MAXWORDSIZE], tname[MAXSIZE][MAXWORDSIZE], temp[MAXWORDSIZE];
    int n;

    cout << "How many to names to sort : ";
    cin >> n;

    cout<<"Enter names ";
    cout<<"\n----------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "Name " << i+1 << " : ";
        cin >> name[i];
        strcpy(tname[i], name[i]);                  // Keep original copy to print later
    }

    for (int i = 0; i < n - 1 ; i++) {              // Loop across the array of names
        for (int j = i + 1; j < n; j++){
            //cout << endl << "i = " << i << " j = " << j << " Name[i] = " << name[i] << " Name[j] = " << name[j];
            if (strcmp(name[i], name[j]) > 0 { // strcmp returns 0 when both are equal, if not reverse them
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
                cout << endl;
                // printNameArray(name, n);
            }
        }
    }

    cout << "\n----------------------------------------\n";
    cout << "Input Name \t Sorted names\n";
    cout << "------------------------------------------\n";

    for (int i = 0; i < n; i++){
       cout << tname[i]<<"\t\t"<< name[i] << endl;
    }
    cout<<"------------------------------------------\n";

    return 0;
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
