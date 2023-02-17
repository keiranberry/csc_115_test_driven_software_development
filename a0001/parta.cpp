#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include <cctype>

using namespace std;

TEST_CASE( "toupper - testing lower boundary of an a")
{
    char achar = 'a';
    char result;
    
    result = toupper( achar );
    REQUIRE( result == 'A' );
}


TEST_CASE( "toupper - testing what happens if the variable is already capitalized")
{
    char Achar = 'A';
    char result;
    
    result = toupper( Achar );
    REQUIRE( result == 'A' ); //hopefully it will know not to change anything if already uppercase 
}


TEST_CASE( "toupper - testing what happens if a digit is inserted")
{
    int numfive = '5';
    int result;
    
    result = toupper( numfive );
    REQUIRE( result == '5' ); //should not change anything because numbers cannot be uppercase
}


TEST_CASE( "toupper - testing end of alphabet")
{
    char zchar = 'z';
    char result;
    
    result = toupper( zchar );
    REQUIRE( result == 'Z' ); //should change lowercase to uppercase, checking the other extreme of the alphabet
}


TEST_CASE( "islower - testing lower boundary of alphabet")
{
    char lowerA = 'a';
    bool result;
    
    result = islower( lowerA );
    REQUIRE( result == true ); //testing lower boundary of alphabet and generally seeing that the function works
}


TEST_CASE( "islower - testing upper boundary of alphabet")
{
    char lowerZ = 'z';
    bool result;
    
    result = islower( lowerZ );
    REQUIRE( result == true); //testing upper boundary of alphabet
}


TEST_CASE( "islower - testing an uppercase letter")
{
    char upperA = 'A';
    bool result;
    
    result = islower( upperA );
    REQUIRE( result == false); //testing that the function can detect that the letter in question is uppercase
}


TEST_CASE( "islower - testing a digit")
{
    int numSeven = '7';
    bool result;
    
    result = islower( numSeven );
    REQUIRE( result == false ); //interested to see what will happen with a number
}


TEST_CASE( "isdigit - testing a digit")
{
    int numEight = '8';
    bool result;
    
    result = isdigit( numEight );
    REQUIRE( result == true); //testing to make sure it works as expected on digits
}


TEST_CASE( "isdigit - testing a double digit number")
{
    int numEleven = '11';
    bool result;
    
    result = isdigit( numEleven );
    REQUIRE( result == false); //I think that it should be false because it isn't 0-9
}

TEST_CASE( "isdigit - testing a letter")
{
    char lowerG = 'g';
    bool result;
    
    result = isdigit( lowerG );
    REQUIRE( result == false); //should be false, a letter is not a number
}

TEST_CASE( "isdigit - testing an uppercase letter")
{
    char upperT = 'T';
    bool result;
    
    result = isdigit( upperT );
    REQUIRE( result == false); //doing an uppercase letter too because I'm having fun
}




