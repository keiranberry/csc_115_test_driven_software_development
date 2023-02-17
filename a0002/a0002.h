#pragma once
#include <cmath>
#include <string>

using namespace std;

double windChill( double initialTemp, double windSpeed );

string windChillWarning( int initialTemp, int windSpeed );
