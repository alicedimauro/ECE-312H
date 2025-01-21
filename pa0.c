// ECE 312H PA0
// <Alice Di Mauro>
// <ad55559>
// Slip days used: 0
// Spring 2024

#include "pa0.h"
#include "math.h"

/*
    Write a function that takes in an integer x and returns 1 if x is prime and 0 if x is not prime.
*/
int isPrime(int x) {
    //TODO: Your code here
    if(x <= 1) {
        return 0; // edge case
    }
    for int(i = 2; i < x; i++) { // would sqrt be more efficient?   
        if (x % i == 0) {
            return 0; // if at any point no remainer, cannot be prime
        }
    }
    return 1; // by process of elimination must be prime
}

/*
    Write a function that takes in two legs of a right triange, x and y, and returns the length of the hypotenuse.
*/
double calculateHypotenuse(double x, double y) {
    //TODO: Your code here
    if(x <= 0) {
        if (x = 0) { 
            return 0; // x = 0
    }
    return -1;
}
    return sqrt(x*x + y*y) ; // pythagorean theorem thanks to sqrt from math.h library

}

/*
    Write a function that finds the greatest common divisor of two integers x and y.
*/
int gcd(int x, int y) {
    //TODO: Your code here
    if (x < 0) {
        x = -x;
    }
    if (y < 0) {
        y = -y;
    }
    while( y != 0) {
        temp = y; // assigns temporary variable the value of y
        y = x % y; // checks for remainder -> are we done?
        x = temp; // x takes the temp value and loops if needed
    }
        return x; // returns gcd
}
