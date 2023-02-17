#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0003.h"

TEST_CASE("countCharacters - testing to make sure the function wil return a value")
{
    string inputString = "initial";
    int amount;
    amount = countCharacters( inputString , 'z');
    REQUIRE( amount == 0);
}

TEST_CASE("countCharacters - testing to see if the function works at all")
{
    string inputString = "Hello";
    int amount;
    amount = countCharacters( inputString, 'l');
    REQUIRE( amount == 2);
}

TEST_CASE("countCharacters - testing to see if the function can detect lowercase and uppercase letters")
{
    string inputString = "I am testing to see if tolower is working";
    int amount;
    amount = countCharacters( inputString, 'I');
    REQUIRE( amount == 5);
}

TEST_CASE("countCharacters - testing to see if the function can tolower things other than the first letter")
{
    string inputString = "here is a test to sHow tHat my function can work with uppercase";
    int amount;
    amount = countCharacters( inputString, 'h');
    REQUIRE( amount == 4);
} 