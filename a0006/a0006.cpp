#include "a0006.h"

void createLookup( int lookup[], int rollResults[], int numRolls)
{
    int i;
    
    for ( i=0; i<7; i++)
    {
        lookup[i] = 0;
    }
    
    for ( i=0; i<numRolls; i++)
    {
        int j;
        for ( j=1; j<7; j++)
        {
        if (rollResults[i] == j)
        {
        lookup[j]++;
        }
        }
    }
}

int fewestRolled( int lookup[], int num)
{
    int i;
    int fewest;
    int lowestNum = lookup[1];
    
    for (i=1; i<num; i++)
    {
        if (lowestNum > lookup[i])
        {
            lowestNum = lookup[i];
            fewest = i;
        }
    }
    return fewest;
}

int mostRolled( int lookup[], int num)
{
    int i;
    int most;
    int highestNum = lookup[1];
    
    for (i=1; i<num; i++)
    {
        if (highestNum < lookup[i])
        {
            highestNum = lookup[i];
            most = i;
        }
    }
    
    return most;
    
}

int sumRolls( int lookup[], int num)
{
    int i;
    int finalSum = 0;
    int newSum;
    
    for (i=1; i<num; i++)
    {
        newSum = lookup[i] * i;
        finalSum = finalSum + newSum;
    }
    return finalSum;
    
}
