#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	//TODO - Implementation
    this -> capacity = 10;
    this -> numOfElements = 0;
    this -> hashTable = new int*[capacity];
    for(int i = 0; i < capacity; i++)
        hashTable[i] = nullptr;
}


void Bag::add(TElem elem) {
	//TODO - Implementation
    if(this->numOfElements >= 0.66 * this->capacity)
    {
        this->rehash();
    }
    int index = this->hashFunction(elem);
    if (this->hashTable[index] == nullptr) {
        this->hashTable[index] = &elem;
    } else while(this->hashTable[index] != nullptr) {
            for (int j = 0; j < this->capacity; j++) {
                int aux = (index + j * j) % (this->capacity * 2);
                if (hashTable[aux] == nullptr) {
                    index = aux;
                    break;
                }
            }
        }
    this->numOfElements++;
}


bool Bag::remove(TElem elem) {
	//TODO - Implementation
	    int index = this->hashFunction(elem);
    if (this->hashTable[index] == &elem) {
        this->hashTable[index] = nullptr;
        this->numOfElements--;
        return true;
    } else {
        int j = 0;
        while (this->hashTable[index] != &elem && j < this->capacity) {
            int aux = (index + j * j) % (this->capacity * 2);
            if (hashTable[aux] == &elem) {
                return true;
            }
            j++;
        }
    }
    return false;
}


bool Bag::search(TElem elem) const {
	//TODO - Implementation
    int index = this->hashFunction(elem);

    if (this->hashTable[index] == &elem) {
        return true;
    } else {
        int j = 0;
        while (this->hashTable[index] != &elem && j < this->capacity) {
            int aux = (index + j * j) % (this->capacity * 2);
            if (hashTable[aux] == &elem) {
                return true;
            }
            j++;
        }
    }
    return false;
}

int Bag::nrOccurrences(TElem elem) const {
	//TODO - Implementation
    int nrOcc = 0;
    int index = this->hashFunction(elem);
    if (this->hashTable[index] == &elem) {
        nrOcc++;
    } else {
        int j = 0;
        while (this->hashTable[index] != &elem && j < this->capacity) {
            int aux = (index + j * j) % (this->capacity * 2);
            if (hashTable[aux] == &elem) {
                nrOcc++;
            }
            j++;
        }
    }
    return nrOcc;
}


int Bag::size() const {
	//TODO - Implementation
	return this->numOfElements;
}


bool Bag::isEmpty() const {
	//TODO - Implementation
	if (this->numOfElements == 0)
        return true;
    return false;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	//TODO - Implementation
    delete[] this -> hashTable;
}

int Bag::hashFunction(TElem e) const {
    int i = 0;
    i= e % this->capacity;
    return i;
}

void Bag::rehash() {
    int **newHashTable = new int*[this->capacity * 2];
    for(int i = 0; i < this->capacity * 2; i++)
        newHashTable[i] = nullptr;
    for(int i = 0; i < this->capacity; i++)
    {
        if(this->hashTable[i] != nullptr)
        {
            int index = this->hashFunction(this->hashTable[i]);
            while(newHashTable[index] != nullptr)
                for (int j = 0; j < this->capacity; j++) {
                    int aux = (index + j * j) % (this->capacity * 2);
                    if (newHashTable[aux] == nullptr) {
                        index = aux;
                        break;
                    }
                }
            }
            newHashTable[index] = this->hashTable[i];
        }
    }
    delete[] this->hashTable;
    this->hashTable = newHashTable;
    this->capacity *= 2;
}

