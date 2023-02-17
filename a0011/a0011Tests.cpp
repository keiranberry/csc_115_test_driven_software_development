#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "a0011.h"

const bool RUNCATCH = false;

int main( int argc, char **argv)
{
    Catch::Session session;
    int result;
    if( RUNCATCH)
    {
        result = session.run();
        if( result != 0 )
        {
            cout << "Test cases didn't pass." << endl;
            return result;
        }
    }
    
    int size = 0;
    int i=0;
    int j=0;
    int nums;
    ifstream input;
    ofstream primes;
    ofstream evens;
    ofstream odds;
    string finInputS;
    string foutPrimesS;
    string foutEvensS;
    string foutOddsS;


    if( argc != 5)
    {
        cout << "Usage: a0011.exe datafile primefile evenfile oddfile" << endl;
        return 0;
    }
    
    if(openInput(input, argv[1]) == false || openOutput(primes, argv[2]) == false
    || openOutput(evens, argv[3]) == false || openOutput(odds, argv[4]) == false)
    {
        cleanUp(input, primes, evens, odds);
    }
    
    while(input >> nums)
    {
        if( isPrime(nums) == true)
        {
            primes << setw(10) << nums << endl;
        }
        else if( nums % 2 == 0)
        {
            evens << setw(10) << nums << endl;
        }
        else 
        {
            odds << setw(10) << nums << endl;
        }
    }

    return 0;
}

TEST_CASE("isPrime - testing to make sure isPrime is working")
{
    CHECK( isPrime(13) == true);
    CHECK( isPrime(12) == false);
}

TEST_CASE("cleanUp - initial test")
{
    ifstream fin;
    ofstream fout, fout1, fout2;
    
    fin.open("given1.txt");
    fout.open("solEven1.txt");
    fout1.open("solOdd1.txt");
    fout2.open("solPrime1.txt");
    
    cleanUp(fin, fout, fout1, fout2);
    
    CHECK(fin.is_open() == false);
    CHECK(fout.is_open() == false);
    CHECK(fout1.is_open() == false);
    CHECK(fout2.is_open() == false);   
}

TEST_CASE("openInput - testing a file which should open")
{
    ifstream fin;
    string fileIn = "given1.txt";
    
    openInput( fin, fileIn);
    
    CHECK(fin.is_open() == true);
}

TEST_CASE("openInput - testing a file which should not open")
{
    ifstream fin;
    string fileIn = "z:\\reeeeeeeee.txt";
    
    openInput( fin, fileIn);
    
    CHECK(fin.is_open() == false);
}

TEST_CASE("openOutput - testing a file which should open")
{
    ofstream fout;
    string fileIn = "solEven1.txt";
    
    openOutput( fout, fileIn);
    
    CHECK(fout.is_open() == true);
}

TEST_CASE("openOutput - testing a file which should not open")
{
    ofstream fout;
    string fileIn = "z:\\AAAAAAAAAAA.txt";
    
    openOutput( fout, fileIn);
    
    CHECK(fout.is_open() == false);
}

