#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "thpef.h"
#include "ourDate.h"

const bool RUNCATCH = true;

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
    ifstream purchase;
    ifstream payment;
    ifstream overdue;
    ofstream output;
    customerInfo customers[100];
    string fileLetter;
    int i=0;
    string currentDate;
    
    
    if( argc != 5)
    {
        cout << "Usage: thpef.exe datafile template1 template2 template3" << endl;
        cout << "       datafile --name of input data file" << endl;
        cout << "       template1 --name of purchase template file" << endl;
        cout << "       template2 --name of payment template file" << endl;
        cout << "       template3 --name of overdue template file" << endl;
        
        return 0;
    }
    
    if( openInput(input, argv[1]) == false)//check that files open
    {
        cout << "Unable to open the input file: " << argv[1] << endl;
    }
    if( openInput(purchase, argv[2]) == false)
    {
        cout << "Unable to open the template file: " << argv[2] << endl;
    }
    if( openInput(payment, argv[3]) == false)
    {
        cout << "Unable to open the template file: " << argv[3] << endl;
    }
    if( openInput(overdue, argv[4]) == false)
    {
        cout << "Unable to open the template file: " << argv[4] << endl;
    }
    
    for( i=0; getClient(input, customers[i]); i++)
    {
        if(currDate != "25 Dec, 2021")
        {
            currentDate  = getDate();
        }
        else
        {
            currentDate = currDate;
        }
        customers[i].currentBalance = customers[i].currentBalance+
        customers[i].transactionAmount;
        if(customers[i].transactionAmount < 0)
        {
            customers[i].transactionAmount = 
            fabs(customers[i].transactionAmount);
            writeLetter(customers[i], argv[3], currDate);
        }
        else if(customers[i].transactionAmount > 0)
        {
            writeLetter(customers[i], argv[2], currDate);
        }
        else if(customers[i].transactionAmount == 0
        && customers[i].currentBalance != 0)
        {
            writeLetter(customers[i], argv[4], currDate);
        }
    }
    
    return 0;
}

TEST_CASE( "getDate - initial test of getDate")
{
    string dateOut = getDate();
    
    REQUIRE( dateOut == "08 Dec, 2021");
}

TEST_CASE("openInput - testing something which should pass")
{
    ifstream inputF;
    string name = "paymentTemplate.txt";
    
    bool open = openInput(inputF, name);
    
    REQUIRE(open == true);
}

TEST_CASE("openInput - testing something which should fail")
{
    ifstream inputF;
    string name = "z:aslkfjsa.txt";
    
    bool open = openInput(inputF, name);
    
    REQUIRE(open == false);
}

TEST_CASE("openOutput - testing something which should pass")
{
    ofstream outputF;
    string name = "Elon.Musk.txt";
    
    bool open = openOutput(outputF, name);
    
    REQUIRE(open == true);
}

TEST_CASE("openOutput - testing something which should fail")
{
    ofstream outputF;
    string name = "z:ffwefhwifuhfif.txt";
    
    bool open = openOutput(outputF, name);
    
    REQUIRE(open == false);
}


/*TEST_CASE("getClient - initial test of getClient")
{
    ifstream file;
    bool client[6];
    customerInfo customers[6];
    file.open("dataFile1.txt");
    for( int i = 0; i<6; i++ )
    {
        client[i] = getClient(file, customers[i]);
        cout << setw(10) << left << i << customers[i].firstName << endl;
        cout << setw(10) << left << i << customers[i].lastName << endl;
        cout << setw(10) << left << i << customers[i].streetAddress << endl;
        cout << setw(10) << left << i << customers[i].city << endl;
        cout << setw(10) << left << i << customers[i].state << endl;
        cout << setw(10) << left << i << customers[i].zipCode << endl;
        cout << setw(10) << left << i << customers[i].transactionAmount << endl;
        cout << setw(10) << left << i << customers[i].currentBalance << endl << endl;
        CHECK(client[i] == true);
    }
    file.close();
}*/

TEST_CASE("getClient - trying to get it to fail")
{
    ifstream file;
    customerInfo customer;
    file.open("z:sjfsdfkskfj.txt");
    bool client = getClient(file, customer);
    CHECK( client == false);
}

TEST_CASE("writeLetter - testing writeLetter for James Smith")
{
    ifstream input;
    input.open("input.txt");
    customerInfo customers;
    string templateFile = "purchaseTemplate.txt";
    bool clientOut = getClient(input, customers);
    string dateOut = getDate();
    getClient(input, customers);
    
    writeLetter( customers, templateFile, dateOut);
    
    CHECK(clientOut == true);
}

    