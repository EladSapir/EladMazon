//Elad Sapir - 209479948 - SCE
#include "Song.h"

//constructor of song
Song::Song(const char* Tname,const int lenthInSec)
{
	name = new char[(strlen(Tname) + 1)];//allocate name
	if (name == NULL)//allocation check
	{
		exit(1);
	}
	strcpy(name, Tname);//copy the given name
	length = lenthInSec;//length of the song
}//end of constructor

//copy constructor
Song::Song(const Song& tSong)
{
	name = new char[(strlen(tSong.name) + 1)];//allocate name
	if (name == NULL)//allocation check
		exit(1);
	strcpy(name, tSong.name);//copy name
	length = tSong.length;//length of song
}//end of copy constructor

//start of function that prints song
void Song::print()const
{
	cout << "\t""<Song><" << name << "><" << length << ">" << endl;//print all the details of the song
}//end of function print

//distructor
Song::~Song()
{
	delete[] name; //delete the name of the song
}//end of distructor