/*
 * Example_buble_sort.cpp
 * Sort N numbers in ascending order using Bubble sort
 * and print both the given and the sorted array.
 * It works with positive and negative numbers.
 */

#include<iostream>
#define MAXSIZE 20      // Maximum size of the array

using namespace std;

/*
 * PrintArray:
 * Simple function to print one dimensional integer array
 * Parameter are integer array and the size of the array.
 * Both cannot be change by function given the const.
 */
int printArray(const int a[MAXSIZE], const int length)
{
    cout<<"[ ";
    for (int i = 0; i < length; i++){ cout << a[i] << " "; }
    cout<<"]";
    return (0);
}
/*
 * getArray:
 * Simple function to get one dimensional integer array.
 * Parameters are integer array and the size of the array.
 * Both will be change since they are passed by reference.
 */
void getArray(int a[MAXSIZE], int& length)
{
    cout<<"How many integers will we sort : ";
    cin>> length ;
    cout<<"Please enter the elements one by one => " << endl;

    for (int i = 0; i < length; i++){
        cout << "Number " << i+1 << " : ";
        cin >> a[i];
    }
}

/*
 * bubbleSort:
 * Simple function to bubble sort a one dimensional integer array.
 * Parameters are integer array and the size of the array.
 * Array is passed by reference and will be changed.
 * Length is passed by reference to be more efficient but const
 * prevent changing it. Answer is saved in same array a.
 */
void bubbleSort(int a[MAXSIZE], const int& length)
{
    int max_element, temp;
    for (int i = 0; i < length; i++) {
        // Using a starting point go through num -1 element and push down the highest number
        max_element = length - i - 1; // -1 because starts at zero
        //cout<<endl<<"Max Element : "<<max_element<<endl;

        for (int j = 0; j < max_element; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            //print_array(array, num);
        }
    }
}

int main()
{
    int a[MAXSIZE];
    int num, max_element, temp;

    getArray(a,num);
    cout << endl<<"Input\t array is => ";
    printArray(a, num);

    bubbleSort(a, num);
    cout<<endl<<"Sorted\t array is => ";
    printArray(a, num);

    return (0);
}

