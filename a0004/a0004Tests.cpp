#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0004.h"

TEST_CASE("isPrime - testing to see if the function works at all")
{
    int input = 0;
    bool primeTest;
    primeTest = isPrime( input);
    
    REQUIRE (primeTest == false);
}

TEST_CASE("isPrime - testing the funtion at 1")
{
    int input = 1;
    bool primeTest;
    primeTest = isPrime( input);
    
    REQUIRE (primeTest == false);
}

TEST_CASE("isPrime - testing the function at 2")
{
    int input = 2;
    bool primeTest;
    primeTest = isPrime( input);
    
    REQUIRE (primeTest == true);
}

TEST_CASE("isPrime - testing the function at 3")
{
    int input = 3;
    bool primeTest;
    primeTest = isPrime( input);
    
    REQUIRE (primeTest == true);
}

TEST_CASE("isPrime - testing the function at 4")
{
    int input = 4;
    bool primeTest;
    primeTest = isPrime( input);
    
    REQUIRE (primeTest == false);
}

TEST_CASE("isPrime - testing the function at 5")
{
    int input = 5;
    bool primeTest;
    primeTest = isPrime( input);
    
    REQUIRE (primeTest == true);
}

TEST_CASE("isPrime - testing the function at 7")
{
    int input = 7;
    bool primeTest;
    primeTest = isPrime( input);
    
    REQUIRE (primeTest == true);
}

TEST_CASE("isPrime - testing the function at 16")
{
    int input = 16;
    bool primeTest;
    primeTest = isPrime( input);
    
    REQUIRE (primeTest == false);
}

TEST_CASE("isPrime - testing the function at 35 to test a higher odd composite number")
{
    int input = 35;
    bool primeTest;
    primeTest = isPrime( input);
    
    REQUIRE (primeTest == false);
}

TEST_CASE("isPrime - testing the function at 3975 because it is a large random odd number I just thought of")
{
    int input = 3975;
    bool primeTest;
    primeTest = isPrime( input);
    
    REQUIRE (primeTest == false);
}

TEST_CASE("isPrime - testing 23")
{
    int input = 23;
    bool primeTest;
    primeTest = isPrime( input);
    
    REQUIRE (primeTest == true);
}

TEST_CASE("isPrime - testing at 24")
{
    int input = 24;
    bool primeTest;
    primeTest = isPrime( input);
    
    REQUIRE (primeTest == false);
}

TEST_CASE("isTwinPrime - testing to see if I can just get the function to return a boolean value")
{
    int input = 11;
    bool twinPrimeTest;
    twinPrimeTest = isTwinPrime( input);
    
    REQUIRE (twinPrimeTest == true);
}

TEST_CASE("isTwinPrime - testing at 13 to see if the function actually works")
{
    int input = 13;
    bool twinPrimeTest;
    twinPrimeTest = isTwinPrime( input);
    
    REQUIRE (twinPrimeTest == true);
}

TEST_CASE("isTwinPrime - testing at 23 for a prime that is not a twin prime")
{
    int input = 23;
    bool twinPrimeTest;
    twinPrimeTest = isTwinPrime( input);
    
    REQUIRE (twinPrimeTest == false);
}

TEST_CASE("isTwinPrime - testing 24 because it is not prime to make sure the function will return a false value")
{
    int input = 24;
    bool twinPrimeTest;
    twinPrimeTest = isTwinPrime( input);
    
    REQUIRE (twinPrimeTest == false);
}

TEST_CASE("isTwinPrime - testing at 59 for a twin prime")
{
    int input = 59;
    bool twinPrimeTest;
    twinPrimeTest = isTwinPrime(input);
    
    REQUIRE (twinPrimeTest == true);
}

TEST_CASE("isTwinPrime - testing 61 to test the other side of the twin prime")
{
    int input = 61;
    bool twinPrimeTest;
    twinPrimeTest = isTwinPrime(input);
    
    REQUIRE (twinPrimeTest == true);
}

TEST_CASE("nextPrime - testing lower boundary of nextPrime with input 1")
{
    int input = 1;
    int nPrime;
    nPrime = nextPrime(input);
    
    REQUIRE (nPrime == 2);
}

TEST_CASE("nextPrime - testing 3 to see if the function will give back 5")
{
    int input = 3;
    int nPrime;
    nPrime = nextPrime(input);
    
    REQUIRE (nPrime == 5);
}

TEST_CASE("nextPrime - testing 5 to see if the function will return 7")
{
    int input = 5;
    int nPrime;
    nPrime = nextPrime(input);
    
    REQUIRE (nPrime == 7);
}

TEST_CASE("nextPrime - testing 79 to see if the function will return 83")
{
    int input = 79;
    int nPrime;
    nPrime = nextPrime(input);
    
    REQUIRE (nPrime == 83);
}

TEST_CASE("nextPrime - testing a very high prime number to test closer to upper boundary")
{
    int input = 4159;
    int nPrime;
    nPrime = nextPrime(input);
    
    REQUIRE (nPrime == 4177);
}

TEST_CASE("nextPrime - testing an even number input")
{
    int input = 4;
    int nPrime;
    nPrime = nextPrime(input);
    
    REQUIRE (nPrime == 5);
}

