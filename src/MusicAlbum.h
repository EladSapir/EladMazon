//Elad Sapir - 209479948 - SCE
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef MUSICALBUM_H
#define MUSICALBUM_H
#include "Product.h"//include product
#include "Song.h"//songs of the album

//class Music Album - virtual inheritance class product ( type of product )
class MusicAlbum: public Product
{
	private:
		Song** songs;//each album hold its songs
		int yearP;//year produced
		int numSongs;//number of songs in the album
	public:
		MusicAlbum( Song** tempSongs=NULL,const char* Tname=NULL,const int YP=1990,const int numberSongs=0);//constructor with default values
		MusicAlbum(const MusicAlbum& tMalbum);//copy constructor
		void print()const;//function to print the album
		~MusicAlbum();//distructor of album
};
#endif
