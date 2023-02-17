/** ********************************************************************
* @file
***********************************************************************/
#pragma once

#include <random>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

/** ********************************************************************
* @brief Set value for the royal flush hand
***********************************************************************/
const int ROYALFLUSH = 9;

/** ********************************************************************
* @brief Set value for the straight flush hand
***********************************************************************/
const int STRAIGHTFLUSH = 8;

/** ********************************************************************
* @brief Set value for the four of a kind hand
***********************************************************************/
const int FOUROFAKIND = 7;

/** ********************************************************************
* @brief Set value for the full house hand
***********************************************************************/
const int FULLHOUSE = 6;

/** ********************************************************************
* @brief Set value for the flush hand
***********************************************************************/
const int FLUSH = 5;

/** ********************************************************************
* @brief Set value for the straight hand
***********************************************************************/
const int STRAIGHT = 4;

/** ********************************************************************
* @brief Set value for the three of a kind hand
***********************************************************************/
const int THREEOFAKIND = 3;

/** ********************************************************************
* @brief Set value for the two pair hand
***********************************************************************/
const int TWOPAIR = 2;

/** ********************************************************************
* @brief Set value for the two of a kind hand
***********************************************************************/
const int TWOOFAKIND = 1;

/** ********************************************************************
* @brief Set value for the high card hand
***********************************************************************/
const int HIGHCARD = 0;

bool checkArg ( string argIn);

string argReturn(string input );

void dealHands( int hands[5], int seed);

void outputS( int handsDealt[10], double quantityIn, int quantity);

void outputF( int handsDealt[10], double quantityIn, int quantity, ofstream &output);

bool openInput( ifstream &file, string fileName);

bool openOutput( ofstream &file, string fileName);

int faceValue( int cardIn);

int findSuit( int cardIn);

int classifyHand( int array[], int arraySize);

void sortHand( int array[], int arraySize);

void sortHandValue( int array[], int arraySize);

void sortHandValueAce( int array[], int arraySize);

bool isRoyalFlush( int array[], int arraySize);

bool isStraightFlush( int array[], int arraySize);

bool isStraight( int array[], int arraySize);

bool isStraightAce( int array[], int arraySize);

bool isFlush( int array[], int arraySize);

int countIf( int array[], int arraySize, int numIn);

string ofAKind( int array[], int arraySize);

