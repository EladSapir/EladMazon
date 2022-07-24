//Elad Sapir - SCE
#include "Product.h"

int Product::SerNum = 1;//static serial number

//constructor of product
Product::Product(float tempPrice,const char *tName) 
{
	if (tempPrice > 100)
		price = 100;
	else
	{
		if (tempPrice < 10)
			price = 10;
		else
			price = tempPrice;
	}//check if the price is more that 100 or less than 10 
	serialNumber = SerNum;//each one gets its serial number
	SerNum++;
	name = new char[strlen(tName) + 1];//get the name in the same size as the given name
	if (name == NULL)//allocation check
		exit(1);
	strcpy(name, tName);//copy the name
}//end of constructor

//operator== - gets name and checks if its the same
bool Product::operator==(const char* newProd)
{
	if (strcmp(newProd, name) == 0)
		return true;//if the same - return true
	else
		return false;//else false
}//end of operator == that gets name

//operator = - gets index and checks if its the serial number
bool Product::operator==(const int index)
{
	if (serialNumber == index)
		return true;//if it is the serial number- return true
	return false;//else false
}//end of function opreator== that gets serial number

//distructor
Product::~Product()
{
	delete[]name;//delete the name
}//end of distructor