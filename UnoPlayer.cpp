#include "UnoPlayer.h"

UnoPlayer::UnoPlayer()
{
}

UnoPlayer::~UnoPlayer()
{};

ostream& operator << (ostream& os, const UnoPlayer &c)
{
	for (int i = 1; i<c.m_size + 1; i++)
	os << c.getHand.retrieve(i);
	return os;
}

