#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0002.h"

TEST_CASE( "windChill - testing values to see if the function works at all")
{
    int initialTemp = 50;
    int windSpeed = 20;
    int finalTemp;
    
    finalTemp = windChill( initialTemp, windSpeed);
    REQUIRE( finalTemp == 44);
}

TEST_CASE( "windChill - testing lower boundary of positive numbers in temp")
{
    int initialTemp = 1;
    int windSpeed = 30;
    int finalTemp;
    
    finalTemp = windChill( initialTemp, windSpeed);
    REQUIRE( finalTemp == -25); //also testing an answer with a negtive value
}

TEST_CASE( "windChill - testing negative initial temperature")
{
    int initialTemp = -10;
    int windSpeed = 12;
    int finalTemp;
    
    finalTemp = windChill( initialTemp, windSpeed);
    REQUIRE( finalTemp == -30); 
}

TEST_CASE( "windChill - testing low end of wind speed")
{
    int initialTemp = 46;
    int windSpeed = 3;
    int finalTemp;
    
    finalTemp = windChill( initialTemp, windSpeed);
    REQUIRE( finalTemp == 45);
}

TEST_CASE( "windChill - testing very high wind speed")
{
    int initialTemp = 10;
    int windSpeed = 99;
    int finalTemp;
    
    finalTemp = windChill( initialTemp, windSpeed);
    REQUIRE( finalTemp == -24);
}

TEST_CASE( "windChillWarning - testing None warning at 32")
{
    int initialTemp = 40;
    int windSpeed = 15;
    string windWarning;
    
    windWarning = windChillWarning ( initialTemp, windSpeed);
    REQUIRE( windWarning == "None");
}

TEST_CASE( "windChillWarning - testing upper bounds of Minimal warning at 31")
{
    int initialTemp = 35;
    int windSpeed = 5;
    string windWarning;
    
    windWarning = windChillWarning ( initialTemp, windSpeed);
    REQUIRE( windWarning == "Minimal");
}

TEST_CASE( "windChillWarning - testing lower bounds of Minimal warning at 0")
{
    int initialTemp = 20;
    int windSpeed = 35;
    string windWarning;
    
    windWarning = windChillWarning ( initialTemp, windSpeed);
    REQUIRE( windWarning == "Minimal");
}

TEST_CASE( "windChillWarning - testing upper bounds of Caution at -1")
{
    int initialTemp = 20;
    int windSpeed = 40;
    string windWarning;
    
    windWarning = windChillWarning ( initialTemp, windSpeed);
    REQUIRE( windWarning == "Caution");
}

TEST_CASE( "windChillWarning - testing lower bounds of Caution at -19")
{
    int initialTemp = 0;
    int windSpeed = 15;
    string windWarning;
    
    windWarning = windChillWarning ( initialTemp, windSpeed);
    REQUIRE( windWarning == "Caution");
}

TEST_CASE( "windChillWarning - testing upper bounds of Intermediate at -21")
{
    int initialTemp = 5;
    int windSpeed = 35;
    string windWarning;
    
    windWarning = windChillWarning ( initialTemp, windSpeed);
    REQUIRE( windWarning == "Intermediate");
}

TEST_CASE( "windChillWarning - testing lower bounds of Intermediate at -40")
{
    int initialTemp = -5;
    int windSpeed = 60;
    string windWarning;
    
    windWarning = windChillWarning ( initialTemp, windSpeed);
    REQUIRE( windWarning == "Intermediate");
}

TEST_CASE( "windChillWarning - testing upper bounds of Extreme")
{
    int initialTemp = -10;
    int windSpeed = 35;
    string windWarning;
    
    windWarning = windChillWarning ( initialTemp, windSpeed);
    REQUIRE( windWarning == "Extreme");
}

TEST_CASE( "windChillWarning - testing lowest temperature on wind chill chart")
{
    int initialTemp = -45;
    int windSpeed = 60;
    string windWarning;
    
    windWarning = windChillWarning ( initialTemp, windSpeed);
    REQUIRE( windWarning == "Extreme");
}

TEST_CASE( "windChillWarning - testing temperatures outside of wind chill chart to test lower boundary of Extreme")
{
    int initialTemp = -100;
    int windSpeed = 60;
    string windWarning;
    
    windWarning = windChillWarning ( initialTemp, windSpeed);
    REQUIRE( windWarning == "Extreme");
}

TEST_CASE( "windChillWarning - testing high final temperature to check for upper bounds of None")
{
    int initialTemp = 120;
    int windSpeed = 3;
    string windWarning;
    
    windWarning = windChillWarning ( initialTemp, windSpeed);
    REQUIRE( windWarning == "None");
}
