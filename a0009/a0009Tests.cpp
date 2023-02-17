#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0009.h"

TEST_CASE("swapStrings - milk, apple")
{
    char string1[50] = "milk";
    char string2[50] = "apple";
    
    swapStrings(string1, string2);
    
    REQUIRE( strcmp(string1, "apple") == 0);
    REQUIRE( strcmp(string2, "milk") == 0);
}

TEST_CASE("swapStrings - keiran, berry")
{
    char string1[50] = "keiran";
    char string2[50] = "berry";
    
    swapStrings(string1, string2);
    
    REQUIRE( strcmp(string1, "berry") == 0);
    REQUIRE( strcmp(string2, "keiran") == 0);
}


TEST_CASE("swapStrings - this is a string, this is another string")
{
    char string1[50] = "this is a string";
    char string2[50] = "this is another string";
    
    swapStrings(string1, string2);
    
    REQUIRE( strcmp(string1, "this is another string") == 0);
    REQUIRE( strcmp(string2, "this is a string") == 0);
}

TEST_CASE("sortOrder - initial test")
{
    char cStrings[3][21] = {"hello", "goodbye", "xylophone"};
    sortOrder(cStrings, 3);
    REQUIRE( strcmp( cStrings[0], "goodbye" )==0);
    REQUIRE( strcmp( cStrings[2], "xylophone" )==0);
}

TEST_CASE("sortOrder - testing a longer string")
{
    char cStrings[6][21] = {"banana", "apple", "zebra", "punch", "chocolate", "tea"};
    sortOrder(cStrings, 6);
    REQUIRE( strcmp( cStrings[0], "apple" )==0);
    REQUIRE( strcmp( cStrings[2], "chocolate" )==0);
    REQUIRE( strcmp( cStrings[5], "zebra" )==0);
}

TEST_CASE("sortOrder - testing words whose value is close to each other")
{
    char cStrings[4][21] = {"zebra", "zebrc", "zebrd", "zebrb"};
    sortOrder(cStrings, 4);
    REQUIRE( strcmp( cStrings[0], "zebra" )==0);
    REQUIRE( strcmp( cStrings[2], "zebrc" )==0);
    REQUIRE( strcmp( cStrings[3], "zebrd" )==0);
}

TEST_CASE("sortLen - initial test")
{
    char cStrings[4][21] = {"to", "four", "two", "a"};
    sortLen(cStrings, 4);
    REQUIRE( strcmp( cStrings[0], "a" )==0);
    REQUIRE( strcmp( cStrings[3], "four" )==0);
}

TEST_CASE("sortLen - testing more variety")
{
    char cStrings[6][21] = {"thisisreallylong", "thisislesslong", "ball", "fourteen", "strawberry", "thisisincrediblylong"};
    sortLen(cStrings, 6);
    REQUIRE( strcmp( cStrings[0], "ball" )==0);
    REQUIRE( strcmp( cStrings[3], "thisislesslong" )==0);
    REQUIRE( strcmp( cStrings[5], "thisisincrediblylong" )==0);
}

TEST_CASE("sortLen - testing with digits instead of characters")
{
    char cStrings[5][21] = {"88888888", "1010101010", "1", "333", "666666",};
    sortLen(cStrings, 5);
    REQUIRE( strcmp( cStrings[0], "1" )==0);
    REQUIRE( strcmp( cStrings[3], "88888888" )==0);
    REQUIRE( strcmp( cStrings[4], "1010101010" )==0);
}