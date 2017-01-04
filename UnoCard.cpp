#include "UnoCard.h"

UnoCard::UnoCard(Colour colour, Denomination denomination) : m_colour(colour), m_denomination(denomination)
{}

// destructor
UnoCard::~UnoCard()
{}

char UnoCard::toCharColour()
{
	if (m_colour == YELLOW)
	{
		return 'Y';
	}
	else if (m_colour == BLUE)
	{
		return 'B';
	}
	else if (m_colour == RED)
	{
		return 'R';
	}
	else 
	{
		return 'G';
	}
	
}

char UnoCard::toCharDenomination()
{
	if (m_denomination == N1)
	{
		return '1';
	}
	else if (m_denomination == N2)
	{
		return '2';
	}
	else if (m_denomination == N3)
	{
		return '3';
	}
	else if (m_denomination == N4)
	{
		return '4';
	}
	else
	{
		return '5';
	}

}

std::ostream& operator<<(std::ostream& os, const UnoCard &c) {
	int suit = c.getColour();
	int demo = c.getDenomination();

	os << demo;

	switch (suit)
	{
	case 1:
		os << " of Yellow";
		break;
	case 2:
		os << " of Blue";
		break;
	case 3:
		os << " of Red";
		break;
	default:
		os << " of Green";
		break;
	}
	return os;
}
