//Elad Sapir - 209479948 - SCE
#include "Shop.h"
//constructor
Shop::Shop()
{
	Items = NULL;//stop with empty array of products
	numProd = 0;	//0 products
}//end of cunstructor

//function to add item to the shop
void Shop::Additem()
{
	char input[INPUTSIZE];//char array to hold the input from the user
	cout << "Enter the data of the new product"<<endl;
	char c=getchar();//buffer clean(last enter)
	cin.getline(input, INPUTSIZE);//get the input from the user
	char tName[ASIZE] = "\0";
	if (input[0] != '<')
	{
		cout << "wrong input" << endl;//input check
		return;
	}
	int i = 1;//first char is <	
	while (input[i] != '>')//run on input untill '>'
	{
		if (input[i] == '\0')
		{
			cout << "wrong input" << endl;//input check
			return;
		}
		tName[i - 1] = input[i];//save the type of the product
		i++;
	}
	if (strcmp("Movie", tName) == 0)//if the product is movie
	{
		if (input[i+1] == '\0')
		{
			cout << "wrong input" << endl;//inuput check
			return;
		}
		i = i + 2;//jump om ><
		int j = 0;
		while (input[i] != '>')//get the type of the movie
		{
			if (input[i] == '\0')
			{
				cout << "wrong input" << endl;//inuput check
				return;
			}
			tName[j] = input[i];//get the type char by char
			i++;
			j++;
		}
		if (strcmp("Action", tName) == 0)//if the type is action
		{
			if (input[i + 1] == '\0')
			{
				cout << "wrong input" << endl;//inuput check
				return;
			}
			i = i + 2;//jump on ><
			j = 0;
			char movieName[ASIZE]="\0";//name of the movie entered
			while (input[i] != '>')
			{
				if (input[i+1] == '\0')
				{
					cout << "wrong input" << endl;//inuput check
					return;
				}
				movieName[j] = input[i];//get the name of the movie
				i++;
				j++;
			}
			movieName[j] = '\0';//end of the name of the movie
			for (int k = 0; k < numProd; k++)
			{
				if (Items[k][0] == movieName)//check if there is already item with that specific name
				{
					cout << "Error: Item already exists in the system." << endl;
					return;//end if already exists
				}
			}
			char Pyear[4]="\0";
			j = 0;
			if (input[i + 1] == '\0')
			{
				cout << "wrong input" << endl;//inuput check
				return;
			}
			for (i=i+2;input[i]!='>';i++)//get the year production of the action movie
			{
				if (input[i] == '\0')
				{
					cout << "wrong input" << endl;//inuput check
					return;
				}
				Pyear[j] = input[i];
				j++;
			}
			int intYear = (Pyear[0] - '0') * 1000 + (Pyear[1] - '0') * 100 + (Pyear[2] - '0') * 10 + (Pyear[3] - '0');//calculate from char to int
			if (input[i + 1] == '\0'||input[i+2]=='\0')
			{
				cout << "wrong input" << endl;//inuput check
				return;
			}
			int LVL=(input[i+2]-'0');//get the action level(i++ was in the loop)
			Action* newA = new Action(movieName, intYear, LVL);//allocate new action movie ( with all data from input )
			if (newA == NULL)//allocation check
				exit(1);
			Product** tempItems = new Product * [numProd + 1];//new array of products - size+1
			if (tempItems == NULL)//allocation check
			{
				delete newA;
				exit(1);
			}
			int k = 0;
			for (k = 0; k < numProd; k++)
			{
				tempItems[k] = Items[k];//copy all the items
			}
			tempItems[k] = newA;//add the new item
			delete[]Items;//delete old array of items
			Items = tempItems;//hold the new array
			numProd++;//number of products +1
		}
		else
		{
			if (strcmp("Sci-Fi", tName) == 0)//if sci fi movie
			{
				if (input[i + 1] == '\0')
				{
					cout << "wrong input" << endl;//inuput check
					return;
				}
				i = i + 2;
				j = 0;
				char movieName[ASIZE]="\0";
				while (input[i] != '>')//run until >
				{
					if (input[i] == '\0')
					{
						cout << "wrong input" << endl;//inuput check
						return;
					}
					movieName[j] = input[i];//get the name of the movie
					i++;
					j++;
				}
				movieName[j] = '\0';
				for (int k = 0; k < numProd; k++)//check on all products
				{
					if (Items[k][0] == movieName)//if there is an item with that specific name already
					{
						cout << "Error: Item already exists in the system." << endl;//error
						return;///stop
					}
				}
				char Pyear[4]="\0";//year produce
				j = 0;
				if (input[i + 1] == '\0')
				{
					cout << "wrong input" << endl;//inuput check
					return;
				}
				for (i = i + 2; input[i] != '>'; i++)
				{
					if (input[i] == '\0')
					{
						cout << "wrong input" << endl;//inuput check
						return;
					}
					Pyear[j] = input[i];//get the year production
					j++;
				}
				int intYear = (Pyear[0] - '0') * 1000 + (Pyear[1] - '0') * 100 + (Pyear[2] - '0') * 10 + (Pyear[3] - '0');//year calculation from char to int
				if (input[i + 1] == '\0'||input[i+2]=='\0')
				{
					cout << "wrong input" << endl;//inuput check
					return;
				}
				int LVL = (input[i + 2] - '0');//get the level
				SciFi* newS = new SciFi(movieName, intYear, LVL);//allocate sci fi movie ( with all data from input )
				if (newS == NULL)//allocation check
					exit(1);
				Product** tempItems = new Product * [numProd + 1];//new array of products
				if (tempItems == NULL)//allocation check
				{
					delete newS;
					exit(1);
				}
				int k = 0;
				for (k = 0; k < numProd; k++)
				{
					tempItems[k] = Items[k];//copy all the products
				}
				tempItems[k] = newS;//add the new product
				delete[]Items;//delete old array of products
				Items = tempItems;//hold the new array of products
				numProd++;//number of products+1
			}
			else
			{
				if (strcmp("Thriller", tName) == 0)//if Thriller movie
				{
					if (input[i + 1] == '\0')
					{
						cout << "wrong input" << endl;//inuput check
						return;
					}
					i = i + 2;
					j = 0;
					char movieName[ASIZE]="\0";
					while (input[i] != '>')//run until >
					{
						if (input[i] == '\0')
						{
							cout << "wrong input" << endl;//inuput check
							return;
						}
						movieName[j] = input[i];//get the name of the movie
						i++;
						j++;
					}
					movieName[j] = '\0';
					for (int k = 0; k < numProd; k++)//run on all products
					{
						if (Items[k][0] == movieName)//if there is already product with this specific name
						{
							cout << "Error: Item already exists in the system." << endl;//error
							return;
						}
					}
					char Pyear[4];
					j = 0;
					if (input[i + 1] == '\0')
					{
						cout << "wrong input" << endl;//inuput check
						return;
					}
					for (i = i + 2; input[i] != '>'; i++)//run until >
					{
						if (input[i] == '\0')
						{
							cout << "wrong input" << endl;//inuput check
							return;
						}
						Pyear[j] = input[i];//get the year production
						j++;
					}
					int intYear = (Pyear[0] - '0') * 1000 + (Pyear[1] - '0') * 100 + (Pyear[2] - '0') * 10 + (Pyear[3] - '0');//calculate from char to int
					if (input[i + 1] == '\0'||input[i+2]=='\0')
					{
						cout << "wrong input" << endl;//inuput check
						return;
					}
					int LVL = (input[i + 2] - '0');//get thriller the level
					Thriller* newT = new Thriller(movieName, intYear, LVL);//allocate new thriller movie ( with all data from input )
					if (newT == NULL)//allocation check
						exit(1);
					Product** tempItems = new Product * [numProd + 1];//new array of products - size+1
					if (tempItems == NULL)//allocation check
					{
						delete newT;
						exit(1);
					}
					int k = 0;
					for (k = 0; k < numProd; k++)
					{
						tempItems[k] = Items[k];//copy all the products
					}
					tempItems[k] = newT;//add the new product
					delete[]Items;//delete old array of products
					Items = tempItems;//hold the new array of products
					numProd++;//+1 number of products
				}
			}
		}
	}
	else
	{
		if (strcmp("Reading Book", tName)==0)//if its a reading book
		{
			if (input[i + 1] == '\0')
			{
				cout << "wrong input" << endl;//inuput check
				return;
			}
			char Bname[ASIZE]="\0";
			i = i + 2;//jump on ><
			int j = 0;
			while (input[i] != '>')
			{
				if (input[i] == '\0')
				{
					cout << "wrong input" << endl;//inuput check
					return;
				}
				Bname[j] = input[i];//get the name of the reading book
				i++;
				j++;
			}
			for (int k = 0; k < numProd; k++)//run on all the products
			{
				if (Items[k][0] == Bname)//if this name already exists - error
				{
					cout << "Error: Item already exists in the system." << endl;//error
					return;//stop and return
				}
			}
			int count = 0;//number of pages
			if (input[i + 1] == '\0')
			{
				cout << "wrong input" << endl;//inuput check
				return;
			}
			for (i = i + 2; input[i] != '>'; i++)
			{
				if (input[i] == '\0')
				{
					cout << "wrong input" << endl;//inuput check
					return;
				}
				count = (input[i] - '0') + count*10;//calculate the number of pages from char to int
			}
			char Pyear[4]="\0";
			j = 0;
			if (input[i + 1] == '\0')
			{
				cout << "wrong input" << endl;//inuput check
				return;
			}
			for (i = i + 2; input[i] != '>'; i++)
			{
				if (input[i] == '\0')
				{
					cout << "wrong input" << endl;//inuput check
					return;
				}
				Pyear[j] = input[i];//get the year produce
				j++;
			}
			int intYear = (Pyear[0] - '0') * 1000 + (Pyear[1] - '0') * 100 + (Pyear[2] - '0') * 10 + (Pyear[3] - '0');//calculate the year from char to int
			char Tgenre[ASIZE] = "\0";
			j = 0;
			if (input[i + 1] == '\0')
			{
				cout << "wrong input" << endl;//inuput check
				return;
			}
			for (i = i + 2; input[i] != '>'; i++)
			{
				if (input[i] == '\0')
				{
					cout << "wrong input" << endl;//inuput check
					return;
				}
				Tgenre[j] = input[i];//get the genre from input
				j++;
			}
			ReadBook* nRbook = new ReadBook(Bname, count, intYear, Tgenre);//allocate new reading book ( with all data from input )
			if (nRbook == NULL)//allocation check
				exit(1);
			Product** tempItems = new Product * [numProd + 1];//new array of products - size+1
			if (tempItems == NULL)//allocation check
			{
				delete nRbook;
				exit(1);
			}
			int k = 0;
			for (k = 0; k < numProd; k++)
			{
				tempItems[k] = Items[k];//copy all the products from old array
			}
			tempItems[k] = nRbook;//add the new reading book
			delete[]Items;//delete old array
			Items = tempItems;//hold the new array of products
			numProd++;	//number of products+1
		}
		else
		{
			if (strcmp("Children Book", tName)==0)//if its a childern book
			{
				if (input[i + 1] == '\0')
				{
					cout << "wrong input" << endl;//inuput check
					return;
				}
				char Bname[ASIZE]="\0";
				i = i + 2;//jump on ><
				int j = 0;
				while (input[i] != '>')//run on input until >
				{
					if (input[i] == '\0')
					{
						cout << "wrong input" << endl;//inuput check
						return;
					}
					Bname[j] = input[i];//get the name from input
					i++;
					j++;
				}
				for (int k = 0; k < numProd; k++)//run on all products
				{
					if (Items[k][0] == Bname)//check if this name already exits
					{
						cout << "Error: Item already exists in the system." << endl;//if already exists - error
						return;
					}
				}
				int count = 0;//number of pages
				if (input[i + 1] == '\0')
				{
					cout << "wrong input" << endl;//inuput check
					return;
				}
				for (i = i + 2; input[i] != '>'; i++)
				{
					if (input[i] == '\0')
					{
						cout << "wrong input" << endl;//inuput check
						return;
					}
					count = (input[i] - '0')  + count*10;//get the number of pages- calculate from char to int 
				}
				char Pyear[4] = "\0";
				j = 0;
				if (input[i + 1] == '\0')
				{
					cout << "wrong input" << endl;//inuput check
					return;
				}
				for (i = i + 2; input[i] != '>'; i++)
				{
					if (input[i] == '\0')
					{
						cout << "wrong input" << endl;//inuput check
						return;
					}
					Pyear[j] = input[i];//get the year produce from input
					j++;
				}
				int intYear = (Pyear[0] - '0') * 1000 + (Pyear[1] - '0') * 100 + (Pyear[2] - '0') * 10 + (Pyear[3] - '0');//calculate the year from char to int
				int TminAge = 0;
				if (input[i + 1] == '\0'||input[i+2]=='\0')
				{
					cout << "wrong input" << endl;//inuput check
					return;
				}
				for (i = i + 2; input[i] != '>'; i++)
				{
					TminAge = (input[i] - '0')  + TminAge*10;//get the minimum age from input, calculate from char to int
				}
				ChildBook* nCbook = new ChildBook(Bname, count, intYear, TminAge);//allocate new children book ( with all data from input )
				if (nCbook == NULL)//allocation check
					exit(1);
				Product** tempItems = new Product * [numProd + 1];//new array of products - size+1
				if (tempItems == NULL)//allocation check
				{
					delete nCbook;//delete the new book and exit
					exit(1);
				}
				int k = 0;
				for (k = 0; k < numProd; k++)
				{
					tempItems[k] = Items[k];//copy all the old products
				}
				tempItems[k] = nCbook;//add the new product - new childern book
				delete[]Items;//delete old array of products
				Items = tempItems; //hold the new array of products
				numProd++;//number of products +1
			}
			else
			{
				if (strcmp("Music Album", tName) == 0)//if it is a music album
				{
					if (input[i + 1] == '\0')
					{
						cout << "wrong input" << endl;//inuput check
						return;
					}
					char Aname[ASIZE * 2]="\0";//name
					int j = 0;
					for (i = i + 2; input[i] != '>'; i++)//run on input until >
					{
						if (input[i] == '\0')
						{
							cout << "wrong input" << endl;//inuput check
							return;
						}
						Aname[j] = input[i];//get the name from input
						j++;
					}
					for (int o = 0; o < numProd; o++)//run on all products
					{
						if (Items[o][0] == Aname)//check by name if there is one with this name already
						{
							cout << "Error: Item already exists in the system." << endl;//error if already exists
							return;//stop and return
						}
					}
					char Pyear[4] = "\0";
					j = 0;
					if (input[i + 1] == '\0')
					{
						cout << "wrong input" << endl;//inuput check
						return;
					}
					for (i = i + 2; input[i] != '>'; i++)//run on input
					{
						if (input[i] == '\0')
						{
							cout << "wrong input" << endl;//inuput check
							return;
						}
						Pyear[j] = input[i];//get the year produce
						j++;
					}
					int intYear = (Pyear[0] - '0') * 1000 + (Pyear[1] - '0') * 100 + (Pyear[2] - '0') * 10 + (Pyear[3] - '0');//calculate year produce from char to int
					if (input[i + 1] == '\0'||input[i+2]=='\0')
					{
						cout << "wrong input" << endl;//inuput check
						return;
					}
					j = i + 2;
					int k = 0;
					int numsongs=0;//number of songs
					while (input[j] != '\0')
					{
						char temp[ASIZE * 2] = "\0";
						k = 0;
						while (input[j] != '>')
						{
							if (input[j] == '\0')
							{
								cout << "wrong input" << endl;//inuput check
								return;
							}
							temp[k] = input[j];//temp for the word "SONG"
							j++;
							k++;
						}
						if (strcmp(temp,"Song") == 0)//if it is a song
						{
							numsongs++;//counting the number of songs - later will get all their data
						}
						if (input[j + 1] == '\0')//if the next char is the end
						{
							j = j + 1;//jump to it and the loop will stop 
						}
						else
							j = j + 2;//else jump on the ><
					}					
					Song** arraySongs = new Song * [numsongs];//allocate new song array
					if (arraySongs == NULL)//allocation check
						exit(1);
					char songN[ASIZE * 2] = "\0";
					int songLen = 0;
					for (int y=0;y<numsongs;y++)//run to get all the data on each song ( we got the number of songs )
					{
						songN[0] = '\0';
						for (i = i + 2; input[i] != '>'; i++)
						{//run on the word song
						};
						k = 0;
						for (i = i + 2; input[i] != '>'; i++)
						{
							songN[k] = input[i];//get the name of the song
							k++;
						}
						for (i = i + 2; input[i] != '>'; i++)
						{
							songLen = (input[i] - '0') * 10 + songLen;//get the length of the song and calculate from char to int
						}
						Song* newsong = new Song(songN, songLen);//allocate new song
						if (newsong == NULL)//allocation check - if fail delete all songs and array of songs
						{
							for (int u = 0; u < k; u++)
							{
								delete arraySongs[u];
							}
							delete[]arraySongs;
						}
						arraySongs[y] = newsong;//hold the new array of songs
					}
					MusicAlbum* newAlbum = new MusicAlbum(arraySongs, Aname, intYear, numsongs);//allocation of new music album with all the data from input
					for (i = 0; i < numsongs; i++)//delete the songs (they get copied in the constructor)
					{
						delete arraySongs[i];//delete each song
					}
					delete[] arraySongs;//delete the array
					if (newAlbum == NULL)//allocation check
					{
						exit(1);//if fails- delete all songs and delete the array of songs
					}
					Product** tempItems = new Product * [numProd + 1];//new array of products - size+1
					if (tempItems == NULL)//allocation check
					{
						delete newAlbum;//if fail - delete the new album and exit
						exit(1);
					}
					int p = 0;
					for (p = 0; p < numProd; p++)
					{
						tempItems[p] = Items[p];//copy all the products
					}
					tempItems[p] = newAlbum;//add the new album
					delete[]Items;//delete old array of products
					Items = tempItems;//hold the new array of products
					numProd++;//number of products +1
				}
				else//if its none of the types - tell the user its not one of the options for products
				{
				cout << "There is no match with any type of product."<<endl;
				}
			}
		}
	}
}//end of function that adds item to the array of products

