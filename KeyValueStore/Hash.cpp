#include "Hash.h"
#include "HelpFunctions.h"
#include <fstream>
#include <string> 

Hash::Hash(size_t tableSize)
{
	size = tableSize;
	for(int i = 0; i < tableSize; i++)
	{
		Elements* newBlock = new Elements();
		hashTable.push_back(newBlock);
	}
}

int Hash::hashFunction(const char* pBlock)
{
	long hash = 0;
	size_t size = strlen(pBlock);

	for(int i = 0; i < size; i++)
	{
		hash += (int)pBlock[i];
		hash += hash*10;
		pow(hash,hash/6);

	}
	hash += hash*3;
	pow(hash,hash/11);
	hash += hash*15;

	cout<< "Result from the generated hash: " << hash%hashTable.size() << endl;

	return hash%hashTable.size();
}

bool Hash::isTaken(int key)
{
	if(hashTable[key]->elements.isEmpty())
	{
		return false;
	}else
		return true;
}

bool Hash::isBlockAlreadyAdded(char* pBlock, int key)
{
	Element<char*>* elementsToCheck = hashTable[key]->elements.getStart();

	while(elementsToCheck != NULL)
	{
		// move this to separate method called equals in Element
		if(elementsToCheck->value == pBlock)
		{
			return true;
		}
		elementsToCheck = elementsToCheck->next;
	}

	return false;
}

int Hash::Store(char* pBlock, size_t Size)
{
	int key = hashFunction(pBlock);

	if(isTaken(key))//it's all cool
	{
		//still don't know what to do here, maybe try to take another cell 
		// take if the block is the same and if it is do nothing
		// TODO test and debug here!
		if(isBlockAlreadyAdded(pBlock,key))
		{
			cout<<"This block is already added to key " << key <<endl;
			return key;
		}
	}

	//if there is something to put in no mater if the key is the same we put it on this key in the eventualy the next element in list
	hashTable[key]->elements.insertBack(pBlock);
	
	char* name = convertIntToString(key);
	fstream file = fstream(name, ios::out | ios::in | ios::app); // | ios::trunc);

	if (!file)
	{
		cout << "Error.Bad file!";
		return -1;
	}

	if(!writeInFile(file, hashTable[key]))
	{
		cout<<"Elements coudn't be saved plase try again"<<endl;
		return -1;
	}

	return 0;
}

bool Hash::Load(const char* pKey, char*& pBlock, size_t& Size)
{
	/-
}

void Hash::destroy()
{
	for(int i = 0; i < size; i++)
	{
		Elements* elem = hashTable[i];
		delete elem;
		hashTable[i] = NULL;
	}
}

Hash::~Hash()
{
	destroy();
}