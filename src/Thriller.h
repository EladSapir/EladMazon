//Elad Sapir - SCE
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef THRILLER_H
#define THRILLER
#include "Movie.h"


//Class of Thriller movie - virtual inheritance class movie ( a type of a movie )
class Thriller :virtual public Movie
{
private:
	int thrilLVL;//thriller level 
public:
	Thriller(const char* Tname=NULL, const int YP=0, int TLVL=0);//constructor with default values
	Thriller(const Thriller& tThriller);//copt constructor
	void print()const;//print function
	~Thriller() {};//distructor - nothing to delete here
};
#endif