#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

// Array-based circular queue
template <typename T>
class queueArr {
    private:
        // Creates a dynamically allocated queue array (pointer array)
        T* q_array;
        size_t q_capacity;
        size_t q_size;
        int q_front;
        int q_back;

    public:
        // Prototypes of member functions:

        // Constructor
        queueArr(size_t capacity);
        bool empty();
        bool full();

        size_t size();
        void Clear();

        T Front();
        T Back();

        void Enqueue(T newData);
        void Dequeue();

        // Destructor
        ~queueArr();

        // Copy constructor and assignment operator
        queueArr(const queueArr& other);
        queueArr& operator=(const queueArr& other);
};

// Constructor
template <typename T>
queueArr<T>::queueArr(size_t capacity) {
    // Capacity of the array
    q_capacity = capacity;

    // Current size of the array
    q_size = 0;

    // Initial front and back index
    q_front = 0;
    q_back = -1;

    // Newly allocated array
    q_array = new T[q_capacity];
    std::cout << "Queue created with capacity: " << q_capacity << std::endl;    
}

// Destructor
template <typename T>
queueArr<T>::~queueArr() {
    delete[] q_array;
    std::cout << "Queue destroyed." << std::endl;
}

// empty()
template <typename T>
bool queueArr<T>::empty() {
    return q_size == 0;
}

// full()
template <typename T>
bool queueArr<T>::full() {
    return q_size == q_capacity;
}

// Clear
template <typename T>
void queueArr<T>::Clear() {
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

// Return the element at the front of the queue
template <typename T>
T queueArr<T>::Front() {
    // Check and display if the queue is empty
    if (empty()) {
        std::cout << "Queue is empty. \n" << std::endl;
        return T{}; // Return default value of T
    }
    // Return the front element
    return q_array[q_front];
}

// Return the element at the back of the queue
template <typename T>
T queueArr<T>::Back() {      
    // Check and display if the queue is empty
    if (empty()) {
        std::cout << "Queue is empty. \n" << std::endl;
        return T{}; // Return default value of T
    }
    // Return the back element
    return q_array[q_back];
}

// Size
template <typename T>
size_t queueArr<T>::size() {
    return q_size;
}

// Enqueue
template <typename T>
void queueArr<T>::Enqueue(T newData) {
    // Check if the queue is full
    if (full()) {
        std::cout << "Queue is full." << std::endl;
        return;
    }

    // Compute for q_back to move it circularly (clue: use modulo)
    q_back = (q_back + 1) % q_capacity;

    // Assign the new value to the back of the queue array
    q_array[q_back] = newData;

    // Increment the q_size
    q_size++;
}

// Dequeue
template <typename T>
void queueArr<T>::Dequeue() {
    // Check if the queue is empty
    if (empty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    // Compute for q_front to move it circularly
    q_front = (q_front + 1) % q_capacity;

    // Decrement the q_size
    q_size--;
}

#endif // QUEUEARR_H