//Elad Sapir - 209479948 - SCE
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef CHILDBOOK_H
#define CHILDBOOK_H
#include "Book.h"//includes product and book

//class Children book - virtual inheritance class book ( type of book )
class ChildBook:virtual public Book
{
	private:
		int minAge;//minimum age for reading the book
	public:
		ChildBook(const char* Name = NULL,const int numberPage = 0,const int yearP = 1990,const int minimumAge = 6);//constructor with default values
		ChildBook(const ChildBook& tCbook);//copy constructor of child book
		virtual void print()const;//function print 
		~ChildBook() {};//distructor - else will be deleted in book and product 
};

#endif
