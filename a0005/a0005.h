#pragma once
#include <cmath>
#include <cctype>
#include <string>

using namespace std;
void passwordCalc( string pwIn, int& entropyOut, string& strengthOut);

int entropy(string passIn);

string strength(int pwEntropy);


