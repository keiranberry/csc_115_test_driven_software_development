#include "a0002.h"

double powerOne ( double windSpeed) //creating a function which can be called upon for the exponential pieces 
{
    return pow(windSpeed, 0.16);
}

double windChill( double initialTemp, double windSpeed )
{
    double finalTemp;
    
    finalTemp = 35.74 + (0.6215 * initialTemp) - (35.75 * powerOne(windSpeed)) + (0.4275 * initialTemp * powerOne(windSpeed));
    finalTemp = round(finalTemp); //need to round, changing finaltemp to an int truncated instead of rounding
    return finalTemp;
}
   
string windChillWarning( int initialTemp, int windSpeed )
{
    int finalTemp = windChill( initialTemp, windSpeed );
    if (finalTemp < 32 && finalTemp >= 0)
    {
        return "Minimal";
    }
    if (finalTemp <0 && finalTemp >= -20)
    {
        return "Caution";
    }
    if (finalTemp < -20 && finalTemp >= -40)
    {
        return "Intermediate";
    }
    if (finalTemp < -40)
    {
        return "Extreme";
    }
    
    return "None";
    
}
