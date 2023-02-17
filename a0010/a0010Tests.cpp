#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "a0010.h"

const bool RUNCATCH = false;
//function main
int main()
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
    int array[1001];
    int howMany = 0;
    int i;
    int j;
    int sum;
    double avg;
    int count = 0;
    
    cout << "Enter up to 1000 integers, <ctrl>-z to stop: " << endl;
    for( i=0; i<1001 && cin; i++)
    {
        cin >> array[i];
        count = count+1;
    }
    int countMinus = count-1;
    
    cout << "Quantity: " << countMinus << endl;
    
    sortArray(array, countMinus);
    
    cout << "Range: " << array[0] << " to " << array[count-2] << endl;
    
    sum = sumArray(array, countMinus);
    cout << "Sum: " << fixed << sum << endl;
    
    double doubleSum = sum;
    
    avg = doubleSum/ countMinus;
    
    cout << fixed << setprecision(4);
    cout << "Average: " << avg << endl;
    cout << "Data: " << endl;
    for( j=0; j < countMinus; j++)
    {
        cout << setw(10) << array[j];
        if(j==4 || (j>4 && (j+1) % 5 == 0))
        {
            cout << endl;
        }
    }
    cout << endl;
}
TEST_CASE("sortArray - initial test")
{
    int arrayIn[3] = {2, 3, 1};
    int arraySize = 3;
    
    sortArray(arrayIn, arraySize);
    
    CHECK( arrayIn[0] == 1);
    CHECK( arrayIn[2] == 3);
}

TEST_CASE("sortArray - further testing")
{
    int arrayIn[8] = {23, -1029, -12, 4, 8, 64, 798, 1098};
    int arraySize = 8;
    
    sortArray(arrayIn, arraySize);
    
    CHECK( arrayIn[0] == -1029);
    CHECK( arrayIn[2] == 4);
    CHECK( arrayIn[7] == 1098);
}

TEST_CASE("sortArray - testing all negatives")
{
    int arrayIn[4] = {-1000, -3, -100, -69};
    int arraySize = 4;
    
    sortArray(arrayIn, arraySize);
    
    CHECK( arrayIn[0] == -1000);
    CHECK( arrayIn[2] == -69);
    CHECK( arrayIn[3] == -3);
}

TEST_CASE("sumArray - initial test")
{
    int arrayIn[3] = {1, 1, 1};
    int arraySize = 3;
    
    double sum = sumArray(arrayIn, arraySize);
    
    REQUIRE(sum == 3);
}

TEST_CASE("sumArray - testing different numbers")
{
    int arrayIn[5] = {1, 2, 3, 4, 5};
    int arraySize = 5;
    
    double sum = sumArray(arrayIn, arraySize);
    
    REQUIRE(sum == 15);
}

TEST_CASE("sumArray - testing with a negative")
{
    int arrayIn[5] = {1, 2, -3, 4, 5};
    int arraySize = 5;
    
    double sum = sumArray(arrayIn, arraySize);
    
    REQUIRE(sum == 9);
}