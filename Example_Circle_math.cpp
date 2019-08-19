//********************************************************
// Example of Circle math with overloaded
//********************************************************
#include <iostream>
#include <cmath>

using namespace std;

//*******************************************************************************
// Simple circle area function with radius as a parameter.
// Returns the Area.
//*******************************************************************************
double circleArea(double radius)
{
    double pi = acos (-1.0);        // Get value of pi
    return(pi * radius * radius);
}

//*******************************************************************************
// Calculates the diagonal using Pythagorean theorem. Returns the diagonal.
//*******************************************************************************
double distance(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt (dx*dx + dy*dy);
}

//*******************************************************************************
// Overloaded version of Area that calls the original one using the radius
// Uses the center coordinate and the coordinate of a point on the perimeter.
// Returns the Area.
//*******************************************************************************
double circleArea (double xc, double yc, double xp, double yp)
{
    double radius = distance(xc, yc, xp, yp);
    return circleArea(radius);
}

int main()
{
    double radius = distance (1.0, 2.0, 4.0, 6.0);
    cout << "RADIUS = "<<radius << endl;
    cout << "AREA = "<< circleArea(radius) << endl;
    return(0);
}
