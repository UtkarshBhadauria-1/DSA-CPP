#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
// Print Linked List
void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
// Reverse Linked List in K Groups
Node* reverseKGroup(Node* head, int k) {
    if (head == nullptr) {
        return nullptr;
    }

    // Check if at least k nodes are present
    Node* temp = head;
    int count = 0;

    while (temp != nullptr && count < k) {
        temp = temp->next;
        count++;
    }

    // If fewer than k nodes are present, don't reverse
    if (count < k) {
        return head;
    }

    // Reverse first k nodes
    Node* prev = nullptr;
    Node* curr = head;
    Node* forward = nullptr;

    count = 0;

    while (curr != nullptr && count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Recursively reverse remaining nodes
    head->next = reverseKGroup(curr, k);

    return prev;
}

// Check whether Linked List is Circular
bool isCircular(Node* head) {
    if (head == nullptr) {
        return false;
    }

    Node* temp = head->next;

    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }

    return temp == head;
}

int main() {

    // -----------------------------
    // Reverse Linked List in K Group
    // -----------------------------

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Original Linked List:" << endl;
    print(head);

    int k = 2;

    head = reverseKGroup(head, k);

    cout << "\nAfter reversing in groups of " << k << ":" << endl;
    print(head);


    // -----------------------------
    // Check Circular Linked List
    // -----------------------------

    Node* circularHead = new Node(10);
    circularHead->next = new Node(20);
    circularHead->next->next = new Node(30);
    circularHead->next->next->next = circularHead;

    cout << "\nCircular Linked List: ";

    if (isCircular(circularHead)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}