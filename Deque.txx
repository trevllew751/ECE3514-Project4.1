#include "deque.hpp"

template<typename T>
Deque<T>::Deque() : frontIndex(-1), rearIndex(0), size(0), capacity(INITIAL_CAPACITY) {
    items = new T[INITIAL_CAPACITY];
}

template<typename T>
Deque<T>::Deque(Deque<T> &other) {
    this->frontIndex = other.frontIndex;
    this->rearIndex = other.rearIndex;
    this->size = other.size;
    this->capacity = other.capacity;
    items = new T[capacity];
    std::copy(std::begin(other.items), std::end(other.items), std::begin(items));
}

template<typename T>
Deque<T>::~Deque() {
    delete[] items;
}

//template<typename T>
//Deque<T> &Deque<T>::operator=(Deque rhs) {
//    return <#initializer#>;
//}

template<typename T>
bool Deque<T>::isEmpty() {
    return size == 0;
}

template<typename T>
void Deque<T>::pushFront(const T &item) {
    if (size + 1 == capacity) {
        resize();
    }
    if (frontIndex == -1) {
        frontIndex = 0;
    } else if (frontIndex == 0) {
        frontIndex = capacity - 1;
    } else {
        frontIndex--;
    }
    items[frontIndex] = item;
    size++;
}

template<typename T>
void Deque<T>::popFront() {
    if (isEmpty()) {
        throw std::runtime_error("Error: Empty Deque");
    }
    if (frontIndex == rearIndex) {
        frontIndex = -1;
        rearIndex = -1;
    } else {
        if (frontIndex == capacity - 1) {
            frontIndex = 0;
        } else {
            frontIndex++;
        }
    }
    size--;
}

template<typename T>
T Deque<T>::front() {
    return items[frontIndex];
}

template<typename T>
void Deque<T>::pushBack(const T &item) {
    if (size + 1 == capacity) {
        resize();
    }
    if (frontIndex == -1) {
        frontIndex = 0;
    } else if (rearIndex == capacity - 1) {
        rearIndex = 0;
    } else {
        rearIndex++;
    }
    items[rearIndex] = item;
    size++;
}

template<typename T>
void Deque<T>::popBack() {
    if (isEmpty()) {
        throw std::runtime_error("Error: Empty Deque");
    }
    if (frontIndex == rearIndex) {
        frontIndex = -1;
        rearIndex = -1;
    } else if (rearIndex == 0) {
        rearIndex = capacity - 1;
    } else {
        rearIndex--;
    }
    size--;
}

template<typename T>
T Deque<T>::back() {
    return items[rearIndex];
}

template<typename T>
void Deque<T>::resize() {

}
