/*
DSA LEVEL 1 — CONDITIONALS AND LOOPS

Questions:
1. Check whether a number is positive, negative or zero.
2. Check whether a number is even or odd.
3. Find the greatest of three numbers.
4. Check whether a year is a leap year.
5. Check whether a character is a vowel or consonant.
6. Print numbers from 1 to N.
7. Print numbers from N to 1.
8. Print the multiplication table of N.
9. Find the sum of first N natural numbers.
10. Find factorial of N.
11. Count digits of a number.
12. Reverse a number.
13. Check whether a number is palindrome.
14. Find the sum of digits.
15. Check whether a number is prime.
16. Print all prime numbers from 1 to N.
17. Print Fibonacci series.
18. Find GCD of two numbers.
19. Find LCM of two numbers.
20. Check whether a number is an Armstrong number.
*/

#include <iostream>
using namespace std;

// Q1
void q1_sign(int n) {
    if (n > 0) cout << "Positive";
    else if (n < 0) cout << "Negative";
    else cout << "Zero";
}

// Q2
bool q2_even(int n) {
    return n % 2 == 0;
}

// Q3
int q3_greatest(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

// Q4
bool q4_leapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

// Q5
bool q5_vowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

// Q6
void q6_print1ToN(int n) {
    for (int i = 1; i <= n; i++)
        cout << i << " ";
    cout << endl;
}

// Q7
void q7_printNTo1(int n) {
    for (int i = n; i >= 1; i--)
        cout << i << " ";
    cout << endl;
}

// Q8
void q8_table(int n) {
    for (int i = 1; i <= 10; i++)
        cout << n << " x " << i << " = " << n * i << endl;
}

// Q9
long long q9_sumN(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    return sum;
}

// Q10
long long q10_factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

// Q11
int q11_countDigits(int n) {
    if (n == 0) return 1;
    n = abs(n);
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

// Q12
int q12_reverseNumber(int n) {
    int sign = n < 0 ? -1 : 1;
    n = abs(n);
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return sign * rev;
}

// Q13
bool q13_palindrome(int n) {
    return n >= 0 && n == q12_reverseNumber(n);
}

// Q14
int q14_digitSum(int n) {
    n = abs(n);
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Q15
bool q15_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Q16
void q16_primes1ToN(int n) {
    for (int i = 2; i <= n; i++) {
        if (q15_prime(i))
            cout << i << " ";
    }
    cout << endl;
}

// Q17
void q17_fibonacci(int n) {
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        long long c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

// Q18
int q18_gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

// Q19
long long q19_lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return abs((long long)a * b) / q18_gcd(a, b);
}

// Q20
bool q20_armstrong(int n) {
    if (n < 0) return false;
    int original = n;
    int digits = q11_countDigits(n);
    long long sum = 0;

    while (n > 0) {
        int digit = n % 10;
        long long power = 1;
        for (int i = 0; i < digits; i++)
            power *= digit;
        sum += power;
        n /= 10;
    }

    return sum == original;
}

int main() {
    // Test individual functions here.

    return 0;
}
