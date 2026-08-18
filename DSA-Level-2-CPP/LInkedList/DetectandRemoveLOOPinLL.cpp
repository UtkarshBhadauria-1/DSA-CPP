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

// Detect Loop
bool detectLoop(Node* head) {
    if (head == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

// Find Starting Point of Loop
Node* getStartingNode(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    // Detect loop
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    // No loop
    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }

    // Move slow to head
    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Remove Loop
void removeLoop(Node* head) {
    Node* startingNode = getStartingNode(head);

    if (startingNode == nullptr) {
        return;
    }

    Node* temp = startingNode;

    while (temp->next != startingNode) {
        temp = temp->next;
    }

    temp->next = nullptr;
}

// Print Linked List
void print(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating loop:
    // 5 -> 3
    head->next->next->next->next->next =
        head->next->next;

    // Detect Loop
    if (detectLoop(head)) {
        cout << "Loop detected." << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    // Find starting node
    Node* startingNode = getStartingNode(head);

    if (startingNode != nullptr) {
        cout << "Loop starts at node: "
             << startingNode->data << endl;
    }

    // Remove Loop
    removeLoop(head);

    cout << "\nAfter removing loop:" << endl;
    print(head);

    return 0;
}