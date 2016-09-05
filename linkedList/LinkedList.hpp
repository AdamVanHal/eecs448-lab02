/**
*	@author Adam Van Hal
*	@date August 30 2016
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
        /**
                ~Done
	*/
        return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
        //check if the list is empty, empty list will not have value
        if (isEmpty()){
            return (false);
        }

	Node<T>* temp = m_front;
	bool isFound = false;
	
	if(temp->getValue() == value) //test if the first vlaue of the list is the correct value
	{
		isFound = true;
		return(isFound);
	}
	while(temp->getNext() != nullptr) //Check all remaining values of the list
	{
		temp = temp->getNext();
		if(temp->getValue() == value)
		{
			isFound = true;
			break;
		}
		
	}

	/**
  	Done 
	*/

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	/** TODO 
		Done
	*/

	if(isEmpty()) //you can't remove the last element of an empty list
	{
		isRemoved = false;	
	}
	else if(size() == 1) //Check if there is only one element in the list, if so, just remove it
	{
		lastNode = m_front;
		m_front = nullptr; //Set the pointer to the front to null
		delete lastNode; //delete the only node
		m_size--;
		isRemoved = true;
	}
	else //find second to last element in list, break chain, delete last element
	{
		lastNode = m_front;
		while(lastNode->getNext() != nullptr) //step to the end of the list
		{
			secondintoLast = lastNode; //track second to last node
			lastNode = lastNode->getNext(); //get next node
		}

		secondintoLast->setNext(nullptr);
		delete lastNode;
		m_size--; //correct the size of the list
		isRemoved = true;
	}

	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
