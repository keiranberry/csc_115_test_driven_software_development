/** ********************************************************************
* @file
***********************************************************************/

#include "thpe3.h"

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Checks that the argument in argv[1] is either -f or -s. -f will run
 *   a file input, and -s will run a simulation. If neither is input,
 *   then the function will not run.
 *
 *  @param[in] argIn The argument input which will be checked.
 *
 *  @returns  A boolean value, stating whether the argument matches
 *           either -f or -s. If it is one of the two, "true" will  
 *           be returned, and "false" will be returned otherwise.
 *
 *  @par Example
 *  @verbatim
    bool output;
    string argIn = "-s";

    output = checkArg(argIn); // result would be true

    string argIn = "-f";
    output = checkArg(argIn); // result would be true

    string argIn = "-k";
    output = checkArg(argIn); // result would be false

    @endverbatim
 ************************************************************************/
bool checkArg ( string argIn) //checks input arguments to confirm it is either -f or -s
{
    if( argIn == "-f" || argIn == "-s")
    {
        return true;
    }
    else 
    {
        return false;
    }
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Returns the argv to be used in the function main. This is to 
 *   circumvent an issue with trying to use the argv directly.
 *
 *  @param[in] input The argument input which will be returned.
 *
 *  @returns  A string, the same as what was input.
 *
 *  @par Example
 *  @verbatim
    string output;
    string input = "-s";

    output = argReturn(input); // result would be -s

    string argIn = "-f";
    output = argReturn(input); // result would be -f

    @endverbatim
 ************************************************************************/
string argReturn(string input ) //returns the argv to be used in main
{
    return input;
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Deals random hands based on the seed and quantity of hands input from 
 *   the console. This is done with the -s argument.
 *
 *  @param[in] hands[] The array which the hands will be dealt into.
 *
 *  @param[in] seedIn The seed from the console.
 *
 *  @par Example
 *  @verbatim
    int hands[5];
    int seedIn = 5;
    int quantityIn = 10;
    
    dealHands(hands, seedIn);
    
    //results in 10 hands dealt into the array with seed 5

    @endverbatim
 ************************************************************************/
void dealHands( int hands[5], int seedIn)
{
    static default_random_engine engine( seedIn );
    uniform_int_distribution<int> deck(0,51);
    
    int i=0;
    int j=0;
    int card;
    bool duplicateFound;
          
    while(i<5)
    {
        duplicateFound = false;
        card = deck(engine);
        
        for(j=0; j<i; j++)
        {
            if(card == hands[j])
            {
                duplicateFound = true;
            }
        }
        if( duplicateFound == true)
        {
            i=i;
        }
        if( duplicateFound == false)
        {
            hands[i] = card;
            i++;
        }
    }
} 

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Returns the output to the console. This is for the -s input. This will
 *   return the amount of each type of hand dealt and the percentage of 
 *   the whole that each one takes up.
 *
 *  @param[in] handsDealt[] The array containing how many of each hand 
 *                             were dealt.
 *
 *  @param[in] quantityIn The amount of hands dealt in double type.
 *
 *  @param[in] quantity The amount of hands in int type.
 *
 *  @par Example
 *  @verbatim
    int handsDealt[10];
    double quantityIn = 10;
    int quantity = 10;
    
    outputS(handsDealt, quantityIn, quantity);
    
    //returns the amount of each hand and its percentage to console

    @endverbatim
 ************************************************************************/
void outputS( int handsDealt[10], double quantityIn, int quantity)
{
    cout << fixed << showpoint << setprecision(6);
    cout << setw(20) << left << "Hand Name" << setw(10) << right << "Dealt" << setw(15) << right << "Chance" << endl;
    cout << setw(20) << left << "Royal Flush" << setw(10) << right << handsDealt[9] << setw(15) << right << (handsDealt[9]/quantityIn) * 100 << left << "%" << endl;
    cout << setw(20) << left << "Straight Flush" << setw(10) << right << handsDealt[8] << setw(15) << right << (handsDealt[8]/quantityIn) * 100 << left << "%" << endl;
    cout << setw(20) << left << "Four of a Kind" << setw(10) << right << handsDealt[7] << setw(15) << right << (handsDealt[7]/quantityIn) * 100 << left << "%" << endl;
    cout << setw(20) << left << "Full House" << setw(10) << right << handsDealt[6] << setw(15) << right << (handsDealt[6]/quantityIn) * 100 << left << "%" << endl;
    cout << setw(20) << left << "Flush" << setw(10) << right << handsDealt[5] << setw(15) << right << (handsDealt[5]/quantityIn) * 100 << left << "%" << endl;
    cout << setw(20) << left << "Straights" << setw(10) << right << handsDealt[4] << setw(15) << right << (handsDealt[4]/quantityIn) * 100 << left << "%" << endl;
    cout << setw(20) << left << "Three of a Kind" << setw(10) << right << handsDealt[3] << setw(15) << right << (handsDealt[3]/quantityIn) * 100 << left << "%" << endl;
    cout << setw(20) << left << "Two Pair" << setw(10) << right << handsDealt[2] << setw(15) << right << (handsDealt[2]/quantityIn) * 100 << left << "%" << endl;
    cout << setw(20) << left << "Two of a Kind" << setw(10) << right << handsDealt[1] << setw(15) << right << (handsDealt[1]/quantityIn) * 100 << left << "%" << endl;
    cout << setw(20) << left << "High Card" << setw(10) << right << handsDealt[0] << setw(15) << right << (handsDealt[0]/quantityIn) * 100 << left << "%" << endl;
    cout << endl;
    cout << setw(20) << left << "Total Hands Dealt" << setw(10) << right << quantity << endl;
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Returns the output to the file out. This is for the -f input. This 
 *   will return the amount of each type of hand dealt and the percentage  
 *    of the whole that each one takes up.
 *
 *  @param[in] handsDealt[] The array containing how many of each hand 
 *                             were dealt.
 *
 *  @param[in] quantityIn The amount of hands dealt in double type.
 *
 *  @param[in] quantity The amount of hands in int type.
 *
 *  @param[in] output The ofstream file to output the information into.
 *
 *  @par Example
 *  @verbatim
    int handsDealt[10];
    double quantityIn = 10;
    int quantity = 10;
    ofstream output;
    
    outputF(handsDealt, quantityIn, quantity, output);
    
    //returns the amount of each hand and its percentage to "output"

    @endverbatim
 ************************************************************************/
void outputF( int handsDealt[10], double quantityIn, int quantity, ofstream &output)
{
    output << fixed << showpoint << setprecision(6);
    output << setw(20) << left << "Hand Name" << setw(10) << right << "Dealt" << setw(15) << right << "Chance" << endl;
    output << setw(20) << left << "Royal Flush" << setw(10) << right << handsDealt[9] << setw(15) << right << (handsDealt[9]/quantityIn) * 100 << left << "%" << endl;
    output << setw(20) << left << "Straight Flush" << setw(10) << right << handsDealt[8] << setw(15) << right << (handsDealt[8]/quantityIn) * 100 << left << "%" << endl;
    output << setw(20) << left << "Four of a Kind" << setw(10) << right << handsDealt[7] << setw(15) << right << (handsDealt[7]/quantityIn) * 100 << left << "%" << endl;
    output << setw(20) << left << "Full House" << setw(10) << right << handsDealt[6] << setw(15) << right << (handsDealt[6]/quantityIn) * 100 << left << "%" << endl;
    output << setw(20) << left << "Flush" << setw(10) << right << handsDealt[5] << setw(15) << right << (handsDealt[5]/quantityIn) * 100 << left << "%" << endl;
    output << setw(20) << left << "Straights" << setw(10) << right << handsDealt[4] << setw(15) << right << (handsDealt[4]/quantityIn) * 100 << left << "%" << endl;
    output << setw(20) << left << "Three of a Kind" << setw(10) << right << handsDealt[3] << setw(15) << right << (handsDealt[3]/quantityIn) * 100 << left << "%" << endl;
    output << setw(20) << left << "Two Pair" << setw(10) << right << handsDealt[2] << setw(15) << right << (handsDealt[2]/quantityIn) * 100 << left << "%" << endl;
    output << setw(20) << left << "Two of a Kind" << setw(10) << right << handsDealt[1] << setw(15) << right << (handsDealt[1]/quantityIn) * 100 << left << "%" << endl;
    output << setw(20) << left << "High Card" << setw(10) << right << handsDealt[0] << setw(15) << right << (handsDealt[0]/quantityIn) * 100 << left << "%" << endl;
    output << endl;
    output << setw(20) << left << "Total Hands Dealt" << setw(10) << right << quantity << endl;
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Checks that the input file has opened successfully.
 *
 *  @param[in] file The ifstream file input.
 *
 *  @param[in] fileName The name of the file which is being checked.
 *
 *  @returns  A boolean value, whether the file has opened successfully 
 *           or not.
 *           
 *
 *  @par Example
 *  @verbatim
    //returns true if the file has opened successfully
    
    //returns false if the file has not opened 
    
    @endverbatim
 ************************************************************************/
bool openInput( ifstream &file, string fileName)//checks that necessary input files are open
{
    file.open( fileName );
    
    if (file.is_open() == true)
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Checks that the output file has opened successfully.
 *
 *  @param[in] file The ofstream file input.
 *
 *  @param[in] fileName The name of the file which is being checked.
 *
 *  @returns  A boolean value, whether the file has opened successfully 
 *           or not.
 *           
 *
 *  @par Example
 *  @verbatim
    //returns true if the file has opened successfully
    
    //returns false if the file has not opened 
    
    @endverbatim
 ************************************************************************/
bool openOutput( ofstream &file, string fileName) //checks that the output file opens
{
    file.open( fileName );
    
    if (file.is_open() == true)
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Passes in a card and returns its face value. This is done by taking 
 *   the (card)%13.
 *
 *  @param[in] cardIn The card which will be passed in.
 *
 *  @returns  An int value, the face value of the card from 0-12. This 
 *           would be from ace to king in physical cards.
 *           
 *
 *  @par Example
 *  @verbatim
    int cardIn= 0;
        
    faceValue(cardIn); //result would be 0
    
    int cardIn= 13;
    faceValue(cardIn); //result would be 0
    
    int cardIn = 14;
    faceValue(cardIn); //result would be 1

    @endverbatim
 ************************************************************************/
int faceValue( int cardIn) //determines the face value of the card in question
{
    int face = cardIn%13;
    
    return face;
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Passes in a card and returns its suit. This is done by taking 
 *   the (card)/13.
 *
 *  @param[in] cardIn The card which will be passed in.
 *
 *  @returns  An int value, the suit of the card from 0-3.
 *           
 *
 *  @par Example
 *  @verbatim
    int cardIn= 0;
        
    findSuit(cardIn); //result would be 0
    
    int cardIn= 13;
    findSuit(cardIn); //result would be 1
    
    int cardIn = 14;
    findSuit(cardIn); //result would be 1

    @endverbatim
 ************************************************************************/
int findSuit( int cardIn) //determines the suit of the card in question
{
    int suit = cardIn/13;
    
    return suit;
}


/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Sorts a hand based on the number from 0-51 which was passed in. This 
 *   corresponds to each different card in a standard deck.
 *
 *  @param[in] array[] The array of cards which will be sorted.
 *
 *  @param[in] arraySize The size of the array which is passed in.
 *
 *
 *  @par Example
 *  @verbatim
    int array[5] = {1, 2, 3, 4, 5};
    int arraySize = 5;
    
    sortHand(array, 5); //result would be {1, 2, 3, 4, 5}
    
    int array[5] = {13, 51, 0, 23, 22};
    int arraySize = 5;
    
    sortHand(array, 5); //result would be {0, 13, 22, 23, 51}
    

    @endverbatim
 ************************************************************************/
void sortHand( int array[], int arraySize) //sorts hand based on numbers 0-51
{
    int i = 0;
    int j = 0;
    
    for( i=0; i<arraySize - 1; i++)
    {
        for( j=0; j<arraySize - 1 - i; j++)
        {
            if( array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Sorts a hand based on the face value of the cards which were passed
 *    in. 
 *
 *  @param[in] array[] The array of cards which will be sorted.
 *
 *  @param[in] arraySize The size of the array which is passed in.
 *
 *
 *  @par Example
 *  @verbatim
    int array[5] = {1, 2, 3, 4, 5};
    int arraySize = 5;
    
    sortHandValue(array, 5); //result would be {1, 2, 3, 4, 5}
    
    int array[5] = {13, 51, 0, 23, 22};
    int arraySize = 5;
    
    sortHandValue(array, 5); //result would be {0, 13, 5, 22, 23}
    

    @endverbatim
 ************************************************************************/
void sortHandValue( int array[], int arraySize) //sorts hand based on face value
{
    int i = 0;
    int j = 0;
    
    for( i=0; i<arraySize - 1; i++)
    {
        for( j=0; j<arraySize - 1 - i; j++)
        {
            if( faceValue(array[j]) > faceValue(array[j+1]))
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Sorts a hand based on the face value of the cards which were passed
 *    in. This puts the ace as the highest card in the array.
 *
 *  @param[in] array[] The array of cards which will be sorted.
 *
 *  @param[in] arraySize The size of the array which is passed in.
 *
 *
 *  @par Example
 *  @verbatim
    int array[5] = {1, 2, 3, 4, 5};
    int arraySize = 5;
    
    sortHandValue(array, 5); //result would be {1, 2, 3, 4, 5}
    
    int array[5] = {13, 51, 0, 23, 22};
    int arraySize = 5;
    
    sortHandValue(array, 5); //result would be {5, 22, 23, 0, 13}
    

    @endverbatim
 ************************************************************************/
void sortHandValueAce( int array[], int arraySize) //sorts hand based on face value
{
    int i = 0;
    int j = 0;
    
    for( i=0; i<arraySize - 1; i++)
    {
        for( j=0; j<arraySize - 1 - i; j++)
        {
            if( faceValue(array[j]) > faceValue(array[j+1]))
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
            else if( faceValue(array[j]) == 0)
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Determines whether the hand passed in is a royal flush. This means the
 *   face value of the cards ascend from 10 to ace, and they are all the 
 *   same suit.
 *
 *  @param[in] array[] The hand which is being passed in.
 *
 *  @param[in] arraySize The size of the array which is passed in.
 *
 *  @returns  A boolean value, whether the hand is a royal flush or not.
 *           
 *
 *  @par Example
 *  @verbatim
    int array[5] = {0, 9, 10, 11, 12};
    int arraySize = 5;
        
    bool out = isRoyalFlush(array[], arraySize); // result would be true
    
    int array[5] = {0, 9, 10, 11, 17};
    int arraySize = 5;
        
    out = isRoyalFlush(array[], arraySize); // result would be false
    

    @endverbatim
 ************************************************************************/
bool isRoyalFlush( int array[], int arraySize ) //checks to see if the hand is a royal flush
{
    sortHand(array, arraySize);
    
    if ( array[0] == 0 && array[1] == 9 && array[2] == 10 
        && array[3] == 11 && array[4] == 12 )
    {
        return true;
    }
    else if ( array[0] == 13 && array[1] == 22 && array[2] == 23
            && array[3] == 24 && array[4] == 25 )
    {
        return true;
    }
    else if ( array[0] == 26 && array[1] == 35 && array[2] == 36
            && array[3] == 37 && array[4] == 38 )
    {
        return true;
    }
    else if ( array[0] == 39 && array[1] == 48 && array[2] == 49 
             && array[3] == 50 && array[4] == 51 )
    {
        return true;
    }
    else 
    {
        return false; //if its not one of the four royal flushes, its not a royal flush
    }
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Determines whether the hand passed in is a straight flush. This means the
 *   face value of the cards ascend by one each time, and they are all the 
 *   same suit.
 *
 *  @param[in] array[] The hand which is being passed in.
 *
 *  @param[in] arraySize The size of the array which is passed in.
 *
 *  @returns  A boolean value, whether the hand is a straight flush or not.
 *           
 *
 *  @par Example
 *  @verbatim
    int array[5] = {0, 1, 2, 3, 4};
    int arraySize = 5;
        
    bool out = isStraightFlush(array[], arraySize); // result would be true
    
    int array[5] = {0, 22, 51, 32, 24};
    int arraySize = 5;
        
    out = isStraightFlush(array[], arraySize); // result would be false
    

    @endverbatim
 ************************************************************************/
bool isStraightFlush( int array[], int arraySize) //checks to see if the hand is a straight flush
{
    int i;
    bool straight = true;
    bool beenFalse = false;
    
    if( isFlush( array, arraySize) == false) //must be a flush to be a straight flush
    {
        return false;
    }
    sortHand( array, arraySize);
    
    for( i=0; i<arraySize-1 && beenFalse == false; i++)
    {
        if( array[i] == array[i+1]-1)
        {
            straight = true;
        }
        else 
        {
            straight = false;
            beenFalse = true;
        }
    }
    
    return straight;
    
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Determines whether the hand passed in is a straight. This means the
 *   face value of the cards ascend by one each time, and they are not 
 *   all the same suit.
 *
 *  @param[in] array[] The hand which is being passed in.
 *
 *  @param[in] arraySize The size of the array which is passed in.
 *
 *  @returns  A boolean value, whether the hand is a straight or not.
 *           
 *
 *  @par Example
 *  @verbatim
    int array[5] = {0, 14, 28, 42, 17};
    int arraySize = 5;
        
    bool out = isStraight(array[], arraySize); // result would be true
    
    int array[5] = {0, 22, 51, 32, 24};
    int arraySize = 5;
        
    out = isStraight(array[], arraySize); // result would be false
    

    @endverbatim
 ************************************************************************/
bool isStraight( int array[], int arraySize) //checks to see if the hand is a straight
{
    int i;
    bool out = false;
    sortHandValue( array, arraySize);
    
    for( i=0; i<arraySize-1; i++) //checks that the face values ascend by one each time
    {
        if(faceValue( array[i]) == faceValue( array[i+1] -1))
        {
            out = true;
        }

        else
        {
            return false;
        }
    }
    
    return out;
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Determines whether the hand passed in is a straight. This means the
 *   face value of the cards ascend by one each time, and they are not 
 *   all the same suit. This is to check with the ace in the high slot.
 *
 *  @param[in] array[] The hand which is being passed in.
 *
 *  @param[in] arraySize The size of the array which is passed in.
 *
 *  @returns  A boolean value, whether the hand is a straight or not.
 *           
 *
 *  @par Example
 *  @verbatim
    int array[5] = {22, 23, 24, 25, 0};
    int arraySize = 5;
        
    bool out = isStraightAce(array[], arraySize); // result would be true
    
    int array[5] = {0, 22, 51, 32, 24};
    int arraySize = 5;
        
    out = isStraightAce(array[], arraySize); // result would be false
    

    @endverbatim
 ************************************************************************/
bool isStraightAce( int array[], int arraySize) // checks for a straight with ace in high card
{
    int i;
    bool out = false;
    sortHandValueAce( array, arraySize);
    
    if( faceValue(array[4]) != 0) // if ace is not the high card dont continue
    {
        return false;
    }
    if( faceValue(array[3]) != 12) //if the second highest card is not a king dont continue
    {
        return false;
    }
    
    for( i=0; i<arraySize-2; i++)
    {
        if(faceValue( array[i]) == faceValue( array[i+1]) -1)
        {
            out = true;
        }
        else
        {
            return false;
        }
    }
    
    return out;
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Determines whether the hand passed in is a flush. This means the
 *   suit of the cards is all the same.
 *
 *  @param[in] array[] The hand which is being passed in.
 *
 *  @param[in] arraySize The size of the array which is passed in.
 *
 *  @returns  A boolean value, whether the hand is a flush or not.
 *           
 *
 *  @par Example
 *  @verbatim
    int array[5] = {22, 23, 24, 25, 0};
    int arraySize = 5;
        
    bool out = isFlush(array[], arraySize); // result would be false
    
    int array[5] = {23, 22, 27, 13, 24};
    int arraySize = 5;
        
    out = isFlush(array[], arraySize); // result would be true
    

    @endverbatim
 ************************************************************************/
bool isFlush( int array[], int arraySize) //checks that the hand is a flush
{
    int i=0;
    
    int firstCard = findSuit(array[0]);
    
    for(i=0; i<arraySize; i++)
    {
        if( findSuit(array[i]) != firstCard)
        {
            return false;
        }
    }
    
    return true;
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Counts the number of cards in a hand which have the same face value.
 *   This will be used for the ofAKind function.
 *
 *  @param[in] array[] The hand which is being passed in.
 *
 *  @param[in] arraySize The size of the array which is passed in.
 *
 *  @param[in] numIn The card which will be searched for in the array.
 *
 *  @returns  An int value, how many of the face value were found.
 *           
 *
 *  @par Example
 *  @verbatim
    int array[5] = {13, 23, 24, 25, 0};
    int arraySize = 5;
    int numIn = 0;
        
    bool out = countIf(array[], arraySize, numIn); // result would be two
    
    int array[5] = {23, 22, 27, 13, 24};
    int arraySize = 5;
    int numIn = 0;
        
    out = isFlush(array[], arraySize); // result would be one
    

    @endverbatim
 ************************************************************************/
int countIf( int array[], int arraySize, int numIn) //basic countIf statement for ofAKind
{
    int i;
    int howMany = 0;
    
    for( i=0; i<arraySize; i++)
    {
        if( faceValue(array[i]) == faceValue(numIn))
        {
            howMany = howMany + 1;
        }
    }
    
    return howMany;
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Determines if the hand is one of the "of a kind", "full house", or "two 
 *   pair" hands. If not, "highCard" is returned.
 *
 *  @param[in] array[] The hand which is being passed in.
 *
 *  @param[in] arraySize The size of the array which is passed in.
 *
 *  @returns  A string, whichever value the hand holds.
 *           
 *
 *  @par Example
 *  @verbatim
    int array[5] = {0, 13, 14, 15, 16};
    int arraySize = 5;
        
    bool out = ofAKind(array[], arraySize); // result would be "two"
    
    int array[5] = {0, 13, 26, 15, 16};
    int arraySize = 5;
        
    out = ofAKind(array[], arraySize); // result would be "three"
    
    int array[5] = {0, 13, 26, 39, 16};
    int arraySize = 5;
        
    out = ofAKind(array[], arraySize); // result would be "four"
    
    int array[5] = {0, 13, 28, 15, 16};
    int arraySize = 5;
        
    out = ofAKind(array[], arraySize); // result would be "twoPair"
    
    int array[5] = {0, 13, 28, 15, 39};
    int arraySize = 5;
        
    out = ofAKind(array[], arraySize); // result would be "fullHouse"
    
    int array[5] = {0, 9, 6, 7, 8};
    int arraySize = 5;
        
    out = ofAKind(array[], arraySize); // result would be "highCard"
    

    @endverbatim
 ************************************************************************/
string ofAKind( int array[], int arraySize) //checks for hand types that are not flushes or straights
{
    int j;
    bool twoFound = false;
    int howManyTwos = 0;
    bool threeFound = false;
    bool fourFound = false;
    string output = "highCard";
    
    
    
    for( j=0; j<arraySize; j++)
    {
        
        if(countIf( array, arraySize, array[j]) == 2)
        {
            output = "two"; //two of a kind
            twoFound = true; //can be used to check for full house
            howManyTwos = howManyTwos + 1; //counts two for each pair
        }
        if(countIf( array, arraySize, array[j]) == 3)
        {
            output = "three"; //three of a kind
            threeFound = true; //can be used to check for full house
        }
        if(countIf( array, arraySize, array[j]) == 4)
        {
            output = "four"; //four of a kind
            fourFound = true;
        }
        
    }
    
    if( howManyTwos == 4) //two pairs if howManyTwos is 4
    {
        output = "twoPair"; 
    }
    
    if( twoFound == true && threeFound == true) //full house if 2 of a kind and 3 of a kind
    {
        output = "fullHouse";
    }
    
    
    return output;
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Determines which value the hand which was passed in holds. These range
 *   from a "high card" hand (at the low end) to a "royal flush" (at the 
 *   high end).
 *   
 *
 *  @param[in] array[] The hand which is being passed in.
 *
 *  @param[in] arraySize The size of the array which is passed in.
 *
 *  @returns  An int value, corresponding to the hand's value.
 *           
 *
 *  @par Example
 *  @verbatim
    int array[5] = {27, 30, 33, 35, 38};
    int arraySize = 5;
        
    bool out = classifyHand(array[], arraySize); // result would be 5
    
    int array[5] = {0, 13, 26, 39, 16};
    int arraySize = 5;
        
    out = classifyHand(array[], arraySize); // result would be 7
    

    @endverbatim
 ************************************************************************/
int classifyHand( int array[], int arraySize) //checks cards to determine the hand dealt
{
    if( isRoyalFlush(array, arraySize) == true)
    {
        return ROYALFLUSH;
    }
    else if( isStraightFlush(array, arraySize) == true)
    {
        return STRAIGHTFLUSH;
    }
    else if( ofAKind(array, arraySize) == "four")
    {
        return FOUROFAKIND;
    }
    else if( ofAKind(array, arraySize) == "fullHouse")
    {
        return FULLHOUSE;
    }
    else if( isFlush(array, arraySize) == true)
    {
        return FLUSH;
    }
    else if( isStraight(array, arraySize) == true)
    {
        return STRAIGHT;
    }
    else if( isStraightAce(array, arraySize) == true)
    {
        return STRAIGHT;
    }
    else if( ofAKind(array, arraySize) == "three")
    {
        return THREEOFAKIND;
    }
    else if( ofAKind(array, arraySize) == "twoPair")
    {
        return TWOPAIR;
    }
    else if( ofAKind(array, arraySize) == "two")
    {
        return TWOOFAKIND;
    }
    else
    {
        return HIGHCARD; //no matching hands? high card!
    }
    
}