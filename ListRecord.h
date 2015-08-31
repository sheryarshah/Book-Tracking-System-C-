/****************************************************************************************
* Author: Sheyar Shah
* Last updated: 5-5-14
* Compiler Used: Microsoft Visual Studio 2013 Professional.
* Program Description: Program written in C++.
* This is ListRecord; it contains functions for seraching for book by isbn number,
* by sorting the records by isbn number, by sorting the records by title.
*****************************************************************************************/

#include "header.h"
#include "BookRecord.h"

#ifndef LISTRECORD_H
#define LISTRECORD_H

int adding_new_books(int n);						//ask's user how many new books were added to the system from option 1

/*
*This function is for case 2. It gives user the option to search for a book
* by its isbn number. It then checks if the isbn number exists and if it does
* it prints the information for the specified book
*/
int ISBN_bookSearch(BookRecord records[], string isbnNumber, int lineCounter){

	string Title;
	string Author;
	string Publisher;

	int i, n = 0;
	bool Exists = false;

	n = adding_new_books(n);	//asking user how many books were added to the system

	cout << "\n";
	for (i = 0; i < lineCounter + n; i++){
		if (isbnNumber == records[i].getISBN()){
			Exists = true;
			Title = records[i].getTitle();
			Author = records[i].getAuthor();
			Publisher = records[i].getPublisher();
		}
	}
	if (Exists == true){
		cout << Title << endl;
		cout << Author << endl;
		cout << Publisher << endl;
		cout << isbnNumber << endl;
	}
	else
		cout << "ISBN number " << isbnNumber << " not found";


	return 0;
}

/*
* Gives user the option on what he wants
*/
int menu_selection(int selection){

	cout << "\n\nSelect an option from the following menu: \n";
	cout << "1) Insert a new book into the list\n";
	cout << "2) Print the info of a specific book by ISBN number\n";
	cout << "3) Print the list sorted by ISBN\n";
	cout << "4) Print the list sorted alphabetically by title\n";
	cout << "5) Quit the program\n";
	cout << "Please select an option: ";
	cin >> selection;

	return selection;
}

/*
* Asks user how many new books were added to the system and returns that value
*/
int adding_new_books(int n){

	cout << "\nHow many new books did you add from option 1? ";
	cin >> n;

	return n;
}

/*
* Sorts the information by isbn number, in ascending order
*/
int compareISBN(const void * a, const void *b){

	return (strcmp(((BookRecord*)a)->getISBN().c_str(), ((BookRecord*)b)->getISBN().c_str()));
}

/*
* Sorts the information by its title
*/
int compareTitle(const void * a, const void *b){

	return (strcmp(((BookRecord*)a)->getTitle().c_str(), ((BookRecord*)b)->getTitle().c_str()));
}
#endif;