//function to check if an item with the given serial number exists
bool Shop::isInShop(const int index)const
{
	for (int i = 0; i < numProd; i++)//run on all the products
	{
		if (Items[i][0] == index)
			return true;//if it has the given serial number - return true
	}
	return false;//else false
}//end of array that checks if the serial number exists

//function to remove product from the shop - boolean function that returns if it succeeded or not
bool Shop::RemovePro(const int indexR)
{
	for (int i = 0; i < numProd; i++)//run on all the products in the shop
	{
		if (Items[i][0] == indexR)//if found item with the given serial number
		{
			Product** tempArr = new Product * [numProd - 1];//new array with size-1
			if (tempArr == NULL)//allocation check
				exit(1);
			for (int j = 0; j < i; j++)
			{
				tempArr[j] = Items[j];//copy all the old items until the deleted one
			}
			delete Items[i];//delete the item that the user wants to delete
			for (int j = i + 1; j < numProd; j++)
			{
				tempArr[j - 1] = Items[j];//copy the rest of the items
			}
			delete[]Items;//delete old array
			Items = tempArr;//hold new array of products
			numProd--;//number of products-1
			return true;//boolean function that returns if it succeeded or not
		}
	}
	cout << "Error, item does not exist";//if got here- means there is no item with that serial number
	return false;//return false 
}

//function to print item from the shop
void Shop::printItem(const int indexR)const
{
	for (int i = 0; i < numProd; i++)//run on all the items
	{
		if (Items[i][0] == indexR)//if there is a product with the given serial number
		{
			Items[i]->print();//call the function that prints product
			return;
		}
	}
	cout << "Error, this item does not exist";//if got here - means there is no item with that serial number
}//end of print function

//start of function that checks if the shop is empty
bool Shop::isNotEmpty()
{
	if (numProd == 0)//if number of products in the shop is 0- means empty
		return false;//false - its not not empty
	return true;//true - it is empty
}//end of function empty check

//function that prints all the items of the shop
void Shop::printALL()const
{
	for (int i = 0; i < numProd; i++)
	{
		Items[i]->print();//call the function that prints product for each product in the array of products
	}
}//end of function that prints all products

//distructor
Shop::~Shop()
{
	for (int i = 0; i < numProd; i++)
	{
		delete Items[i];//delete all the items - call distructor of each product
	}
	delete[]Items;//delete array of products
}//end of distructor