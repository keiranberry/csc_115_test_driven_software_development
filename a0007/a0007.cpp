#include "a0007.h"

void sortByID( string namesIn[], int idIn[], int arraySize)
{
    int i, j; 
    
    for (i=0; i< arraySize-1; i++)
    {   
        for (j=0; j< arraySize-1 -i ; j++)
        {
            if (idIn[j] > idIn[j+1])
            {
            int temp = idIn[j];
            idIn[j] = idIn[j+1];
            idIn[j+1] = temp;
            
            string temp1 = namesIn[j];
            namesIn[j] = namesIn[j+1];
            namesIn[j+1] = temp1;
            }
        }
    }
}
void sortByName( string namesIn[], int idIn[], int arraySize)
{
    int i;
    int j;
    string temp;
    int temp1;
    
    for (i=0; i< arraySize-1; i++)
    {
        for (j=0; j< arraySize-1; j++)
        {
            if (namesIn[j] > namesIn[j+1])
            {
            temp = namesIn[j];
            namesIn[j] = namesIn[j+1];
            namesIn[j+1] = temp;
            
            temp1 = idIn[j];
            idIn[j] = idIn[j+1];
            idIn[j+1] = temp1;
            
            }
        }
    }
}

int getID( string namesIn[], int idIn[], int arraySize, string person)
{
    int i;
    int output = -1;
    bool nameFound = false;
    
    for (i=0; i<arraySize && nameFound == false; i++)
    {
        if (namesIn[i] == person)
        {
            output = idIn[i];
            nameFound = true;
        }
    }
    return output;
}

string getName( string namesIn[], int idIn[], int arraySize, int idNum)
{
    int i;
    string output = "";
    bool idFound = false;
    
    for (i=0; i<arraySize && idFound == false; i++)
    {
        if (idIn[i] == idNum)
        {
            output = namesIn[i];
            idFound = true;
        }
    }
    return output;
}