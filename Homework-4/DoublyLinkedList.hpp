// DoublyLinkedList.hpp

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdexcept>

template <typename Type>
class DoublyLinkedList {

public:
    DoublyLinkedList();
    ~DoublyLinkedList(); // Destructor to free memory
    unsigned int size() const;
    bool isEmpty() const;
    void insert(const Type& e);
    unsigned int find(Type& e);
    void erase(unsigned int index);
    void show() const;
    void sort();
    Type& getHead() const;
    Type& getTail() const;
    Type& operator[] (const unsigned int index) const;

private:
    struct Node {
        Type data;
        Node* prev;
        Node* next;
    };

    unsigned int n;
    Node* header;
    Node* trailer;

    Node* merge(Node* left, Node* right);
};

// Implementation of inline member functions

// Constructors
template <typename Type>
DoublyLinkedList<Type>::DoublyLinkedList() : n(0) {
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

// Destructor
template <typename Type>
DoublyLinkedList<Type>::~DoublyLinkedList() {
    while (!isEmpty()) {
        erase(0);
    }
    delete header;
    delete trailer;
}

// Getters
template <typename Type>
unsigned int DoublyLinkedList<Type>::size() const {
    return n;
}

template <typename Type>
bool DoublyLinkedList<Type>::isEmpty() const {
    return n == 0;
}

template <typename Type>
Type& DoublyLinkedList<Type>::getHead() const {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    return header->next->data;
}

template <typename Type>
Type& DoublyLinkedList<Type>::getTail() const {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    return trailer->prev->data;
}

// Insertion
template <typename Type>
void DoublyLinkedList<Type>::insert(const Type& e) {
    Node* newNode = new Node{ e, trailer->prev, trailer };
    trailer->prev->next = newNode;
    trailer->prev = newNode;
    n++;  // Increment the size after insertion.
}

// Finding
template <typename Type>
unsigned int DoublyLinkedList<Type>::find(Type& e) {
    Node* current = header->next;
    unsigned int index = 0;

    while (current != trailer) {
        if (current->data == e) {
            return index;
        }
        current = current->next;
        index++;
    }

    // Element not found, throw an exception or return a special value (-1)
    throw std::out_of_range("Element not found in the list.");
    // Alternatively, you can return a special value like -1 to indicate not found:
    // return -1;
}

// Erasing
template <typename Type>
void DoublyLinkedList<Type>::erase(unsigned int index) {
    if (index >= n) {
        throw std::out_of_range("Index out of range.");
    }

    Node* current = header->next;
    for (unsigned int i = 0; i < index; ++i) {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    n--; // Update the size
}

// Displaying
template <typename Type>
void DoublyLinkedList<Type>::show() const {
    Node* current = header->next;
    while (current != trailer) {
        // Implement your own way of displaying the data (e.g., std::cout)
        // For now, let's assume Type supports std::cout
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Sorting
template <typename Type>
void DoublyLinkedList<Type>::sort() {
    for (Node* i = header->next; i->next != trailer; i = i->next) {
        for (Node* j = header->next; j->next != trailer; j = j->next) {
            if (j->data > j->next->data) {
                // Swap data
                Type temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

template <typename Type>
typename DoublyLinkedList<Type>::Node* DoublyLinkedList<Type>::merge(Node* left, Node* right) {
    Node dummy;
    Node* current = &dummy;

    while (left != nullptr && right != nullptr) {
        if (left->data < right->data) {
            current->next = left;
            left->prev = current;
            left = left->next;
        }
        else {
            current->next = right;
            right->prev = current;
            right = right->next;
        }

        current = current->next;
    }

    if (left != nullptr) {
        current->next = left;
        left->prev = current;
    }

    if (right != nullptr) {
        current->next = right;
        right->prev = current;
    }

    return dummy.next;
}

// Overloaded subscript operator
template <typename Type>
Type& DoublyLinkedList<Type>::operator[](const unsigned int index) const {
    if (index >= n) {
        throw std::out_of_range("Index out of bounds");
    }
    Node* current = header->next;
    for (unsigned int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

#endif /* DoublyLinkedList_hpp */