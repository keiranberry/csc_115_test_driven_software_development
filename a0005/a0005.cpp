#include "a0005.h"

void passwordCalc( string pwIn, int& entropyOut, string& strengthOut)
{
    int pwEntropy = entropy(pwIn);
    string pwStrength = strength(pwEntropy);
    entropyOut = pwEntropy;
    strengthOut = pwStrength;
}

int entropy(string passIn)
{
    int charPool = 0;
    int i = 0;
    int length = passIn.size();
    char charAt;
    bool hasUpper = false;
    bool hasLower = false;
    bool hasPunct = false;
    bool hasSpace = false;
    bool hasDigit = false;
    double entropyBits = 0;
    
    while (i < length)
    {
        charAt = passIn.at(i);
        if (hasUpper == false)
        {
            hasUpper = isupper(charAt);
        }
        if (hasLower == false)
        {
            hasLower = islower(charAt);
        }
        if (hasPunct == false)
        {
            hasPunct = ispunct(charAt);
        }
        if (hasSpace == false)
        {
            hasSpace = isspace(charAt);
        }
        if (hasDigit == false)
        {
            hasDigit = isdigit(charAt);
        }
        i = i + 1;
    }
    if (hasUpper == true)
    {
        charPool = charPool + 26;
    }
    if (hasLower == true)
    {
        charPool = charPool + 26;
    }
    if (hasPunct == true)
    {
        charPool = charPool + 32;
    }
    if (hasSpace == true)
    {
        charPool = charPool + 2;
    }
    if (hasDigit == true)
    {
        charPool = charPool + 10;
    }
    
    entropyBits = log2(charPool);
    
    double pwEntropy = (entropyBits * length);
    pwEntropy = round(pwEntropy);
    
    return pwEntropy;
}

string strength(int pwEntropy)
{
    if (pwEntropy <= 28)
    {
        return "Very Weak";
    }
    else if (pwEntropy <= 35)
    {
        return "Weak";
    }
    else if (pwEntropy <= 59)
    {
        return "Reasonable";
    }
    else if (pwEntropy <= 127)
    {
        return "Strong";
    }
    else if (pwEntropy > 127)
    {
        return "Very Strong";
    }
    return "Error";
}
