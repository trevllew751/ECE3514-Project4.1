#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"

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
    T items[];

};

#include "Deque.txx"

#endif
