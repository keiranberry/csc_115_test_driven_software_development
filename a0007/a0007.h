#pragma once
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

void sortByID( string namesIn[], int idIn[], int arraySize);

void sortByName( string namesIn[], int idIn[], int arraySize);

int getID( string namesIn[], int idIn[], int arraySize, string person);

string getName( string namesIn[], int idIn[], int arraySize, int idNum);

