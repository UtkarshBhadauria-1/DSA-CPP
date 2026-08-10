/*
DSA LEVEL 1 — RECURSION

Questions:
1. Print numbers from 1 to N using recursion.
2. Print numbers from N to 1 using recursion.
3. Find factorial using recursion.
4. Find sum of first N natural numbers.
5. Find sum of digits recursively.
6. Find power recursively.
7. Find nth Fibonacci number.
8. Find GCD recursively.
9. Reverse a string using recursion.
10. Check palindrome using recursion.
11. Binary search using recursion.
12. Generate all subsequences of a string.
13. Generate all permutations of a string.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Q1
void q1_1ToN(int n) {
    if (n == 0) return;
    q1_1ToN(n - 1);
    cout << n << " ";
}

// Q2
void q2_NTo1(int n) {
    if (n == 0) return;
    cout << n << " ";
    q2_NTo1(n - 1);
}

// Q3
long long q3_factorial(int n) {
    if (n <= 1) return 1;
    return n * q3_factorial(n - 1);
}

// Q4
long long q4_sumN(int n) {
    if (n <= 0) return 0;
    return n + q4_sumN(n - 1);
}

// Q5
int q5_digitSum(int n) {
    n = abs(n);
    if (n == 0) return 0;
    return n % 10 + q5_digitSum(n / 10);
}

// Q6
long long q6_power(long long x, int n) {
    if (n == 0) return 1;
    return x * q6_power(x, n - 1);
}

// Q7
long long q7_fibonacci(int n) {
    if (n <= 1) return n;
    return q7_fibonacci(n - 1) + q7_fibonacci(n - 2);
}

// Q8
int q8_gcd(int a, int b) {
    if (b == 0) return abs(a);
    return q8_gcd(b, a % b);
}

// Q9
void q9_reverseString(string& s, int left, int right) {
    if (left >= right) return;
    swap(s[left], s[right]);
    q9_reverseString(s, left + 1, right - 1);
}

// Q10
bool q10_palindrome(const string& s, int left, int right) {
    if (left >= right) return true;
    if (s[left] != s[right]) return false;
    return q10_palindrome(s, left + 1, right - 1);
}

// Q11
int q11_binarySearch(const vector<int>& a, int left, int right, int target) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (a[mid] == target) return mid;

    if (target < a[mid])
        return q11_binarySearch(a, left, mid - 1, target);

    return q11_binarySearch(a, mid + 1, right, target);
}

// Q12
void q12_subsequences(const string& s, int index, string current) {
    if (index == (int)s.length()) {
        cout << current << endl;
        return;
    }

    // Do not take current character
    q12_subsequences(s, index + 1, current);

    // Take current character
    q12_subsequences(s, index + 1, current + s[index]);
}

// Q13
void q13_permutations(string& s, int index) {
    if (index == (int)s.length()) {
        cout << s << endl;
        return;
    }

    for (int i = index; i < (int)s.length(); i++) {
        swap(s[index], s[i]);
        q13_permutations(s, index + 1);
        swap(s[index], s[i]);
    }
}

int main() {
    // q1_1ToN(5);
    // cout << q3_factorial(5) << endl;
    // cout << q4_sumN(5) << endl;
    // cout << q8_gcd(24, 36) << endl;

    // string s = "hello";
    // q9_reverseString(s, 0, s.length() - 1);
    // cout << s << endl;

    // q12_subsequences("abc", 0, "");

    return 0;
}
