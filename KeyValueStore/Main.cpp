#include"Hash.h"	

int main()
{	/*
	LinkedList<char*> list;
	list.insertBack("2");
	list.insertFront("1");
	list.print();
	*/

	Hash hash(11);

	char* name = "rfg";

	hash.Store(name,4);
	hash.Store(name,4);
	hash.Store("fbvdfb",4);
	hash.Store("fdbdfbdfngdfxfdc",4);
	hash.Store("kkeldw",4);


	return 0;
}