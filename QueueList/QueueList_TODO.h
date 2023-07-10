#include "QueueList.h"
//! \file QueueList_TODO.h
//! \brief Defines the <code>fullsail_ai::data_structures::QueueList</code> class template
//! implementation.
//! \author Cromwell D. Enage
#ifndef _FULLSAIL_AI_FUNDAMENTALS_QUEUELIST_TODO_H_
#define _FULLSAIL_AI_FUNDAMENTALS_QUEUELIST_TODO_H_

namespace fullsail_ai { namespace fundamentals {

	//! \TODO
	//!   - Complete the definition of the <code>QueueList::Iterator</code> pre-increment operator.
	//!   - Complete the definition of the <code>QueueList::Iterator</code> dereference operator.
	//!   - Define the <code>QueueList</code> constructor.
	//!   - Define the <code>QueueList</code> destructor.
	//!   - Define the <code>QueueList</code> methods.


	template <typename T>
	typename QueueList<T>::Iterator& QueueList<T>::Iterator::operator++()
	{
		// TODO: Complete the definition of this operator.
		currentNode = currentNode->next;
		return *this;
	}

	template <typename T>
	T QueueList<T>::Iterator::operator*() const
	{
		// TODO: Complete the definition of this operator.
		return currentNode->data;
	}

	template<typename T>
	inline QueueList<T>::QueueList()
	{
		// Set the front & back
		front = nullptr;
		back = nullptr;
	}

	template<typename T>
	inline QueueList<T>::~QueueList()
	{
		// Delete all Nodes
		removeAll();
	}

	template<typename T>
	inline bool fundamentals::QueueList<T>::isEmpty() const
	{
		// If the Linkes list is empty
		if (front == nullptr)
		{
			return true;
		}
		// If not empty
		return false;
	}

	template<typename T>
	inline void QueueList<T>::enqueue(T element)
	{
		// If Linked list is empty
		if (this->isEmpty())
		{
			// Create a new Node to add to the list
			Node* newNode = new Node(element);
			front = newNode;
			back = front;
			back->next = nullptr;
		}
		// IF the list contains Nodes
		else
		{
			Node* newNode = new Node(element);
			back->next = newNode;
			back = newNode;
		}
	}

	template<typename T>
	inline T QueueList<T>::getFront() const
	{
		// return the element at the front of the list
		return front->data;
	}

	template<typename T>
	inline void QueueList<T>::dequeue()
	{
		// If there's only one Node
		if (front == back)
		{
			front->data = nullptr;

			delete front;

			front = NULL;
			back = NULL;
			return;
		}

		// Move the head pointer to the next node to delete
		Node* temp = front;
		front = front->next;

		// Delete the node
		delete temp;
	}

	template<typename T>
	inline void QueueList<T>::removeAll()
	{
		// Iterate thorugh the Linked list
		while (front != nullptr)
		{
			// Move front the next element in the list
			Node* temp = front;
			front = front->next;

			// Delete the curr_node
			delete temp;
		}
	}

	template<typename T>
	inline bool QueueList<T>::contains(T element) const
	{
		// Point to the current node
		Node* current = front;

		// Loop through the Linked list
		while (current != NULL)
		{
			// If element found in list return true
			if (current->data == element)
			{
				return true;
			}

			// Iterate to the next Node
			current = current->next;
		}

		// If element not found
		return false;
	}

	template<typename T>
	inline void QueueList<T>::remove(T element)
	{
		// Node to delete
		Node* currNode = front;

		// Node used to reLink the list
		Node* prevNode = nullptr;

		// If the currNode is the only Node
		if (currNode->data == element && currNode == front && currNode->next == nullptr)
		{
			delete currNode;

			front = nullptr;
			back = nullptr;
			return;
		}

		while (currNode != nullptr )
		{
			// elment found
			if (currNode->data == element)
			{
				// If the currNode is the front 
				if (currNode == front)
				{
					front = currNode->next;

					delete currNode;
					break;
				}
				// If the currNode is the back
				else if (currNode == back)
				{
					back = prevNode;
					prevNode->next = nullptr;

					delete currNode;
					break;
				}
				// IF the currNode is any Node in between
				else
				{
					// element is in the list
					prevNode->next = currNode->next;

					delete currNode;
					break;
				}
				
			}
			
			// Keeping going through the list
			prevNode = currNode;
			currNode = currNode->next;

			// If the end of the list is reached
			if (prevNode->next == nullptr)
			{
				break;
			}
		}
	}
	




}}  // namespace fullsail_ai::fundamentals

#endif  // _FULLSAIL_AI_FUNDAMENTALS_QUEUELIST_TODO_H_

