/** ********************************************************************
* @file
***********************************************************************/

#include "thpe2.h"
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Takes the square root of a number which is passed in using the 
 *   bisector method. Continues to narrow down potential answers until 
 *   an answer has been found by checking midpoints.
 *
 *  @param[in] sqrtNumIn The number of which the square root will be taken.
 *
 *  @returns  A double value, the square root of the number which was
 *           passed in. This value is within ERRORVALUE (.000000000001) 
 *           of the precise square root of what was passed in.
 *
 *  @par Example
 *  @verbatim
    double sqrt;
    double sqrtNumIn = 9;

    sqrt = mySqrt(sqrtNumIn); // result would be 3

    sqrtNumIn = 16;
    sqrt = mySqrt(sqrtNumIn); // result would be 4

    sqrtNumIn = 84;
    sqrt = mySqrt(sqrtNumIn); // result would be Approx 9.16515

    @endverbatim
 ************************************************************************/
double mySqrt( double sqrtNumIn)
{
    if (sqrtNumIn <= 0)
    {
        return 0;
    }
    double low = 0;
    double high;
    if (sqrtNumIn < 1 && sqrtNumIn > 0)
    {
        high = 1;
    }
    if (sqrtNumIn >= 1)
    {
        high = sqrtNumIn;
    }
    bool sqrtFound = false;
    int i = 0;
    for (i = 0; i<ITERATIONMAX && sqrtFound == false; i++)
        {
            double midpoint = (high+low)/2;
            double midSquared = pow(midpoint, 2);
            if (fabs(midSquared - sqrtNumIn) < ERRORVALUE)
            {
                return midpoint;
                sqrtFound = true;
            }
            else if (midSquared - sqrtNumIn > 0)
            {
                high = midpoint;
            }
            else if (midSquared - sqrtNumIn < 0)
            {
                low = midpoint;
            }
        }
    return 0;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Takes the cube root of a number which is passed in using the 
 *   bisector method. Continues to narrow down potential answers until 
 *   an answer has been found by checking midpoints.
 *
 *  @param[in] cbrtNumIn The number of which the cube root will be taken.
 *
 *  @returns  A double value, the cube root of the number which was
 *           passed in. This value is within ERRORVALUE (.000000000001) 
 *           of the precise cube root of what was passed in.
 *
 *  @par Example
 *  @verbatim
    double cbrt;
    double cbrtNumIn = 27;

    cbrt = myCbrt(cbrtNumIn); // result would be 3

    cbrtNumIn = 64;
    cbrt = myCbrt(cbrtNumIn); // result would be 4

    cbrtNumIn = 12167;
    cbrt = myCbrt(cbrtNumIn); // result would be 23

    @endverbatim
 ************************************************************************/
double myCbrt( double cbrtNumIn)
{
    double cbrtOut;
    if (cbrtNumIn <= 0)
    {
        cbrtOut= 0;
    }
    double low = 0;
    double high;
    if (cbrtNumIn < 1 && cbrtNumIn > 0)
    {
        high = 1;
    }
    else if (cbrtNumIn >= 1)
    {
        high = cbrtNumIn;
    }
    bool cbrtFound = false;
    int i = 0;
    for (i = 0; i<ITERATIONMAX && cbrtFound == false; i++)
        {
            double midpoint = (high+low)/2;
            double midCubed = pow(midpoint, 3);
            if (fabs(midCubed - cbrtNumIn) < ERRORVALUE)
            {
                cbrtOut = midpoint;
                cbrtFound = true;
            }
            else if ((midCubed - cbrtNumIn) > 0)
            {
                high = midpoint;
            }
            else if ((midCubed - cbrtNumIn) < 0)
            {
                low = midpoint;
            }
        }
    return cbrtOut;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Computes the logarithm of a base and a number x. This means finding 
 *   what exponent of the base will result in a final answer x. This is  
 *   done with the bisector method.
 *
 *  @param[in] x The final number using base and the found exponent.
 *
 *  @param[in] base The base of the base, exponent pair.
 *
 *  @returns  A double value, the logarithm of the base and x. This 
 *           returned value is within ERRORVALUE (.000000000001) of 
 *           the precise answer that would be returned with a calculator.
 *
 *  @par Example
 *  @verbatim
    double log;
    double x = 27;
    double base = 3;

    log = myLog(x, base); // result would be 3

    x = 16;
    base = 2
    log = myLog(x, base); // result would be 4

    x = 16.6608;
    base = 6;
    log = myLog(x, base); // result would be 1.57

    @endverbatim
 ************************************************************************/
double myLog( double x, int base)
{
    double high = 1;
    int i, j;
    double midpoint = 0;
    bool expFound = false;
    double low;
    double output;
    for( j=0 ; pow(base, high) < x; j ++)
    {
        high = high+1;
    }
    if ( pow(base, high) == x)
    {
        output = high;
        expFound = true;
    }
    low = high - 1;
    
    
    for(i=0; i<ITERATIONMAX && expFound == false; i++)
    {
        double midpoint = (low + high)/2;
        double power = pow(base, midpoint);
        
        if (fabs(power -x) < ERRORVALUE)
        {
            output = midpoint;
            expFound = true;
        }
        else if (power-x > 0)
        {
            high = midpoint;
        }
        else if (power-x < 0)
        {
            low = midpoint;
        }
    }
    if(i == ITERATIONMAX)
    {
        output = midpoint;
    }
    return output;

}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Takes the factorial of a number which is passed in. This means 
 *   multiplying the integer which is passed in by all integers  
 *   descending from it, until it hits 0 (does not multiply by 0).
 *
 *  @param[in] numIn The number of which the factorial will be taken.
 *
 *  @returns  A double value, the factorial of the number which was
 *           passed in. This value can be used in the mySin, myCos,  
 *           and myTan functions for the Taylor series.
 *
 *  @par Example
 *  @verbatim
    double factorialOut;
    double numIn = 3;

    factorialOut = factorial(numIn); // result would be 6

    numIn = 4;
    factorialOut = factorial(numIn); // result would be 24

    numIn = 2;
    factorialOut = factorial(numIn); // result would be 2
    @endverbatim
 ************************************************************************/
double factorial(double numIn)
{
    int i;
    double total = 1;
    
    for (i=numIn; i>0; i--)
    {
        total = i * total;
    }
    
    return total;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Takes the sin of a number which is passed in. The number which is  
 *   passed in is in radians. This uses a set number of terms of the 
 *   Taylor series for sin in order to approximate an answer. The 
 *   constant PI can be input as well.
 *
 *  @param[in] numIn The number of which the sin will be taken.
 *
 *  @returns  A double value, the sin of the number which was
 *           passed in. This value can be used for the myTan function.  
 *           
 *
 *  @par Example
 *  @verbatim
    double sinx;
    double numIn = PI/2;

    sinx = mySin(numIn); // result would be 1

    numIn = 0;
    sinx = mySin(numIn); // result would be 0

    numIn = PI/6;
    sinx = mySin(numIn); // result would be .5
    @endverbatim
 ************************************************************************/
double mySin( double numIn)
{
    int i;
    double sinTotal = 0;
    double sinTemp;
    for (i=0; i<TERMS; i++)
    {
        double magicNum = (2*i)+1;
        double coefficient = pow(-1, i);
        double numerator = pow(numIn, magicNum);
        double denominator = factorial(magicNum);
        
        sinTemp = coefficient*(numerator/denominator);
        
        sinTotal = sinTotal + sinTemp;
    }
    if (sinTotal < 0 && sinTotal > -1*ERRORVALUE)
    {
        sinTotal = 0;
    }
    return sinTotal;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Takes the sin of a number which is passed in. The number which is  
 *   passed in is in degrees. Converts the degree value to radians 
 *   and then passes it through the regular mySin function.
 *
 *  @param[in] numInD The number of which the sin will be taken.
 *
 *  @returns  A double value, the sin of the number which was
 *           passed in. This value can be used for the myTan function.  
 *           
 *
 *  @par Example
 *  @verbatim
    double sinx;
    double numIn = 90;

    sinx = mySinD(numInD); // result would be 1

    numIn = 0;
    sinx = mySinD(numInD); // result would be 0

    numIn = 30;
    sinx = mySinD(numInD); // result would be .5
    @endverbatim
 ************************************************************************/
double mySinD( double numInD)
{
    double numIn = numInD*(PI/180);
    double sinOut = mySin(numIn);
    
    return sinOut;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Takes the cos of a number which is passed in. The number which is  
 *   passed in is in radians. This uses a set number of terms of the 
 *   Taylor series for cos in order to approximate an answer. The 
 *   constant PI can be input as well.
 *
 *  @param[in] numIn The number of which the cos will be taken.
 *
 *  @returns  A double value, the cos of the number which was
 *           passed in. This value can be used for the myTan function.  
 *           
 *
 *  @par Example
 *  @verbatim
    double cosx;
    double numIn = 0;

    cosx = myCos(numIn); // result would be 1

    numIn = PI/2;
    cosx = myCos(numIn); // result would be 0

    numIn = PI/3;
    cosx = myCos(numIn); // result would be .5
    @endverbatim
 ************************************************************************/
double myCos( double numIn)
{
    int i;
    double cosTotal = 0;
    double cosTemp;
    for (i=0; i<TERMS; i++)
    {
        double magicNum = 2*i;
        double coefficient = pow(-1, i);
        double numerator = pow(numIn, magicNum);
        double denominator = factorial(magicNum);
        
        cosTemp = coefficient*(numerator/denominator);
        
        cosTotal = cosTotal + cosTemp;
    }
    if (cosTotal < 0 && cosTotal > -1*ERRORVALUE)
    {
        cosTotal = 0;
    }
    
    return cosTotal;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Takes the cos of a number which is passed in. The number which is  
 *   passed in is in degrees. Converts the degree value to radians 
 *   and then passes it through the regular myCos function.
 *
 *  @param[in] numInD The number of which the cos will be taken.
 *
 *  @returns  A double value, the cos of the number which was
 *           passed in. This value can be used for the myTan function.  
 *           
 *
 *  @par Example
 *  @verbatim
    double cosx;
    double numInD = 0;

    cosx = myCosD(numInD); // result would be 1

    numIn = 90;
    cosx = myCosD(numInD); // result would be 0

    numIn = 60;
    cosx = myCosD(numInD); // result would be .5
    @endverbatim
 ************************************************************************/
double myCosD( double numInD)
{
    double numIn = numInD*(PI/180);
    double cosOut = myCos(numIn);
    
    return cosOut;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Takes the tan of a number which is passed in. The number which is  
 *   passed in is in radians. The constant PI can be input. This function 
 *   passes the number which is passed in into mySin and myCos as tan is 
 *   defined as sin/cos.
 *
 *  @param[in] numIn The number of which the tan will be taken.
 *
 *  @returns  A double value, the tan of the number which was
 *           passed in. 
 *           
 *
 *  @par Example
 *  @verbatim
    double tanx;
    double numIn = 0;

    tanx = myTan(numIn); // result would be 0

    numIn = PI/4;
    tanx = myTan(numIn); // result would be 1

    numIn = -PI/4;
    tanx = myTan(numIn); // result would be 1
    @endverbatim
 ************************************************************************/
double myTan( double numIn)
{
    double numerator = mySin(numIn);
    double denominator = myCos(numIn);
    
    double tangent = (numerator/denominator);
    
    if (tangent < 0 && tangent > -0.000001)
    {
        tangent = 0;
    }
    return tangent;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Takes the tan of a number which is passed in. The number which is  
 *   passed in is in degrees. Converts the degree value to radians 
 *   and then passes it through the regular myTan function.
 *
 *  @param[in] numInD The number of which the tan will be taken.
 *
 *  @returns  A double value, the tan of the number which was
 *           passed in. 
 *           
 *
 *  @par Example
 *  @verbatim
    double tanx;
    double numInD = 0;

    tanx = myTanD(numInD); // result would be 0

    numIn = 45;
    tanx = myTanD(numInD); // result would be 1

    numIn = -135;
    tanx = myTanD(numInD); // result would be 1
    @endverbatim
 ************************************************************************/
double myTanD( double numInD)
{
    double numIn = numInD*(PI/180);
    double tanOut = myTan(numIn);
    
    return tanOut;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Copies a source array into a destination array. The destination array 
 *   will end up the exact same as the source array.  
 *
 *  @param[in] destination[] The array which will be copied from source.
 *
 *  @param[in] source[] The array which will be copied into destination.
 *
 *  @param[in] arraySize The size of both arrays.
 *
 *
 *  @par Example
 *  @verbatim
    double destination[4];
    double source[4] = {1, 2, 3, 4};
    int arraySize = 4;

    copyArray(destination, source, arraySize); // destination {1, 2, 3, 4}

    @endverbatim
 ************************************************************************/
void copyArray( double destination[], double source[], int arraySize)
{
    int i;
    
    for (i = 0; i<arraySize; i++)
    {
        destination[i] = source[i];
    }
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Initializes every item in the array to the specified value. If 
 *   the specified value to initialize to is 0, every item in the 
 *   array will be set to 0.
 *
 *  @param[in] array[] The array which will be initialized.
 *
 *  @param[in] arraySize The size of the array.
 *
 *  @param[in] initialize The value which each item will be initialized to.
 *
 *
 *  @par Example
 *  @verbatim
    double array[3];
    int arraySize = 3;
    double initialize = 0;

    initialArray(array, arraySize, initialize); // result is {0, 0, 0}

    @endverbatim
 ************************************************************************/
void initialArray( double array[], int arraySize, double initialize)
{
    int i;
    
    for (i = 0; i<arraySize; i++)
    {
        array[i] = initialize;
    }
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Takes the sum of all items in the array.
 *
 *  @param[in] arrayIn[] The array which will be summed.
 *
 *  @param[in] arraySize The size of the array.
 *
 *  @returns  A double value, the sum of the array which was
 *           passed in. 
 *           
 *
 *  @par Example
 *  @verbatim
    double arrayIn[5] = {1, 1, 1, 1, 1};
    int arraySize = 5;

    double sum = sumArray(arrayIn, arraySize); // result would be 5

    arrayIn[3] = {3, 8, 5};
    sum = sumArray(arrayIn, arraySize); // result would be 16

    arrayIn[6] = {1, 3, 5, 7, 9, 1};
    sum = sumArray(arrayIn, arraySize); // result would be 26
    @endverbatim
 ************************************************************************/
double sumArray( double arrayIn[], int arraySize)
{
    double arraySum = 0;
    int i = 0;
    for (i=0; i<arraySize; i++)
    {
        arraySum = arraySum + arrayIn[i];
    }
    return arraySum;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Takes the average of the items in a given array. Refers to sumArray
 *   and then divides the found sum by the array size to find average.
 *
 *  @param[in] arrayIn[] The array which will be averaged.
 *
 *  @param[in] arraySize The size of the array.
 *
 *  @returns  A double value, the average of the array which was
 *           passed in. 
 *           
 *
 *  @par Example
 *  @verbatim
    double arrayIn[5] = {1, 1, 1, 1, 1};
    int arraySize = 5;

    double average = averageArray(arrayIn, arraySize); // result would be 1

    arrayIn[3] = {2, 10, 12};
    double average = averageArray(arrayIn, arraySize); // result would be 8

    arrayIn[6] = {2, 4, 1, 1, 1, 27};
    double average = averageArray(arrayIn, arraySize); // result would be 6
    @endverbatim
 ************************************************************************/
double averageArray ( double arrayIn[], int arraySize)
{
    double sum = sumArray( arrayIn, arraySize);
    double arrayAverage = sum/arraySize;
    
    return arrayAverage;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Finds the minimum value in the array and returns its location. If 
 *   there are two of the same minimum, the lower location index is 
 *   returned.
 *
 *  @param[in] arrayIn[] The array which will be searched for a minimum.
 *
 *  @param[in] arraySize The size of the array.
 *
 *  @returns  An integer, the location of the minimum value which was
 *           found in the array. 
 *           
 *
 *  @par Example
 *  @verbatim
    double arrayIn[5] = {1, 1, 1, 1, 1};
    int arraySize = 5;

    double location = minLocation(arrayIn, arraySize); // result would be 0

    arrayIn[3] = {10, 0, 12};
    double location = minLocation(arrayIn, arraySize); // result would be 1

    arrayIn[6] = {2, 4, 1, -12, 1, 27};
    double location = minLocation(arrayIn, arraySize); // result would be 3
    @endverbatim
 ************************************************************************/
int minLocation ( double arrayIn[], int arraySize)
{
    int i;
    int j;
    int minimum = 0;
    for (i=0; i<arraySize-1; i++)
    {
        for(j = i+1; j<arraySize; j++)
        {
            if (arrayIn[j]<arrayIn[minimum])
            {
                minimum = j;
            }
        }
    }
    return minimum;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Finds the minimum value in the array and returns it. This uses the 
 *   minLocation function.
 *
 *
 *  @param[in] arrayIn[] The array which will be searched for a minimum.
 *
 *  @param[in] arraySize The size of the array.
 *
 *  @returns  An integer, the minimum value which was found in the array.
 *          
 *           
 *
 *  @par Example
 *  @verbatim
    double arrayIn[5] = {1, 1, 1, 1, 1};
    int arraySize = 5;

    double minimum = minValue(arrayIn, arraySize); // result would be 1

    arrayIn[3] = {10, 0, 12};
    double minimum = minValue(arrayIn, arraySize); // result would be 0

    arrayIn[6] = {2, 4, 1, -12, 1, 27};
    double minimum = minValue(arrayIn, arraySize); // result would be -12
    @endverbatim
 ************************************************************************/
double minValue ( double arrayIn[], int arraySize)
{
    int minIndex = minLocation(arrayIn, arraySize);
    double minimumValue = arrayIn[minIndex];
    
    return minimumValue;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Finds the maximum value in the array and returns its location. If 
 *   there are two of the same maximum, the lower location index is 
 *   returned.
 *
 *  @param[in] arrayIn[] The array which will be searched for a maximum.
 *
 *  @param[in] arraySize The size of the array.
 *
 *  @returns  An integer, the location of the maximum value which was
 *           found in the array. 
 *           
 *
 *  @par Example
 *  @verbatim
    double arrayIn[5] = {1, 1, 1, 1, 1};
    int arraySize = 5;

    double location = maxLocation(arrayIn, arraySize); // result would be 0

    arrayIn[3] = {10, 0, 12};
    double location = maxLocation(arrayIn, arraySize); // result would be 2

    arrayIn[6] = {2, 4, 1, -12, 1, 27};
    double location = maxLocation(arrayIn, arraySize); // result would be 5
    @endverbatim
 ************************************************************************/
int maxLocation ( double arrayIn[], int arraySize)
{
    int i;
    int j;
    int maximum = 0;
    for (i=0; i<arraySize-1; i++)
    {
        for(j = i+1; j<arraySize; j++)
        {
            if (arrayIn[j]>arrayIn[maximum])
            {
                maximum = j;
            }
        }
    }
    return maximum;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Finds the maximum value in the array and returns it. This uses the 
 *   maxLocation function.
 *
 *
 *  @param[in] arrayIn[] The array which will be searched for a maximum.
 *
 *  @param[in] arraySize The size of the array.
 *
 *  @returns  An integer, the maximum value which was found in the array.
 *          
 *           
 *
 *  @par Example
 *  @verbatim
    double arrayIn[5] = {1, 1, 1, 1, 1};
    int arraySize = 5;

    double maximum = maxValue(arrayIn, arraySize); // result would be 1

    arrayIn[3] = {10, 0, 12};
    double maximum = maxValue(arrayIn, arraySize); // result would be 12

    arrayIn[6] = {2, 4, 1, -12, 1, 27};
    double maximum = maxValue(arrayIn, arraySize); // result would be 27
    @endverbatim
 ************************************************************************/
double maxValue ( double arrayIn[], int arraySize)
{
    int maxIndex = maxLocation(arrayIn, arraySize);
    double maximumValue = arrayIn[maxIndex];
    
    return maximumValue;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Searches for a specified item in the array and returns how many of 
 *   that item exist in the array. For every matching item in the 
 *   array, one is added to the total count.
 *
 *  @param[in] arrayIn[] The array which will be searched.
 *
 *  @param[in] arraySize The size of the array.
 *
 *  @param[in] lookFor The item which will be searched for in the array.
 *
 *  @returns  An integer, how many of the specified item were found 
 *             in the array. 
 *           
 *
 *  @par Example
 *  @verbatim
    double arrayIn[5] = {0, 1, 2, 2, 2};
    int arraySize = 5;
    double lookFor = 2;
    
    double countOut = countIf(arrayIn, arraySize, lookFor); // result 3

    arrayIn[3] = {10, 0, 12};
    arraySize = 3;
    double lookFor = 0;
    double countOut = countIf(arrayIn, arraySize, lookFor); // result 1
    @endverbatim
 ************************************************************************/
int countIf( double arrayIn[], int arraySize, double lookFor)
{
    int howMany = 0;
    int i;
    for (i=0; i<arraySize; i++)
    {
        if (arrayIn[i] == lookFor)
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
 *  Sorts doubles in an array in either ascending or descending order.
 *   The order is to be specified as either "ASC" or "DSC". If 
 *   neither are specified, the array is not sorted.
 *
 *  @param[in] arrayIn[] The array which will be sorted.
 *
 *  @param[in] arraySize The size of the array.
 *
 *  @param[in] order A string, either "ASC" or "DSC", order to sort in.
 *
 *
 *  @par Example
 *  @verbatim
    double arrayIn[3] = {2, 1, 3};
    int arraySize = 3;
    string order = "ASC";

    mySort(arrayIn, arraySize, order); // result is {1, 2, 3}

    arrayIn[3] = {2, 1, 3};
    arraySize = 3;
    order = "DSC";

    initialArray(array, arraySize, initialize); // result is {3, 2, 1}
    @endverbatim
 ************************************************************************/
void mySort ( double arrayIn[], int arraySize, string order)
{
    int i,j;
    if( order == "ASC")
    {
        for (i=0; i<arraySize-1; i++)
        {
            for (j=0; j< arraySize-1 -i ; j++)
            {
                if (arrayIn[j] > arrayIn[j+1])
                {
                double temp = arrayIn[j];
                arrayIn[j] = arrayIn[j+1];
                arrayIn[j+1] = temp;
                }
            }
        }
    }
    if( order == "DSC")
    {
        for (i=0; i<arraySize-1; i++)
        {
            for (j=0; j< arraySize-1 -i ; j++)
            {
                if (arrayIn[j] < arrayIn[j+1])
                {
                int temp = arrayIn[j];
                arrayIn[j] = arrayIn[j+1];
                arrayIn[j+1] = temp;
                }
            }
        }
    }
}                
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Searches for a specified item in the array and returns its location. 
 *   If the specified value is not in the array, -1 is returned. This 
 *   searching is done by going through the array in order.
 *
 *  @param[in] arrayIn[] The array which will be searched.
 *
 *  @param[in] arraySize The size of the array.
 *
 *  @param[in] lookFor The item which will be searched for in the array.
 *
 *  @returns  An integer, the location of the item in the array. If not
 *             found, -1 is returned.
 *           
 *
 *  @par Example
 *  @verbatim
    double arrayIn[5] = {0, 1, 2, 3, 4};
    int arraySize = 5;
    double lookFor = 3;
    
    double where = linearSearch(arrayIn, arraySize, lookFor); // result 3

    arrayIn[3] = {10, 0, 12};
    arraySize = 3;
    double lookFor = 0;
    double where = linearSearch(arrayIn, arraySize, lookFor); // result 1
    @endverbatim
 ************************************************************************/
int linearSearch(double arrayIn[], int arraySize, double lookFor)
{
    int i;
    
    for (i=0; i<arraySize; i++)
    {
        if (arrayIn[i] == lookFor)
        {
            return i;
        }
    }
    
    return -1;
}
/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Searches for a specified item in the array and returns its location. 
 *   If the specified value is not in the array, -1 is returned. This 
 *   searching is done by sorting the array in ascending order with mySort 
 *   and then using the bisector method.
 *
 *  @param[in] arrayIn[] The array which will be searched.
 *
 *  @param[in] arraySize The size of the array.
 *
 *  @param[in] lookFor The item which will be searched for in the array.
 *
 *  @returns  An integer, the location of the item in the array. If not
 *             found, -1 is returned.
 *           
 *
 *  @par Example
 *  @verbatim
    double arrayIn[5] = {0, 1, 2, 3, 4};
    int arraySize = 5;
    double lookFor = 3;
    
    double where = binarySearch(arrayIn, arraySize, lookFor); // result 3

    arrayIn[3] = {10, 0, 12};
    arraySize = 3;
    double lookFor = 0;
    double where = binarySearch(arrayIn, arraySize, lookFor); // result 0
    @endverbatim
 ************************************************************************/
int binarySearch(double arrayIn[], int arraySize, double lookFor)
{
    int low = 0;
    int high = arraySize - 1;
    int midpoint;
    while (low <= high)
    {
        midpoint = (low + high) / 2;
        if (arrayIn[midpoint] == lookFor)
        {
            return midpoint;
        }
        if (arrayIn[midpoint] < lookFor)
        {
            low = midpoint + 1;
        }
        else 
        {
            high = midpoint - 1;
        }
    }
    return -1;
}