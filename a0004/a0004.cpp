#include "a0004.h"



bool isPrime( int input)
{
    int i = 3;
    
    if (input > 1)
    {
        if (input == 2 || input == 3)
        {
        return true;
        }
        
        if (input % 2 == 0)
        {
            return false;
        }
        
        while ( i < input)
            
        { if (input % i == 0)
            {
                return false;
            }
            i = i + 2;
        }
        return true;
    }
    
    return false;
}

bool isTwinPrime( int input)
{
    int inputUp = (input + 2);
    int inputDown = (input - 2);
    bool isPrimeUp = isPrime(inputUp);
    bool isPrimeDown = isPrime(inputDown);
    
    if (isPrime(input) == true)
    {
        if (isPrimeDown == true)
        {
            return true;
        }
        
        if (isPrimeUp == true)
        {
            return true;
        }
        
        return false;
    }
    return false;
}


int nextPrime( int input)
{
    int primeNext = input + 1;
    
    while (isPrime(primeNext) == false)
    {
        if (isPrime(primeNext) == true)
        {
            return primeNext;
        }
        primeNext = primeNext + 1;
    }
    return primeNext;
}


