#include "ContactBook.h"
using namespace std;

//default constructor
ContactBook::ContactBook() : storageSize(10), book(new Contact*[10]), nextIndex(0) { 
	for (int i = 0; i < 2; i++) 
	{
		book[i] = NULL;
	}
	cout << "Please enter the first name of this contact book's owner.: ";
	cin >> fn;
	cout << "Please enter the last name of this contact book's owner.: ";
	cin >> ln;
	cout << "This contact book belongs to " << fn << " " << ln << ".\n\n";
}

//destructor for the new dynamic class
ContactBook::~ContactBook() 
{ 
	for (int i = 0; i < nextIndex; i++) 
	{
		if (book[i] != NULL)
		{
			delete book[i]; //this deletes all the actual object, not the pointers
		}
	}
	if (book != NULL)
	{
		delete[] book; //this deletes the array of pointers itself
	}
}

//overload of the copy constructor 
ContactBook::ContactBook(const ContactBook& other) 
{ 
	nextIndex = other.nextIndex;
	storageSize = other.storageSize;

	book = new Contact*[storageSize];
	for (int i = 0; i < nextIndex; i++) 
	{
		book[i] = new Contact(*(other.book[i])); 
	}
}

//assignment operator overload
ContactBook& ContactBook::operator = (const ContactBook& other) 
{ 

	if (this != &other) 
	{
		/*checks if this and the parameter object are the same or not first  
		return the original object if this and parameter are the same)*/

		if (book != NULL) 
		{
			for (int i = 0; i < nextIndex; i++) 
			{
				delete book[i];
			}
			delete[] book;
		}

		nextIndex = other.nextIndex;
		storageSize = other.storageSize;
		book = new Contact*[storageSize];

		for (int i = 0; i < nextIndex; i++) {
			book[i] = new Contact(*(other.book[i]));
		}

	}
	return *this;
}

// Double the size of the original array
void ContactBook::grow() 
{ 
	storageSize += 10;
	Contact** newArray = new Contact*[storageSize];
	for (int i = 0; i < storageSize; i++) 
	{
		newArray[i] = NULL; 
	}
	for (int i = 0; i < storageSize; i++) 
	{
		newArray[i] = book[i];
	}

	delete[] book;
	book = newArray;
}

const int ContactBook::getSize() const 
{
	return nextIndex;
}

const int ContactBook::getCapacity() const 
{
	return storageSize;
}

void ContactBook::add(Contact* input) 
{
	if (nextIndex == storageSize) 
	{
		grow();
	}
	book[nextIndex] = input;
	++nextIndex;
}

void ContactBook::remove(int index) 
{
	if (index > -1 && index < nextIndex) 
	{
		delete book[index];
		for (int i = index; i < nextIndex; i++) 
		{
			book[i] = book[i + 1];
		}
		nextIndex--;
	}

	else cerr << "No contact at that index number." << endl << endl;
}

void ContactBook::remove(int index, bool& check) 
{
	if (index > -1 && index < nextIndex) 
	{
		delete book[index];
		for (int i = index; i < nextIndex; i++) 
		{
			book[i] = book[i + 1];
		}
		nextIndex--;
		check = true;
	}

	else 
	{
		cerr << "No contact at that index number." << endl << endl;
		check = false;
	}
}

void ContactBook::update(int index, Contact* input) 
{
	if (index > -1 && index < nextIndex) 
	{
		delete book[index];
		book[index] = input;
		cout << "Contact successfully updated!" << endl << endl;
	}
	else cerr << "Error: Index is out of bounds." << endl << endl;
}

void ContactBook::update(int index, Contact* input, bool& check) 
{
	if (index > -1 && index < nextIndex) 
	{
		delete book[index];
		book[index] = input;
		cout << "Contact successfully updated!" << endl << endl;
		check = true;
	}
	else
	{
		cerr << "Error: Index is out of bounds." << endl << endl;
		check = false;
	}
}

const int ContactBook::search(string name) const 
{
	for (int i = 0; i < nextIndex; i++) 
	{
		string fullName = (*book[i]).getFirstName() + ' ' + book[i]->getLastName();
		
		if (name.compare(book[i]->getFirstName()) == 0) return i;
		else if (name.compare(book[i]->getLastName()) == 0) return i;
		else if (name.compare(fullName) == 0) return i;
	}

	return -1;
	cout << " Error ";
}

const Contact ContactBook::contactAtIndex(int index) const 
{
	if (index > -1 && index < nextIndex) return *book[index];
	else throw ('c');
}

const void ContactBook::displayAll() const 
{
	for (int i = 0; i < nextIndex; i++) 
	{
		book[i]->output();
	}
}

//replaces displayAll function
ostream& operator << (ostream& print, const ContactBook& list) 
{ 
	if (list.getSize() == 0) 
	{
		print << "There are no contacts in " << list.fn << " " << list.ln << "'s contact book.\n";
		return print;
	}
	print << list.fn << " " << list.ln << "'s Contact Book:\n\n";
	for (int i = 0; i < list.getSize(); i++) 
	{
		print << *list.book[i] << endl;
	}
	print << "End of " << list.fn << " " << list.ln << "'s Contact Book\n\n";
	return print;
}