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

class DoublyCircularLinkedList {
public:
    Node* head;

    DoublyCircularLinkedList() {
        head = nullptr;
    }

    // 1. Forward Traversal
    void traverseForward() {
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

    // 2. Backward Traversal
    void traverseBackward() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head->prev;

        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != head->prev);

        cout << endl;
    }

    // 3. Insert at Beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;

        head = newNode;
    }

    // 4. Insert at End
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }

    // 5. Insert at Position
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
        Node* nextNode = temp->next;

        newNode->prev = temp;
        newNode->next = nextNode;

        temp->next = newNode;
        nextNode->prev = newNode;
    }

    // 6. Search
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

    // 7. Delete from Beginning
    void deleteFromBeginning() {
        if (head == nullptr) return;

        // Only one node
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* last = head->prev;
        Node* deleteNode = head;

        head = head->next;

        last->next = head;
        head->prev = last;

        delete deleteNode;
    }

    // 8. Delete from End
    void deleteFromEnd() {
        if (head == nullptr) return;

        // Only one node
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* last = head->prev;
        Node* newLast = last->prev;

        newLast->next = head;
        head->prev = newLast;

        delete last;
    }

    // 9. Delete from Position
    void deleteFromPosition(int position) {
        if (head == nullptr || position <= 0) return;

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position; i++) {
            temp = temp->next;

            if (temp == head) {
                return;
            }
        }

        Node* previous = temp->prev;
        Node* nextNode = temp->next;

        previous->next = nextNode;
        nextNode->prev = previous;

        delete temp;
    }

    // 10. Delete by Value
    void deleteByValue(int value) {
        if (head == nullptr) return;

        Node* temp = head;

        do {
            if (temp->data == value) {
                if (temp == head) {
                    deleteFromBeginning();
                } else {
                    Node* previous = temp->prev;
                    Node* nextNode = temp->next;

                    previous->next = nextNode;
                    nextNode->prev = previous;

                    delete temp;
                }

                return;
            }

            temp = temp->next;
        } while (temp != head);
    }

    // 11. Length
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
    DoublyCircularLinkedList dcll;

    dcll.insertAtEnd(10);
    dcll.insertAtEnd(20);
    dcll.insertAtEnd(30);

    dcll.insertAtBeginning(5);
    dcll.insertAtPosition(15, 3);

    cout << "Forward: ";
    dcll.traverseForward();

    cout << "Backward: ";
    dcll.traverseBackward();

    cout << "Length: " << dcll.length() << endl;

    cout << "Search 20: ";
    cout << (dcll.search(20) ? "Found" : "Not Found") << endl;

    dcll.deleteFromBeginning();

    cout << "After deleting beginning: ";
    dcll.traverseForward();

    dcll.deleteFromEnd();

    cout << "After deleting end: ";
    dcll.traverseForward();

    dcll.deleteFromPosition(2);

    cout << "After deleting position 2: ";
    dcll.traverseForward();

    dcll.deleteByValue(20);

    cout << "After deleting 20: ";
    dcll.traverseForward();

    return 0;
}