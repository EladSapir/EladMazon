//Elad Sapir - 209479948 - SCE
#include "ReadBook.h"

//start of constructor with default values
ReadBook::ReadBook(const char* Name,const int numberPage,const int yearP,const char*tempGenre):Product((float(numberPage*2.0)), Name), Book( numberPage, yearP)//product gets the price and name, book gets number of books and year produce
{
	genre = new char[(strlen(tempGenre) + 1)];//genre allocation
	if (genre == NULL)//allocation check
		exit(1);
	strcpy(genre, tempGenre);//copy the given genre
}//end of constructor


//start of copy constructor
ReadBook::ReadBook(const ReadBook& tRbook):Product(tRbook.price, tRbook.name), Book( tRbook.pageNum, tRbook.yearP)
{//product and book gets the same values of the given reading book
	genre = new char[strlen(tRbook.genre) + 1];//genre allocation
	if (genre == NULL)//allocation check
		exit(1);
	strcpy(genre, tRbook.genre);//copy genre
}//end of copy constructor

//start of print function
void ReadBook::print()const
{
	cout << "<" << serialNumber << "><" << price << "><Reading Book><" << name << "><" << yearP << "><" << pageNum << "><" << genre << ">" << endl;
}//end of print function

//start of distructor
ReadBook::~ReadBook()
{
	delete[] genre;//delete genre (else will be deleted in the book and product)
}//end of distructor