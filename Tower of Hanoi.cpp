/* tower of Hanoi.cpp
 * Simple implementation of the Classic problem of Tower of Hanoi using recursion.
 */
#include <iostream>

using namespace std;

void moveSingleDisk(char start, char dest);
void moveTower(int n, char start, char dest, char temp);

int main() {
    cout << "Enter number of disk:";
    int disk;
    cin >> disk;
    moveTower(disk, 'a', 'b', 'c');
    return 0;
}

/*
 * moveSingleDisk:
 * Function that serves at the base case
 */
void moveSingleDisk(char start, char dest) {
    cout << start << " -> " << dest << endl;
}
/*
 * moveTower:
 * Function that moves all the disk.
 */
void moveTower(int n, char start, char dest, char temp) {
    if (n == 1) {       // Base case
        moveSingleDisk(start, dest);
    } else {
        moveTower(n-1, start, temp, dest);
        moveSingleDisk(start, dest);
        moveTower(n-1, temp, dest, start);  // Note that we are changing the temp, start and dest locations
    }
}
