#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "thpe2.h"

TEST_CASE("mySqrt - testing a negative number to return 0")
{
    double numIn = -1;
    double sqrt = mySqrt(numIn);
    
    REQUIRE(sqrt == 0);
}

TEST_CASE("mySqrt - doing a real test of mySqrt")
{
    double numIn = 9;
    double sqrt = mySqrt(numIn);
    
    REQUIRE(sqrt == Approx (3));
}

TEST_CASE("mySqrt - testing a square that doesn't return an int")
{
    double numIn = 84;
    double sqrt = mySqrt(numIn);
    
    REQUIRE(sqrt == Approx (9.16515));
}

TEST_CASE("mySqrt - testing a large number just because")
{
    double numIn = 3585435;
    double sqrt = mySqrt(numIn);
    
    REQUIRE(sqrt == Approx (1893.52));
}

TEST_CASE("myCbrt - initial testing of myCbrt")
{
    double numIn = 27;
    double cbrt = myCbrt(numIn);
    
    REQUIRE(cbrt == Approx (3));
}

TEST_CASE("myCbrt - further testing of myCbrt")
{
    double numIn = 12167;
    double cbrt = myCbrt(numIn);
    
    REQUIRE(cbrt == Approx (23));
}

TEST_CASE("myLog - initial test")
{
    double base = 2;
    double x = 4;
    
    double exponent = myLog(x, base);
    REQUIRE( exponent == Approx(2));
}

TEST_CASE("myLog - further testing")
{
    double base = 4;
    double x = 64;
    
    double exponent = myLog(x, base);
    REQUIRE( exponent == Approx(3));
}

TEST_CASE("myLog - testing a non int answer")
{
    double base = 6;
    double x = 16.6608;
    
    double exponent = myLog(x, base);
    REQUIRE( exponent == Approx(1.57));
}

TEST_CASE("factorial - initial test")
{
    double numIn = 3;
    
    double numOut = factorial(numIn);
    
    REQUIRE(numOut == 6);
}

TEST_CASE("factorial - testing if double will be enough")
{
    double numIn = 18;
    
    double numOut = factorial(numIn);
    
    REQUIRE(numOut == 6402373705728000);
}

TEST_CASE("mySin - initial test")
{
    double numIn = PI/2;
    double sinx = mySin(numIn);
    
    REQUIRE (sinx == Approx(1));
}

TEST_CASE("mySin - testing a negative number")
{
    double numIn = -PI/2;
    double sinx = mySin(numIn);
    
    REQUIRE (sinx == Approx(-1));
}

TEST_CASE("mySin - further testing of mySin")
{
    double numIn = PI/6;
    double sinx = mySin(numIn);
    
    REQUIRE (sinx == Approx(.5));
}

TEST_CASE("mySin - testing when a 0 should be returned")
{
    double numIn = 0;
    double sinx = mySin(numIn);
    
    REQUIRE (sinx == Approx(0));
}

TEST_CASE("mySinD - initial test")
{
    double numInD = 90;
    double sinx = mySinD(numInD);
    
    REQUIRE (sinx == Approx(1));
}

TEST_CASE("mySinD - testing a negative number")
{
    double numInD = -90;
    double sinx = mySinD(numInD);
    
    REQUIRE (sinx == Approx(-1));
}

TEST_CASE("mySinD - further testing")
{
    double numInD = 30;
    double sinx = mySinD(numInD);
    
    REQUIRE (sinx == Approx(.5));
}

TEST_CASE("myCos - initial test")
{
    double numIn = 0;
    double cosx = myCos(numIn);
    
    REQUIRE (cosx == Approx(1));
}

TEST_CASE("myCos - testing a negative")
{
    double numIn = -(4*PI)/3;
    double cosx = myCos(numIn);
    
    REQUIRE (cosx == Approx(-.5));
}

TEST_CASE("myCos - further testing")
{
    double numIn = PI/2;
    double cosx = myCos(numIn);
    
    REQUIRE (cosx == Approx(0));
}

TEST_CASE("myCosD - initial test")
{
    double numInD = 0;
    double cosx = myCosD(numInD);
    
    REQUIRE (cosx == Approx(1));
}

TEST_CASE("myCosD - testing a return of 0")
{
    double numInD = 90;
    double cosx = myCosD(numInD);
    
    REQUIRE (cosx == Approx(0));
}

TEST_CASE("myCosD - testing a negative")
{
    double numInD = -120;
    double cosx = myCosD(numInD);
    
    REQUIRE (cosx == Approx(-.5));
}

