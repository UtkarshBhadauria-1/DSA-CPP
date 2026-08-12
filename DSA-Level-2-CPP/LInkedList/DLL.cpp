#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }

    // 1. Traversal - Forward
    void traverseForward() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // 2. Traversal - Backward
    void traverseBackward() {
        if (head == nullptr) return;

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }

    // 3. Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // 4. Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // 5. Insert at position
    void insertAtPosition(int value, int position) {
        if (position <= 0) return;

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    // 6. Search
    bool search(int value) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    // 7. Delete from beginning
    void deleteFromBeginning() {
        if (head == nullptr) return;

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }

        delete temp;
    }

    // 8. Delete from end
    void deleteFromEnd() {
        if (head == nullptr) return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->prev->next = nullptr;

        delete temp;
    }

    // 9. Delete from position
    void deleteFromPosition(int position) {
        if (head == nullptr || position <= 0) return;

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    // 10. Length
    int length() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);

    dll.insertAtBeginning(5);

    dll.insertAtPosition(15, 3);

    cout << "Forward: ";
    dll.traverseForward();

    cout << "Backward: ";
    dll.traverseBackward();

    cout << "Length: " << dll.length() << endl;

    cout << "Search 20: ";
    cout << (dll.search(20) ? "Found" : "Not Found") << endl;

    dll.deleteFromBeginning();

    cout << "After deleting beginning: ";
    dll.traverseForward();

    dll.deleteFromEnd();

    cout << "After deleting end: ";
    dll.traverseForward();

    dll.deleteFromPosition(2);

    cout << "After deleting position 2: ";
    dll.traverseForward();

    return 0;
}