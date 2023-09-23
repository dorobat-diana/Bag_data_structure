#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	//TODO - Implementation
    this->current = bag.hashTable[0];
}

void BagIterator::first() {
	//TODO - Implementation
    this->current = bag.hashTable[0];

}


void BagIterator::next() {
	//TODO - Implementation
    if(!this->valid())
        throw std::exception();
    this->current = this->current + 1;
}


bool BagIterator::valid() const {
	//TODO - Implementation
    if(this->current != -1)
        return true;
    return false;
}


TElem BagIterator::getCurrent() const
{
	//TODO - Implementation
    if(this->current == -1)
        throw std::exception();
    return this->current;
}
