// Leetcode 206 Reverse LL
#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Helper: build a list from an array (LeetCode does this behind the scenes)
ListNode* buildList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return head;
}

// Helper: print a list (LeetCode also does this behind the scenes)
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = buildList(arr, n);
    cout << "Original: ";
    printList(head);

    head = reverseList(head);
    cout << "Reversed: ";
    printList(head);

    return 0;
}