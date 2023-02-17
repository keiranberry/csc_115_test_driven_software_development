/** ********************************************************************
* @file
***********************************************************************/

#pragma once
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

/** ********************************************************************
* @brief How many terms the mySin and myCos functions run through to 
*         reach an answer
***********************************************************************/
const int TERMS=10;

/** ********************************************************************
* @brief A constant to approximate pi to be used in testing and 
*         functions
***********************************************************************/
const double PI = atan(1.0) * 4;

/** ********************************************************************
* @brief How close to exact an answer needs to be to be good enough to 
*         return
***********************************************************************/
const double ERRORVALUE = .000000000001;

/** ********************************************************************
* @brief The maximum amount of times a bisector function can run 
*         through midpoints; if an answer has not been found in 
*         5000 bisectors, return best guess.
***********************************************************************/
const int ITERATIONMAX = 5000;

/** ********************************************************************
* @brief Error tolerance for what is approximately correct
***********************************************************************/
const double ERRORTOLERANCE = .000001;

double mySqrt( double sqrtNumIn);

double myCbrt( double cbrtNumIn);

double myLog( double x, int base);

double factorial(double numIn);

double mySin( double numIn);

double mySinD( double numInD);

double myCos( double numIn);

double myCosD( double numInD);

double myTan( double numIn);

double myTanD( double numInD);

void copyArray( double destination[], double source[], int arraySize);

void initialArray( double array[], int arraySize, double initialize);

double sumArray( double arrayIn[], int arraySize);

double averageArray ( double arrayIn[], int arraySize);

int minLocation ( double arrayIn[], int arraySize);

double minValue ( double arrayIn[], int arraySize);

int maxLocation ( double arrayIn[], int arraySize);

double maxValue ( double arrayIn[], int arraySize);

int countIf( double arrayIn[], int arraySize, double lookFor);

void mySort ( double arrayIn[], int arraySize, string order);

int linearSearch(double arrayIn[], int arraySize, double lookFor);

int binarySearch(double arrayIn[], int arraySize, double lookFor);

