#include <iostream>
using namespace std;

// Constants varible
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

// The Definition of the DoublyLinkedList class
class DoublyLinkedList {
private:
    // Definition of the Node structure
    struct Node {
        int data;       // The value stored in the node
        Node* prev;     // Pointer to the previous node
        Node* next;     // Pointer to the next node

        // Constructor for Node
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val;     // Initialize data with val
            prev = p;       // Initialize prev with p 
            next = n;       // Initialize next with n 
        }
    };

    Node* head; // Pointer to the first node in the list
    Node* tail; // Pointer to the last node in the list

public:
    // Constructor for DoublyLinkedList
    DoublyLinkedList() {
        head = nullptr; // Initialize head to nullptr (with empty list)
        tail = nullptr; // Initialize tail to nullptr (with empty list)
    }

    // Method to insert a new node with value 'value' after position 'position'
    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        // Create a new node with the given value
        Node* newNode = new Node(value);

        if (!head) {
            // If the list is empty, set head and tail to the new node
            head = tail = newNode;
            return;
        }

        // Start from the head node
        Node* temp = head;

        // Move temp to the node at the given position
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            // If position exceeds list size
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode; // Free the memory allocated for newNode
            return;
        }

        // Insert newNode after temp
        newNode->next = temp->next; // newNode's next points to temp's next
        newNode->prev = temp;       // newNode's prev points to temp

        if (temp->next)
            temp->next->prev = newNode; // Update next node's prev to newNode
        else
            tail = newNode;             // If temp was the tail, update tail

        temp->next = newNode;           // temp's next points to newNode
    }

    // Method to delete the first node with the given value
    void delete_val(int value) {
        if (!head) {
            // If the list is empty nothing need to be delete
            return;
        }

        Node* temp = head;

        // Traverse the list to find the node with the specified value
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) {
            // Value not found in the list
            return;
        }

        // Adjust pointers to remove temp from the list
        if (temp->prev) {
            // If temp is not the head, update the previous node's next pointer
            temp->prev->next = temp->next;
        } else {
            // If temp is the head, update the head pointer
            head = temp->next;
        }

        if (temp->next) {
            // If temp is not the tail, update the next node's prev pointer
            temp->next->prev = temp->prev;
        } else {
            // If temp is the tail, update the tail pointer
            tail = temp->prev;
        }

        delete temp; // Free memory to prevent leak
    }

    // Method to delete a node at a specific position (1-based index)
    void delete_pos(int pos) {
        if (!head) {
            // List is empty
            cout << "List is empty." << endl;
            return;
        }

        if (pos == 1) {
            // Delete the first node
            pop_front();
            return;
        }

        Node* temp = head;

        // Traverse to the node at the specified position
        for (int i = 1; i < pos; ++i) {
            if (!temp) {
                // Position is beyond the list length
                cout << "Position doesn't exist." << endl;
                return;
            }
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }

        if (!temp->next) {
            // Delete the last node
            pop_back();
            return;
        }

        // Adjust pointep from the list
        Node* tempPrev = temp->prev; // Node temp
        tempPrev->next = temp->next; // Skip  thpointer
        temp->next->prev = tempPrev; 

        delete temp; // Free memory to prevent leak
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}