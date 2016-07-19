#include"Hash.h"
#include <fstream>

int writeInFile(fstream& file, Item<char*>* element)
{
	file << element->value;
	file << endl;
	if (!file)
	{
		cout << "Error.Bad file!";
		return -1;
	}

	return 0;
}

int Hash::hashFunction(const char* pBlock)
{
	long hash = 0;
	size_t size = strlen(pBlock);

	for(int i = 0; i < size; i++){
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

char* Hash::Store(const char* pBlock, size_t Size)
{

	int key = hashFunction(pBlock);
	Item<char*>* newItem = new  (nothrow)Item<char*>;

}