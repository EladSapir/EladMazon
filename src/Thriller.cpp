//Elad Sapir - 209479948 - SCE
#include "Thriller.h"

//constructor with default values
Thriller::Thriller(const char* Tname , const int YP, int TLVL):Product(20, Tname),Movie(YP)//product gets the price and name, movie get the year produce
{//thriller level check 
	if (TLVL > 6)
	{
		thrilLVL = 6;//if more than 6 - gets 6,
	}
	else 
	{
		if (TLVL < 1)
		{
			thrilLVL = 1;//if less then 1 - gets 1,
		}
		else
			thrilLVL = TLVL;//if between 1-6 - gets the value
	}
}//end of constructor

//start of copy constructor
Thriller::Thriller(const Thriller& tThriller):Product(tThriller.price, tThriller.name),Movie(tThriller.yearP)
{//product gets the price and name, movie gets the year
	thrilLVL = tThriller.thrilLVL;//same thirller level
}//end of constructor

//start of print function
void Thriller::print()const
{//print all details on the thriller movie
	cout << "<" << serialNumber << "><" << price << "><movie><Thriller><" << name << "><" << yearP << "><" << thrilLVL << ">" << endl;
}//end of print function
