//Elad Sapir - 209479948 - SCE
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
using namespace std;
#include "Basket.h"
#include "Shop.h"
//#define SIZE 10

//class of the client - handles the baskets 
class Client
{
private:
	Basket** baskets;//baskets of the client
	int numbaskets;//number of buskets
	const Shop* tShop;//gets the shop (gets the details of the products)
	typedef enum { NEW_BASKET = 1, COPY_BASKET, X_U_Y, X_n_Y, RETURN } ShopMenuOptions;//options for the menu

public:
	Client(const Shop* mainShop);//constructor - gets the address of the shop
	void MenuAddNewBasket();//function of the menu to add new basket
	void addBasket();//function to add basket
	void CopyBasket();//function to copy basket
	void UniteBaskets();//function to unite baskets
	void diffBaskets();//function to cut baskets
	void printOptionsBasket();//function to print the options of the menu
	void deleteItemFromBaskets(const int indexR);//function to delete item from baskets
	void printBasket()const;//function to print specific basket
	void printAllBaskets()const;//function to print all baskets
	void deleteBasket();//function to delete basket
	~Client();//distructor
};

#endif