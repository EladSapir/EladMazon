//Elad Sapir - 209479948 - SCE
#include "Basket.h"

int Basket::SerNum = 1;//serial number of baskets - first starts with 1

//default constructor
Basket::Basket()
{
	Prods = NULL;//array of products null
	numofTypes = 0;//0 types of products
	serialnumber = SerNum;//serial number for each basket
	SerNum++;
}//end of default constructor

//copy constructor
Basket::Basket(const Basket& tbasket)
{
	numofTypes = tbasket.numofTypes;//copy the number of types of products
	Prods = new int* [numofTypes];//array in the same size
	if (Prods == NULL)
		exit(1);
	for (int i = 0; i < numofTypes; i++)
	{
		Prods[i] = new int[2];//allocation for each line
		if (Prods[i] == NULL)//allocation check
		{
			for (int j = 0; j < i; j++)
			{
				delete Prods[j];//delete all secceded lines
			}
			delete[]Prods;//delete arrau
			exit(1);
		}
		Prods[i][0] = tbasket.Prods[i][0];//copy serial numbers 
		Prods[i][1] = tbasket.Prods[i][1];//copy amounts
	}
	serialnumber = SerNum;//the new basket gets new serial number
	SerNum++;
}//end of copy constructor

//function to add product to the basket
void Basket::addprod(const int sernum, const int amount)
{
	for (int i = 0; i < numofTypes; i++)
	{
		if (Prods[i][0] == sernum)
		{
			Prods[i][1] = Prods[i][1] + amount;//if this type already in the basket - add to amount
			return;
		}
	}
	int** temp = new int* [numofTypes + 1];//new temp array with 1more type of products
	if (temp == NULL)//allocation check
		exit(1);
	numofTypes++;
	for (int i = 0; i < numofTypes; i++)
	{
		temp[i] = new int[2];//allocate each line in the temp array
		if (temp[i] == NULL)//allocation check
		{
			for (int j = 0; j < i; j++)
			{
				delete temp[j];//if didnt succeed delete 
			}
			delete[]temp;
			exit(1);
		}
	}
	for (int i = 0; i < numofTypes - 1; i++)
	{
		temp[i][0] = Prods[i][0];//copy serial numbers
		temp[i][1] = Prods[i][1];//copy amounts
	}
	temp[numofTypes-1][0] = sernum;//insert added serial number
	temp[numofTypes-1][1] = amount;//insert added amount
	delete[] Prods;//delete old array
	Prods = temp;//save new array
}//end of function add product

//operator + to unite baskets
Basket& Basket::operator+(const Basket& b1)const
{
	int countEqual=0;//count how much equal products
	for (int i = 0; i < numofTypes; i++)
	{
		for (int j = 0; j < b1.numofTypes; j++)
		{
			if (Prods[i][0] == b1.Prods[j][0])
			{
				countEqual++;//if same serial number count 
				j = b1.numofTypes;
			}
		}
	}
	int size = numofTypes + b1.numofTypes - countEqual;//size of the new array of products
	int** temp = new int* [size];//allocate temp array with the calculated size
	if(temp == NULL)//allocation check
		exit(1);
	for (int i = 0; i < size; i++)
	{
		temp[i] = new int[2];//allocate each line
		if (temp[i] == NULL)//alocation check
		{
			for (int j = 0; j < i; j++)
			{
				delete temp[j];//if didnt succeed delete all
			}
			delete[] temp;
			exit(1);//exit
		}
	}
	for (int i = 0; i < numofTypes; i++)//copy first array of products and amounts
	{
		temp[i][0] = Prods[i][0];//copy serial numbers
		temp[i][1] = Prods[i][1];//copy amounts
	}
	int flag=0;//flag if found or not
	int k = 0;//the number of the equal product ( from the equal counted )
	for (int i = 0; i < b1.numofTypes; i++)//run on the second array 
	{
		flag = 0;
		for (int j = 0; j < numofTypes; j++)
		{
			if (temp[j][0] == b1.Prods[i][0])//if already in
			{
				if (temp[j][1] < b1.Prods[i][1])//check which amount is bigger
				{
					temp[j][1] = b1.Prods[i][1];
				}
				flag = 1;//founded
				j = numofTypes;//end run
			}
		}
		if (flag == 0)//if didnt find it, add it to the array
		{
			temp[(numofTypes + k)][0] = b1.Prods[i][0];//copy serial number
			temp[(numofTypes + k)][1] = b1.Prods[i][1];//copy amount
			k++;//number of equals
		}
	}
	Basket* btemp = new Basket();//alocate the new basket
	if (btemp == NULL)
	{
		for (int i = 0; i < size; i++)
		{
			delete temp[i];//if didnt succeed delete the temp array
		}
		delete[]temp;
		exit(1);
	}
	btemp->Prods = temp;//the new basket holds the array of products
	btemp->numofTypes = size;//the new basket holds the calculated size
	SerNum--;//the function makes 1 temp basket and than 1 more - want to count only 1
	return *btemp;//return new united basket
}//end of unite function

