//Elad Sapir - SCE
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include "Product.h"//include product
#include <string.h>
#define MOVIEPRICE 20 //price of each movie

//class movie - virtual inheritance class product ( type of product )
class Movie :virtual public Product
{
protected:
	int yearP;//year produce
public:
	Movie(const int YP = 1990);//constructor with default values
	virtual void print()const {};//virtual function of print for movie 
	~Movie()=0 {};//distructor , abstract class
};
#endif