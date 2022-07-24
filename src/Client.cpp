//Elad Sapir - SCE
#include "Client.h"
//constructor
Client::Client(const Shop* mainShop)
{
	baskets = NULL;//no baskets - NULL
	numbaskets = 0;//number of baskets 0
	tShop = mainShop;//the address of the shop
}//end of constructor

//function of the menu to add new basket
void Client::MenuAddNewBasket()
{
	int option = 0;
	bool run = true;
	while (run)//while we still want to run
	{
		printOptionsBasket();//print menu
		cin >> option;
		switch (option)
		{//choose the function according to the users choose:
		case NEW_BASKET:
			addBasket();//call function to add Basket
			break;
		case COPY_BASKET:
			CopyBasket();//call function to copy basket
			break;
		case X_U_Y:
			UniteBaskets();//call function that unites baskets ( U )
			break;
		case X_n_Y:
			diffBaskets();//call function that cuts baskets ( /\ )
			break;
		case RETURN: run = false; // the user chose to quit - we stop the while and tell him good bye
			cout << "Goodbye!\n";
			break;
		default: cout << "Wrong option. Please try again!\n"; //not a supported option
		}//end switch
	}
}

void Client::printOptionsBasket()
{
	cout << "Choose one of the following options:\n Press\n"//tell the user to choose one of the following options 
	//after the user chooses, the menu gets the function that the user wants to use and calls her accordingly
		<< "_______________________________________________________________" << endl
		<< NEW_BASKET << " -In order to create new basket." << endl//create new basket
		<< COPY_BASKET << " -In order to copy basket." << endl//copy basket
		<< X_U_Y << " -In order to unite baskets." << endl//unite baskets
		<< X_n_Y << " -In order to cut baskets" << endl//cut baskets
		<< RETURN << " -In order to return to menu." << endl//return
		<< "_______________________________________________________________" << endl;

}
//function to add new basket
void Client::addBasket()
{
	tShop->printALL();//print all the products once - so the user will know his options
	int cernum = 0, amount = 0;//cerial number and amount of each product
	char input[ASIZE]="\0";//input char array
	Basket* newBasket = new Basket();//allocate new basket 
	if (newBasket == NULL)//allocation check
		exit(1);
	char c = getchar();//clean last 'enter'
	do {
		cernum = 0;
		amount = 0;
		cout << "Enter the serial number and amount of the item to add"<<endl;//tell the user to enter details
		cin.getline(input, ASIZE);//get input from user (serial number ' ' amount)
		int j = 0;//index in the input
		while (input[j] != ' ')//run until space
		{
			cernum = cernum * 10 + (input[j] - '0');//get the ciral number from the input
			j++;
		}
		j++;//after the space
		while (input[j] != '\0')//run until the end
		{
			amount = amount * 10 + (input[j] - '0');//get the amount from the input
			j++;
		}
		if (tShop->isInShop(cernum) == true)//check if there is a product with this serial number
		{
			if (amount == 0)
				cout << "Cant add 0 items";//if the amount is 0
			else
				newBasket->addprod(cernum, amount);//call the fucntion to add
		}
		else
		{
			cout << "The item does not exist in the shop"<<endl;//if the item does not exist in the shop
		}
	}while (cernum != 0 || amount != 0);//continue while the input is not 0 0
	Basket** tempB = new Basket*[numbaskets + 1];//new array of baskets +1 in size
	if (tempB == NULL)//allocation check
	{
		delete newBasket;//delete the new basket
		exit(1);
	}
	for (int i = 0; i < numbaskets; i++)
	{
		tempB[i] = baskets[i];//copy all old baskets
	}
	tempB[numbaskets] = newBasket;//add the new basket to the array
	delete[] baskets;//delete the old array
	baskets = tempB;//hold the new array
	numbaskets++;//+1 to number of baskets
}//end of function add new basket

