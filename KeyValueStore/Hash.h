#ifndef _HASH_H_
#define _HASH_H_

#include "LinkedList.h"
#include <vector>
#include<cassert>

struct Elements
{
	LinkedList<char*> elements;
};

class Hash 
{
public:
	Hash();
	Hash(size_t);
	~Hash();

	int Store(char* pBlock, size_t Size);
	bool Load(const char* pKey, char*& pBlock, size_t& Size);
	bool Erase(const char* pKey);

private:
	vector<Elements*> hashTable;//taking the pointers here
	int hashFunction(const char* pBlock);
	bool isBlockAlreadyAdded(char* pBlock, int key);
	bool isTaken(int);
	void destroy();

	size_t size;
};

#endif