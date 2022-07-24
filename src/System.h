//Elad Sapir - SCE
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Client.h"
#include "Shop.h"
#ifndef SYSTEM_H
#define SYSTEM_H

//class system - runs all the other classes, holds most of the menus and operates Elad SCEMAZON
class System
{
private:
	typedef enum { ADD_NEW_BASKET = 1, PRINT_BASKET, PRINT_ALL_BASKETS, DELETE_BASKET, RETURNB } UserManageMenuOptions;//options for client
	typedef enum { BUILD_SHOP = 1, MANAGE_CLIENT, EXIT} MenuOptions;//options for the menu
	typedef enum { ADD_NEW_ITEM = 1, DELETE_ITEM, PRINT_ITEM, PRINT_ALL_ITEMS, RETURN } ShopMenuOptions;//options for the shop
	Shop* EladSCEMazon;//the shop of the system
	Client* mainClient;//the client
public:
	System();//constructor - default
	void printOptionsUserManage();//print the options for user manage
	void userManage();//menu of the user 

	void printOptionsMainMenu();//print the options for main menu
	void mainMenu();//main menu

	void printOptionsShop();//print the options for the shop ( items )
	void startManageShop();//shop menu

	void deleteItem();//funtion that deletes item 
	//delete item is also here to call some functions (both deletes from the store and from all the baskets)
	~System();//distructor


};


#endif 
