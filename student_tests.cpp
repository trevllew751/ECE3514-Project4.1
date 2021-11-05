#include "catch.hpp"
#include "Deque.hpp"

TEST_CASE("Peek at empty deque", "[deque]") {
    Deque<int> dq;
    REQUIRE(dq.isEmpty());
    REQUIRE_THROWS_AS(dq.front(), std::runtime_error);
    REQUIRE_THROWS_AS(dq.back(), std::runtime_error);
}

TEST_CASE("Test pushBack and back", "[Deque]") {
    Deque<int> dq;
    REQUIRE(dq.isEmpty());
    dq.pushBack(1);
    REQUIRE(dq.back() == 1);
    dq.pushBack(2);
    REQUIRE(dq.back() == 2);
    dq.pushBack(3);
    REQUIRE(dq.back() == 3);
    dq.pushBack(4);
    REQUIRE(dq.back() == 4);
    REQUIRE(dq.front() == 1);
    REQUIRE_FALSE(dq.isEmpty());
}

TEST_CASE("Test pushFront and front", "[Deque]") {
    Deque<int> dq;
    REQUIRE(dq.isEmpty());
    dq.pushFront(1);
    REQUIRE(dq.front() == 1);
    dq.pushFront(2);
    REQUIRE(dq.front() == 2);
    dq.pushFront(3);
    REQUIRE(dq.front() == 3);
    dq.pushFront(4);
    REQUIRE(dq.front() == 4);
    REQUIRE(dq.back() == 1);
    REQUIRE_FALSE(dq.isEmpty());
}

TEST_CASE("Test push both", "[Deque]") {
    Deque<int> dq;

    REQUIRE(dq.isEmpty());
    dq.pushFront(1);
    REQUIRE(dq.front() == 1);
    dq.pushFront(2);
    REQUIRE(dq.front() == 2);
    dq.pushBack(3);
    REQUIRE(dq.back() == 3);
    dq.pushBack(4);
    REQUIRE(dq.back() == 4);
    REQUIRE(dq.front() == 2);
    REQUIRE_FALSE(dq.isEmpty());
}
// TODO: Fix pop methods for when the deque becomes empty
TEST_CASE("Test popBack and popFront", "[Deque]") {
    Deque<int> dq;

    REQUIRE(dq.isEmpty());
    dq.pushFront(1);
    dq.pushFront(2);
    dq.pushBack(3);
    dq.pushBack(4);
    REQUIRE(dq.front() == 2);
    REQUIRE(dq.back() == 4);
    dq.popFront();
    dq.popBack();
    REQUIRE(dq.front() == 1);
    REQUIRE(dq.back() == 3);
    dq.popFront();
    dq.popBack();
    REQUIRE(dq.isEmpty());
    dq.pushFront(1);
    dq.pushBack(2);
    REQUIRE(dq.front() == 1);
    REQUIRE(dq.back() == 2);
}

TEST_CASE("Test copy constructor", "[Deque]") {
    Deque<int> dq;
    REQUIRE(dq.isEmpty());
    dq.pushFront(1);
    REQUIRE(dq.front() == 1);
    dq.pushFront(2);
    REQUIRE(dq.front() == 2);
    dq.pushBack(3);
    REQUIRE(dq.back() == 3);
    dq.pushBack(4);
    REQUIRE(dq.back() == 4);

    Deque<int> dq1(dq);
    REQUIRE(dq1.front() == 2);
    REQUIRE(dq1.back() == 4);
    dq1.popFront();
    dq1.popBack();
    REQUIRE(dq1.front() == 1);
    REQUIRE(dq1.back() == 3);
}

TEST_CASE("Test operator=", "[Deque]") {
    Deque<int> dq;
    dq.pushFront(1);
    dq.pushFront(2);
    dq.pushBack(3);
    dq.pushBack(4);

    Deque<int> dq1 = dq;
    REQUIRE(dq1.front() == 2);
    REQUIRE(dq1.back() == 4);
    dq1.popFront();
    dq1.popBack();
    REQUIRE(dq1.front() == 1);
    REQUIRE(dq1.back() == 3);
}

TEST_CASE("Test resize", "[Deque]") {
    Deque<int> dq;
    for (int i = 0; i < 32; i++) {
        dq.pushBack(i);
    }
    for (int i = 0; i < 33; i++) {
        dq.pushFront(i);
    }
    REQUIRE(dq.front() == 32);
}