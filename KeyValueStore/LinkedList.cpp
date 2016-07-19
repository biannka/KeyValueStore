#include"LinkedList.h"

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
	void LinkedList<T>::copy(const LinkedList<T> & other){
		item<T> * current = new (nothrow)item<T>;//current element of new list
	if (current == NULL && other.getStart()==NULL)
	{
		cout << "Error!" << endl;
		return;
	}

	current->value=other.start->value;//get content of object.start
	end = start = current;

	Item * temp = other.start;//iterating element of object
	if (current != NULL)
	{
		while (temp->next != NULL)
		{
			current->next = new (nothrow)item;//create new node for our next
			current = current->next;//come in our new element
			
			temp = temp->next;//get next element from object

			current->value = temp->value;
			
			end = current;
			end->next = NULL;
		}
	}
	}
	
	template<class T>
	void LinkedList<T>::print()const{
		Item<T>* nextItem  = start;

		while(nextItem != NULL){

			cout<<nextItem->value<<endl;
			nextItem = nextItem->next;
		}
	}
	
	template<class T>
	void LinkedList<T>::insertBack(T newValue){

		Item<T>* newItem = new (nothrow)item<T>;
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
	void LinkedList<T>::insertFront(T newValue){

		Item<T>* newItem = new (nothrow)item<T>;

		if (newItem == NULL){
			cout << "Error: memory could not be allocated";
		}

		newItem->next = start;
		start = newItem;
		newItem->value = newValue;

	}
	
	template<class T>
	void LinkedList<T>::deleteElem(int pos){

		Item<T>* temp = new (nothrow)item;
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
		Item<T>* temp = new (nothrow)item;
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
	Item<T>* LinkedList<T>::getStart()const{
		return start;
	}
	
	template<class T>
	Item<T>* LinkedList<T>::getEnd()const{
		return end;
	}
	
	template<class T>
	bool LinkedList<T>::isEmpty()const{
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

		Item<T> * toDel = start;

		if(toDel != NULL) {//if list is not empty
			while(toDel != NULL){

				Item<T>* p = toDel;
				toDel = toDel->next;
				delete p;
			}
		}
	   end = NULL;
	   start = NULL;

	}

	int main(){
		
		
		LinkedList<char*> list;
		list.insertBack("2");
		list.insertFront("1");
		list.print();

		return 0;
	}