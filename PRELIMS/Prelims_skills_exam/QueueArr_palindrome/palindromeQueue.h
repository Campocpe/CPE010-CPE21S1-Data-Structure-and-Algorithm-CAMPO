#ifndef PALINDROMEQUEUE_H
#define PALINDROMEQUEUE_H

#include <iostream>

template <typename T>
class queueArr {
private:
    T* q_array;
    size_t q_capacity;
    size_t q_size;
    int q_front;
    int q_back;

public:
    queueArr(size_t capacity);
    ~queueArr();

    bool empty();
    bool full();
    size_t size();
    void Clear();

    T Front();
    T Back();

    void Enqueue(T newData);
    void Dequeue();
};

// Constructor
template <typename T>
queueArr<T>::queueArr(size_t capacity) {
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new T[q_capacity];
}

// Destructor
template <typename T>
queueArr<T>::~queueArr() {
    delete[] q_array;
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

// Clear()
template <typename T>
void queueArr<T>::Clear() {
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

// Return Front Element
template <typename T>
T queueArr<T>::Front() {
    if (empty()) {
        return T{};
    }
    return q_array[q_front];
}

// Return Back Element
template <typename T>
T queueArr<T>::Back() {
    if (empty()) {
        return T{};
    }
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
    if (full()) {
        return;
    }
    q_back = (q_back + 1) % q_capacity;
    q_array[q_back] = newData;
    q_size++;
}

// Dequeue
template <typename T>
void queueArr<T>::Dequeue() {
    if (empty()) {
        return;
    }
    q_front = (q_front + 1) % q_capacity;
    q_size--;
}

#endif 