#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class Queue {
    private:
        Node* front;
        Node* rear;
        int size;
        int capacity;
    
    public:
        Queue(int capacity) {
            front = NULL;
            rear = NULL;
            size = 0;
            this->capacity = capacity;
        }
        
        bool is_empty() {
            return front == NULL;
        }
        
        bool is_full() {
            return size == capacity;
        }
        
        void enqueue(int data) {
            if (is_full()) {
                return;
            }
            
            Node* new_node = new Node();
            new_node->data = data;
            new_node->next = NULL;
            
            if (rear == NULL) {
                front = rear = new_node;
                size++;
                return;
            }
            
            rear->next = new_node;
            rear = new_node;
            size++;
        }
        
        void dequeue() {
            if (is_empty()) {
                return;
            }
            
            Node* temp = front;
            front = front->next;
            
            if (front == NULL) {
                rear = NULL;
            }
            
            delete temp;
            size--;
        }
        
        int front_data() {
            if (is_empty()) {
                return -1; // Or any other error value
            }
            
            return front->data;
        }
        
        void display() {
            if (is_empty()) {
                cout << "Queue is empty" << endl;
                return;
            }
            
            Node* temp = front;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    Queue queue(5);
    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(20);
    queue.enqueue(25);
    queue.enqueue(30); // Should not be added to the queue since it's full
    queue.dequeue();
    cout << "Front data: " << queue.front_data() << endl;
    queue.display();
    return 0;
}