/****************************************************************************************
* Author: Sheyar Sha
* Last updated: 5-5-14
* Compiler Used: Microsoft Visual Studio 2013 Professional.
* Program Description: Program written in C++.
* The program reads in a file which contains information for different books. The user is
* given 4 different options, to add on how many ever books he want to add to the system,
* to get information from the book via isbn number,to get all the books in the system sorted
* by isbn number, or to get information of all the books in system by title.
*****************************************************************************************/

#define _CRT_SECURE_NO_DEPRECATE		//needed for this specific complier, ignores unnessary warnings

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

#define TABLE_SIZE 200				//max number for information allowed in an object, record
