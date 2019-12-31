#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;  


struct Football
{
	string firstName; // first name // 
	string lastName; // last name // 
	string pos; // position // 
	int numOfTds; // number of touchdown // 
	int numOfCatches; // number of catches // 
	int numOfPassYrds; // number of passing yards // 
	int numOfRecYrds; // number of receiving yards // 
	int numOfRushYrds; // number of rushing // 
};

void inputData(struct Football Players[],int); // user input for file // 
void outputData(struct Football Players[],int); // output file // 
void searchName(struct Football Players[]); // search for a player's name // 
void display(struct Football Players[], int); // print data to the screen // 
void mainMenu(); // Main menu // 
void update(struct Football Players[], int); // update player information // 

int main()
{
	struct Football Players[50];
	int count;
	int option;
	int exit = 0;

	while(exit != 1)
	{
		mainMenu(); // menu for options for the user // 

		cin >> option; 
		switch (option)
		{

		case 0: exit = 1;
				break; // exit program // 

		case 1: cout << "How many football players information do you want to enter? (Max 50 players)" << endl;
				cin >> count;
				inputData(Players, count); 
				break; // call function for user input // 

		case 2: outputData(Players, count); 
				break; // call function for output file // 

		case 3: display(Players, count); 
				break; // call function for displaying data on screen // 
	
		case 4: searchName(Players); 
				break; // call for searching for a specific player // 

		default: cout << "Incorrect entry, please try again" << endl; // incorrect entry // 

		}
	}

	system("pause");
	return 0;
}

//////////////////////////////           Functions              ///////////////////////////////////////////////


void inputData(struct Football Players[],int count) // function for user input in a file // 
{
	ifstream in;
	in.open("texans.txt");

	cout << "Now opening texans.txt ...." << endl;

	for (int i = 0; i < count; i++)
	{
		cout << "Enter the football player's first name." << endl;
		cin >> Players[i].firstName;

		cout << "Enter the football player's last name." << endl;
		cin >> Players[i].lastName;

		cout << "Enter the football player's position (use letters only)" << endl;
		cin >> Players[i].pos;

		cout << "Enter the number of touchdowns by the player." << endl;
		cin >> Players[i].numOfTds;

		cout << "Enter the number of catches by the player." << endl;
		cin >> Players[i].numOfCatches;

		cout << "Enter the number of passing yards by the player." << endl;
		cin >> Players[i].numOfPassYrds;

		cout << "Enter the number of receiving yards by the player." << endl;
		cin >> Players[i].numOfRecYrds;

		cout << "Enter the number of rushing yards by the player." << endl;
		cin >> Players[i].numOfRushYrds;
	}
	in.close();
}

void outputData(struct Football Players[],int count)  // Function for output data to file // 
{
	ofstream out;
	out.open("texans.txt");

	cout << "Now saving data into file now" << endl;

	for (int i = 0; i < count; i++)
	{
		out << " **************************" << endl;
		out << "Name:" << Players[i].firstName << " " << Players[i].lastName << endl;
		out << "Position: " << Players[i].pos << endl;
		out << "Number of touchdowns: " << Players[i].numOfTds << endl;
		out << "Number of catches: " << Players[i].numOfCatches << endl;
		out << "Number of passing yards: " << Players[i].numOfPassYrds << endl;
		out << "Number of receiving yards: " << Players[i].numOfRecYrds << endl;
		out << "Number of rushing yards: " << Players[i].numOfRushYrds << endl;
		out << " ****************************" << endl;
	}
	out.close();

}

void searchName(struct Football Players[]) // Function for searching for a specific name // 
{
	string searchName;

	cout << "Enter the football's player first name you want to search" << endl;
	cin >> searchName;

	cout << "Now searching for " << searchName << " ." << endl;

	for (int count = 0; count < 10; count++)
	{
		if (Players[count].firstName == searchName)
		{
			cout << "Search results found" << endl;
			update(Players,count);
			break;
		}
		else
		{
			cout << "No search results found" << endl;
			break;
		}
	}
}

void display(struct Football Players[], int count) // Function to print data onto the screen // 
{
	for (int i = 0; i < count; i++)
	{
		cout << " ****************************** " << endl;
		cout << "Name:" << Players[i].firstName << " " << Players[i].lastName << endl;
		cout << "Position: " << Players[i].pos << endl;
		cout << "Number of touchdowns: " << Players[i].numOfTds << endl;
		cout << "Number of catches: " << Players[i].numOfCatches << endl;
		cout << "Number of passing yards: " << Players[i].numOfPassYrds << endl;
		cout << "Number of receiving yards: " << Players[i].numOfRecYrds << endl;
		cout << "Number of rushing yards: " << Players[i].numOfRushYrds << endl;
		cout << " ******************************* " << endl << endl;
	}
}

void mainMenu() // main menu with mutiple options // 
{
	cout << " *** Football rosters *** " << endl << endl;
	cout << "Please select an option" << endl;
	cout << "0 - Exit the program" << endl;
	cout << "1 - Input new data" << endl;
	cout << "2 - Save the data into a file" << endl;
	cout << "3 - Display the current data on the screen" << endl;
	cout << "4 - Search for a specific football player" << endl;
	cout << " ****    ****" << endl << endl;
}

void update(struct Football Players[], int count)
{
	int choice = 0;

	cout << " ***************************** " << endl;
	cout << "0 - return to the main menu" << endl;  // update menu // 
	cout << "1 - Update the position " << endl;
	cout << "2 - Update the number of touchdowns" << endl;
	cout << "3 - Update the number of catches" << endl;
	cout << "4 - Update the passing yards" << endl;
	cout << "5 - Update the receiving yards" << endl;
	cout << "6 - Update the rushing yards" << endl;
	cout << " ******************************** " << endl;

	cout << "What do you want to update for this player?" << endl;
	cin >> choice;

	while (choice != -1) // options for updating a specific player // 
	{
		if (choice = 0)
		{
			choice = -1;
			break; // returns back to the main menu // 
		}

		else if (choice = 1)
		{
			cout << "Enter the football player's position (use letters only)" << endl;
			cin >> Players[count].pos;
			break;
		}
		else if (choice = 2)
		{
			cout << "Enter the new number of touchdowns by the player." << endl;
			cin >> Players[count].numOfTds;
			break;
		}

		else if (choice = 3)
		{
			cout << "Enter the new number of catches by the player." << endl;
			cin >> Players[count].numOfCatches;
			break;
		}
		else if (choice = 4)
		{
			cout << "Enter the new number of passing yards by the player." << endl;
			cin >> Players[count].numOfPassYrds;
			break;
		}
		else if (choice = 5)
		{
			cout << "Enter the new number of receiving yards by the player." << endl;
			cin >> Players[count].numOfRecYrds;
			break;
		}
		else if (choice = 6)
		{
			cout << "Enter the new number of rushing yards by the player." << endl;
			cin >> Players[count].numOfRushYrds;
			break;
		}
	}
}
