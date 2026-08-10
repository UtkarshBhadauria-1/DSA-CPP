/*
DSA LEVEL 1 — ARRAYS

Questions:
1. Input and print an array.
2. Find the sum of array elements.
3. Find maximum and minimum element.
4. Find the second largest element.
5. Reverse an array.
6. Check whether an array is sorted.
7. Count even and odd elements.
8. Linear search.
9. Move all zeroes to the end.
10. Remove duplicates from a sorted array.
11. Rotate array left by one position.
12. Rotate array right by one position.
13. Rotate array by K positions.
14. Find the missing number from 1 to N.
15. Find the maximum subarray sum (Kadane's algorithm).
16. Merge two sorted arrays.
17. Find the intersection of two arrays.
18. Find the longest consecutive sequence.
19. Find pair with a given sum.
20. Find the majority element.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1
void q1_print(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

// Q2
long long q2_sum(const vector<int>& a) {
    long long sum = 0;
    for (int x : a) sum += x;
    return sum;
}

// Q3
pair<int, int> q3_minMax(const vector<int>& a) {
    int mn = a[0], mx = a[0];
    for (int x : a) {
        mn = min(mn, x);
        mx = max(mx, x);
    }
    return {mn, mx};
}

// Q4
int q4_secondLargest(const vector<int>& a) {
    int largest = INT_MIN, second = INT_MIN;
    for (int x : a) {
        if (x > largest) {
            second = largest;
            largest = x;
        } else if (x > second && x != largest) {
            second = x;
        }
    }
    return second;
}

// Q5
void q5_reverse(vector<int>& a) {
    int i = 0, j = (int)a.size() - 1;
    while (i < j) swap(a[i++], a[j--]);
}

// Q6
bool q6_sorted(const vector<int>& a) {
    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i] < a[i - 1]) return false;
    }
    return true;
}

// Q7
pair<int, int> q7_evenOdd(const vector<int>& a) {
    int even = 0, odd = 0;
    for (int x : a) {
        if (x % 2 == 0) even++;
        else odd++;
    }
    return {even, odd};
}

// Q8
int q8_linearSearch(const vector<int>& a, int target) {
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == target) return i;
    }
    return -1;
}

// Q9
void q9_moveZeroes(vector<int>& a) {
    int j = 0;
    for (int x : a) {
        if (x != 0) a[j++] = x;
    }
    while (j < (int)a.size()) a[j++] = 0;
}

// Q10
int q10_removeDuplicates(vector<int>& a) {
    if (a.empty()) return 0;
    int j = 1;
    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i] != a[i - 1])
            a[j++] = a[i];
    }
    return j;
}

// Q11
void q11_leftRotateOne(vector<int>& a) {
    if (a.empty()) return;
    int first = a[0];
    for (int i = 1; i < (int)a.size(); i++)
        a[i - 1] = a[i];
    a.back() = first;
}

// Q12
void q12_rightRotateOne(vector<int>& a) {
    if (a.empty()) return;
    int last = a.back();
    for (int i = (int)a.size() - 1; i > 0; i--)
        a[i] = a[i - 1];
    a[0] = last;
}

// Q13
void q13_rotateK(vector<int>& a, int k) {
    int n = a.size();
    if (n == 0) return;
    k %= n;
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
}

// Q14
int q14_missingNumber(const vector<int>& a) {
    int n = a.size();
    int ans = n;
    for (int i = 0; i < n; i++)
        ans ^= i ^ a[i];
    return ans;
}

// Q15
long long q15_kadane(const vector<int>& a) {
    long long current = a[0], best = a[0];
    for (int i = 1; i < (int)a.size(); i++) {
        current = max((long long)a[i], current + a[i]);
        best = max(best, current);
    }
    return best;
}

// Q16
vector<int> q16_mergeSorted(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }

    while (i < (int)a.size()) result.push_back(a[i++]);
    while (j < (int)b.size()) result.push_back(b[j++]);

    return result;
}

// Q17
vector<int> q17_intersection(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] == b[j]) {
            if (result.empty() || result.back() != a[i])
                result.push_back(a[i]);
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    return result;
}

// Q18
int q18_longestConsecutive(vector<int> a) {
    if (a.empty()) return 0;
    sort(a.begin(), a.end());
    int best = 1, current = 1;

    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i] == a[i - 1] + 1) {
            current++;
            best = max(best, current);
        } else if (a[i] != a[i - 1]) {
            current = 1;
        }
    }
    return best;
}

// Q19
bool q19_pairSum(const vector<int>& a, int target) {
    int i = 0, j = (int)a.size() - 1;
    while (i < j) {
        int sum = a[i] + a[j];
        if (sum == target) return true;
        if (sum < target) i++;
        else j--;
    }
    return false;
}

// Q20 — Boyer-Moore Voting Algorithm
int q20_majorityElement(const vector<int>& a) {
    int candidate = 0, count = 0;

    for (int x : a) {
        if (count == 0) candidate = x;
        count += (x == candidate) ? 1 : -1;
    }

    return candidate;
}

int main() {
    // Example:
    // vector<int> a = {1, 2, 0, 4, 0, 5};
    // q1_print(a);
    // q5_reverse(a);
    // q1_print(a);

    return 0;
}
