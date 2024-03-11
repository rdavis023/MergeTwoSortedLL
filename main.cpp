#include <iostream>

using namespace std;

class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail; 
        }

        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

       void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }

    //   +=====================================================+
    //   |                WRITE YOUR CODE HERE                 |
    //   | Description:                                        |
    //   | - This method merges two sorted linked lists        |
    //   |   into a single sorted linked list.                 |
    //   | - Utilizes a dummy node to simplify merging.        |
    //   |                                                     |
    //   | Return type: void                                   |
    //   | - Modifies the list in place.                       |
    //   | - Sets the 'head' and 'tail' pointers correctly.    |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - Uses a dummy node for easier linking.             |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
    void merge(LinkedList& other) {
    Node* dummyHead = new Node(0); // Temporary dummy node to simplify list manipulation
    Node* tail = dummyHead; // Points to the last node of the new sorted list

    Node* l1 = this->head; // Pointer to the current list's nodes
    Node* l2 = other.head; // Pointer to the other list's nodes

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->value < l2->value) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // At least one of l1 and l2 can still have elements left; attach the remainder
    tail->next = (l1 != nullptr) ? l1 : l2;

    // Update head and tail of the current list
    this->head = dummyHead->next;
    if (this->head == nullptr) {
        // If the resulting list is empty, also reset the tail
        this->tail = nullptr;
    } else {
        // Otherwise, find the new tail
        Node* newTail = this->head;
        while (newTail->next != nullptr) {
            newTail = newTail->next;
        }
        this->tail = newTail;
    }

    // Adjust the length, simple way but not efficient
    Node* temp = this->head;
    int newLength = 0;
    while (temp != nullptr) {
        newLength++;
        temp = temp->next;
    }
    this->length = newLength;

    // Clean up
    delete dummyHead; // Delete the dummy head node

    // Reset the other list to prevent double deletion of nodes
    other.head = nullptr;
    other.tail = nullptr;
    other.length = 0;
}

};


