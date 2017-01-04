#pragma once

#include <iostream>
#include <string>

#include "UnoGame.h"
#include "Bag.h"
#include "UnoPlayer.h"
#include "Queue.h"
#include "Stack.h"
#include "UnoCard.h"

#define NUM_OF_PLAYERS 3
#define DEFAULT_BAG 40
#define NUM_OF_STARTING_CARDS 7

using namespace std;
class UnoGame
{
	int _numplayer;				//how many players
	int _numstartingcards;
	int _numofdecks;			//how many decks ie 2

public:	
	UnoPlayer *players;
	Bag<UnoCard> mybag;
	Stack<UnoCard> faceUpCards;
	Queue<UnoCard> deckPile;	

	UnoGame(int wantedPlayers = NUM_OF_PLAYERS, int wantedHandSize = NUM_OF_STARTING_CARDS);		//this will initialize the game!!!!!!!!

	void fillBag();
	void createDeck();
	void createPlayers(int _players);
	void drawStartCard();
	void play();	//starts the game
	void deckPileEmpty();
	bool finishGame();
	bool addDeck();
	
	~UnoGame();
};

