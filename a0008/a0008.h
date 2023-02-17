#pragma once
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

void splitNameLF( string &fullName, string &firstName, string &lastName);

void splitNameFL( string &fullName, string &firstName, string &lastName);

string createEmail( string firstName, string lastName, string domain);

void fixList( string mixedList[], string firstLast[], string lastFirst[], string email[], int arraySize, string domainName);

