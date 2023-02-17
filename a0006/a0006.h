#pragma once
#include <cmath>
#include <string>

using namespace std;

void createLookup( int lookup[], int rollResults[], int numRolls);

int fewestRolled( int lookup[], int num);

int mostRolled( int lookup[], int num);

int sumRolls( int lookup[], int num);

