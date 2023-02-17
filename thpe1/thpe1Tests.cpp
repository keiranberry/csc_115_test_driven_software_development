#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "thpe1.h"

TEST_CASE("getCCType - testing an unknown number as an initial test")
{
    string ccIn = "9999999999999999";
    string ccType = getCCType(ccIn);
    
    REQUIRE(ccType == "Unknown");
}

TEST_CASE("getCCType - initial test for American Express")
{
    string ccIn = "340123456789012";
    string ccType = getCCType(ccIn);
    REQUIRE(ccType == "American Express");
}

TEST_CASE("getCCType - testing 37 as the first two digits of AmEx card")
{
    string ccIn = "370123456789012";
    string ccType = getCCType(ccIn);
    REQUIRE(ccType == "American Express");
}

TEST_CASE("getCCType - testing lower boundary of Mastercard range")
{
    string ccIn = "5011111111111111";
    string ccType = getCCType(ccIn);
    REQUIRE(ccType == "Mastercard");
}

TEST_CASE("getCCType - testing upper boundary of Mastercard range")
{
    string ccIn = "5599999999999999";
    string ccType = getCCType(ccIn);
    REQUIRE(ccType == "Mastercard");
}

TEST_CASE("getCCType - testing lower boundary of Visa with length 13")
{
    string ccIn = "4000000000000";
    string ccType = getCCType(ccIn);
    REQUIRE(ccType == "Visa");
}

TEST_CASE("getCCType - testing upper boundary of Visa with length 16")
{
    string ccIn = "4999999999999999";
    string ccType = getCCType(ccIn);
    REQUIRE(ccType == "Visa");
}

TEST_CASE("getCCType - testing 65 for Discover")
{
    string ccIn = "6500000000000000";
    string ccType = getCCType(ccIn);
    REQUIRE(ccType == "Discover");
}

TEST_CASE("getCCType - testing lower bound of first range for Discover")
{
    string ccIn = "6440000000000000";
    string ccType = getCCType(ccIn);
    REQUIRE(ccType == "Discover");
}

TEST_CASE("getCCType - testing upper bound of first range for Discover")
{
    string ccIn = "6499999999999999";
    string ccType = getCCType(ccIn);
    REQUIRE(ccType == "Discover");
}

TEST_CASE("getCCType - testing 6011 for Discover")
{
    string ccIn = "6011000000000000";
    string ccType = getCCType(ccIn);
    REQUIRE(ccType == "Discover");
}

TEST_CASE("getCCType - testing 622126 for Discover")
{
    string ccIn = "6221260000000000";
    string ccType = getCCType(ccIn);
    REQUIRE(ccType == "Discover");
}

TEST_CASE("getCCType - testing 622926 for Discover")
{
    string ccIn = "6229260000000000";
    string ccType = getCCType(ccIn);
    REQUIRE(ccType == "Discover");
}

TEST_CASE("getCCType - testing a random number in the seocnd range for Discover")
{
    string ccIn = "6222750000000000";
    string ccType = getCCType(ccIn);
    REQUIRE(ccType == "Discover");
}

TEST_CASE("isValidCC - testing a valid CC number to check for functionality")
{
    string ccIn = "4794630503276178";
    bool ccValid = isValidCC (ccIn);
    REQUIRE(ccValid == true);
}

TEST_CASE("isValidCC - testing an invalid CC number to check for functionality")
{
    string ccIn = "4425473125791";
    bool ccValid = isValidCC(ccIn);
    REQUIRE(ccValid == false);
}

TEST_CASE("isValidCC - testing a valid number with 15 digits")
{
    string ccIn = "343669144240775";

    bool ccValid = isValidCC (ccIn);
    CHECK(ccValid == true);
}

TEST_CASE("isValidCC - testing an invalid card with odd digits")
{
    string ccIn = "345649595068090";
    bool ccValid = isValidCC(ccIn);
    REQUIRE(ccValid == false);
}

TEST_CASE("isValidCC - testing an invalid Mastercard")
{
    string ccIn = "5385288768768674";
    bool ccValid = isValidCC(ccIn);
    REQUIRE(ccValid == false);
}

TEST_CASE("isValidCC - testing an invalid Discover")
{
    string ccIn = "6585288877768476";
    bool ccValid = isValidCC(ccIn);
    REQUIRE(ccValid == false);
}

TEST_CASE("isValidCC - testing letters to make sure my isdigit is working")
{
    string ccIn = "aaaaaaaaaaaaaaaa";
    bool ccValid = isValidCC(ccIn);
    REQUIRE(ccValid == false);
}

TEST_CASE("isValidCC - further testing to make sure the digit thing is working")
{
    string ccIn = "47946305032761t8";
    bool ccValid = isValidCC(ccIn);
    REQUIRE(ccValid == false);
}

TEST_CASE("isValidCC - testing a Mastercard that should return true")
{
    string ccIn = "5023589379548211";
    bool ccValid = isValidCC(ccIn);
    REQUIRE(ccValid == true);
}

TEST_CASE("isValidCC - testing a Discover that should return true")
{
    string ccIn = "6440747636070782";
    bool ccValid = isValidCC(ccIn);
    REQUIRE(ccValid == true);
}

TEST_CASE("luhnsEven - checking to see if something is wrong with my luhnsEven")
{
    string ccIn = "5385288768768674";
    bool luhnEvens = luhnsEven(ccIn);
    REQUIRE(luhnEvens == false);
}

TEST_CASE("luhnsOdd - testing my luhnsOdd function")
{
    string ccIn = "345649595068090";
    bool luhnOdds = luhnsOdd(ccIn);
    REQUIRE(luhnOdds == false);
}

TEST_CASE("luhnsOdd - further testing of luhnsOdd")
{
    string ccIn = "343669144240775";
    bool luhnOdds = luhnsOdd(ccIn);
    REQUIRE(luhnOdds == true);
}

TEST_CASE("getCCType and isValidCC - testing both functions at the same time because that is more realistic")
{
    string ccIn = "6440747636070782";
    bool ccValid = isValidCC(ccIn);
    string ccType = getCCType(ccIn);
    
    CHECK(ccValid == true);
    CHECK(ccType == "Discover");
}

TEST_CASE("getCCType and isValidCC - testing both functions at the same time")
{
    string ccIn = "7425473237792";
    bool ccValid = isValidCC(ccIn);
    string ccType = getCCType(ccIn);
    
    CHECK(ccValid == true);
    CHECK(ccType == "Unknown");
}

