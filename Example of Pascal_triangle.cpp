/*
 * Calculate the value of a position in Pascal triangle using recursion
 * The way to compute any given position's value is to add up the numbers
 * to the pos's right and left in the preceding row.
*/

#include <iostream>
#include <string>
#include <sstream>

#define MAX_ROW 10

using namespace std;

/*
 * NumberToString:
 * Function to convert anumber into a string
 */
template <typename T>
string NumberToString(T pNumber)
{
 ostringstream oOStrStream;
 oOStrStream << pNumber;
 return oOStrStream.str();
}
/*
 * computePascalValue:
 * Function that returns the Pascal triangle value using recursion.
 * Need to specify the row and the position in that row as a positive integer.
 */
int computePascalValue(int row, int pos)
{
    if (row == 0 || pos == 0) {  // Check for errors
        cout << "\nError *** Row = "<< row <<", " << "position = "<< pos << " these numbers cannot be equal to zero\n";
        return(-1);
    }

	if (pos == 1) {  // Base case in recursion
		return 1;
	} else if (pos == row) {
		return 1;
	} else {
		return computePascalValue(row-1, pos) + computePascalValue(row-1, pos-1); // Add the two numbers from the previous row
	}
}
/*
 * Prints the Pascal triangle
 */
int printPascalTriangle(int row)
{
    int i,j;
    string tri[MAX_ROW][2*MAX_ROW-1];
    int max_length = 2*row-1;
    int mid = max_length/2+1;
    int temp, pos_adj;

    for (i = 1; i <= row; i++) {
        for (j = 1; j <= max_length; j++) {
            tri[i][j] = ' ';
        }
    }

    tri[1][mid] = '1';
    tri[2][mid-1] = '1';
    tri[2][mid+1] = '1';
    for (i = 3; i <= row; i++) {
        for (j = 1; j <= i; j++) { // Position
            temp = computePascalValue(i, j);
            pos_adj = row - i;        //calculate the initial empty spaces for that row
            tri[i][pos_adj+2*j-1] = NumberToString(temp);
            //cout<<"["<<i<<","<<j<<"] = "<<temp<<" "<<tri[i][2*j-1]<<endl ;
        }
        cout << endl;
    }

    //print
    for (i = 1; i <= row; i++) {
        for (j = 1; j <= max_length; j++) {
            cout << tri[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    int row, pos;
    cout << "Please enter a row and a position on that row to compute : ";
    cin >> row >> pos;

    if (row < pos) {
        cout << "Invalid entry.  Position must be less than or equal to row.";
        return 0;
    }
    cout << "Value at row " << row << " and position " << pos << " is " << computePascalValue(row, pos) << endl;

    printPascalTriangle(row);
    return 0;
}
