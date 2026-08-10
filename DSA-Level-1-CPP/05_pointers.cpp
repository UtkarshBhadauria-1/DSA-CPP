/*
DSA LEVEL 1 — POINTERS

Questions:
1. Print address and value of a variable.
2. Modify a variable using a pointer.
3. Swap two numbers using pointers.
4. Find sum of two numbers using pointers.
5. Traverse an array using a pointer.
6. Find maximum element using a pointer.
7. Reverse an array using pointers.
8. Demonstrate pointer to pointer.
9. Dynamic memory allocation using new/delete.
10. Understand pointer arithmetic.
*/

#include <iostream>
using namespace std;

// Q1
void q1_address() {
    int x = 10;
    int* ptr = &x;

    cout << "Value: " << x << endl;
    cout << "Address: " << &x << endl;
    cout << "Pointer value: " << ptr << endl;
    cout << "Value through pointer: " << *ptr << endl;
}

// Q2
void q2_modify(int* ptr) {
    *ptr = 100;
}

// Q3
void q3_swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Q4
int q4_sum(int* a, int* b) {
    return *a + *b;
}

// Q5
void q5_traverse(int* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

// Q6
int q6_max(int* arr, int n) {
    int mx = *arr;

    for (int i = 1; i < n; i++)
        mx = max(mx, *(arr + i));

    return mx;
}

// Q7
void q7_reverse(int* arr, int n) {
    int* left = arr;
    int* right = arr + n - 1;

    while (left < right) {
        swap(*left, *right);
        left++;
        right--;
    }
}

// Q8
void q8_pointerToPointer() {
    int x = 10;
    int* p = &x;
    int** pp = &p;

    cout << x << endl;
    cout << *p << endl;
    cout << **pp << endl;
}

// Q9
void q9_dynamicMemory() {
    int* ptr = new int(50);

    cout << *ptr << endl;

    delete ptr;
    ptr = nullptr;
}

// Q10
void q10_pointerArithmetic() {
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;

    cout << *ptr << endl;
    ptr++;
    cout << *ptr << endl;
    ptr += 2;
    cout << *ptr << endl;
}

int main() {
    // q1_address();

    // int x = 10;
    // q2_modify(&x);
    // cout << x << endl;

    // int a = 10, b = 20;
    // q3_swap(&a, &b);
    // cout << a << " " << b << endl;

    // int arr[] = {1, 2, 3, 4, 5};
    // q5_traverse(arr, 5);
    // q7_reverse(arr, 5);
    // q5_traverse(arr, 5);

    return 0;
}