//start of cut function
Basket& Basket::operator-(const Basket& b2)const
{
	int countequal = 0;//count of equal types of products
	for (int i = 0; i < numofTypes; i++)
	{
		for (int j = 0; j < b2.numofTypes; j++)//run on both arrays 
		{
			if (Prods[i][0] == b2.Prods[j][0])
				countequal++;//count if same serial number
		}
	}
	int** temp = new int* [countequal];//allocate new array of serial numbers and amounts
	if (temp == NULL)//allocation check
		exit(1);
	for (int i = 0; i < countequal; i++)
	{
		temp[i] = new int[2];//allocate each new line
		if (temp[i] == NULL)//if didnt succeed delete all 
		{
			for (int j = 0; j < i; j++)
			{
				delete[] temp[j];//delete each line
			}
			delete[] temp;//delete array
			exit(1);
		}
	}
	int k = -1;
	for (int i = 0; i < numofTypes; i++)
	{
		for (int j = 0; j < b2.numofTypes; j++)//run on both arrays and enter the common products
		{
			if (Prods[i][0] == b2.Prods[j][0])
			{
				k++;//index of the common product
				temp[k][0] = Prods[i][0];//insert the serial number
				if (Prods[i][1] > b2.Prods[j][1])//check which amount is smaller 
				{
					temp[k][1] = b2.Prods[j][1];
				}
				else
					temp[k][1] = Prods[i][1];
			}
		}
	}
	Basket* newBasket = new Basket();//allocate the new basket
	if (newBasket == NULL)
	{
		for (int i = 0; i < countequal; i++)
		{
			delete temp[i];//if didnt secceed delete the temp array - each line
		}
		delete[] temp;//delete the array
		exit(1);
	}
	newBasket->Prods = temp;//the new basket holds the temp array
	newBasket->numofTypes = countequal;//its size is the number of common products
	return* newBasket;//return the new basket
}//end of cut baskets

//start of function to remove item from basket
void Basket::removeItem(const int indexR)
{
	int isIn = -1;//if its in or not
	for (int i = 0; i < numofTypes; i++)//run on the array
	{
		if (Prods[i][0] == indexR)//check if the given index is a serial number in the array
		{
			isIn = i;
			i = numofTypes;//end run if founded
		}
	}
	if (isIn != -1)//if the index is a serial number in the array- needed to be deleted
	{
		int** tempProd = new int* [numofTypes - 1];//allocate new array of serial numbers and amounts
		if (tempProd == NULL)//allocation check
		{
			exit(1);
		}
		for (int i = 0; i < numofTypes-1; i++)
		{
			tempProd[i] = new int[2];//allocate each new line 
			if (tempProd[i] == NULL)//allocation check
			{
				for (int j = 0; j < i; j++)
				{
					delete[] tempProd[j];//delete each line
				}
				delete[] tempProd;//delete array
				exit(1);
			}
		}
		for (int i = 0; i < isIn; i++)//copy until the deleted index
		{
			tempProd[i][0] = Prods[i][0];//copy serial number
			tempProd[i][1] = Prods[i][1];//copy amount
		}
		for (int i = isIn; i < numofTypes - 1; i++)//copy after the deleted index until the end
		{
			tempProd[i][0] = Prods[i+1][0];//copy serial number
			tempProd[i][1] = Prods[i+1][1];//copy amount
		}
		for (int i = 0; i < numofTypes; i++)//delete old array
		{
			delete[] Prods[i];//delete each line
		}
		delete[] Prods;//delete array
		Prods = tempProd;//hold the new array of serial numbers and amounts
		numofTypes--;//number of types of products -1
	}
}//end of function to remove item from busket

//start operator == to check if the given index is the serial number
bool Basket::operator==(const int indexR)
{
	if (serialnumber == indexR)
		return true;//if they are the same - true . else false
	return false;
}//end of operator==

//start of distructor
Basket::~Basket()
{
	for (int i = 0; i < numofTypes; i++)
	{
		delete[] Prods[i];//delete each line in the array of serial numbers and amounts
	}
	delete[]Prods;//delete the array
}//end of distructor