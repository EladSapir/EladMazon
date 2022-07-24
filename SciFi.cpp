//Elad Sapir - 209479948 - SCE
#include "SciFi.h"
//start of constructor 
SciFi::SciFi(const char* Tname, const int YP, const int tLVL) :Product(MOVIEPRICE, Tname), Movie(YP)//product gets the price and name, movie gets the year
{//check if the Sci fi level is between 1-9
	if (tLVL > 9)
	{
		SciLVL = 9;
	}
	else 
	{
		if (tLVL < 1)
		{
			SciLVL = 1;
		}
		else
			SciLVL = tLVL;
	}
}//end of constructor

//copy constructor
SciFi::SciFi(const SciFi& tSciFi):Product(tSciFi.price, tSciFi.name), Movie(tSciFi.yearP)
{//product and movie gets the same values as the given Sci fi movie
	SciLVL = tSciFi.SciLVL;
}//end of copy constructor

//function print
void SciFi::print()const
{//print all details of the Sci fi movie
	cout << "<" << serialNumber << "><" << price << "><movie><Sci-Fi><" << name << "><" << yearP << "><" << SciLVL << ">" << endl;
}//end of print function