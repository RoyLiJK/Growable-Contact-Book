                                                                                                                                                             #include <iostream>
#include <string>
#include "Address.h"
#include "Contact.h"                                                                                                                                                                           
using namespace std;

const regex Contact::checkPhone("[0-9]{10}");
                                                                                                                     
const regex Contact::checkEmail("[0-9a-zA-Z._-]+@[0-9a-zA-Z._-]+.(com|gov|net|edu|nyc|info|biz|cn|co.uk|eu|jp|au|int|mil|arpa|fr|hk|in|kr|kp|my|ru|us|vn)");
                                                                                                                                                                                
string Contact::getFirstName() const{ return firstname; }
string Contact::getLastName() const{ return lastname; }

//creates an output of the address as a single string   
string Contact::getAddress() const{                                                                                                         
   string output = address.getHome() + " " + address.getStreet() + ", ";
   if (address.getApt().compare("none") != 0) output = output + address.getApt() + ", ";
   output = output + address.getCity() + ", " + address.getState() + " " + address.getZip();
   return output;
}

string Contact::getPhone() const{ return phone; }
string Contact::getEmail() const{ return email; }
Address Contact::returnAddress() const{ return address; }
                                                                                                                                                                                  
void Contact::setFirstName(string x){ firstname = x; }
void Contact::setLastName(string x){ lastname = x; }
void Contact::setAddress(){ cin >> address; }


void Contact::setPhone(string x){
   while (true){ 
      if (regex_match(x, checkPhone)){ 
         phone = x;
         break; 
      }
      else { 
         cout << "Error: Invalid phone number format entered for " << firstname << " " << lastname << ". Phone number must be 10 digits only - no dashes or parentheses. Please try again.:" << endl;
         cin >> x;
      }
      cout << endl << endl;
   }
}


void Contact::setEmail(string x){
   while (true){ 
      if (regex_match(x, checkEmail)) { 
         email = x;
         break; 
      }
      else {
         cout << "Error: Invalid E-mail address format entered for " << firstname << " " << lastname << ". Please try again.:" << endl;
         cin >> x;
      }
      cout << endl << endl;
   }
}

void Contact::input(){
   string fn, ln,  ph, em;
   cout << "Please enter the first name of the new contact.: ";
   cin >> fn;
   setFirstName(fn);

   cout << "Please enter the last name of the new contact.: ";
   cin >> ln;
   setLastName(ln);

   cout << "Please heed the following prompts to properly enter the address for this new contact." << endl;
   cin >> address;

   cout << "Please enter the phone number of the new contact.: ";
   cin >> ph;
   setPhone(ph);

   cout << "Please enter the email address of the new contact.: ";
   cin >> em;
   setEmail(em);

   cout << endl << "Contact created successfully." << endl << endl;
}

void Contact::output() const{
   cout << "First Name: " << firstname << endl
      << "Last Name: " << lastname << endl
      << "Address: " << endl;
   address.output();
   cout << "Phone Number: " << phone << endl
      << "Email Address: " << email << endl << endl;
}

//member operator overloads:
const bool Contact::operator < (const Contact& contact){
   if (getLastName().compare(contact.getLastName()) < 0) return true;
   else if (getLastName().compare(contact.getLastName()) == 0) if (getFirstName().compare(contact.getFirstName()) < 0) return true;
   return false;
}

const bool Contact::operator > (const Contact& contact){
   if (getLastName().compare(contact.getLastName()) > 0) return true;
   else if (getLastName().compare(contact.getLastName()) == 0) if (getFirstName().compare(contact.getFirstName()) > 0) return true;
   return false;
}

const bool Contact::operator == (const Contact& contact){
   if (getLastName().compare(contact.getLastName()) == 0 && getFirstName().compare(contact.getFirstName()) == 0) return true;
   return false;
}

const bool Contact::operator != (const Contact& contact){
   if (getLastName().compare(contact.getLastName()) == 0 && getFirstName().compare(contact.getFirstName()) == 0) return false;
   return true;
}

const bool Contact::operator <= (const Contact& contact){
   if (getLastName().compare(contact.getLastName()) > 0) return false;
   else if (getLastName().compare(contact.getLastName()) == 0) if (getFirstName().compare(contact.getFirstName()) > 0) return false;
   return true;
}

const bool Contact::operator >= (const Contact& contact){
   if (getLastName().compare(contact.getLastName()) < 0) return false;
   else if (getLastName().compare(contact.getLastName()) == 0) if (getFirstName().compare(contact.getFirstName()) < 0) return false;
   return true;
}


//non-member operator overloads:
istream& operator >> (istream& in, Contact& contact){
   string fn, ln, ph, em;
   cout << "Please enter the first name of the new contact.: ";
   in >> contact.firstname;
   
   cout << "Please enter the last name of the new contact.: ";
   in >> ln; contact.setLastName(ln);
  
   cout << "Please heed the following prompts to correctly enter the contact's address.:" << endl;
   contact.setAddress();
   cout << endl;
   
   cout << "Please enter the phone number of the new contact.: ";
   in >> ph; contact.setPhone(ph);

   cout << "Please enter the email of the new contact.: ";
   in >> em; contact.setEmail(em);

   cout << "Contact updated successfully." << endl;

   return in;
}

ostream& operator << (ostream& out, const Contact& contact){
   out << "First Name: " << contact.getFirstName() << endl
      << "Last Name: " << contact.getLastName() << endl
      << "Address:" << endl;
   out << contact.returnAddress();
   out << "Phone number: " << contact.getPhone() << endl
      << "Email Address: " << contact.getEmail() << endl;

   return out;
}