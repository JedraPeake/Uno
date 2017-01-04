#include "UnoGame.h"
#include <time.h>
using namespace std;

UnoGame::UnoGame(int wantedPlayers, int wantedHandSize)
{
	fillBag();
	createDeck();
	createPlayers(wantedPlayers);

	_numstartingcards = wantedHandSize;
	
	for (unsigned int i = 0; i < _numplayer; i++)//each player gets a hand 
	{
		for (int j = 1; j <= _numstartingcards; j++)
		{
			players[i].getHand.insert(deckPile.dequeue());
		}
	}
	cout << "PLayers Hands:" << endl;
	for (int i = 0; i < _numplayer; i++)//each player gets a hand 
	{
		cout << "Player " << i + 1 << endl;
		for (int j = 1; j <= _numstartingcards; j++)
		{
			cout << players[i].getHand.retrieve(j) << endl;
		}
		cout << endl;
	}

	drawStartCard();
}

void UnoGame::fillBag()
{
		Colour s[] = { RED, YELLOW, BLUE, GREEN };
		Denomination d[] = { N1,N2,N3,N4,N5 };

		for (int z = 0; z < 2; z++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					mybag.add(UnoCard(s[i], d[j]));
				}
			}
		}
}

void UnoGame::createDeck()
{
	srand(time(NULL));																//randomly call cards from bag and place them into the deck
	for (int i = 1; i <= 40; i++)													//for loop counts to 40 as we need to move 40 cards
	{
		deckPile.enqueue(mybag.getOne());											//calls getone form bag class which randomly picks a an index to get, and returns the value to place into the queue
	}
}

void UnoGame::createPlayers(int _players)
{
	_numplayer = _players;
	players = new UnoPlayer[_numplayer];
}

void UnoGame::drawStartCard()
{
	faceUpCards.push(deckPile.peek());													//draw a starting card for the face up pile		stack	//gets top card
	deckPile.dequeue();																	//removes top card from queue
}

void UnoGame::play()
{
	cout << "Start" << endl;
	cout << "The card on the start of the face up pile is: " << faceUpCards.peek() << endl;

	do {

		for (int i = 0; i<_numplayer; i++)														//does a round of turns at a time!
		{
			UnoCard topCardOnStack = faceUpCards.peek();								//Getting the ccard on top of the stack

			cout << "Player " << i + 1 << "'s turn: " << endl;
			cout << "The top card on the pile is: " << topCardOnStack << endl;

			for (int j = 1; j <= players[i].getHand.getLength(); j++)					//go through playyers hand
			{
				UnoCard current_Card = players[i].getHand.retrieve(j);					//card in current location of players hand
				cout << "Player " << i + 1 << " current card is " << current_Card << endl;

				if (current_Card.toCharDenomination() == topCardOnStack.toCharDenomination()) //Checking if the numbers are the same on the topcard and the retrived card
				{
					faceUpCards.push(current_Card);										//if true it goes on top of the stack
					players[i].getHand.remove(j);										//remove card from players hand
					cout << "Player " << i + 1 << " has a card with the same demoniation since they played the " << current_Card << " to matched with " << topCardOnStack << endl;
					goto turnComplete;													//goes to the end, to skip other possabiliteis on players go
				}

			}

			for (int j = 1; j <= players[i].getHand.getLength(); j++)					//does same as for loop above at first
			{

				UnoCard current = players[i].getHand.retrieve(j);

				if (current.toCharColour() == topCardOnStack.toCharColour())			//Checking if the colour are the same on the topcard and the retrived card
				{
					faceUpCards.push(current);											//does same as if statement above
					players[i].getHand.remove(j);
					cout << "Player " << i + 1 << " has a card with the same colour since they played the " << current << " to matched with " << topCardOnStack << endl;
					goto turnComplete;
				}

			}

			players[i].getHand.insert(deckPile.peek());									//If no match found, draw a card from deck pile, and insert in hand
			deckPile.dequeue();
			cout << "Unfortunately player " << i + 1 << " did not find a match, so drew a card from the deck." << endl;

			if (deckPile.isEmpty())															 //if the deck pile runs out of cards
			{
				cout << "All cards in the starting deck used..." << endl;
				deckPileEmpty();															//calls deckpileEmpty function from the class
				players[i].getHand.insert(deckPile.dequeue());								//still have to insert a card into the players hand
				cout << "..The deck has been filled again" << endl;
			}

		turnComplete:																		//what happens when turn is finished

			if (players[i].getHand.getLength() == 1)										//players call UNO if they have 1 card left 
			{
				cout << "Player " << i + 1 << " currently has 1 cards remaining therfore calls UNO" << endl;
			}

			if (players[i].getHand.getLength() == 0)										//Check to see if anyone won the game yet 
			{
				cout << "Player " << i + 1 << " has won as they have 0 cards left, and therfore they WIN!" << endl;
			}


			if (finishGame())																// Calls a function to see if the game is over  or not 
				break;

			cout << endl << "Everyone still has cards!" << endl;
		}

	} while (!finishGame());
}

bool UnoGame::finishGame()
{
	for (int i = 0; i < _numplayer; i++)
	{
		if (players[i].getHand.isEmpty())	//The game is finished if any of the players has no cards in their hand. 
		{
			return true;
		}
	}
	return false;
}

void UnoGame::deckPileEmpty()
{
	if (deckPile.isEmpty() == true)
	{
		UnoCard tempTop = faceUpCards.pop();			//Saves the top faceup card

		Bag<UnoCard> newDeckPile;						//create new bag

		while (faceUpCards.isEmpty() == false)					//move cards from stack to bag, till stack is empty 
			newDeckPile.add(faceUpCards.pop());

		faceUpCards.push(tempTop);							   //topCard goes to the top of the stack

		for (int i = 0; i < newDeckPile.currentSize(); i++)		//add to deck
			deckPile.enqueue(newDeckPile.getOne());
	}
}

UnoGame::~UnoGame()
{
	delete[] players;
}