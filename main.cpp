/****************************************************************************************
* Author: Sheyar Shah 
* Last updated: 5-5-14
* Compiler Used: Microsoft Visual Studio 2013 Professional.
* Program Description: Program written in C++.
* The program reads in a file which contains information for different books. The user is
* given 4 different options, to add on how many ever books he want to add to the system,
* to get information from the book via isbn number,to get all the books in the system sorted
* by isbn number, or to get information of all the books in system by title.
*****************************************************************************************/

#include "header.h"
#include "BookRecord.h"
#include "ListRecord.h"


int menu_selection(int selection);					//Gives the user different options to choose from
int ISBN_bookSearch(BookRecord records[], string isbnNumber, int lineCounter);	//For option 2, searches book by isbn
int adding_new_books(int n);						//ask's user how many new books were added to the system from option 1
int compareISBN(const void * a, const void *b);		//sorts the information by isbn number
int compareTitle(const void * a, const void *b);	//sorts the information by title

int main(){

	string title, author, publisher, isbn, line;
	string fileName;

	int selection = 0, lineCounter = 0, i;

redo:
	cout << "Enter the name of the file : ";
	cin >> fileName;

	ifstream myFile(const_cast<char *>(fileName.c_str()));	//converting fileName to character

	if (myFile.is_open()){
		cout << "Loading " << fileName << ".... \n\n";
	}
	else{
		cout << "Invalid file name or can't open the file" << endl;
		goto redo;						//if wrong file name, re-enter
	}


	BookRecord records[TABLE_SIZE];			//creating an array of object, named records

	while (!myFile.eof()){					//reading file until it reaches end of file
		bool Valid = true;

		getline(myFile, title);			//reads in fist line and puts into title
		getline(myFile, author);		//reads in second line and puts into author
		getline(myFile, publisher);		//reads in third line and puts into publisher
		getline(myFile, isbn);			//reads in fourth line and puts into isbn
		getline(myFile, line);			//fifth line is empty space, that contains nothing

		/*This parts checks for duplicate isbn number and if found, it
		ignores the entire information for the duplicate book*/
		for (i = 0; i < lineCounter; i++){
			if (isbn == records[i].getISBN()){
				cout << "\nDuplicate ISBN Number...ignoring entry" << endl;
				Valid = false;
				break;
			}
		}

		/*puts the valid information into class*/
		if (Valid == true){
			records[lineCounter].setTitle(title);
			records[lineCounter].setAuthor(author);
			records[lineCounter].setPublisher(publisher);
			records[lineCounter].setISBN(isbn);
			lineCounter++;									//valid lines in a file
		}
	}

	/*Different option given to the user*/
	while (1){
		selection = menu_selection(selection);
		switch (selection){

			/*Option for adding new books to the record*/
		case(1) :
		{
					string NewSpace, NewTitle, NewAuthor, NewPublisher, NewISBN;
					int n = 0;

					cout << "\nHow many books do want add to the record: ";	//user is given option of how many books he wants to add
					cin >> n;

					for (i = lineCounter; i < lineCounter + n; i++){

						cout << "";
						getline(cin, NewSpace);					//taking care of empty space between new records

						cout << "\nEnter books's title: ";
						getline(cin, NewTitle);					//taking in new title for the book
						records[i].setTitle(NewTitle);			//adding it the class

						cout << "Enter author's name: ";
						getline(cin, NewAuthor);				//taking in new author for specified book
						records[i].setAuthor(NewAuthor);		//adding it the class

						cout << "Enter book's publisher: ";
						getline(cin, NewPublisher);				//taking in new publisher for specified book
						records[i].setPublisher(NewPublisher);	//adding it the class

						cout << "Enter books's ISBN: ";
						getline(cin, NewISBN);					//taking in the isbn number for specified book
						records[i].setISBN(NewISBN);			//adding it the class
					}

					cout << "\n\nThe record has been added to the list" << endl;

					break;
		}

				/*Option for searching for books by isbn number*/
		case(2) :
		{
					int n = 0;
					string isbnNumber;

					cout << "\nEnter an ISBN number: ";
					cin >> isbnNumber;

					ISBN_bookSearch(records, isbnNumber, lineCounter);

					break;
		}

				/*Option for sorting the book by isbn number*/
		case(3) :
		{
					int i = 0, n = 0;

					n = adding_new_books(n);			//ask user how many new books were added to the system

					cout << "\nThe first 22 characters of each field is displayed\n";
					cout << "\n        Title\t              Author\t           Publisher\t        ISBN" << endl;
					cout << "---------------------- ---------------------- ---------------------- ----------" << endl;

					qsort(records, lineCounter + n, sizeof(BookRecord), compareISBN);		//sorting function

					/*outputting the results for case 3 in tabular format*/
					for (i = 0; i < lineCounter + n; i++){
						cout << left;
						cout << setw(22) << records[i].getTitle().substr(0, 22) << " " << setw(23)
							<< records[i].getAuthor().substr(0, 22)
							<< setw(22) << records[i].getPublisher().substr(0, 22) << " "
							<< records[i].getISBN() << "\n";
					}

					break;
		}

				/*Option for sorting the books by title*/
		case(4) :
		{
					int i = 0, n = 0;

					n = adding_new_books(n);			//ask user how many new books were added to the system

					cout << "\nThe first 22 characters of each field is displayed\n";
					cout << "\n        Title\t              Author\t           Publisher\t        ISBN" << endl;
					cout << "---------------------- ---------------------- ---------------------- ----------" << endl;

					qsort(records, lineCounter + n, sizeof(BookRecord), compareTitle);			//sorting function

					/*outputting the results for case 3 in tabular format*/
					for (i = 0; i < lineCounter + n; i++){
						cout << left;
						cout << setw(22) << records[i].getTitle().substr(0, 22) << " " << setw(23)
							<< records[i].getAuthor().substr(0, 22)
							<< setw(22) << records[i].getPublisher().substr(0, 22) << " "
							<< records[i].getISBN() << "\n";
					}

					break;
		}

				/*Terminating the program*/
		case(5) :
		{
					cout << "\nProgram terminated normally...\n";
					cin.ignore();
					cin.get();
					return 0;						//system exit 
					break;
		}

		default:
			cout << "Wrong selection, please re-enter ";
			break;
		}
	}

	myFile.close();


	cin.ignore();					//needed for this specific complier, keeps cmd open
	cin.get();

	return 0;

}

