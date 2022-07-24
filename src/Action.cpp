//Elad Sapir - 209479948 - SCE
#include "Action.h"
//start of constuctor and default constructor
Action::Action(const char* Tname, const int YP, const int aLVL) :Product(20, Tname), Movie(YP)
{//action is a movie(movie is a product) - price for movie 20 
	if (aLVL > 5)
	{
		actionLVL = 5;//check for action level
	}
	else
	{
		if (aLVL < 1)
		{
			actionLVL = 1;//check for action level
		}
		else
			actionLVL = aLVL;//if not more than 5 and not less than 1 enter the given action level
	}
}//end of constructor

//start of copy constructor
Action::Action(const Action& tAction) : Product(tAction.price, tAction.name), Movie( tAction.yearP)//new movie new product with the same values
{
	actionLVL = tAction.actionLVL;
}//end of copy constructor

//start of function print - prints all about action movie
void Action::print()const
{
	cout <<"<"<<serialNumber<<"><"<<price<<"><movie><Action><" << name << "><" << yearP << "><"<<actionLVL<<">" << endl;
}//end of function print