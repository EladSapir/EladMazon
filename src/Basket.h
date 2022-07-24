//Elad Sapir - 209479948 - SCE
//Elad Sapir - 209479948 - SCE
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef BASKET_H
#define BASKET_H
#include <iostream>
using namespace std;

//each basket holds serial numbers of products and amount of each, each basket has its own serial number
class Basket
{
private:
	int** Prods;//serial numbers of products and amounts
	int numofTypes;//number of types of products in the basket
	int serialnumber;//each baskets serial number
	static int SerNum;//static int to count the baskets and give them serial number
public:	
	Basket();//default constructor
	Basket(const Basket& tbasket);//copy constructor
	void addprod(const int sernum, const int amount);//function to add product to basket
	void removeItem(const int indexR);//function to remove item from basket
	bool operator==(const int indexR);//operator== to check if the serial number is the given index
	Basket& operator+(const Basket& b1)const;// function to unite baskets
	Basket& operator-(const Basket& b2)const;// function to cut baskets
	~Basket();//distructor
	friend class Client;//access for class client(the client prints baskets and more)
};



#endif