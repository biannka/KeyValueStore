#ifndef LINKED_LIST
#define LINKED_LIST

#include<iostream>
using namespace std;

template<class T>
struct Item{
	Item * next;
	T value;

	Item()
	{
		value = T();
		next = NULL;
	}
	Item(T x)
	{
		value = x;
		link = NULL;
	}
};

template<class T>
class LinkedList{
public:
	LinkedList();
	LinkedList(const LinkedList<T>&);
	LinkedList<T>& operator=(const LinkedList<T>&);

	Item<T>* Iter(item<T>*);
	void print()const;
	void insertBack(T);
	void insertFront(T);
	void deleteElem(int);

	int getSize()const;
	Item<T>* getStart()const;
	Item<T>* getEnd()const;
	bool isEmpty()const;
	~LinkedList<T>();

private:

	void copy(const LinkedList<T> & );
	void free();

	Item<T>* start;
	Item<T>* end;

};

#endif