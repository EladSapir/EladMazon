//Elad Sapir - 209479948 - SCE
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef ACTION_H
#define ACTION_H
#include "Movie.h"//includes product and movie

//Class of Action movie - virtual inheritance class movie ( a type of a movie )
class Action :virtual public Movie
{
private:
	int actionLVL;//action level
public:
	Action(const char* Tname = NULL, const int YP = 1990, const int aLVL = 0);//constructor and default constructor
	Action(const Action& tAtcion);//copy constructor
	void print()const;//print function
	~Action() {};//distructor - nothing to delete here 
};
#endif