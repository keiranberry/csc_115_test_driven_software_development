#include "a0003.h"

int countCharacters( string wordsIn, char character)
{
    int amount = 0;
    int i = 0;
    int length = wordsIn.size();
    char charAt;
    
    while (i < length)
    {
        character = tolower(character);
        charAt = wordsIn.at(i);
        charAt = tolower(charAt);
        if(charAt == character)
        {
            amount = amount + 1;
            
        }
        i = i + 1;
    }
    
return amount;
}