TEST_CASE("myTan - initial test")
{
    double numIn = PI/4;
    double tanx = myTan(numIn);
    
    REQUIRE (tanx == Approx(1));
}

TEST_CASE("myTan - further testing")
{
    double numIn = 0;
    double tanx = myTan(numIn);
    
    REQUIRE (tanx == Approx(0));
}

TEST_CASE("myTan - testing a negative")
{
    double numIn = -(3*PI)/4;
    double tanx = myTan(numIn);
    
    REQUIRE (tanx == Approx(1));
}

TEST_CASE("myTan - testing a negative output")
{
    double numIn = -PI/4;
    double tanx = myTan(numIn);
    
    REQUIRE (tanx == Approx(-1));
}

TEST_CASE("myTan - seeing if it returns -0 like cos did")
{
    double numIn = -PI;
    double tanx = myTan(numIn);
    
    REQUIRE (tanx == Approx(0));
}

TEST_CASE("myTanD - initial test")
{
    double numInD = 45;
    double tanx = myTanD(numInD);
    
    REQUIRE (tanx == Approx(1));
}

TEST_CASE("myTanD - testing 0")
{
    double numInD = 0;
    double tanx = myTanD(numInD);
    
    REQUIRE (tanx == Approx(0));
}

TEST_CASE("myTanD - testing negative output")
{
    double numInD = -45;
    double tanx = myTanD(numInD);
    
    REQUIRE (tanx == Approx(-1));
}

TEST_CASE("myTanD - testing neg input, pos output")
{
    double numInD = -135;
    double tanx = myTanD(numInD);
    
    REQUIRE (tanx == Approx(1));
}

TEST_CASE("copyArray - initial test of copyArray")
{
    double destination[4];
    double source[4] = {1, 2, 3, 4};
    int arraySize = 4;
    
    copyArray(destination, source, arraySize);

    CHECK( destination[0] == 1);
    CHECK( destination[2] == 3);
}

TEST_CASE("copyArray - further testing of copyArray")
{
    double destination[9];
    double source[9] = {123, 234, 345, 456, 567, 678, 789, 890, 901};
    int arraySize = 9;
    
    copyArray(destination, source, arraySize);

    CHECK( destination[0] == 123);
    CHECK( destination[4] == 567);
    CHECK( destination[8] == 901);
}

TEST_CASE("initialArray - initial test")
{
    double array[3];
    int arraySize = 3;
    double initialize = 0;
    
    initialArray(array, arraySize, initialize);
    
    CHECK( array[0] == 0);
    CHECK( array[2] == 0);
}

TEST_CASE("initialArray - testing a larger array")
{
    double array[1000];
    int arraySize = 1000;
    double initialize = 69;
    
    initialArray(array, arraySize, initialize);
    
    CHECK( array[0] == 69);
    CHECK( array[420] == 69);
    CHECK( array[999] == 69);
}

TEST_CASE("sumArray - testing to see if sumArray works")
{
    double arrayIn[4] = {2, 3, 4, 3};
    int arraySize = 4;
    
    double sum = sumArray(arrayIn, arraySize);
    REQUIRE(sum == 12);
}

TEST_CASE("sumArray - further testing of sumArray")
{
    double arrayIn[9] = {2, 3, 4, 3, 5, 7, 8, 6, 4};
    int arraySize = 9;
    
    double sum = sumArray(arrayIn, arraySize);
    REQUIRE(sum == 42);
}

TEST_CASE("averageArray - initial test of averageArray")
{
    double arrayIn[2] = {3, 5};
    int arraySize = 2;
    
    double average = averageArray(arrayIn, arraySize);
    REQUIRE(average == 4);
} 

