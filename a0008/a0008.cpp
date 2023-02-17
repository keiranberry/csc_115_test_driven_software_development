#include "a0008.h"

void splitNameLF( string &fullName, string &firstName, string &lastName)
{
    int size = fullName.size();
    int i = 0;
    int commaLocation = 0;
    for( i=0; i<size; i++)
    {
        if (fullName[i] == ',')
        {
            commaLocation = i;
        }
    }
    
    lastName = fullName.substr(0, commaLocation);
    firstName = fullName.substr(commaLocation+2, size-(commaLocation+2));
    
}

void splitNameFL( string &fullName, string &firstName, string &lastName)
{
    int size = fullName.size();
    int i = 0;
    int spaceLocation = 0;
    for ( i=0; i<size; i++)
    {
        if (fullName[i] == ' ')
        {
            spaceLocation = i;
        }
    }
    
    firstName = fullName.substr(0, spaceLocation);
    lastName = fullName.substr(spaceLocation+1, size-(spaceLocation+1));
    
}

string createEmail( string firstName, string lastName, string domain)
{
    string emailOut = "initialize.email@initialize.com";
    
    emailOut = firstName + "." + lastName + "@" + domain;
    
    return emailOut;
}

void fixList( string mixedList[], string firstLast[], string lastFirst[], string email[], int arraySize, string domainName)
{
    int i = 0;
    
    for (i=0; i<arraySize; i++)
    {
        string firstName;
        string lastName;
        
        if (mixedList[i].find(",") != string::npos)
        {
            splitNameLF(mixedList[i], firstName, lastName);
        }
        else
        {
            splitNameFL(mixedList[i], firstName, lastName);
        }
        firstLast[i] = firstName + " " + lastName;
        lastFirst[i] = lastName + ", " + firstName;
        email[i] = createEmail(firstName, lastName, domainName);
    }
}
