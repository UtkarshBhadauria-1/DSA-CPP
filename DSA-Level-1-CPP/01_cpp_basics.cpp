/*
DSA LEVEL 1 — C++ BASICS
Topics:
- Input / Output
- Data types
- Operators
- Type casting
- Functions

Questions:
1. Print Hello World.
2. Take two integers and print their sum, difference, product and quotient.
3. Calculate simple interest.
4. Swap two numbers.
5. Convert Celsius to Fahrenheit.
6. Check the size of common C++ data types.
7. Write a function to calculate the square of a number.
8. Write a function to find the maximum of two numbers.
*/

#include <iostream>
using namespace std;

// Q1
void q1_helloWorld() {
    cout << "Hello World" << endl;
}

// Q2
void q2_basicOperations() {
    int a, b;
    cin >> a >> b;
    cout << "Sum: " << a + b << endl;
    cout << "Difference: " << a - b << endl;
    cout << "Product: " << a * b << endl;
    if (b != 0)
        cout << "Quotient: " << (double)a / b << endl;
}

// Q3
void q3_simpleInterest() {
    double p, r, t;
    cin >> p >> r >> t;
    double si = (p * r * t) / 100;
    cout << "Simple Interest: " << si << endl;
}

// Q4
void q4_swap() {
    int a, b;
    cin >> a >> b;
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}

// Q5
void q5_celsiusToFahrenheit() {
    double c;
    cin >> c;
    double f = (c * 9.0 / 5.0) + 32;
    cout << f << endl;
}

// Q6
void q6_dataTypes() {
    cout << "int: " << sizeof(int) << " bytes\n";
    cout << "char: " << sizeof(char) << " bytes\n";
    cout << "float: " << sizeof(float) << " bytes\n";
    cout << "double: " << sizeof(double) << " bytes\n";
    cout << "long long: " << sizeof(long long) << " bytes\n";
}

// Q7
int square(int n) {
    return n * n;
}

// Q8
int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    // Uncomment one question at a time to test it.

    // q1_helloWorld();
    // q2_basicOperations();
    // q3_simpleInterest();
    // q4_swap();
    // q5_celsiusToFahrenheit();
    // q6_dataTypes();

    // cout << square(5) << endl;
    // cout << maximum(10, 20) << endl;

    return 0;
}
