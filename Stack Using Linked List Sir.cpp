#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class Stack {
    private:
        Node* top;
        Node* bottom;
        int size;
    
    public:
        Stack() {
            top = NULL;
            bottom = NULL;
            size = 0;
        }
        
        bool is_empty() {
            return top == NULL;
        }
        
        void push(int data) {
            Node* new_node = new Node();
            new_node->data = data;
            new_node->next = top;
            
            if (bottom == NULL) {
                bottom = new_node;
            }
            
            top = new_node;
            size++;
        }
        
        void pop() {
            if (is_empty()) {
                return;
            }
            
            Node* temp = top;
            top = top->next;
            
            if (top == NULL) {
                bottom = NULL;
            }
            
            delete temp;
            size--;
        }
        
        void delete_bottom() {
            if (is_empty()) {
                return;
            }
            
            if (top == bottom) {
                delete top;
                top = bottom = NULL;
                size--;
                return;
            }
            
            Node* temp = top;
            while (temp->next != bottom) {
                temp = temp->next;
            }
            
            delete bottom;
            bottom = temp;
            bottom->next = NULL;
            size--;
        }
        
        void delete_at_index(int index) {
            if (index < 0 || index >= size) {
                return;
            }
            
            if (index == 0) {
                pop();
                return;
            }
            
            if (index == size - 1) {
                delete_bottom();
                return;
            }
            
            Node* temp = top;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            
            Node* to_delete = temp->next;
            temp->next = to_delete->next;
            delete to_delete;
            size--;
        }
        
        int top_data() {
            if (is_empty()) {
                return -1; // Or any other error value
            }
            
            return top->data;
        }
        
        void display() {
            if (is_empty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    Stack stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.pop();
    stack.delete_bottom();
    stack.delete_at_index(0);
    cout << "Top data: " << stack.top_data() << endl;
    stack.display();
    return 0;
}