#ifndef HELPFUNCTIONS_H
#define HELPFUNCTIONS_H

#include "Hash.h"
#include <vector>
#include <cassert>
#include <fstream>
#include <string> 

int writeInFile(fstream& file, Elements* elem)
{
	//write the last element the previous are added
	// Later make the function back to char*
	Element<char*> * el = elem->elements.getEnd(); //Element<char*> * el = elem->elements.getStart();
	//while(el != NULL)
	//{
		file << el->value;
		file << endl;
		//el = el->next;
	//}
	if (!file)
	{
		cout << "Error.Bad file!";
		return 0;
	}

	return 1;
}

char* convertIntToString(int key)
{
	size_t size = 2;
	int counter = key;
	while(counter>10)
	{
		counter = counter/10;
		size++;
	}
	
	char* newString = new char[size];
	for(int i = size-2; i>=0;i--)
	{
		newString[i] = key%10 + '0';
		key = key/10;
	}

	newString[size-1] = '\0';
	return newString;
}

string loadFromFile(fstream& file, char* key)
{
	return NULL;
}

#endif