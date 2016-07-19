#ifndef _HASH_H_
#define _HASH_H_

#include <vector>
using namespace std;
#include<cassert>
#include "LinkedList.h"

struct Element
{
	bool isEmpty;
	LinkedList<char*> element;

};

class Hash 
{
public:
	Hash();
	~Hash();

	char* Store(const char* pBlock, size_t Size);
	bool Load(const char* pKey, char*& pBlock, size_t& Size);
	bool Erase(const char* pKey);

private:
	vector<Element> hashTable;
	int hashFunction(const char* pBlock);
};

#endif