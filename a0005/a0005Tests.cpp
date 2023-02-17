#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0005.h"

TEST_CASE("entropy - initial test to check if a value is returned in the entropy function")
{
    string passIn = "abcde";
    int entropyNum = entropy(passIn);
    
    CHECK (entropyNum == 24);
    
}

TEST_CASE("entropy - testing an uppercase and lowercase letter together")
{
    string passIn = "AbcDe";
    int entropyNum = entropy(passIn);
    
    CHECK (entropyNum == 29);
    
}

TEST_CASE("entropy - testing digits, such as a 4 digit pin")
{
    string passIn = "2468";
    int entropyNum = entropy(passIn);
    
    CHECK (entropyNum == 13);
    
}

TEST_CASE("entropy - testing white space and punctuation")
{
    string passIn = ". . .";
    int entropyNum = entropy(passIn);
    
    CHECK (entropyNum == 25);
    
}

TEST_CASE("entropy - testing one of each thing added to char pool")
{
    string passIn = "aB. 3";
    int entropyNum = entropy(passIn);
    
    CHECK (entropyNum == 33);
    
}

TEST_CASE("passwordCalc - testing for functionality of passwordCalc")
{
    string passIn = "abcde";
    int entropyNum = 0;
    string ppStrength;
    
    passwordCalc( passIn, entropyNum, ppStrength);
    
    CHECK (entropyNum == 24);
    CHECK (ppStrength == "Very Weak");
}

TEST_CASE("passwordCalc - testing upper boundary of Very Weak")
{
    string passIn = "abcxyz";
    int entropyNum = 0;
    string ppStrength;
    
    passwordCalc( passIn, entropyNum, ppStrength);
    
    CHECK (entropyNum == 28);
    CHECK (ppStrength == "Very Weak");
}

TEST_CASE("passwordCalc - testing lower boundary of Weak")
{
    string passIn = "abc yz";
    int entropyNum = 0;
    string ppStrength;
    
    passwordCalc( passIn, entropyNum, ppStrength);
    
    CHECK (entropyNum == 29);
    CHECK (ppStrength == "Weak");
}

TEST_CASE("passwordCalc - testing upper boundary of Weak")
{
    string passIn = "ABCDE.";
    int entropyNum = 0;
    string ppStrength;
    
    passwordCalc( passIn, entropyNum, ppStrength);
    
    CHECK (entropyNum == 35);
    CHECK (ppStrength == "Weak");
}

TEST_CASE("passwordCalc - testing lower boundary of Reasonable")
{
    string passIn = "A123456";
    int entropyNum = 0;
    string ppStrength;
    
    passwordCalc( passIn, entropyNum, ppStrength);
    
    CHECK (entropyNum == 36);
    CHECK (ppStrength == "Reasonable");
}

TEST_CASE("passwordCalc - testing upper boundary of Reasonable")
{
    string passIn = "Az 7@sdaf";
    int entropyNum = 0;
    string ppStrength;
    
    passwordCalc( passIn, entropyNum, ppStrength);
    
    CHECK (entropyNum == 59);
    CHECK (ppStrength == "Reasonable");
}

TEST_CASE("passwordCalc - testing Strong")
{
    string passIn = "asdFghJklo@";
    int entropyNum = 0;
    string ppStrength;
    
    passwordCalc( passIn, entropyNum, ppStrength);
    
    CHECK (entropyNum == 70);
    CHECK (ppStrength == "Strong");
}

TEST_CASE("passwordCalc - testing upper boundary of Strong")
{
    string passIn = "qwertyuiopasdfghjklzxcvbnmg";
    int entropyNum = 0;
    string ppStrength;
    
    passwordCalc( passIn, entropyNum, ppStrength);
    
    CHECK (entropyNum == 127);
    CHECK (ppStrength == "Strong");
}

TEST_CASE("passwordCalc - testing lower boundary of Very Strong")
{
    string passIn = "aB @2qwertyuiopasdfg";
    int entropyNum = 0;
    string ppStrength;
    
    passwordCalc( passIn, entropyNum, ppStrength);
    
    CHECK (entropyNum == 132);
    CHECK (ppStrength == "Very Strong");
}

