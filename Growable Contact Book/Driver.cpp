#include <iostream>
#include <string>
#include "Address.h"
#include "Contact.h"
#include "ContactBook.h"

using namespace std;


int main() {
   int menu = 1; 
   ContactBook list; 

   while (menu > 0 && menu < 7){
      cout << endl << "Please make a selection from the menu below .\n\n";

      //menu
      cout << "1. Add a new contact" << endl
         << "2. Delete an old contact" << endl
         << "3. Display a contact's info" << endl
         << "4. Update a contact's info" << endl
         << "5. Display the entire contact list" << endl
         << "6. Exit" << endl << endl;

      cin >> menu;
      cout << endl;

      if (menu == 6) break; 

      else if (menu == 1)
	  {
		  Contact* x = new Contact(); 
		  cin >> *x;
		  list.add(x);
		  continue;		  		
      }

      else if (menu == 2)
	  { 
         int index;
         char answer;

      deleteIndex: 
         cout << "Do you know the index of the contact you'd like to delete? (Y/N): ";
         cin.ignore();
         cin >> answer;

         if (answer == 'Y' || answer == 'y')
		 {
            cout << "Please enter the index you'd like to delete: ";
            cin >> index;
            list.remove(index);
            continue;
         }

         else if (answer == 'N' || answer == 'n')
		 {
            string name;
            cout << "Please enter the name of the contact you'd like to delete: ";
            cin.ignore();
            getline(cin, name);
            list.remove(list.search(name));
            continue;
         }

         else 
		 {
            cerr << "Error: Invalid answer. Please try again." << endl << endl;
            goto deleteIndex;
         }
      }

      else if (menu == 3)
	  {
        /* string display;
         cout << "Please enter the name of the contact you'd like to have displayed: ";
         cin.ignore();
         getline(cin, display);

         cout << list.contactAtIndex(list.search(display)); 
         continue;*/

	 display: //return here if an exception is thrown for invalid search name parameter
		 string display;
		 cout << "Please enter the name of the contact you'd like to displayed: ";
		 cin.ignore();
		 getline(cin, display);

		 cout << list.search(display); //outputs the contact specified if it exists, throws an exception otherwise
		 
		 
      }

      else if (menu == 4)
	  { 
         string mod;
         cout << "Please enter the full name of the contact you'd like to modify: ";
         cin.ignore();
         getline(cin, mod);

         int index = list.search(mod);

         cout << "Please enter the new data for the contact " << list.contactAtIndex(list.search(mod)).getFirstName()
            << ' ' << list.contactAtIndex(list.search(mod)).getLastName() << '.' << endl << endl;

         Contact *input = new Contact();
         cin >> *input;
         list.update(index, input);

         cout << "Contact updated successfully!" << endl << endl;
         continue;
      }

      else if (menu == 5)
	  { 
         cout << list;
         cout << endl << endl;
         continue;
      }
   }

   cout << "Program Terminated!!" << endl;

  
   return 0;
}