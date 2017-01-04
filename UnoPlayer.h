#pragma once

#include <iostream>
#include <string>
#include<memory>

#include "OrderedList.h"
#include "UnoCard.h"
using namespace std;

class UnoPlayer
{
public:	
	int m_size = 3;
	UnoPlayer();
	~UnoPlayer();
	OrderedList<UnoCard> getHand;
	friend ostream& operator << (ostream& os, const UnoPlayer &c);		//not needed to cout players as names were array spot +1 but defines anyway
private:
	
};



