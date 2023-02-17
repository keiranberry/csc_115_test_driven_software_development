/** ********************************************************************
* @file
***********************************************************************/
#pragma once

#include <sstream>
#include <ctime>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

/** ********************************************************************
* @brief Structure to be filled in with customer information
***********************************************************************/
struct customerInfo
{
/** ********************************************************************
* @brief String to be filled in with customer's first name
***********************************************************************/
    string firstName;
/** ********************************************************************
* @brief String to be filled in with customer's last name
***********************************************************************/
    string lastName;
/** ********************************************************************
* @brief String to be filled in with customer's street address
***********************************************************************/
    string streetAddress;
/** ********************************************************************
* @brief String to be filled in with customer's city
***********************************************************************/
    string city;
/** ********************************************************************
* @brief String to be filled in with customer's state
***********************************************************************/
    string state;
/** ********************************************************************
* @brief String to be filled in with customer's zip code
***********************************************************************/
    string zipCode;
/** ********************************************************************
* @brief Double to be filled in with customer's transaction amount
***********************************************************************/
    double transactionAmount;
/** ********************************************************************
* @brief Double to be filled in with customer's current balance
***********************************************************************/
    double currentBalance;
};

bool openInput( ifstream &file, string fileName);

bool openOutput( ofstream &file, string fileName);

string getDate();

bool getClient( ifstream &input, customerInfo &client);

void writeLetter( customerInfo &client, string tempFile, string currentDate);