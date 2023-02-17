#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "thpe3.h"

const bool RUNCATCH = false;


int main( int argc, char **argv)
{
    Catch::Session session;
    int result;
    
    if( RUNCATCH )
    {
        result = session.run();
        if( result != 0)
        {
            cout << "Test cases didn't pass." << endl;
            return result;
        }
    }

    ifstream input;
    ofstream output;
    int seedValue;
    int quantity;
    string inputFileName;
    string outputFileName;
    int arrayF[5];
    int nums;
    int i = 0;
    int j = 0;
    int k=0;
    string arg;
    int arrayS[5] = {0};
    int handValue;
    int handsDealt[10];
    double quantityDoub;
    double totalHands = 0;
    int totalHandsInt = 0;
    
    
    
    
    if( argc != 4)
    {
        cout << "Usage: thpe3.exe -s seedValue quantity"<< endl;
        cout << "       seedValue - # is integer for random numbers" << endl;
        cout << "       quantity - # of hands to deal" << endl << endl;
        cout << "       thpe3.exe -f inputfilename outputfilename" << endl;
        cout << "       inputfilename - filename containing the poker hands to classify" << endl;
        cout << "       outputfilename - filename to output the statistics in" << endl;
        
        return 0;
    }
    
    arg = argReturn( argv[1]);
    
    if ( checkArg(arg) == false)
    {
        cout << "Invalid Option" << endl;
        return 0;
    }
    if ( arg == "-s")
    {
        seedValue = atoi(argv[2]);
        quantity = atoi(argv[3]);
        
        
        for( i = 0; i < 10; i++)
        {
            handsDealt[i] = 0;
        }
        
        for(k=0; k<quantity; k++)
        {
            dealHands(arrayS, seedValue);
            handValue = classifyHand(arrayS,5);
            handsDealt[handValue]++;
        }
        
        quantityDoub = quantity;
        outputS( handsDealt, quantityDoub, quantity);
    }
    
    
    if ( arg == "-f")
    {
        if ( openInput( input, argv[2]) == false)
        {
            cout << "Unable to open the file: " << argv[2] << endl;
        }
        else if ( openOutput( output, argv[3]) == false)
        {
            cout << "Unable to open the file: " << argv[3] << endl;
        }
        else 
        {
            for( k = 0; k < 10; k++)
            {
                handsDealt[k] = 0;
            }
            
            while ( input >> nums )
            {
                arrayF[j] = nums;
                j++;
                totalHandsInt ++;
                
                for ( i=0; i<4; i++)
                {
                    input >> nums;
                    arrayF[j] = nums;
                    j++;
                }
                handValue = classifyHand( arrayF, 5);
                handsDealt[handValue]++;
                
                j = 0;
            }
            quantityDoub = quantity;
            totalHands = totalHandsInt;
            
            outputF( handsDealt, totalHands, totalHandsInt, output);
        }
    }
        
        
    return 0;
}    

TEST_CASE("sortHand - initial test of sortHand")
{
    int array[5] = {5, 4, 3, 2, 1};
    int arraySize = 5;
    
    sortHand(array, 5);
    
    CHECK(array[0] == 1);
    CHECK(array[1] == 2);
    CHECK(array[2] == 3);
    CHECK(array[3] == 4);
    CHECK(array[4] == 5);
}

TEST_CASE("sortHand - testing more different numbers")
{
    int array[5] = {45, 51, 13, 2, 7};
    int arraySize = 5;
    
    sortHand(array, 5);
    
    CHECK(array[0] == 2);
    CHECK(array[1] == 7);
    CHECK(array[2] == 13);
    CHECK(array[3] == 45);
    CHECK(array[4] == 51);
}

TEST_CASE("isRoyalFlush - initial test")
{
    int array[5] = {13, 22, 23, 24, 25};
    int arraySize = 5;
    
    bool royal = isRoyalFlush(array, 5);
    
    REQUIRE( royal == true);
}

TEST_CASE("isRoyalFlush - testing unsorted inputs")
{
    int array[5] = {22, 25, 24, 23, 13};
    int arraySize = 5;
    
    bool royal = isRoyalFlush(array, 5);
    
    REQUIRE( royal == true);
}

TEST_CASE("isRoyalFlush - testing something that should fail")
{
    int array[5] = {2, 45, 23, 5, 7};
    int arraySize = 5;
    
    bool royal = isRoyalFlush(array, 5);
    
    REQUIRE( royal == false);
}

TEST_CASE("isRoyalFlush - testing a second royal flush")
{
    int array[5] = {26, 35, 36, 37, 38};
    int arraySize = 5;
    
    bool royal = isRoyalFlush(array, 5);
    
    REQUIRE( royal == true);
}

TEST_CASE("isRoyalFlush - testing a third royal flush")
{
    int array[5] = {39, 48, 49, 50, 51};
    int arraySize = 5;
    
    bool royal = isRoyalFlush(array, 5);
    
    REQUIRE( royal == true);
}

