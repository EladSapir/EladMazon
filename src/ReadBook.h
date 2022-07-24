//Elad Sapir - SCE
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef READBOOK_H
#define READBOOK_H
#include "Book.h"//include book class

//class Reading Book - virtual inheritance class Book ( a type of a book )
class ReadBook:virtual public Book
{
private:
	char * genre;//the genre of the reading book
public:
	ReadBook(const char* Name = NULL,const int numberPage = 0,const int yearP = 1990,const char* tempGenre = NULL);//constructor with default values
	ReadBook(const ReadBook& tRbook);//copy constructor
	void print()const;//function to print all the details of the reading book
	~ReadBook();//distructor
};

#endif