#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0007.h"

TEST_CASE("sortByID - testing if one switch can be made")
{
    int idIn[3] = {2, 1, 3};
    string namesIn[3] = {"Bob", "Phil", "Jim"};
    int arraySize = 3;
    
    sortByID(namesIn, idIn, 3);
    
    CHECK(idIn[0] == 1);
    CHECK(idIn[1] == 2);
}

TEST_CASE("sortByID - testing a larger array")
{
    int idIn[12] = {1, 12, 3, 4, 5, 6, 7, 8, 9, 10, 11, 2};
    string namesIn[12] = {"Bob", "Phil", "Jim", "Mary", "Billy",
    "Madison", "James", "Richard", "Rich", "Rick", "Noah", "Robert"};
    int arraySize = 12;
    
    sortByID(namesIn, idIn, 12);
    
    CHECK(idIn[1] == 2);
    CHECK(idIn[11] == 12);
}

TEST_CASE("sortByID - testing if every number needs to be moved")
{
    int idIn[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    string namesIn[10] = {"Bob", "Phil", "Jim", "Mary", "Billy",
    "Madison", "James", "Richard", "Rich", "Rick"};
    int arraySize = 10;
    
    sortByID(namesIn, idIn, 10);
    
    CHECK(idIn[1] == 2);
    CHECK(idIn[9] == 10);
    CHECK(idIn[6] == 7);
    
}

TEST_CASE("sortByID - testing differing numbers")
{
    int idIn[3] = {1, 78, 54};
    string namesIn[3] = {"Bob", "Phil", "Jim"};
    int arraySize = 3;
    
    sortByID(namesIn, idIn, 3);
    
    CHECK(idIn[0] == 1);
    CHECK(idIn[1] == 54);
}

TEST_CASE("sortByName - testing if one switch can be made")
{
    int idIn[3] = {2, 1, 3};
    string namesIn[3] = {"Bob", "Phil", "Jim"};
    int arraySize = 3;
    
    sortByName(namesIn, idIn, 3);
    
    CHECK(namesIn[0] == "Bob");
    CHECK(namesIn[1] == "Jim");
}

TEST_CASE("sortByName - testing names with only one letter difference")
{
    int idIn[3] = {24, 344, 4};
    string namesIn[3] = {"Bill", "Billy", "Bally"};
    int arraySize = 3;
    
    sortByName(namesIn, idIn, 3);
    
    CHECK(namesIn[0] == "Bally");
    CHECK(namesIn[1] == "Bill");
}

TEST_CASE("sortByName - testing more slight differences bc Im in disbelief")
{
    int idIn[3] = {20, 2, 345};
    string namesIn[3] = {"Bb", "Ab", "Aa"};
    int arraySize = 3;
    
    sortByName(namesIn, idIn, 3);
    
    CHECK(namesIn[0] == "Aa");
    CHECK(namesIn[1] == "Ab");
}

TEST_CASE("sortByName - testing more slight differences bc Im still in disbelief")
{
    int idIn[3] = {20, 23, 343};
    string namesIn[3] = {"Appleseed, Johnny", "Smith, Jeff", "Cassidy, Cole"};
    int arraySize = 3;
    
    sortByName(namesIn, idIn, 3);
    
    CHECK(namesIn[0] == "Appleseed, Johnny");
    CHECK(idIn[0] == 20);
    CHECK(namesIn[1] == "Cassidy, Cole");
    CHECK(idIn[1] == 343);
}

TEST_CASE("getID - initial test to see if an ID is returned")
{
    int idIn[2] = {69, 420};
    string namesIn[2] = {"Johnny Appleseed", "Jeff Kaplan"};
    int arraySize = 2;
    string person = "Johnny Appleseed";
    sortByName(namesIn, idIn, 2);
    int idNumOut = getID(namesIn, idIn, 2, "Johnny Appleseed");
    
    REQUIRE( idNumOut == 69);
}

TEST_CASE("getID - further testing of getID")
{
    int idIn[6] = {2981, 1238, 3453, 3465, 8765, 4768};
    string namesIn[6] = {"Ziegler, Angela", "McCree, Jesse", "Song, Hana", "Reyes, Gabriel", "Morrison, Jack", "Amari, Ana"};
    int arraySize = 6;
    string person = "Morrison, Jack";
    sortByName(namesIn, idIn, 6);
    int idNumOut = getID(namesIn, idIn, 6, "Morrison, Jack");
    
    REQUIRE( idNumOut == 8765);
}

TEST_CASE("getName - initial test to see if a name is returned")
{
    int idIn[2] = {69, 420};
    string namesIn[2] = {"Johnny Appleseed", "Jeff Kaplan"};
    int arraySize = 2;
    int idNum = 420;
    sortByID(namesIn, idIn, 2);
    string nameOut = getName(namesIn, idIn, 2, 420);
    
    REQUIRE( nameOut == "Jeff Kaplan");
}

TEST_CASE("getName - further testing of getName")
{
    int idIn[6] = {2981, 1238, 3453, 3465, 8765, 4768};
    string namesIn[6] = {"Ziegler, Angela", "McCree, Jesse", "Song, Hana", "Reyes, Gabriel", "Morrison, Jack", "Amari, Ana"};
    int arraySize = 6;
    int idNum = 1238;
    sortByID(namesIn, idIn, 6);
    string nameOut = getName(namesIn, idIn, 6, 1238);
    
    REQUIRE( nameOut == "McCree, Jesse");
}

TEST_CASE("getName - testing the last item in the list")
{
    int idIn[6] = {2981, 1238, 3453, 3465, 8765, 4768};
    string namesIn[6] = {"Ziegler, Angela", "McCree, Jesse", "Song, Hana", "Reyes, Gabriel", "Morrison, Jack", "Amari, Ana"};
    int arraySize = 6;
    int idNum = 4768;
    sortByID(namesIn, idIn, 6);
    string nameOut = getName(namesIn, idIn, 6, 4768);
    
    REQUIRE( nameOut == "Amari, Ana");
}

TEST_CASE("getName - testing the last item in the list with an array of 5")
{
    int idIn[5] = {2981, 1238, 3453, 3465, 8765};
    string namesIn[5] = {"Ziegler, Angela", "McCree, Jesse", "Song, Hana", "Reyes, Gabriel", "Morrison, Jack"};
    int arraySize = 5;
    int idNum = 8765;
    sortByID(namesIn, idIn, 5);
    string nameOut = getName(namesIn, idIn, 5, 8765);
    
    REQUIRE( nameOut == "Morrison, Jack");
}

TEST_CASE("getName - more testing because I cant figure out whats wrong")
{
    int idIn[7] = {234, 345, 456, 567, 678, 789, 890};
    string namesIn[7] = {"Carver, Michelle", "Lord, Amelia", "Schofield, Rohan", "Berg, Tania", "Hall, Jayson", "Dominguez, Elle", "Christian, Arnav"};
    int arraySize = 7;
    int idNum = 678;
    sortByID(namesIn, idIn, 7);
    string nameOut = getName(namesIn, idIn, 7, 678);
    
    REQUIRE( nameOut == "Hall, Jayson");
}

