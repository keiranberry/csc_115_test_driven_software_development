#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include "..\\a0004\a0004.h"
using namespace std;

void cleanUp( ifstream &numsIn, ofstream &primes, ofstream &evens, ofstream &odds);

bool openInput( ifstream &file, string fileName);

bool openOutput( ofstream &file, string fileName);
