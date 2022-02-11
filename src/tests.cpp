#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "my_math.hpp"

// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

TEST_CASE("Addition")
{

    SECTION("0 + 0 is also zero")
    {

        REQUIRE(sum(0, 0) == 0);
    }

    SECTION("0 + 1 is 1")
    {
        REQUIRE(sum(0, 1));
    }
}
