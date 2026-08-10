/*
DSA LEVEL 1 — SEARCHING, SORTING AND BASIC HASHING

Questions:
1. Linear search.
2. Binary search.
3. Find first and last occurrence.
4. Bubble sort.
5. Selection sort.
6. Insertion sort.
7. Merge sort.
8. Quick sort.
9. Count frequency of array elements.
10. Find duplicate element.
11. Find the element appearing once when every other element appears twice.
12. Two Sum using hashing.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Q1 — Linear Search
int q1_linearSearch(const vector<int>& a, int target) {
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == target) return i;
    }
    return -1;
}

// Q2 — Binary Search
int q2_binarySearch(const vector<int>& a, int target) {
    int low = 0, high = a.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == target) return mid;
        if (a[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}

// Q3 — First and last occurrence
pair<int, int> q3_firstLast(const vector<int>& a, int target) {
    int first = -1, last = -1;

    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == target) {
            if (first == -1) first = i;
            last = i;
        }
    }

    return {first, last};
}

// Q4 — Bubble Sort
void q4_bubbleSort(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

// Q5 — Selection Sort
void q5_selectionSort(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        swap(a[i], a[minIndex]);
    }
}

// Q6 — Insertion Sort
void q6_insertionSort(vector<int>& a) {
    int n = a.size();

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// Q7 — Merge Sort
void merge(vector<int>& a, int low, int mid, int high) {
    vector<int> temp;
    int i = low, j = mid + 1;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }

    while (i <= mid) temp.push_back(a[i++]);
    while (j <= high) temp.push_back(a[j++]);

    for (int k = low; k <= high; k++)
        a[k] = temp[k - low];
}

void q7_mergeSort(vector<int>& a, int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;

    q7_mergeSort(a, low, mid);
    q7_mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

// Q8 — Quick Sort
int partitionArray(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void q8_quickSort(vector<int>& a, int low, int high) {
    if (low >= high) return;

    int pivotIndex = partitionArray(a, low, high);

    q8_quickSort(a, low, pivotIndex - 1);
    q8_quickSort(a, pivotIndex + 1, high);
}

// Q9 — Frequency
unordered_map<int, int> q9_frequency(const vector<int>& a) {
    unordered_map<int, int> freq;

    for (int x : a)
        freq[x]++;

    return freq;
}

// Q10 — Duplicate
int q10_findDuplicate(const vector<int>& a) {
    unordered_map<int, int> freq;

    for (int x : a) {
        freq[x]++;
        if (freq[x] == 2) return x;
    }

    return -1;
}

// Q11 — Single number using XOR
int q11_singleNumber(const vector<int>& a) {
    int ans = 0;

    for (int x : a)
        ans ^= x;

    return ans;
}

// Q12 — Two Sum using hashing
pair<int, int> q12_twoSum(const vector<int>& a, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < (int)a.size(); i++) {
        int required = target - a[i];

        if (mp.count(required))
            return {mp[required], i};

        mp[a[i]] = i;
    }

    return {-1, -1};
}

void printArray(const vector<int>& a) {
    for (int x : a)
        cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> a = {5, 2, 8, 1, 3};

    // q4_bubbleSort(a);
    // q5_selectionSort(a);
    // q6_insertionSort(a);
    // q7_mergeSort(a, 0, a.size() - 1);
    // q8_quickSort(a, 0, a.size() - 1);

    // printArray(a);

    return 0;
}
