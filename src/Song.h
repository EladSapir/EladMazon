//Elad Sapir - 209479948 - SCE
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef SONG_H
#define SONG_H
#include <string.h>
#include <iostream>
using namespace std;

//class Song - each one hold name and length of the song
class Song
{
private:
	char* name;//name of the song
	int length;//length of the song
public:
	Song(const char*Tname=NULL,const int lenthInSec=0);//constructor - with default values
	Song(const Song& tSong);//copy constructor
	void print()const;//function that prints songs details
	~Song();//distructor
};

#endif
