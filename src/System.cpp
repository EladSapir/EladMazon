//Elad Sapir - 209479948 - SCE
#include "System.h"

//constructor - function that also starts the main menu
System::System()
{
	EladSCEMazon=new Shop();//new empty shop
	mainClient=new Client(EladSCEMazon);//new client ( client gets the shop to get be able to do things with products )
	mainMenu();//call main menu
}//end of constructor

//user menu
void System::userManage()
{
	bool run = true;// continue or not
	int option;//user chosen option
	while (run)//while we still want to run
	{
		printOptionsUserManage();//print menu
		cin >> option;//get the choice from the user

		switch (option)
		{//choose the function according to the users choose:
		case ADD_NEW_BASKET:
			mainClient->MenuAddNewBasket();//call function to add new baskset
			break;
		case PRINT_BASKET:
			mainClient->printBasket();//call function to print specific basket
			break;
		case PRINT_ALL_BASKETS:
			mainClient->printAllBaskets();//call function to print all baskets
			break;
		case DELETE_BASKET:
			mainClient->deleteBasket();//call function to delete specific basket
			break;
		case RETURNB: run = false; // the user chose to quit - we stop the while and tell him good bye
			break;
		default: cout << "Wrong option. Please try again!\n"; //not a supported option
		}//end switch
	}
}//end of users menu

//start of main menu
void System::mainMenu()
{
	bool run = true;// continue or not
	int option;//user chosen option
	while (run)//while we still want to run
	{
		printOptionsMainMenu();//print menu
		cin >> option;//input - choice of the user
		int indexR = 0;
		switch (option)
		{//choose the function according to the users choose:
		case BUILD_SHOP:
			startManageShop();//call the shop menu
			break;
		case MANAGE_CLIENT:
			if (EladSCEMazon->isNotEmpty() == true)//in case the shop is not empty
				userManage();//call the user menu that handles the baskets
			else
				cout << "The shop is empty"<<endl;//in case the shop is empty - massage to the user
			break;	
		case EXIT: run = false; // the user chose to quit - we stop the while and tell him good bye
			cout << "Goodbye!"<<endl;
			break;
		default: cout << "Wrong option. Please try again!"<<endl; //not a supported option
		}//end switch
	}
}//end of user menu function

//start of shop manage function 
void System::startManageShop()
{
	bool run = true;// continue or not
	int option;//user chosen option
	while (run)//while we still want to run
	{
		printOptionsShop();//print menu
		cin >> option;
		int indexR = 0;
		switch (option)
		{//choose the function according to the users choose:
		case ADD_NEW_ITEM:
			EladSCEMazon->Additem();//call function to add item to the shop
			break;
		case DELETE_ITEM:
			deleteItem();//call function to remove item from the shop
			break;
		case PRINT_ITEM:
			cout << "Enter the serial number of the product you wish print:" << endl;//get input from the user - the serial to print
			cin >> indexR;
			EladSCEMazon->printItem(indexR);//call function to print the specific product
			break;
		case PRINT_ALL_ITEMS:
			EladSCEMazon->printALL();//call function to print all products
			break;
		case RETURN:
			run = false; //the user chose to quit - we stop the while and tell him good bye
			break;
		default: cout << "Wrong option. Please try again!\n"; //not a supported option
		}//end switch
	}
}//end of function user manage

//function print options for user manage
void System::printOptionsUserManage()
{
	cout << "Choose one of the following options:\n Press\n"//tell the user to choose one of the following options 
		//after the user chooses, the menu gets the function that the user wants to use and calls her accordingly
		<< "_______________________________________________________________" << endl
		<< ADD_NEW_BASKET << " -In order to add Basket." << endl//add new basket
		<< PRINT_BASKET << " -In order to print one basket" << endl//print basket
		<< PRINT_ALL_BASKETS << " -In order to print all baskets." << endl//print all baskets
		<< DELETE_BASKET << " -In order to delete basket." << endl//delete basket
		<< RETURN << " -In order to return to menu." << endl//return to main menu
		<< "_______________________________________________________________" << endl;
}//end of function print options for user menu

//start function print options main menu
void System::printOptionsMainMenu()
{
	cout << "Choose one of the following options:\n Press\n"//tell the user to choose one of the following options 
		//after the user chooses, the menu gets the function that the user wants to use and calls her accordingly
		<< "_______________________________________________________________" << endl
		<< BUILD_SHOP << " -In order to build and manage the shop." << endl//Shop menu
		<< MANAGE_CLIENT << " -In order to manage the client" << endl//User manage menu
		<< EXIT << " -In order to Exit" << endl//Exit the program
		<< "_______________________________________________________________" << endl;
}//end of function print options for main menu

//function print options for shop
void System::printOptionsShop()
{
	cout << "Choose one of the following options:\n Press\n"//tell the user to choose one of the following options 
		//after the user chooses, the menu gets the function that the user wants to use and calls her accordingly
		<< "_______________________________________________________________" << endl
		<< ADD_NEW_ITEM << " -In order to add item to the shop." << endl//add item
		<< DELETE_ITEM << " -In order to remove item from the shop" << endl//remove item
		<< PRINT_ITEM << " -In order to print one item." << endl//print one product
		<< PRINT_ALL_ITEMS << " -In order to print all items." << endl//print all products
		<< RETURN << " -In order to return to menu." << endl//return to main menu
		<< "_______________________________________________________________" << endl;

}//end method Menu::printOptions()

//function delete item - exits here because we need to delete the items from the baskets too 
void System::deleteItem()
{
	bool isIn = 0;
	int indexDel = 0;
	cout << "Enter serial number to delete" << endl;
	cin >> indexDel;//get input from the user
	isIn = EladSCEMazon->RemovePro(indexDel);//trying to remove the item from the shop
	if (isIn == true)//if the product exists in the shop
	{
		mainClient->deleteItemFromBaskets(indexDel);//call function that deletes the item from all baskets
	}
}//end of function that deletes item 

//distructor
System::~System()
{
	delete EladSCEMazon;//delete the shop
	delete mainClient;//delete the client
}//end of distructor