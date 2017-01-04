#pragma once
#include <iostream>

enum Colour
{
	RED = 1, YELLOW = 2, BLUE = 3, GREEN = 4, WILD=5
};
enum Denomination
{
	N1 = 1, N2 = 2, N3 = 3, N4 = 4, N5 = 5
};

class UnoCard
{
public:
	UnoCard(Colour colour = YELLOW, Denomination denomination = N2); // constructor with some default values

	inline Colour getColour(void) const							 //getter to access private storage
	{
		return m_colour;
	}
	inline Denomination getDenomination(void) const				//getter to access private storage
	{
		return m_denomination;
	}

	char toCharColour(void); // returns a char that "describes" card's colour
	char toCharDenomination(void); // returns a char that "describes" card's denomination

	~UnoCard(); // destructor

private:
	Colour m_colour; // private storage of colour
	Denomination m_denomination; // private storage of denomination
	friend std::ostream& operator<<(std::ostream& os, const UnoCard &c);
};

// global operator functions comparing denominations of two cards
// The cards a and b are passed by reference
inline bool operator<(const UnoCard& a, const UnoCard& b)
{
	if (a.getColour() == b.getColour())
	{
		return (a.getDenomination() < b.getDenomination());
	}
	else
	{
		return (a.getColour() < b.getColour());
	}
}
inline bool operator>(const UnoCard& a, const UnoCard& b)
{
	if (a.getColour() == b.getColour())
	{
		return (a.getDenomination() > b.getDenomination());
	}
	else
	{
		return (a.getColour()>b.getColour());
	}
}

// checks equality of colour and denominations for two cards
inline bool operator==(UnoCard& a, UnoCard& b)
{
	return (a.getDenomination() == b.getDenomination() && a.getColour() == b.getColour());
}


