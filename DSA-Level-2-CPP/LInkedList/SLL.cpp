#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Traversal
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    // Insert at position
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL) {
                cout << "Position out of range" << endl;
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of range" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Insert after a value
    void insertAfterValue(int target, int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == target) {
                Node* newNode = new Node(value);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Target value not found" << endl;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    // Delete from position
    void deleteFromPosition(int position) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (position < 1) {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 1) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL || temp->next == NULL) {
                cout << "Position out of range" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Delete by value
    void deleteByValue(int value) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            if (temp->next->data == value) {
                Node* nodeToDelete = temp->next;
                temp->next = nodeToDelete->next;
                delete nodeToDelete;
                return;
            }
            temp = temp->next;
        }
        cout << "Value not found" << endl;
    }

    // Searching
    int search(int value) {
        Node* temp = head;
        int position = 1;
        while (temp != NULL) {
            if (temp->data == value)
                return position;
            temp = temp->next;
            position++;
        }
        return -1;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();

    list.insertAtBeginning(5);
    list.display();

    list.insertAtPosition(15, 3);
    list.display();

    list.insertAfterValue(20, 25);
    list.display();

    int position = list.search(25);
    if (position != -1)
        cout << "25 found at position " << position << endl;
    else
        cout << "25 not found" << endl;

    list.deleteFromBeginning();
    list.display();

    list.deleteFromEnd();
    list.display();

    list.deleteFromPosition(2);
    list.display();

    list.deleteByValue(20);
    list.display();

    return 0;
}