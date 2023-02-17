#include "a0011.h"

void cleanUp( ifstream &numsIn, ofstream &primes, ofstream &evens, ofstream &odds)
{
    numsIn.close();
    primes.close();
    evens.close();
    odds.close();
}

bool openInput( ifstream &file, string fileName)
{
    file.open( fileName );
    
    if (file.is_open() == true)
    {
    return true;
    }
    else 
    {
        cout << "Unable to open file: " << fileName << endl;
        return false;
    }
    
}

bool openOutput( ofstream &file, string fileName)
{
    file.open( fileName );
    
    if (file.is_open() == true)
    {
    return true;
    }
    else 
    {
        cout << "Unable to open file: " << fileName << endl;
        return false;
    }
    
}