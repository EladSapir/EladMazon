//Elad Sapir - 209479948 - SCE
#include "MusicAlbum.h"

//start of constructor with default values
MusicAlbum::MusicAlbum(Song** tempSongs,const char* Tname,const int YP,const int numberSongs):Product(float(numberSongs*5),Tname)//product gets the price and name
{
	songs = new Song * [numberSongs];//new array of songs
	if (songs == NULL)//allocation check
		exit(1);
	for (int i = 0; i < numberSongs; i++)
	{
		songs[i] = new Song(tempSongs[i][0]);//copy each song
		if (songs[i] == NULL)
		{
			for(int j = i; j >= 0; j--)
			{
				delete songs[j];//if allocation fails - delete all songs
			}
			delete[] songs;//delete array of songs
			exit(1);
		}
	}
	yearP = YP;//year produce
	numSongs = numberSongs;//number of song is the same
}//end of constructor 

//start of copy constructor
MusicAlbum::MusicAlbum(const MusicAlbum& tMalbum):Product(tMalbum.price,tMalbum.name)//product gets the price and name
{
	songs = new Song * [tMalbum.numSongs];//new array of songs
	if (songs == NULL)//allocation check
		exit(1);
	for (int i = 0; i < tMalbum.numSongs; i++)
	{
		songs[i] = new Song(tMalbum.songs[i][0]);//copy each song
		if (songs[i] == NULL)
		{
			for (int j = i; j >= 0; j--)
			{
				delete songs[j];//if allocation fails - delete all songs
			}
			delete[] songs;//delete array of songs
			exit(1);
		}
	}
	yearP = tMalbum.yearP;//same year produce
	numSongs = tMalbum.numSongs;//same number of songs
}//end of copy constructor

//start of function print
void MusicAlbum::print()const
{
	cout << "<" << serialNumber << "><" << price << "><Music Album><" << name << "><" << yearP << ">" << endl;//print all details
	for (int i = 0; i < numSongs; i++)
	{
		songs[i]->print();//use the fucntion of print song to print each song
	}
}//end of function print

//distructor
MusicAlbum::~MusicAlbum()
{
	for (int i = 0; i < numSongs; i++)
	{
		delete songs[i];//delete each song
	}
	delete[]songs;//delete the array of songs
}//end of distructor