TEST_CASE("isRoyalFlush - testing a final royal flush")
{
    int array[5] = {0, 9, 10, 11, 12};
    int arraySize = 5;
    
    bool royal = isRoyalFlush(array, 5);
    
    REQUIRE( royal == true);
}

TEST_CASE("faceValue - initial test")
{
    int cardIn = 35;
    
    int out = faceValue( 35);
    
    REQUIRE(out == 9);
}

TEST_CASE("faceValue - testing upper bounds")
{
    int cardIn = 51;
    
    int out = faceValue( 51);
    
    REQUIRE(out == 12);
}

TEST_CASE("faceValue - testing lower bounds")
{
    int cardIn = 0;
    
    int out = faceValue(0);
    
    REQUIRE(out == 0);
}

TEST_CASE("findSuit - initial test")
{
    int cardIn = 4;
    
    int out = findSuit(4);
    
    REQUIRE(out == 0);
}

TEST_CASE("findSuit - testing upper bounds of a suit")
{
    int cardIn = 12;
    
    int out = findSuit(12);
    
    REQUIRE(out == 0);
}

TEST_CASE("findSuit - testing lower bounds of a suit")
{
    int cardIn = 13;
    
    int out = findSuit(13);
    
    REQUIRE(out == 1);
}

TEST_CASE("isFlush - initial test")
{
    int array[5] = {2, 3, 4, 5, 6};
    int arraySize = 5;
    
    bool output = isFlush(array, 5);
    
    REQUIRE( output == true);
}

TEST_CASE("isFlush - further testing")
{
    int array[5] = {27, 30, 33, 35, 38};
    int arraySize = 5;
    
    bool output = isFlush(array, 5);
    
    REQUIRE( output == true);
}

TEST_CASE("isFlush - testing something that should fail")
{
    int array[5] = {27, 30, 51, 35, 38};
    int arraySize = 5;
    
    bool output = isFlush(array, 5);
    
    REQUIRE( output == false);
}

TEST_CASE("isFlush - testing crossing suits")
{
    int array[5] = {23, 24, 25, 26, 27};
    int arraySize = 5;
    
    bool output = isFlush(array, 5);
    
    REQUIRE( output == false);
}

TEST_CASE("isStraightFlush - initial test")
{
    int array[5] = {14, 15, 16, 17, 18};
    int arraySize = 5;
    
    bool output = isStraightFlush(array, 5);
    
    REQUIRE( output == true);
}

TEST_CASE("isStraightFlush - testing something which should fail")
{
    int array[5] = {14, 15, 16, 17, 37};
    int arraySize = 5;
    
    bool output = isStraightFlush(array, 5);
    
    REQUIRE( output == false);
}

TEST_CASE("isStraightFlush - testing one out of order")
{
    int array[5] = {18, 16, 15, 14, 17};
    int arraySize = 5;
    
    bool output = isStraightFlush(array, 5);
    
    REQUIRE( output == true);
}

TEST_CASE("isStraightFlush - testing crossing suits")
{
    int array[5] = {23, 24, 25, 26, 27};
    int arraySize = 5;
    
    bool output = isStraightFlush(array, 5);
    
    REQUIRE( output == false);
}

TEST_CASE("isStraightFlush - testing a royal flush")
{
    int array[5] = {0, 12, 10, 9, 11};
    int arraySize = 5;
    
    bool output = isStraightFlush(array, 5);
    
    REQUIRE( output == false);
}

TEST_CASE("ofAKind - testing two of a kind")
{
    int array[5] = {0, 13, 14, 15, 16};
    int arraySize = 5;
    
    string kindOut = ofAKind(array, 5);
    
    REQUIRE( kindOut == "two");
}

TEST_CASE("ofAKind - testing three of a kind")
{
    int array[5] = {0, 13, 26, 15, 16};
    int arraySize = 5;
    
    string kindOut = ofAKind(array, 5);
    
    REQUIRE( kindOut == "three");
}

TEST_CASE("ofAKind - testing four of a kind")
{
    int array[5] = {0, 13, 26, 39, 16};
    int arraySize = 5;
    
    string kindOut = ofAKind(array, 5);
    
    REQUIRE( kindOut == "four");
}

TEST_CASE("ofAKind - testing two pair")
{
    int array[5] = {0, 13, 28, 15, 16};
    int arraySize = 5;
    
    string kindOut = ofAKind(array, 5);
    
    REQUIRE( kindOut == "twoPair");
}

TEST_CASE("ofAKind - testing full house")
{
    int array[5] = {0, 13, 28, 15, 39};
    int arraySize = 5;
    
    string kindOut = ofAKind(array, 5);
    
    REQUIRE( kindOut == "fullHouse");
}

TEST_CASE("ofAKind - testing high card")
{
    int array[5] = {0, 9, 6, 7, 8};
    int arraySize = 5;
    
    string kindOut = ofAKind(array, 5);
    
    REQUIRE( kindOut == "highCard");
}

TEST_CASE("isStraight - initial test")
{
    int array[5] = {0, 1, 2, 3, 4};
    int arraySize = 5;
    
    bool output = isStraight( array, 5);
    
    REQUIRE( output == true);
}

