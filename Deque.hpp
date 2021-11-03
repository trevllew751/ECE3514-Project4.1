#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"
#include <algorithm>
#include <iterator>

#define INITIAL_CAPACITY 64

template<typename T>
class Deque : public AbstractDeque<T> {
public:

    Deque();

    Deque(Deque<T> &other);

    ~Deque();

    Deque &operator=(Deque rhs);

    bool isEmpty();

    void pushFront(const T &item);

    void popFront();

    T front();

    void pushBack(const T &item);

    void popBack();

    T back();

private:
    T* items;
    int frontIndex;
    int rearIndex;
    int size;
    int capacity;

    void resize();
};

#include "Deque.txx"

#endif
