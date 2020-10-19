#include <iostream>
using namespace std;
class Node {
    public:
        int data;
        Node *next;
        Node(int _data) {
            data = _data;
            next = NULL;
        }
};
class Stack {
    private:
        Node *top;
        int size, MAX;
    public:
        Stack() {
            top = NULL;
            size = 0;
            MAX = 10;
        }
        ~Stack() {
            cout << "End of stack";
        }
        bool isEmpty() {
            return top == NULL;
        }
        void push(int data) {
            if (isEmpty()) {
                top = new Node(data);
                size++; 
            }
            else if (size > MAX) {
                cout << "Stack is full." << endl;
            }
            else {
             Node *newNode = new Node(data);
                newNode->next = top;
                top = newNode;
                size++;
            }

        }
        int pop() {
            if (isEmpty()) {
                cout << "Stack is empty." << endl;
                return -1;
            }
            int data = top->data;
            top = top->next;
            size--;
            return data;
        }

};
int main() {
    Stack stack;
    for (int i=1 ; i<=10 ; i++) {
        stack.push(i);
    }
    while (!stack.isEmpty()) {
        cout << stack.pop() << " -> ";
    }
    cout << "NULL" << endl;
    
}