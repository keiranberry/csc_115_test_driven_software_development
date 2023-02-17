#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0008.h"

TEST_CASE("splitNameLF - testing to see that variables get returned")
{
    string fullName = "Berry, Keiran";
    string firstName;
    string lastName;
    
    splitNameLF(fullName, firstName, lastName);
    CHECK( firstName == "Keiran");
    CHECK( lastName == "Berry");
}


TEST_CASE("splitNameLF - further testing of splitNameLF")
{
    string fullName = "Book, Robert";
    string firstName;
    string lastName;
    
    splitNameLF(fullName, firstName, lastName);
    CHECK( firstName == "Robert");
    CHECK( lastName == "Book");
}

TEST_CASE("splitNameLF - testing a name with a hyphen")
{
    string fullName = "Cassidy-Cole, Jesse";
    string firstName;
    string lastName;
    
    splitNameLF(fullName, firstName, lastName);
    CHECK( firstName == "Jesse");
    CHECK( lastName == "Cassidy-Cole");
}

TEST_CASE("splitNameFL - testing to see that variables get returned")
{
    string fullName = "Keiran Berry";
    string firstName;
    string lastName;
    
    splitNameFL(fullName, firstName, lastName);
    CHECK( firstName == "Keiran");
    CHECK( lastName == "Berry");
}

TEST_CASE("splitNameFL - further testing of splitNameFL")
{
    string fullName = "Robert Book";
    string firstName;
    string lastName;
    
    splitNameFL(fullName, firstName, lastName);
    CHECK( firstName == "Robert");
    CHECK( lastName == "Book");
}

TEST_CASE("splitNameFL - testing a name with a hyphen")
{
    string fullName = "Keiran-Michael Berry";
    string firstName;
    string lastName;
    
    splitNameFL(fullName, firstName, lastName);
    CHECK( firstName == "Keiran-Michael");
    CHECK( lastName == "Berry");
}

TEST_CASE("createEmail - testing to see that a value is returned")
{
    string firstName = "Keiran";
    string lastName = "Berry";
    string domain = "mines.sdsmt.edu";
    
    string email = createEmail(firstName, lastName, domain);
    REQUIRE(email == "Keiran.Berry@mines.sdsmt.edu");
}

TEST_CASE("createEmail - further testing of createEmail")
{
    string firstName = "Robert";
    string lastName = "Book";
    string domain = "mines.sdsmt.edu";
    
    string email = createEmail(firstName, lastName, domain);
    REQUIRE(email == "Robert.Book@mines.sdsmt.edu");
}

TEST_CASE("createEmail - more testing of createEmail")
{
    string firstName = "Mike";
    string lastName = "Berry";
    string domain = "gmail.com";
    
    string email = createEmail(firstName, lastName, domain);
    REQUIRE(email == "Mike.Berry@gmail.com");
}

TEST_CASE("fixList - initial test of fixList")
{
    string mixedList[3] = {"Berry, Keiran", "Ziegler, Angela", "Carson Smith"};
    string firstLast[3];
    string lastFirst[3];
    string email[3];
    string domainName = "gmail.com";
    
    fixList(mixedList, firstLast, lastFirst, email, 3, domainName);
    
    CHECK( mixedList[0] == "Berry, Keiran");
    CHECK( firstLast[0] == "Keiran Berry");
    CHECK( lastFirst[0] == "Berry, Keiran");
    CHECK( email[0] == "Keiran.Berry@gmail.com");
    
    CHECK( mixedList[1] == "Ziegler, Angela");
    CHECK( firstLast[1] == "Angela Ziegler");
    CHECK( lastFirst[1] == "Ziegler, Angela");
    CHECK( email[1] == "Angela.Ziegler@gmail.com");
    
    CHECK( mixedList[2] == "Carson Smith");
    CHECK( firstLast[2] == "Carson Smith");
    CHECK( lastFirst[2] == "Smith, Carson");
    CHECK( email[2] == "Carson.Smith@gmail.com");
}

TEST_CASE("fixList - further testing of fixList")
{
    string mixedList[3] = {"Dreemurr, Asgore", "Sans Skeleton", "Skeleton, Papyrus"};
    string firstLast[3];
    string lastFirst[3];
    string email[3];
    string domainName = "mines.sdsmt.edu";
    
    fixList(mixedList, firstLast, lastFirst, email, 3, domainName);
    
    CHECK( mixedList[0] == "Dreemurr, Asgore");
    CHECK( firstLast[0] == "Asgore Dreemurr");
    CHECK( lastFirst[0] == "Dreemurr, Asgore");
    CHECK( email[0] == "Asgore.Dreemurr@mines.sdsmt.edu");
    
    CHECK( mixedList[1] == "Sans Skeleton");
    CHECK( firstLast[1] == "Sans Skeleton");
    CHECK( lastFirst[1] == "Skeleton, Sans");
    CHECK( email[1] == "Sans.Skeleton@mines.sdsmt.edu");
    
    CHECK( mixedList[2] == "Skeleton, Papyrus");
    CHECK( firstLast[2] == "Papyrus Skeleton");
    CHECK( lastFirst[2] == "Skeleton, Papyrus");
    CHECK( email[2] == "Papyrus.Skeleton@mines.sdsmt.edu");
}
