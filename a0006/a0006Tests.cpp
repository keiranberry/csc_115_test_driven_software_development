#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0006.h"

TEST_CASE( "createLookup - testing all zeros")
{
    int i;
    int lookup[7];
    int die [5] {0, 0, 0, 0, 0};
    
    createLookup(lookup, die, 0);
    
    for (i=0; i<7; i++)
    {
        REQUIRE(lookup[i] == 0);
    }
}

TEST_CASE( "createLookup - testing actual numbers to see if the function will work")
{
    int i;
    int lookup[7];
    int die [3] {1, 2, 2};
    
    createLookup(lookup, die, 3);
    
    REQUIRE(lookup[2] == 2);
    
}

TEST_CASE( "createLookup - testing multiple lookups at a time")
{
    int i;
    int lookup[7];
    int die [6] {1, 2, 3, 4, 5, 6};
    
    createLookup(lookup, die, 6);
    
    REQUIRE(lookup[1] == 1);
    REQUIRE(lookup[2] == 1);
    REQUIRE(lookup[3] == 1);
    REQUIRE(lookup[4] == 1);
    REQUIRE(lookup[5] == 1);
    REQUIRE(lookup[6] == 1);
    
}

TEST_CASE( "createLookup - testing some random rolls to confirm the function's functionality")
{
    int i;
    int lookup[7];
    int die [8] {1, 2, 4, 6, 4, 3, 6, 1};
    
    createLookup(lookup, die, 8);
    
    REQUIRE(lookup[6] == 2);
    
}

TEST_CASE( "fewestRolled - testing for functionaluty of fewestRolled")
{
    int leastRolls;
    int lookup[7];
    int die [11] = { 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    
    createLookup( lookup, die, 11);
    
    leastRolls = fewestRolled( lookup, 7);
    
    REQUIRE( leastRolls == 4);
}

TEST_CASE( "fewestRolled - testing when the lookup of the fewest returns 0")
{
    int leastRolls;
    int lookup[7];
    int die [5] = { 1, 2, 3, 4, 5};
    
    createLookup( lookup, die, 5);
    
    leastRolls = fewestRolled( lookup, 7);
    
    REQUIRE( leastRolls == 6);
}

TEST_CASE( "fewestRolled - testing when 2 fewests exist (should return the one with lower numerical value)")
{
    int leastRolls;
    int lookup[7];
    int die [10] = {1, 1, 2, 3, 4, 4, 5, 5, 6, 6};
    
    createLookup( lookup, die, 10);
    
    leastRolls = fewestRolled( lookup, 7);
    
    REQUIRE( leastRolls == 2);
}

TEST_CASE( "mostRolled - testing for functionality of mostRolled")
{
    int highestRolls;
    int lookup[7];
    int die [7] = {1, 2, 3, 4, 5, 6, 6};
    
    createLookup( lookup, die, 7);
    
    highestRolls = mostRolled( lookup, 7);
    
    REQUIRE( highestRolls == 6);
}

TEST_CASE( "mostRolled - testing mostRolled when most values in the array are 0")
{
    int highestRolls;
    int lookup[7];
    int die [1] = {4};
    
    createLookup( lookup, die, 1);
    
    highestRolls = mostRolled( lookup, 7);
    
    REQUIRE( highestRolls == 4);
}

TEST_CASE( "mostRolled - further testing of mostRolled just because I don't know what else to test tbh")
{
    int highestRolls;
    int lookup[7];
    int die [12] = {2, 4, 3, 5, 4, 6, 5, 1, 3, 2, 6, 4};
    
    createLookup( lookup, die, 12);
    
    highestRolls = mostRolled( lookup, 7);
    
    REQUIRE( highestRolls == 4);
}

TEST_CASE( "sumRolls - testing for functionality")
{
    int sum;
    int lookup[7];
    int die[3] = {1, 2, 3};
    
    createLookup( lookup, die, 3);
    
    sum = sumRolls (lookup, 7);
    
    REQUIRE( sum == 6);
}

TEST_CASE( "sumRolls - testing sumRolls further")
{
    int sum;
    int lookup[7];
    int die[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    createLookup( lookup, die, 9);
    
    sum = sumRolls (lookup, 7);
    
    REQUIRE( sum == 9);
}

TEST_CASE( "sumRolls - testing sumRolls on a large scale")
{
    int sum;
    int lookup[7];
    int die[18] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6};
    
    createLookup( lookup, die, 18);
    
    sum = sumRolls (lookup, 7);
    
    REQUIRE( sum == 63);
}