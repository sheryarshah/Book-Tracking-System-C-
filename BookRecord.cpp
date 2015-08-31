/****************************************************************************************
* Author: Sheyar Shah
* Last updated: 5-5-14
* Compiler Used: Microsoft Visual Studio 2013 Professional.
* Program Description: Program written in C++.
* This is BookRecord class; it contains constructors, setters and getters for title, isbn,
* publisher and isbn number.
*****************************************************************************************/

#include "header.h"

#ifndef BOOKRECORD_H
#define BOOKRECORD_H

class BookRecord{

private:
	string Title, Author, Publisher, ISBN;

public:
	BookRecord(){}	//creating default values

	BookRecord(string Title, string Author, string Publisher, string ISBN){ //argument constructor
		setTitle(Title);
		setAuthor(Author);
		setPublisher(Publisher);
		setISBN(ISBN);
	}

	/*Mutator method for title, author, publisher, isbn*/
	void setTitle(string newTitle){
		Title = newTitle;
	}
	void setAuthor(string newAuthor){
		Author = newAuthor;
	}
	void setPublisher(string newPublisher){
		Publisher = newPublisher;
	}
	void setISBN(string newISBN){
		ISBN = newISBN;
	}

	/*Get method or accessor method for title, author, publisher, isbn*/
	string getTitle(){
		return Title;
	}
	string getAuthor(){
		return Author;
	}
	string getPublisher(){
		return Publisher;
	}
	string getISBN(){
		return ISBN;
	}

};
#endif