TEST_CASE("isStraight - testing different suits")
{
    int array[5] = {0, 14, 28, 42, 17};
    int arraySize = 5;
    
    bool output = isStraight( array, 5);
    
    REQUIRE( output == true);
}

TEST_CASE("isStraight - testing something that should fail")
{
    int array[5] = {0, 14, 28, 42, 49};
    int arraySize = 5;
  
    bool output = isStraight( array, 5);
    
    REQUIRE( output == false);
}

TEST_CASE("isStraight - testing unsorted numbers")
{
    int array[5] = {14, 28, 17, 42, 0};
    int arraySize = 5;
    
    bool output = isStraight( array, 5);
    
    REQUIRE( output == true);
}

TEST_CASE("sortHandValue - initial test")
{
    int array[5] = {5, 4, 3, 2, 1};
    int arraySize = 5;
    
    sortHandValue(array, 5);
    
    CHECK(array[0] == 1);
    CHECK(array[1] == 2);
    CHECK(array[2] == 3);
    CHECK(array[3] == 4);
    CHECK(array[4] == 5);
}

TEST_CASE("sortHandValue - testing different suits")
{
    int array[5] = {14, 28, 17, 42, 0};
    int arraySize = 5;
    
    sortHandValue(array, 5);
    
    CHECK(array[0] == 0);
    CHECK(array[1] == 14);
    CHECK(array[2] == 28);
    CHECK(array[3] == 42);
    CHECK(array[4] == 17);
}

TEST_CASE("classifyHand - testing a royal flush")
{
    int array[5] = {22, 25, 24, 23, 13};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 9);
}

TEST_CASE("classifyHand - testing a straight flush")
{
    int array[5] = {18, 16, 15, 14, 17};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 8);
}

TEST_CASE("classifyHand - testing four of a kind")
{
    int array[5] = {0, 13, 26, 39, 16};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 7);
}

TEST_CASE("classifyHand - testing full house")
{
    int array[5] = {0, 13, 28, 15, 39};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 6);
}

TEST_CASE("classifyHand - testing flush")
{
    int array[5] = {27, 30, 33, 35, 38};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 5);
}

TEST_CASE("classifyHand - testing straight")
{
    int array[5] = {0, 14, 28, 42, 17};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 4);
}

TEST_CASE("classifyHand - testing three of a kind")
{
    int array[5] = {0, 13, 26, 15, 16};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 3);
}

TEST_CASE("classifyHand - testing two pair")
{
    int array[5] = {0, 13, 28, 15, 16};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 2);
}

TEST_CASE("classifyHand - testing two of a kind")
{
    int array[5] = {0, 13, 14, 15, 16};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 1);
}

TEST_CASE("classifyHand - testing high card")
{
    int array[5] = {0, 9, 6, 7, 43};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 0);
}

TEST_CASE("classifyHand - testing a straight with ace in high")
{
    int array[5] = {22, 36, 24, 25, 13};
    int arraySize = 5;
    
    int hand = classifyHand(array,5);
    
    REQUIRE( hand == 4);
}

TEST_CASE("sortHandValueAce - initital testing")
{
    int array[5] = {0, 22, 23, 24, 25};
    int arraySize = 5;
    
    sortHandValueAce(array,5);
    
    CHECK(array[0] == 22);
    CHECK(array[1] == 23);
    CHECK(array[2] == 24);
    CHECK(array[3] == 25);
    CHECK(array[4] == 0);
}

TEST_CASE("classifyHand - testing the first -s failure")
{
    int array[5] = {43, 45, 49, 4, 51};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 1);
}

TEST_CASE("classifyHand - testing the second -s failure")
{
    int array[5] = {13, 4, 17, 15, 23};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 1);
}

TEST_CASE("classifyHand - testing the third -s failure")
{
    int array[5] = {27, 48, 23, 7, 5};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 0);
}

TEST_CASE("classifyHand - testing the fourth -s failure")
{
    int array[5] = {18, 5, 36, 29, 12};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 1);
}

TEST_CASE("classifyHand - testing the fifth -s failure")
{
    int array[5] = {33, 26, 10, 21, 31};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 0);
}

TEST_CASE("classifyHand - testing the sixth -s failure")
{
    int array[5] = {26, 42, 10, 4, 13};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 1);
}

TEST_CASE("classifyHand - testing the seventh -s failure")
{
    int array[5] = {30, 0, 37, 45, 40};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 0);
}

TEST_CASE("classifyHand - testing the eigth -s failure")
{
    int array[5] = {28, 36, 10, 37, 33};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 1);
}

TEST_CASE("classifyHand - testing the ninth -s failure")
{
    int array[5] = {23, 17, 47, 22, 36};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 1);
}

TEST_CASE("classifyHand - testing the tenth -s failure")
{
    int array[5] = {0, 15, 31, 18, 17};
    int arraySize = 5;
    
    int hand = classifyHand(array, 5);
    
    REQUIRE( hand == 1);
}
