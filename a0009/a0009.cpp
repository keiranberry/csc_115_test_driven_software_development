#include "a0009.h"

void swapStrings( char string1[50], char string2[50])
{
    char temp[50];
    strcpy(temp, string1);
    strcpy(string1, string2);
    strcpy(string2, temp);
}

void sortOrder( char cStrings[][21], int numStrings)
{
    int i;
    int j;
    
    for (i=0; i<numStrings; i++)
    {

        for (j=0; j<numStrings-1; j++)
        {    
            if ( strcmp(cStrings[j+1], cStrings[j]) < 0)
            {
                swapStrings( cStrings[j], cStrings[j+1]);
            }
        }
    }
}

void sortLen( char cStrings[][21], int numStrings)
{
    int i;
    int j;
    int minimum;
    for (i=0; i<numStrings-1; i++)
    {
        minimum = i;
        for(j = i+1; j< numStrings; j++)
        {
            if( strlen( cStrings[j]) < strlen( cStrings[minimum]))
            {
                minimum = j;
            }
        }
        swapStrings( cStrings[i], cStrings[minimum]);        
    }
}


void cleanUp( ifstream numsIn, ofstream primes, ofstream evens, ofstream odds)
{
    close numsIn;
    close primes;
    close evens;
    close odds;
}