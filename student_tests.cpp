#include "catch.hpp"
#include "Deque.hpp"

TEST_CASE( "Peek at empty deque", "[deque]" )
{
  Deque<int> dq;
  
  REQUIRE_THROWS_AS(dq.peek(), std::range_error);
}
