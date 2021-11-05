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
    std::copy(other.items, other.items + other.capacity, items);
}

template<typename T>
Deque<T>::~Deque() {
    delete[] items;
}

template<typename T>
Deque<T> &Deque<T>::operator=(Deque rhs) {
    if (this != rhs) {
        Deque<T> temp(rhs);
        swap(*this, rhs);
        this->frontIndex = rhs.frontIndex;
        this->rearIndex = rhs.rearIndex;
        this->size = rhs.size;
        this->capacity = rhs.capacity;
    }
    return *this;
}

template<typename T>
bool Deque<T>::isEmpty() const noexcept {
    return size == 0;
}

template<typename T>
void Deque<T>::pushFront(const T &item) {
    if (size == capacity) {
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
        rearIndex = 0;
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
T Deque<T>::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Error: Empty deque");
    }
    return items[frontIndex];
}

template<typename T>
void Deque<T>::pushBack(const T &item) {
    if (size == capacity) {
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
        rearIndex = 0;
    } else if (rearIndex == 0) {
        rearIndex = capacity - 1;
    } else {
        rearIndex--;
    }
    size--;
}

template<typename T>
T Deque<T>::back() const {
    if (isEmpty()) {
        throw std::runtime_error("Error: Empty deque");
    }
    return items[rearIndex];
}

template<typename T>
void Deque<T>::resize() {
    capacity *= 2;
    int newFront = capacity - frontIndex;
    T* temp = new T[capacity];
    if (rearIndex != 0) {
        std::copy(items, items + rearIndex + 1, temp);
    }
    if (frontIndex != 0) {
        for (int i = newFront; i < capacity; i++) {
            temp[i] = front();
            popFront();
        }
    }
    delete [] items;
    items = nullptr;
    items = temp;
    frontIndex = newFront;
}

template<typename T>
void Deque<T>::swap(Deque &lhs, Deque &rhs) {
    T *temp = lhs.items;
    lhs.items = rhs.items;
    rhs.items = temp;
}
