//Elad Sapir - 209479948 - SCE
#include "childBook.h"
//start of constructor
ChildBook::ChildBook(const char* Name,const int numberPage,const int yearP,const int minimumAge):Product((float(numberPage/2.0)),Name),Book(numberPage,yearP)
{//price of this product is (number of pages)/2 , with the given name , number of pages and and year goes to book constructor
	minAge = minimumAge;//minimum age in months
}//end of constructor

//start of copy constructor
ChildBook::ChildBook(const ChildBook& tCbook):Product(tCbook.price, tCbook.name),Book(tCbook.pageNum,tCbook.yearP)
{//same values
	minAge = tCbook.minAge;//copy minimum age
}//end of copy constructor

//start of function print
void ChildBook::print()const
{//print all details of the children book
	cout << "<" << serialNumber << "><" << price << "><Children Book><" << name << "><" << yearP << "><"<<pageNum<<"><" << minAge << ">" << endl;
}//end print function