TEST_CASE("averageArray - further testing of averageArray")
{
    double arrayIn[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arraySize = 9;
    
    double average = averageArray(arrayIn, arraySize);
    REQUIRE(average == 5);
} 

TEST_CASE("averageArray - testing averageArray with decimals")
{
    double arrayIn[6] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    int arraySize = 6;
    
    double average = averageArray(arrayIn, arraySize);
    REQUIRE(average == 3.85);
}

TEST_CASE("minLocation - initial test of minLocation")
{
    double arrayIn[5] = {6, 8, 2, 9, 5};
    int arraySize = 5;
    
    int minIndex = minLocation(arrayIn, arraySize);
    REQUIRE(minIndex == 2);
}

TEST_CASE("minLocation - testing minLocation with a negative")
{
    double arrayIn[7] = {6, 8, 2, -7, 5, 8, 12};
    int arraySize = 7;
    
    int minIndex = minLocation(arrayIn, arraySize);
    REQUIRE(minIndex == 3);
}

TEST_CASE("minLocation - testing minLocation with decimals")
{
    double arrayIn[5] = {237.67, 345, 12.6996, 420, 546.0954};
    int arraySize = 5;
    
    int minIndex = minLocation(arrayIn, arraySize);
    REQUIRE(minIndex == 2);
}

TEST_CASE("minLocation - testing if two elements have the same value")
{
    double arrayIn[5] = {6, 8, 2, 9, 2};
    int arraySize = 5;
    
    int minIndex = minLocation(arrayIn, arraySize);
    REQUIRE(minIndex == 2);
}

TEST_CASE("minLocation - testing all elements with the same value")
{
    double arrayIn[5] = {2, 2, 2, 2, 2};
    int arraySize = 5;
    
    int minIndex = minLocation(arrayIn, arraySize);
    REQUIRE(minIndex == 0);
}

TEST_CASE("minValue - initial test of minValue")
{
    double arrayIn[3] = {98, 4, 67};
    int arraySize = 3;
    
    double valueMin = minValue(arrayIn, arraySize);
    REQUIRE(valueMin == 4);
}

TEST_CASE("minValue - testing minValue with decimals")
{
    double arrayIn[5] = {237.67, 345, 12.6996, 420, 546.0954};
    int arraySize = 5;
    
    double valueMin = minValue(arrayIn, arraySize);
    REQUIRE(valueMin == 12.6996);
}

TEST_CASE("minValue - testing minValue with a negative")
{
    double arrayIn[8] = {98, 4, 67, 68, 23, 43, 6, -12.2342};
    int arraySize = 8;
    
    double valueMin = minValue(arrayIn, arraySize);
    REQUIRE(valueMin == -12.2342);
}

TEST_CASE("maxLocation - initial test of maxLocation")
{
    double arrayIn[5] = {3, 6, 4, 9, 2};
    int arraySize = 5;
    
    double maxIndex = maxLocation(arrayIn, arraySize);
    REQUIRE(maxIndex == 3);
}

TEST_CASE("maxLocation - testing all elements with the same value")
{
    double arrayIn[5] = {2, 2, 2, 2, 2};
    int arraySize = 5;
    
    int maxIndex = maxLocation(arrayIn, arraySize);
    REQUIRE(maxIndex == 0);
}

TEST_CASE("maxLocation - testing maxLocation with decimals")
{
    double arrayIn[5] = {237.67, 345, 12.6996, 420, 546.0954};
    int arraySize = 5;
    
    int maxIndex = maxLocation(arrayIn, arraySize);
    REQUIRE(maxIndex == 4);
}

TEST_CASE("maxValue - initial test of maxValue")
{
    double arrayIn[3] = {98, 4, 67};
    int arraySize = 3;
    
    double valueMax = maxValue(arrayIn, arraySize);
    REQUIRE(valueMax == 98);
}

TEST_CASE("maxValue - testing maxValue with decimals")
{
    double arrayIn[5] = {237.67, 345, 12.6996, 420, 546.0954};
    int arraySize = 5;
    
    double valueMax = maxValue(arrayIn, arraySize);
    REQUIRE(valueMax == 546.0954);
}

TEST_CASE("maxValue - testing maxValue with all negatives")
{
    double arrayIn[5] = {-4.5, -0.8, -34, -78, -123};
    int arraySize = 5;
    
    double valueMax = maxValue(arrayIn, arraySize);
    REQUIRE(valueMax == -0.8);
}

TEST_CASE("countIf - initial test of countIf")
{
    double arrayIn[5] = {1, 2, 3, 2, 2};
    int arraySize = 5;
    double lookFor = 2;
    
    double found = countIf(arrayIn, arraySize, lookFor);
    REQUIRE(found == 3);
}

TEST_CASE("countIf - testing countIf with decimals")
{
    double arrayIn[8] = {0.8, 6.9, 6.9, 7.4, 6.9, 6.9, 2, 90};
    int arraySize = 8;
    double lookFor = 6.9;
    
    double found = countIf(arrayIn, arraySize, lookFor);
    REQUIRE(found == 4);
}

TEST_CASE("countIf - testing countIf with negatives")
{
    double arrayIn[4] = {23, -23, -45.67, -23};
    int arraySize = 4;
    double lookFor = -23;
    
    double found = countIf(arrayIn, arraySize, lookFor);
    REQUIRE(found == 2);
}

TEST_CASE("mySort - testing ascending order")
{
    double arrayIn[6] = {6, 5, 2, 4, 3, 1};
    int arraySize = 6;
    string order = "ASC";
    
    mySort(arrayIn, arraySize, order);
    
    CHECK( arrayIn[0] == 1);
    CHECK( arrayIn[2] == 3);
    CHECK( arrayIn[4] == 5);
}

TEST_CASE("mySort - further testing of mySort")
{
    double arrayIn[9] = {-7, 34, 765, 3465, 343, 23, 3456, 7653, 3};
    int arraySize = 9;
    string order = "ASC";
    
    mySort(arrayIn, arraySize, order);
    
    CHECK( arrayIn[0] == -7);
    CHECK( arrayIn[2] == 23);
    CHECK( arrayIn[4] == 343);
}

TEST_CASE("mySort - testing descending order")
{
    double arrayIn[5] = {5, 2, 4, 3, 1};
    int arraySize = 5;
    string order = "DSC";
    
    mySort(arrayIn, arraySize, order);
    
    CHECK( arrayIn[0] == 5);
    CHECK( arrayIn[2] == 3);
    CHECK( arrayIn[4] == 1);
}

TEST_CASE("mySort - further testing of mySort DSC")
{
    double arrayIn[9] = {-7, 34, 765, 3465, 343, 23, 3456, 7653, 3};
    int arraySize = 9;
    string order = "DSC";
    
    mySort(arrayIn, arraySize, order);
    
    CHECK( arrayIn[0] == 7653);
    CHECK( arrayIn[2] == 3456);
    CHECK( arrayIn[4] == 343);
}

TEST_CASE("mySort - testing neither asc or dsc")
{
    double arrayIn[5] = {5, 2, 4, 1, 3};
    int arraySize = 5;
    string order = "as;lfjsa;flsakjf";
    
    mySort(arrayIn, arraySize, order);
    
    CHECK( arrayIn[0] == 5);
    CHECK( arrayIn[2] == 4);
    CHECK( arrayIn[4] == 3);
}

TEST_CASE("linearSearch - initial test of linearSearch")
{
    double arrayIn[3] = {1, 2, 3};
    int arraySize = 3;
    double lookFor = 2;
    
    int where = linearSearch( arrayIn, arraySize, lookFor);
    
    REQUIRE(where == 1);
}

TEST_CASE("linearSearch - further testing of linearSearch")
{
    double arrayIn[9] = {-7, 34, 765, 3465, 343, 23, 3456, 7653, 3};
    int arraySize = 9;
    double lookFor = 7653;
    
    int where = linearSearch(arrayIn, arraySize, lookFor);
    
    REQUIRE( where == 7);
}

TEST_CASE("linearSearch - testing one that doesnt match")
{
    double arrayIn[9] = {-7, 34, 765, 3465, 343, 23, 3456, 7653, 3};
    int arraySize = 9;
    double lookFor = 3298572;
    
    int where = linearSearch(arrayIn, arraySize, lookFor);
    
    REQUIRE( where == -1);
}

TEST_CASE("binarySearch - initial test")
{
    double arrayIn[10] = {2, 3, 1, 5, 4, 6, 8, 7, 9, 0};
    int arraySize = 10;
    double lookFor = 8;
    
    mySort(arrayIn, arraySize, "ASC");
    
    int where = binarySearch(arrayIn, arraySize, lookFor);
    
    REQUIRE( where == 8);
}

TEST_CASE("binarySearch - further testing")
{
    double arrayIn[5] = {-1089, 0, -56, 1243, 586};
    int arraySize = 5;
    double lookFor = -56;
    
    mySort(arrayIn, arraySize, "ASC");
    
    int where = binarySearch(arrayIn, arraySize, lookFor);
    
    REQUIRE( where == 1);
}

TEST_CASE("binarySearch - testing no matches")
{
    double arrayIn[10] = {2, 3, 1, 5, 4, 6, 8, 7, 9, 0};
    int arraySize = 10;
    double lookFor = 10;
    
    mySort(arrayIn, arraySize, "ASC");
    
    int where = binarySearch(arrayIn, arraySize, lookFor);
    
    REQUIRE( where == -1);
}

TEST_CASE("known data")
{
    double arrayIn[10] = {34.5, 23.4, 1.05, 7.4, 290.38, 20.7, 5.02, 1.05, 290.38, 7.4};
    
    mySort(arrayIn, 10, "ASC");
    
    int where = binarySearch(arrayIn, 10, 5.02);
    
    REQUIRE( where == 2);
}