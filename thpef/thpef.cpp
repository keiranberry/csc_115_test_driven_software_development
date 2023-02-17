/** ********************************************************************
* @file
***********************************************************************/
#include "thpef.h"
 
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
bool openInput( ifstream &file, string fileName)
{
    file.open( fileName );
    
    if (file.is_open() == true)//check that file is open
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
bool openOutput( ofstream &file, string fileName)
{
    file.open( fileName );
    
    if (file.is_open() == true)//check that file is open
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
 *  Returns the current date in a string, formatted like "25 Dec, 2021".
 *   If the day is less than 10, it is output with a 0 leading (09).
 *
 *  @returns  A string, the current date.
 *           
 *
 *  @par Example
 *  @verbatim
    //returns whatever the current date is 
    
    @endverbatim
 ************************************************************************/
string getDate ()
{
    string day;
    string month;
    string year;
    string date;
    
    time_t currentTimeT = time(NULL);
    string currentTime = ctime( &currentTimeT );
    
    day = currentTime.substr(8, 2);
    month = currentTime.substr(4, 3);
    year = currentTime.substr(20,4);
    if( day[0] == ' ')
    {
        day[0] = '0';//if the first digit of day is blank, make it a 0
    }
    
    date = day + " " + month + ", " + year;
    
    return date;
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Fills in the customerInfo structure with information provided from the
 *   input file.
 *
 *  @param[in] input The ifstream file input.
 *
 *  @param[in] client The structure which will be filled in.
 *
 *  @returns  A boolean value, true if the fields were filled successfully
 *             and false if no data was read.           
 *
 *  @par Example
 *  @verbatim
    ifstream file;
    customerInfo customer;
    file.open("z:thisfiledoesntexist.txt");
    bool client = getClient(file, customer);//result would be false
    
    ifstream file;
    customerInfo customer;
    file.open("datafile1.txt");
    client = getClient(file, customer);//result would be true
    
    @endverbatim
 ************************************************************************/
bool getClient( ifstream &input, customerInfo &client)
{
    int i,j;
    int fieldLength = 0;//used to determine how many characters to take
    int commasFound = 0;//how many commas= how many fields found 
    int lastComma = -1;
    double transaction = 0;
    string transactionString;
    double balance = 0;
    string balanceString;
    int size = 0;
    string line;
    int endLine = 0;
    
    
    if( getline(input, line))
    {
        size = line.size();
            
        for( i=0; i<size; i++)
        {
            if (line.at(i) != ',')//if not a comma, add one to the field length
            {
                fieldLength++;
                commasFound = commasFound;
            }
            else if (line.at(i) == ',' && commasFound == 0)//first name
            {
                client.firstName = line.substr(0, fieldLength);
                commasFound ++;
                fieldLength = 0;//reset field length
                lastComma = i;//start next field at the delimiter
            }
            else if (line.at(i) == ',' && commasFound == 1)//last name
            {
                client.lastName = line.substr(lastComma+1, fieldLength);
                commasFound ++;
                fieldLength = 0;
                lastComma = i;
            }
            else if (line.at(i) == ',' && commasFound == 2)//address
            {
                client.streetAddress = line.substr(lastComma+1, fieldLength);
                commasFound ++;
                fieldLength = 0;
                lastComma = i;
            }
            else if (line.at(i) == ',' && commasFound == 3)//city
            {
                client.city = line.substr(lastComma+1, fieldLength);
                commasFound ++;
                fieldLength = 0;
                lastComma = i;
            }
            else if (line.at(i) == ',' && commasFound == 4)//state
            {
                client.state = line.substr(lastComma+1, fieldLength);
                commasFound ++;
                fieldLength = 0;
                lastComma = i;
            }
            else if (line.at(i) == ',' && commasFound == 5)//zip
            {
                client.zipCode = line.substr(lastComma+1, fieldLength);
                commasFound++;
                fieldLength = 0;
                lastComma = i;
            }
            else if (line.at(i) == ',' && commasFound == 6)//transaction
            {
                transactionString = line.substr(lastComma+1, fieldLength);
                transaction = stod(transactionString);
                client.transactionAmount = transaction;
                commasFound ++;
                fieldLength = 0;
                lastComma = i;
            }
            if (commasFound == 7)//balance, if instead of else-if so it isn't skipped
            {
                balanceString = line.substr(lastComma+1, size-i);
                balance = stod(balanceString);
                client.currentBalance = balance;
                commasFound ++;   
            }
           
        }
        return true;
        
    }
    return false;
}

/** **********************************************************************
 *  @author Keiran M. Berry
 *
 *  @par Description
 *  Writes a letter to the customer depending on if they made a purchase,
 *   payment, or are overdue for a payment. Once this is determined, the
 *   corresponding template file is opened and the generic fields are 
 *   replaced with the pieces of the structure.
 *
 *  @param[in] client The structure which contains the client's information
 *
 *  @param[in] tempFile A string, the name of the template file to be used.
 *
 *  @param[in] currentDate The current date, as a string.
 *           
 *
 *  @par Example
 *  @verbatim
    ifstream input;
    input.open("input.txt");
    customerInfo customers;
    string templateFile = "purchaseTemplate.txt";
    string dateOut = getDate();
    getClient(input, customers);
    
    writeLetter( customers, templateFile, dateOut);
    //result would be a letter written with purchaseTemplate and using 
      the current date
    

    @endverbatim
 ************************************************************************/
void writeLetter( customerInfo &client, string tempFile, string currentDate)
{
    ifstream fileIn;
    ofstream fileOut;
    string outputName;
    string first;
    string last;
    string line;
    string fullName;
    string::size_type findName;
    string::size_type findAddress;
    string::size_type findCity;
    string::size_type findState;
    string::size_type findZip;
    string::size_type findFirst;
    string::size_type findLast;
    string::size_type findDate;
    string::size_type findTransaction;
    string::size_type findBalance;    
    string transactionStr;
    string balanceStr;
    
    
    fullName = client.firstName + " " + client.lastName;//will be used to fill in fullname field
    
    if (openInput(fileIn, tempFile) == false)
    {
        cout << "Unable to open the template file: " << tempFile << endl;
    }
    
    first = client.firstName;
    last = client.lastName;
    outputName = first + "." + last + ".txt";//naming the output file
    
    if (openOutput(fileOut, outputName) == false)
    {
        cout << "Unable to open the output file: " << outputName << endl;
    }
    
    while(getline(fileIn, line))//while lines are coming in from template
    {
        
        findName = line.find("#FULLNAME");
        if( findName != string::npos)
        {
            line.replace(findName, 9, fullName);
        }
        
        findAddress = line.find("#ADDRESS");
        if( findAddress != string::npos)
        {
            line.replace( findAddress, 8, client.streetAddress);
        }
        
        findCity = line.find("#CITY");
        if( findCity != string::npos)
        {
            line.replace( findCity, 5, client.city);
        }
        
        findState = line.find("#STATE");
        if( findState != string::npos)
        {
            line.replace( findState, 6, client.state);
        }
        
        findZip = line.find("#ZIP");
        if( findZip != string::npos)
        {
            line.replace( findZip, 4, client.zipCode);
        }
        
        findFirst = line.find("#FIRST");
        if( findFirst != string::npos)
        {
            line.replace( findFirst, 6, client.firstName);
        }
        
        findLast = line.find("#LAST");
        if(findLast != string::npos)
        {
            line.replace( findLast, 5, client.lastName);
        }
        
        findDate = line.find("#DATE");
        if(findDate != string::npos)
        {
            line.replace( findDate, 5, currentDate);
        }
        
        findTransaction = line.find("#TRANSACTION");
        if(findTransaction != string::npos)
        {
            ostringstream myTransaction;//convert double transaction to string
            myTransaction << fixed << setprecision(2);
            myTransaction << client.transactionAmount;
            transactionStr = myTransaction.str();
            
            line.replace( findTransaction, 12, transactionStr);
        }
        
        findBalance = line.find("#BALANCE");
        if(findBalance != string::npos)
        {
            ostringstream myBalance;//convert double balance to string
            myBalance << fixed << setprecision(2);
            myBalance << client.currentBalance;
            balanceStr = myBalance.str();
            
            line.replace( findBalance, 8, balanceStr);
        }
        fileOut << line << endl;
    }
    fileIn.close();
    fileOut.close();//close both files which were opened
}