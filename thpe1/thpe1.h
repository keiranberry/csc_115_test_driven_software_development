/** ********************************************************************
* @file
***********************************************************************/
#pragma once
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

string getCCType (string ccNumber);

bool isValidCC (string ccNumber);

bool luhnsEven (string ccNumber);

bool luhnsOdd (string ccNumber);
