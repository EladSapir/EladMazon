//Elad Sapir - SCE
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
using namespace std;

//class product
//will be the base to all the products - holds the name,price and serial number of the products
class Product
{
	protected:
		float price;//price 
		char* name;//name of product
		int serialNumber;// serial number of the product
	private:
		static int SerNum;//static serial number to count the products and give them serial number
	public:
		Product(float tempPrice=10,const char* tName=NULL);//constructor with default values
		bool operator==(const char* newProd);//operator == that checks if its the name
		bool operator==(const int index);//operator == that checks if its the serial number
		virtual void print()const {};//virtual function to print product - here does nothing
		virtual ~Product()=0;//distructor - !abstract class! 
};

#endif