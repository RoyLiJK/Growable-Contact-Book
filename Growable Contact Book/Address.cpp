// Address.cpp

/**
* Defenition of class Address. It is used to store and retrieve
* information on Address such as home number, street, apt#, city,
* state, and zip.
*
* Author: Yosef Alayev
*/


#include "Address.h"
#include <string>
#include <iostream>

using namespace std;

Address::Address() : home(""),
street(""),
apt("none"),
city(""),
state(""),
zip("")
{
   // empty
}

string Address::getHome() const
{
   return home;
}

string Address::getStreet() const
{
   return street;
}

string Address::getApt() const
{
   return apt;
}

string Address::getCity() const
{
   return city;
}

string Address::getState() const
{
   return state;
}

string Address::getZip() const
{
   return zip;
}

void Address::output() const
{
   cout << home << " " << street;
   if (apt != "none")
      cout << ", Apt# " << apt;
   cout << endl;
   cout << city << ", " << state << " " << zip << endl;
}

void Address::input()
{
   char choice;
   cout << "Apartment or House (a/h):> ";
   cin >> choice;
   cout << endl;

   cin.ignore(10, '\n');
   cout << "Enter home number: ";
   getline(cin, home);
   cout << "Enter street number: ";
   getline(cin, street);

   if (choice == 'a')
   {
      cout << "Enter Apartment Number: ";
      getline(cin, apt);
   }
   else
      apt = "none";

   cout << "Enter city: ";
   getline(cin, city);

   cout << "Enter state: ";
   getline(cin, state);

   cout << "Enter zip code: ";
   getline(cin, zip);
}

istream& operator >> (istream& in, Address& add){
   char choice;
   cout << "Apartment or House (a/h):> ";
   in >> choice;
   cout << endl;

   in.ignore(10, '\n');
   cout << "Enter home number: ";
   getline(in, add.home);
   cout << "Enter street number: ";
   getline(in, add.street);

   if (choice == 'a')
   {
      cout << "Enter Apartment Number: ";
      getline(in, add.apt);
   }
   else
      add.apt = "none";

   cout << "Enter city: ";
   getline(in, add.city);

   cout << "Enter state: ";
   getline(in, add.state);

   cout << "Enter zip code: ";
   getline(in, add.zip);

   return in;
}

ostream& operator << (ostream& out, const Address& add){
   out << add.home << " " << add.street;
   if (add.apt != "none")
      out << ", Apt# " << add.apt;
   out << endl;
   out << add.city << ", " << add.state << " " << add.zip << endl;

   return out;
}