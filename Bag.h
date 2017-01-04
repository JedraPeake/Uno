#pragma once
#include <stdlib.h> 
#include <assert.h>
#define DEFAULT_BAG 40
//will be used to create all the cards.

//bags allow us to remove RANDOM objects from it (that were previously placed inside)
// NOTE: your main should initialize a random number generator (via srand) when using Bag<T> objects

template <class T>
class Bag
{
private:
	unsigned int m_size; // number of elements currently stored in the bag
	unsigned int bagCapacity; // the maximum capacity of the bag
	T * m_container;   // internal storage array of pointers to Ts 

public:
	//Bag(unsigned int max_capacity = DEFAULT_BAG); // construct an empty bag of specified "max_capacity"
	Bag(int DefaultBag = DEFAULT_BAG);																						 // if no value is provided, DEFAULT_BAG is used

	void add(T value); // adds a new T into the bag, 
					   // PRECONDITION: the bag must not be "full"
	T getOne(); // extracts an T from the bag, 
				// PRECONDITION: the bag must not be "empty"

	bool isEmpty() const;
	bool isFull() const;

	unsigned int currentSize() const;   // returns # of Ts now in bag
	unsigned int capacity() const;        // returns bag’s upper capacity

	~Bag();  // destructor (recycles memory allocated by constructor)

};

template <class T>
Bag<T> ::Bag(int DefaultBag)
{
	bagCapacity = DefaultBag;
	m_size = 0;
	m_container = new T[bagCapacity];
}

template <class T>
void Bag<T> ::add(T value)
{
	// PRECONDITION: the bag must not be "full"
	assert(!isFull() && "Bag is full (in add)");

	m_container[m_size] = value; // store the pointer 
	m_size++;
}

template <class T>
T Bag<T> ::getOne()
{
	// PRECONDITION: the bag must not be empty when "getOne()" is called
	assert(!isEmpty() && "Bag is empty (in getOne)");


	//generate a random number between 0 and (m_size-1);
	unsigned int index = (unsigned int)(rand() % m_size);

	T value = m_container[index];
	m_container[index] = m_container[m_size - 1];

	m_size--;
	return value;
}

template <class T>
bool Bag<T> ::isEmpty() const
{
	return (m_size == 0);
}

template <class T>
bool Bag<T> ::isFull() const
{
	return (m_size == bagCapacity);
}

template <class T>
unsigned int Bag<T> ::currentSize() const
{
	return m_size;
}

template <class T>
unsigned int Bag<T> ::capacity() const
{
	return bagCapacity;
}

template <class T>
Bag<T> :: ~Bag()
{
	delete[] m_container;
}