//function to copy basket
void Client::CopyBasket()
{
	int index = 0;
	cout << "Which product basket to copy" << endl;
	cin >> index;//get input from user - the basket to copy
	for (int i = 0; i < numbaskets; i++)
	{
		if(baskets[i][0] == index)//if fount the basket
		{
			Basket* newBasket = new Basket(baskets[i][0]);//allocate new basket(copy constructor)
			if (newBasket == NULL)//allocation check
				exit(1);
			Basket** tempBaskets = new Basket*[numbaskets+1];//new array of baskets
			if (tempBaskets == NULL)//allocation check
			{
				delete newBasket;//delete the copied basket
				exit(1);
			}
			for (int i = 0; i < numbaskets; i++)
			{
				tempBaskets[i] = baskets[i];//copy old baskets from old array
			}
			tempBaskets[numbaskets] = newBasket;//add copied basket
			delete[]baskets;//delete old array
			baskets = tempBaskets;//hold new array
			numbaskets++;//+1 to number of baskets
			return;
		}
	}
	cout << "Error: Selected product serial number does not exist." << endl;//if not founded - tell the user
}//end of function to copy basket

//function to unite baskets
void Client::UniteBaskets()
{
	int index1 = 0;//index of basket 1
	int index2 = 0;//index of basket 2
	char input[ASIZE] = "\0";//char array of input
	cout << "Which product baskets to use?" << endl;
	char c = getchar();//clean last 'enter'
	cin.getline(input, ASIZE);//get the input from the user
	int i = 0;
	while (input[i] != ' ')//run until space to get first index
	{
		index1 = index1 * 10 + (input[i] - '0');//get the first index
		i++;
	}
	i++;//after space
	while (input[i] != '\0')//run to the end to get second index
	{
		index2 = index2 * 10 + (input[i] - '0');//get second index
		i++;
	}
	int flag1 = -1;
	int flag2 = -1;
	for (int j = 0; j < numbaskets; j++)//run on baskets and search the given indexes
	{
		if (baskets[j][0] == index1)
			flag1 = j;
		if (baskets[j][0] == index2)
			flag2 = j;
	}
	if (flag1 != -1 && flag2 != -1)//if both founded
	{
		Basket* newBasket = new Basket(baskets[flag1][0] + baskets[flag2][0]);//creat new basket with operator + of basket(unite baskets)
		if (newBasket == NULL)//allocation check
			exit(1);
		Basket** tempBaskets = new Basket * [numbaskets + 1];//new array of baskets size +1
		for (int i = 0; i < numbaskets; i++)
		{
			tempBaskets[i] = baskets[i];//copy old baskets from old array
		}
		tempBaskets[numbaskets] = newBasket;//add new united basket 
		delete[] baskets;//delete old array of baskets
		baskets = tempBaskets;//hold new array
		numbaskets++;//number of baskets+1
	}
	else
		cout << "Error: One of the selected product baskets does not exist.";//if one of the flags is -1 means one of the indexes is wrong
}//end of function that unite baskets

//function to cut between baskets
void Client::diffBaskets()
{
	int index1 = 0;//index of basket 1
	int index2 = 0;//index of basket 2
	char input[ASIZE] = "\0";
	cout << "Which product baskets to use?" << endl;
	char c = getchar();//clear last 'enter
	cin.getline(input, ASIZE);//get the input from the user
	int i = 0;
	while (input[i] != ' ')//run until first space
	{
		index1 = index1 * 10 + (input[i] - '0');//get first index
		i++;
	}
	i++;//after the space
	while (input[i] != '\0')//run to end 
	{
		index2 = index2 * 10 + (input[i] - '0');//get the second index
		i++;
	}
	int flag1 = -1;
	int flag2 = -1;
	for (int j = 0; j < numbaskets; j++)//run on baskets
	{
		if (baskets[j][0] == index1)//check if first index exists
			flag1 = j;
		if (baskets[j][0] == index2)//check if second index exists
			flag2 = j;
	}
	if (flag1 !=- 1 && flag2 !=- 1)//if both found
	{
		Basket* newBasket = new Basket(baskets[flag1][0] - baskets[flag2][0]);//new basket with operator - that cuts baskets
		if (newBasket == NULL)//allocation check
			exit(1);
		Basket** tempBaskets = new Basket * [numbaskets + 1];//new array of baskets
		for (int i = 0; i < numbaskets; i++)
		{
			tempBaskets[i] = baskets[i];//copy old baskets from old array
		}
		tempBaskets[numbaskets] = newBasket;//add the new basket
		delete[] baskets;//delete old array of baskets
		baskets = tempBaskets;//hold the new array of baskets
		numbaskets++;//+1 to number of baskets
	}
	else
		cout << "Error: One of the selected product baskets does not exist."<<endl;//if one of the flags is -1 means one of the indexes is wrong
}//end of function that cuts baskets

