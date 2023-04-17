#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList() {
            head = NULL;
        }

        // Insertion at the beginning
        void insertAtBeginning(int value) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }

        // Insertion at the end
        void insertAtEnd(int value) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }

        // Insertion at a specific position
        void insertAtPosition(int value, int position) {
            Node* newNode = new Node();
            newNode->data = value;

            if (position == 1) {
                newNode->next = head;
                head = newNode;
            } else {
                Node* previous = head;
                for (int i = 1; i < position - 1; i++) {
                    previous = previous->next;
                }
                newNode->next = previous->next;
                previous->next = newNode;
            }
        }

        // Deletion at the beginning
        void deleteAtBeginning() {
            if (head == NULL) {
                cout << "List is empty!" << endl;
            } else {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }

        // Deletion at the end
        void deleteAtEnd() {
            if (head == NULL) {
                cout << "List is empty!" << endl;
            } else {
                if (head->next == NULL) {
                    delete head;
                    head = NULL;
                } else {
                    Node* current = head;
                    while (current->next->next != NULL) {
                        current = current->next;
                    }
                    delete current->next;
                    current->next = NULL;
                }
            }
        }

        // Deletion at a specific position
        void deleteAtPosition(int position) {
            if (head == NULL) {
                cout << "List is empty!" << endl;
            } else {
                if (position == 1) {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                } else {
                    Node* previous = head;
                    for (int i = 1; i < position - 1; i++) {
                        previous = previous->next;
                    }
                    Node* temp = previous->next;
                    previous->next = temp->next;
                    delete temp;
                }
            }
        }

        // Display the list
        void display() {
            if (head == NULL) {
                cout << "List is empty!" << endl;
            } else {
                Node* current = head;
                while (current != NULL) {
                    cout << current->data << " ";
                    current = current->next;
                }
                cout << endl;
            }
        }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(5);
    list.insertAtBeginning(3);
    list.insertAtEnd(10);
    list.insertAtPosition(8, 2);

    list.display();

    list.deleteAtBeginning();
    list.deleteAtEnd();
    list.deleteAtPosition(1);
}