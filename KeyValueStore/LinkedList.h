#ifndef LINKED_LIST
#define LINKED_LIST

#include<iostream>
using namespace std;

template<class T>
struct Element{
	Element * next;
	T value;

	Element()
	{
		value = T();
		next = NULL;
	}
	Element(T x)
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

	Element<T>* Iter(Element<T>*);
	void print()const;
	void insertBack( T);
	void insertFront(T);
	void deleteElem(int);

	int getSize()const;
	Element<T>* getStart()const;
	Element<T>* getEnd()const;
	bool isEmpty();
	~LinkedList<T>();

private:

	void copy(const LinkedList<T> & );
	void free();

	Element<T>* start;
	Element<T>* end;

};

template<class T>
LinkedList<T>::LinkedList(){
	start = NULL;
	end = NULL;
}
	
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other){

	if(this != &other){
		copy(other);
	}else
		return;
}
	
template<class T>
void LinkedList<T>::copy(const LinkedList<T> & other)
{
		item<T> * current = new (nothrow)item<T>;//current Elements of new list
	if (current == NULL && other.getStart()==NULL)
	{
		cout << "Error!" << endl;
		return;
	}

	current->value=other.start->value;//get content of object.start
	end = start = current;

	Element * temp = other.start;//iterating Elements of object
	if (current != NULL)
	{
		while (temp->next != NULL)
		{
			current->next = new (nothrow)item;//create new node for our next
			current = current->next;//come in our new Elements
			
			temp = temp->next;//get next Elements from object

			current->value = temp->value;
			
			end = current;
			end->next = NULL;
		}
	}
}
	
template<class T>
void LinkedList<T>::print()const
{
	Element<T>* nextItem  = start;

	while(nextItem != NULL){

		cout<<nextItem->value<<endl;
		nextItem = nextItem->next;
	}
}
	
template<class T>
void LinkedList<T>::insertBack(T newValue)
{

	Element<T>* newItem = new (nothrow)Element<T>;
	newItem ->value = newValue;
	newItem->next = NULL;

	if (start == NULL) {
		start = newItem;
		end = newItem;
	}
	else if (start == end) {
		start->next = newItem;
		end = newItem;
	}
	else {

		end->next = newItem;
		end = end->next;
	}

}
	
template<class T>
void LinkedList<T>::insertFront(T newValue)
{

	Element<T>* newItem = new (nothrow)Element<T>;

	if (newItem == NULL)
	{
		cout << "Error: memory could not be allocated";
	}

	newItem->next = start;
	start = newItem;
	newItem->value = newValue;

}
	
template<class T>
void LinkedList<T>::deleteElem(int pos){

	Element<T>* temp = new (nothrow)item;
	temp = start;
	int i = 0;

	while (i < pos -1) {
		temp = temp->next;
		pos++;
	}

	// the next one is the element we wan to erace
	temp->next = (temp->next)->next;

}

template<class T>
int LinkedList<T>::getSize()const{

	int counter = 0;
	Element<T>* temp = new (nothrow)item;
	temp = start;

	if (temp == NULL){
		cout << "Error: memory could not be allocated";
		return 1;
	}

	while(temp != NULL){
		temp = temp->next;
		counter++;
	}
	delete temp;
	return counter;

}
	
template<class T>
Element<T>* LinkedList<T>::getStart()const{
	return start;
}
	
template<class T>
Element<T>* LinkedList<T>::getEnd()const{
	return end;
}
	
template<class T>
bool LinkedList<T>::isEmpty()
{
	if(start == NULL || end == NULL)
		return true;
	else
		return false;
}
	
template<class T>
LinkedList<T>::~LinkedList(){
	free();
}
	
template<class T>
void LinkedList<T>::free(){

	Element<T> * toDel = start;

	if(toDel != NULL) {//if list is not empty
		while(toDel != NULL){

			Element<T>* p = toDel;
			toDel = toDel->next;
			delete p;
		}
	}
	end = NULL;
	start = NULL;

}


#endif