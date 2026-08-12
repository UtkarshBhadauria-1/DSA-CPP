#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    // 1. Traversal
    void traverse() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }

    // 2. Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // 3. Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    // 4. Insert at position
    void insertAtPosition(int value, int position) {
        if (position <= 0) return;

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        if (head == nullptr) return;

        Node* temp = head;

        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;

            if (temp == head) {
                return;
            }
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 5. Search
    bool search(int value) {
        if (head == nullptr) {
            return false;
        }

        Node* temp = head;

        do {
            if (temp->data == value) {
                return true;
            }

            temp = temp->next;

        } while (temp != head);

        return false;
    }

    // 6. Delete from beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        Node* deleteNode = head;

        head = head->next;
        temp->next = head;

        delete deleteNode;
    }

    // 7. Delete from end
    void deleteFromEnd() {
        if (head == nullptr) {
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;

        while (temp->next->next != head) {
            temp = temp->next;
        }

        Node* deleteNode = temp->next;

        temp->next = head;

        delete deleteNode;
    }

    // 8. Delete from position
    void deleteFromPosition(int position) {
        if (head == nullptr || position <= 0) {
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;

            if (temp == head) {
                return;
            }
        }

        Node* deleteNode = temp->next;

        if (deleteNode == head) {
            return;
        }

        temp->next = deleteNode->next;

        delete deleteNode;
    }

    // 9. Delete by value
    void deleteByValue(int value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;

        while (temp->next != head) {
            if (temp->next->data == value) {
                Node* deleteNode = temp->next;
                temp->next = deleteNode->next;
                delete deleteNode;
                return;
            }

            temp = temp->next;
        }
    }

    // 10. Length
    int length() {
        if (head == nullptr) {
            return 0;
        }

        int count = 0;
        Node* temp = head;

        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);

    cll.insertAtBeginning(5);
    cll.insertAtPosition(15, 3);

    cout << "Circular Linked List: ";
    cll.traverse();

    cout << "Length: " << cll.length() << endl;

    cout << "Search 20: ";
    cout << (cll.search(20) ? "Found" : "Not Found") << endl;

    cll.deleteFromBeginning();

    cout << "After deleting beginning: ";
    cll.traverse();

    cll.deleteFromEnd();

    cout << "After deleting end: ";
    cll.traverse();

    cll.deleteFromPosition(2);

    cout << "After deleting position 2: ";
    cll.traverse();

    cll.deleteByValue(20);

    cout << "After deleting 20: ";
    cll.traverse();

    return 0;
}