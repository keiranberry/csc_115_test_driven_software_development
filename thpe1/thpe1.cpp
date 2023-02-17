/** ********************************************************************
* @file
***********************************************************************/

#include "thpe1.h"
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Determines the company which a given credit card number belongs to. 
 *  American Express, Visa, Mastercard, and Discover work with this 
 *  function, and any other numbers will return "Unknown".
 *
 *  @param[in] ccNumber The credit card number which will be tested.
 *
 *  @returns The company which the given card number belongs to. If 
 *          the company is not American Express, Visa, Mastercard, 
 *          or Discover, an "Unknown" will be returned. 
 *
 *  @par Example
 *  @verbatim
    string ccType;
    string ccNum = "340123456789012";

    ccType = getCCType(ccNum); // result would be "American Express"

    ccNum = "9999999999999999";
    ccType = getCCType(ccNum); // result would be "Unknown"

    ccNum = "4794630503276178";
    ccType = getCCType(ccNum); // result would be "Visa"

    @endverbatim
 ************************************************************************/
string getCCType (string ccNumber)
{
    int i = 0;
    int ccSize = ccNumber.size();
    string partial;
    //American Express
    if (ccSize == 15)
    {
        if (ccNumber.substr( i, 2) == "34" || ccNumber.substr( i, 2) == "37")
        {
            return "American Express";
        }
    }
    //Discover
    if (ccSize == 16)
    {
        if (ccNumber.substr( i, 2) == "65" || ccNumber.substr( i, 3) == "644" || ccNumber.substr( i, 3) == "645" || 
        ccNumber.substr( i, 3) == "646" || ccNumber.substr( i, 3) == "647" || ccNumber.substr( i, 3) == "648" || 
        ccNumber.substr( i, 3) == "649" || ccNumber.substr( i, 4) == "6011" || ccNumber.substr( i, 6) == "622126" ||
        ccNumber.substr( i, 6) == "622127" || ccNumber.substr( i, 6) == "622128" || ccNumber.substr( i, 6) == "622129" ||
        ccNumber.substr( i, 5) == "62213" || ccNumber.substr( i, 5) == "62214" || ccNumber.substr( i, 5) == "62215" ||
        ccNumber.substr( i, 5) == "62216" || ccNumber.substr( i, 5) == "62217" || ccNumber.substr( i, 5) == "62218" ||
        ccNumber.substr( i, 5) == "62219" || ccNumber.substr( i, 4) == "6222" || ccNumber.substr( i, 4) == "6223" ||
        ccNumber.substr( i, 4) == "6224" || ccNumber.substr( i, 4) == "6225" || ccNumber.substr( i, 4) == "6226" ||
        ccNumber.substr( i, 4) == "6227" || ccNumber.substr( i, 4) == "6228" || ccNumber.substr( i, 5) == "62290" ||
        ccNumber.substr( i, 5) == "62291" || ccNumber.substr( i, 6) == "622920" || ccNumber.substr( i, 6) == "622921" ||
        ccNumber.substr( i, 6) == "622922" || ccNumber.substr( i, 6) == "622923" || ccNumber.substr( i, 6) == "622924" ||
        ccNumber.substr( i, 6) == "622925" || ccNumber.substr( i, 6) == "622926")
        {
            return "Discover";
        }
    }
      
    //Mastercard
    if (ccSize == 16)
    {
        if(ccNumber.substr( i, 2) == "50" || ccNumber.substr( i, 2) == "51" || ccNumber.substr( i, 2) == "52" ||
        ccNumber.substr( i, 2) == "53" || ccNumber.substr( i, 2) == "54" || ccNumber.substr( i, 2) == "55")
        {
            return "Mastercard";
        }
    }
    //Visa
        if (ccSize == 13 || ccSize == 16)
        {
            if (ccNumber.substr( i, 1) == "4")
            {
                return "Visa";
            }
        }
    return "Unknown"; //if card number doesn't match any tested card types, return unknown
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Runs a 16-digit credit card number through Luhn's Algorithm. The  
 *   resulting number is then checked for divisibility by 10. This 
 *   divisibility by 10 helps validate the credit card number.
 *
 *  @param[in] ccNumber The credit card number which will be tested.
 *
 *  @returns  A boolean value, whether the resulting number after 
 *           Luhn's algorithm is divisible by 10 or not. This boolean  
 *           value can be passed into the isValidCC function.
 *
 *  @par Example
 *  @verbatim
    bool luhnEvens;
    string ccNum = "3401234567890121";

    luhnEvens = luhnsEven(ccIn); // result would be "False"

    ccNum = "9999999999999999";
    luhnEvens = luhnsEven(ccIn); // result would be "False"

    ccNum = "4794630503276178";
    luhnEvens = luhnsEven(ccIn); // result would be "True"

    @endverbatim
 ************************************************************************/
bool luhnsEven (string ccNumber)
{    
    int i;
    int ccSize = ccNumber.size();
    int oddITemp = 0;
    int oddIFinal= 0;
    int evenITemp = 0;
    int evenIFinal = 0;
    int numDoubled;
    int sxtLuhnTotal;
    int sxtLuhnMod;
    
    if (ccSize == 16)
    {
        for (i = 1; i < ccSize; i = i + 2)
        {
            int ccNumAt = ccNumber[i] - '0';
            oddIFinal = oddIFinal + ccNumAt;
        }
        for (i = 0; i < ccSize; i = i + 2)
        {
            int ccNumAt = ccNumber[i] - '0';
            numDoubled = ccNumAt * 2;
            if (numDoubled > 9)
            {
                evenITemp = (numDoubled - 10) + 1;
                evenIFinal = evenIFinal + evenITemp;
            }
            else 
            {
                evenIFinal = evenIFinal + numDoubled;
            }
            
            
        }
        sxtLuhnTotal = evenIFinal + oddIFinal;
    }
    sxtLuhnMod = sxtLuhnTotal % 10;
    if (sxtLuhnMod == 0)
    {
        return true;
    }
    return false;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Runs a 13-or-15-digit credit card number through Luhn's Algorithm. The  
 *   resulting number is then checked for divisibility by 10. This 
 *   divisibility by 10 helps validate the credit card number.
 *
 *  @param[in] ccNumber The credit card number which will be tested.
 *
 *  @returns  A boolean value, whether the resulting number after 
 *           Luhn's algorithm is divisible by 10 or not. This boolean  
 *           value can be passed into the isValidCC function.
 *
 *  @par Example
 *  @verbatim
    bool luhnOdds;
    string ccNum = "343669144240775";

    luhnOdds = luhnsOdd(ccIn); // result would be "True"

    ccNum = "9999999999999";
    luhnOdds = luhnsOdd(ccIn); // result would be "False"

    ccNum = "7425473237792";
    luhnOdds = luhnsOdd(ccIn); // result would be "True"

    @endverbatim
 ************************************************************************/
bool luhnsOdd (string ccNumber)
{
    int i;
    int ccSize = ccNumber.size();
    int evenDigitTemp = 0;
    int evenDigitFinal = 0;
    int oddDigitTemp = 0;
    int oddDigitFinal = 0;
    int digitDoubled;
    int oddLuhnTotal;
    int oddLuhnMod;
    
    if (ccSize == 13 || ccSize == 15)
    {
        for (i = 0; i < ccSize; i = i + 2)
        {
            int ccNumAt = ccNumber[i] - '0';
            evenDigitFinal = evenDigitFinal + ccNumAt;
        }
        for (i = 1; i < ccSize; i = i + 2)
        {
            int ccNumAt = ccNumber[i] - '0';
            digitDoubled = ccNumAt * 2;
            if (digitDoubled > 9)
            {
                oddDigitTemp = (digitDoubled - 10) + 1;
                oddDigitFinal = oddDigitFinal + oddDigitTemp;
            }
            else 
            {
                oddDigitFinal = oddDigitFinal + digitDoubled;
            }
            
            
        }
        oddLuhnTotal = oddDigitFinal + evenDigitFinal;
    }
    oddLuhnMod = oddLuhnTotal % 10;
    if (oddLuhnMod == 0)
    {
        return true;
    }
    return false;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Determines if a credit card number which is passed in is valid or not. 
 *   Checks to confirm that every character in the string is a digit, and 
 *   uses luhnsOdd and luhnsEven to check for validity. If all characters
 *   are digits, and luhnsOdd/luhnsEven returns true, as well as the
 *   string being 13, 15, or 16 in length, the card is valid.
 *
 *  @param[in] ccNumber The credit card number which will be tested.
 *
 *  @returns  A boolean value, whether the card number which is passed in 
 *            is a valid number (true) or not (false).
 *           
 *
 *  @par Example
 *  @verbatim
    bool ccValid;
    string ccNum = "343669144240775";

    ccValid = isValidCC(ccIn); // result would be "True"

    ccNum = "3436691442407YY";
    ccValid = isValidCC(ccIn); // result would be "False"

    ccNum = "7425473237792";
    ccValid = isValidCC(ccIn); // result would be "True"

    @endverbatim
 ************************************************************************/
bool isValidCC (string ccNumber)
{
    int i = 0;
    int ccSize = ccNumber.size();
    int digitAt;
    bool allDigit = true;
    
    
    for (i = 0; i < ccSize; i++)
    {
        digitAt = ccNumber[i];
        bool isDigitAt = isdigit(digitAt);
        
        if (isDigitAt == true && allDigit == true)
        {
            allDigit = true;
        }
        if (isDigitAt == false)
        {
            allDigit = false;
        }
    }
        
    if (ccSize == 16 && allDigit == true)
    {
        bool evenLuhns = luhnsEven(ccNumber);
        if (evenLuhns == true)
        {
            return true;
        }
        return false;
    }

    if (ccSize == 13 && allDigit == true)
    {
        bool oddLuhns = luhnsOdd(ccNumber);
        if (oddLuhns == true)
        {
            return true;
        }
        return false;
        
    }
    if (ccSize == 15 && allDigit == true)
    {
        bool oddLuhns = luhnsOdd(ccNumber);
        if (oddLuhns == true)
        {
            return true;
        }
        return false;
    }
    
    return false;
}

        
