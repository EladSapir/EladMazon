//Elad Sapir - SCE
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef BOOK_H
#define BOOK_H
#include "Product.h"//include product
#include <string.h>

//class book - virtual inheritance class product ( type of product )
class Book:virtual public Product
{

protected:
	int pageNum;//number of pages of the book
	int yearP;//year produce

public:
	Book(const int PN=0,const int YP=1990);//constructor with default values - 0 pages , produced 1990
	virtual void print()const {};//virtual function print for each time of book , this one does nothing
	virtual ~Book() = 0 {};//distructor - abstract class
};
#endif