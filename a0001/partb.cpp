#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include <cmath>

using namespace std;

TEST_CASE("pow - 2.35 to the 5.67 power")
{
    double base = 2.35;
    double exponent = 5.67;
    double answer;
    
    answer = pow(base, exponent);
    REQUIRE( answer == Approx(127.04418)); //testing example code for practice 
}


TEST_CASE("pow - 234 to the 10 power")
{
    double base = 234;
    double exponent = 10;
    double answer;
    
    answer = pow(base, exponent);
    REQUIRE( answer == Approx(4.9221923E23)); //trying an answer with scientific notation
}


TEST_CASE("pow - 2E10 to the 7 power")
{
    double base = 2E10;
    double exponent = 7;
    double answer;
    
    answer = pow(base, exponent);
    REQUIRE( answer == Approx(1.28E72)); //trying a base with scientific notation
}


TEST_CASE("pow - 4 to the 2E2 power")
{
    double base = 4;
    double exponent = 2E2;
    double answer;
    
    answer = pow(base, exponent);
    REQUIRE( answer == Approx(2.58225E120)); //trying an exponent with scientific notation
}


TEST_CASE("log10 - log10(20)")
{
    double param = 20;
    double answer;
    
    answer = log10(20);
    REQUIRE( answer == Approx(1.30102)); //trying simple numbers for proof of concept
}


TEST_CASE("log10 - log10(1000)")
{
    double param = 1000;
    double answer;
    
    answer = log10(1000);
    REQUIRE( answer == 3); //trying something which should have an integer answer with no need for approx
}


TEST_CASE("log10 - log10(4.5587)")
{
    double param = 4.5587;
    double answer;
    
    answer = log10(4.5587);
    REQUIRE( answer == Approx(.65884)); //trying a decimal param
}


TEST_CASE("log10 - log10(.678954)")
{
    double param = .678954;
    double answer;
    
    answer = log10(.678954);
    REQUIRE( answer == Approx(-.168159)); //trying a negative answer
}


    