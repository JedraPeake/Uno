#include <iostream>
#include <memory>

#include "UnoGame.h"

using namespace std;

int main(void)
{
	cout << "Welcome to Uno" << endl;
	cout << "Would you like to play:" << endl;
	cout << "1) default version for assignmnet 3?" << endl;
	cout << "2) Non default version with a deck of 40 cards" << endl;
	
	int choice =0;
	cin >> choice;
	while ((choice < 1) || (choice > 2))
	{
		cout << "Invalid choice please enter either choice 1 or 2" << endl;
		cin >> choice;
	}
	
	if (choice==1)
	{
		cout << "Choice 1" << endl;
		UnoGame defaultGame;
		defaultGame.play();
	}

	else
	{
		cout << "Choice 2" << endl;
		cout << "how many players would you like? ";
		int myPlayers = 0;
		cin >> myPlayers;
		
		cout << "how big would you like the hand size? "<<endl;
		cout << "Please bare in mind that the deck size can is only 40, so dont make the hands to big." << endl;
		int myHands = 0;
		cin >> myHands;

		int check = myHands*myPlayers;

		while(check >= 40)
		{
			cout << endl;
			cout << "Invalid input deck size camn only be 40 so players*hands needs to be less then 40" << endl;

			cout << "Choice 2" << endl;
			cout << "how many players would you like? ";
			cin >> myPlayers;

			cout << "how big would you like the hand size? " << endl;
			cout << "Please bare in mind that the deck size can is only 40, so dont make the hands to big." << endl;
			cin >> myHands;

			check = myHands*myPlayers;
		}
	
		UnoGame defaultGame(myPlayers,myHands);
		defaultGame.play();
	}
	cout << endl;
	cout << endl;
	cout << "For the purposes of making my code extensible:" << endl;
	cout << "Option to add or remove players and change the hand size" << endl;
	cout << endl;
	cout << endl;
}