//function of print specific basket
void Client::printBasket()const
{
	int index = 0;
	cout << "Enter the index of the basket to print" << endl;
	cin >> index;//get input of the serial number of the basket to print
	for(int j=0;j<numbaskets;j++)
	{
		cout << "<Product Basket><" << index << ">" << endl;//print the basket
		for (int i = 0; i < baskets[j][0].numofTypes; i++)
		{
			tShop->printItem(baskets[j][0].Prods[i][0]);//print each product
			cout << "<Amount><" << baskets[j][0].Prods[i][1] <<">"<< endl;//print the amount
		}
		return;
	}
		cout << "Error: Product basket with corresponding serial does not exist" << endl;//if got here- index not found- tell the user
}//end of function print basket

//start function to print all baskets
void Client::printAllBaskets()const
{
	if (numbaskets == 0)
	{
		cout << "No baskets to print"<<endl;//if number of baskets is 0 there is no baskets to print
	}
	else 
	{
		for (int i = 0; i < numbaskets; i++)
		{
			cout << "<Product Basket><" << baskets[i][0].serialnumber << ">" << endl;//print each baskets serial number
			for (int j = 0; j < baskets[i][0].numofTypes; j++)
			{
				tShop->printItem(baskets[i][0].Prods[j][0]);//each product of each basket
				cout << "<Amount><" << baskets[i][0].Prods[j][1] << ">" << endl;//amount 
			}
		}
	}
}//end of function that prints all baskets

//function to delete item from baskets
void Client::deleteItemFromBaskets(const int indexR)
{
	int countNull = 0;
	for (int i = 0; i < numbaskets; i++)
	{
		baskets[i]->removeItem(indexR);//call the function that removes item from the basket
		if (baskets[i]->numofTypes == 0)
		{
			countNull ++;//count the baskets that remain null after removing item
		}
	}
	Basket** temp = new Basket * [numbaskets - countNull];//allocate new array of baskets minus the null baskets
	if (temp == NULL)//allocation check
		exit(1);
	int k = 0;//the number of the null basket
	for (int i = 0; i < numbaskets; i++)
	{
		if (baskets[i]->numofTypes != 0)
		{
			temp[k] = baskets[i];//copy the basket if the number of products in it is not 0
			k++;
		}
		else
		{
			delete baskets[i];//if the number of products is 0 - delete the basket
		}
	}
	numbaskets = numbaskets - countNull;//number of baskets minus empty baskets
}//end of function to remove item from baskets

//function to delete basket
void Client::deleteBasket()
{
	int index = 0;
	cout << "Enter the index of the basket to delete" << endl;
	cin >> index;//get the serial number from the user
	int flag = -1;
	for (int i = 0; i < numbaskets; i++)
	{
		if (baskets[i][0] == index)//search the basket with this serial number with (operator ==)
			flag = i;		
	}
	if (flag !=- 1)//if there is a basket with this serial number
	{
		Basket** tempBasket = new Basket * [numbaskets - 1];//new array size-1
		if (tempBasket == NULL)//allocation check
		{
			exit(1);
		}
		for (int i = 0; i < flag; i++)
		{
			tempBasket[i] = baskets[i];//copy old basksets until the deleted basket
		}
		delete baskets[flag];//delete the basket that the user wants to delete
		for (int i = flag; i < numbaskets - 1; i++)
		{
			tempBasket[i] = baskets[i + 1];//copy the rest of the baskets
		}
		delete[] baskets;//delete old array of baskets
		baskets = tempBasket;//hold the new array of baskets
		numbaskets--;//number of baskets-1
	}
	else
		cout << "There is no basket with this serial number" << endl;//if flag is -1 - there is no basket with this serial number
}//end of function that delete basket

//disteructor
Client::~Client()
{
	for (int i = 0; i < numbaskets; i++)
	{
		delete baskets[i];//delete all baskets
	}
	delete[]baskets;//delete array of baskets
}