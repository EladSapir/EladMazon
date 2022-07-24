//Elad Sapir - 209479948 - SCE
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef SHOP_H
#define SHOP_H
#include "MusicAlbum.h"
#include "ChildBook.h"
#include "ReadBook.h"
#include "SciFi.h"
#include "Thriller.h"
#include "Action.h"//include all types of products in the shop
#include <iostream>
using namespace std;

#define INPUTSIZE 500//input size 
#define ASIZE 30//Array size

//class Shop - holds the products  
class Shop
{
private:
	Product** Items;//array of products of the shop
	int numProd;//number of products int the shop

public:
	Shop();
	void Additem();//function to add product to the shop
	bool isNotEmpty();//function that checks if the shop is empty 
	bool RemovePro(const int indexR);//function that removes product from the shop
	void printItem(const int indexR)const;//function to print item
	bool isInShop(const int index)const;//function to check if there is an item with this serial number in the shop
	void printALL()const;//function to print all the products
	~Shop();//distructor 
};

#endif