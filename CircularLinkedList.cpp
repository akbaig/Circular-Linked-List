#include <iostream>

using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template <class Type>
class circularLinkedList
{
	private:
		nodeType<Type> *first;
		int count;
		
	public:
		circularLinkedList();
		void initializeList();
		bool isEmptyList() const;
		void destroyList();
		void print() const;
		int length() const;
		int search(const Type& searchItem) const;
		void insert(const Type& insertItem);
		void deletenode(const Type& deleteItem);
		void copyList(const circularLinkedList<Type>& otherList);
};

template <class Type>
circularLinkedList<Type>::circularLinkedList() 
{
	first = NULL;
	count = 0;
}
template <class Type>
int circularLinkedList<Type>::length() const 
{
	return count;
}

template <class Type>
void circularLinkedList<Type>::initializeList()
{
	destroyList();
}

template <class Type>
void circularLinkedList<Type>::deletenode(const Type& deleteItem)
{
	nodeType<Type> *current, *previous; 
	current = first->link;
	previous = first;
	int counter = 0;
	while(counter != count)
	{
		if(current->info == deleteItem)
		{
			if(current == first)
				first = previous;
			previous->link = current->link;
			delete current;
			count--;
			if(count == 0) first = NULL;
			break;
		}
		previous = current;
		current = current->link;
		counter++;
	}
}

template <class Type>
void circularLinkedList<Type>::destroyList()
{
	nodeType<Type> *current, *temp; 
	current = first->link; 
	if(first == first->link)// there is only one node
	{
		delete first;
		first = NULL;
	}
	else //multiple nodes
	{	
		do
		{
			temp = current->link;
			delete current;
			current = temp;
			
		} while(current != first->link);
		first->link = NULL;
		first = NULL;
	}
	count = 0;
}
template <class Type>
void circularLinkedList<Type>::insert(const Type& insertItem)
{
	nodeType<Type> *newnode = new nodeType<Type>;
	newnode->info = insertItem;
	if(first == NULL)
	{
		first = newnode;
		newnode->link = first;
	}
	else
	{
		newnode->link = first->link;
 		first->link = newnode;
	}
	count++;
}

template <class Type>
int circularLinkedList<Type>::search(const Type& searchItem) const
{
    if(!isEmptyList())
    {
    	nodeType<Type> *iterator = first->link;
    	int counter = 0;
    	do
    	{
    		if(iterator->info == searchItem) 
    			return counter;
    		iterator = iterator->link;
    		counter++;
    		
    	}while(iterator != first->link);
    }
    return -1;
}

template <class Type>
bool circularLinkedList<Type>::isEmptyList() const
{
	return (first == NULL);
}
template <class Type>
void circularLinkedList<Type>::print() const
{
    if(!isEmptyList())
    {
		nodeType<Type> *current; 
		current = first->link; 
		do
		{
			cout << current->info << " ";
			current = current->link;
		} while(current != first->link);

    
    }
}
template <class Type>
void circularLinkedList<Type>::copyList(const circularLinkedList<Type>& otherList)
{
    nodeType<Type> *newNode; 
    nodeType<Type> *current;
	nodeType<Type> *last; 
    if (first != NULL) 
    	destroyList();
    if (otherList.first == NULL) 
    {
	    first = NULL;
	    count = 0;
    }
    else
    {
	    current = otherList.first; 
	    count = otherList.count;
	    first = new nodeType<Type>;
	    first->info = current->info;
	    first->link = NULL; 
		last = first;
	    current = current->link;
	    while (current != otherList.first)
	    {
	        newNode = new nodeType<Type>; 
	        newNode->info = current->info;
	        last->link = newNode;
	        last = newNode;
			current = current->link;
		}
		last->link = first;
	}
}
int main()
{
	circularLinkedList<int> C;
	C.insert(12);
	C.insert(14);
	C.insert(16);
	C.print();
	cout << endl;
	C.destroyList();
	C.print();
	C.insert(16);
	C.insert(14);
	C.insert(12);
	C.print();
	cout << endl;
	C.deletenode(14);
	C.deletenode(16);
	C.print();
	circularLinkedList<int> D;
	D.copyList(C);
    D.print();
	return 0;
}
