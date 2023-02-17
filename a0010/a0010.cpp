#include "a0010.h"

void sortArray(int arrayIn[],int arraySize)
{
    int i,j;
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

double sumArray( int arrayIn[], int arraySize)
{
    double arraySum = 0;
    int i = 0;
    for (i=0; i<arraySize; i++)
    {
        arraySum = arraySum + arrayIn[i];
    }
    return arraySum;
}