//Elad Sapir - 209479948 - SCE
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef SCIFI_H
#define SCIFI_H
#include "Movie.h"//include movie

//Class of Sci Fi movie - virtual inheritance class movie ( a type of a movie )
class SciFi :virtual public Movie
{
private:
	int SciLVL;//Sci fi level
public:
	SciFi(const char* Tname = NULL, const int YP = 1990, const int tLVL = 0);//constuctor with default values
	SciFi(const SciFi& tSciFi);//copy constructor
	void print()const;//fucntion to print the details of the sci fi movie
	~SciFi() {};//distructor - else will be deleted in product and movie
};
#endif