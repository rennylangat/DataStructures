#pragma once
#include <iostream>
#include <string>
#include "node.h"



template <class T> class LinkedList 
{
	public:
		LinkedList<T>() { head = NULL; count = 0; }
		virtual ~LinkedList<T>() {
			clear();
		}
		void traverse_list();
		Node<T>* append(T);
		Node<T>* insert(T);
		Node<T>* get_front();
		void delete_front();
		void delete_end();
		bool is_empty();
		Node<T>* insert_at(T x, int);
		bool delete_at(int);
		bool delete_by_val(T);
		int count_of_items();
		Node<T>* search(T);
		void clear();

	protected:
		Node<T>* head;
		int count;
};
// Fetching the list value/ or content.
template <class T>
void LinkedList<T>::traverse_list() {
	Node<T>* temp = head;
	while (temp != NULL) {
		std::cout << temp->val << std::endl;
		temp = temp->link;
	}
}
// Appending a new node to the end. Previous last node is 
// connecting with the new node and new node linking with the NULL.
// Pre:New node value T a 
// Post:Returns the new node object 
template <class T>
Node<T>* LinkedList<T>::append(T a) {
	Node<T>* temp_ptr = new Node<T>(a, NULL);
	count++;
	if (head == NULL) {
		head = temp_ptr;
		return temp_ptr;
	}
	Node<T>* temp_head = head;
	while (temp_head->link != NULL) {
		temp_head = temp_head->link;
	}
	temp_head->link = temp_ptr;
	return temp_ptr;
}
// Inserting a new node to the head of linked list. That new node is 
// linking with the previous head node. 
// Pre:New node value T a 
// Post:Returns the new node object
template <class T>
Node<T>* LinkedList<T>::insert(T a) {
	count++;
	Node<T>* temp_ptr = new Node<T>(a, NULL);
	temp_ptr->link = head;
	head = temp_ptr;
	return head;
}

// Deleting a node form the head of the linked list. Assigning next node 
// as head node object to the linked list. 
// Pre:None 
// Post:Returns new head node object
template <class T>
void LinkedList<T>::delete_front() {
	if (!head)
		return;
	Node<T>* temp_ptr = head;
	head = head->link;
	delete temp_ptr;
	count--;

	
}

// Returns front node
template <class T>
Node<T>* LinkedList<T>::get_front() {
	return head;
}

// Deleting a node form the tail of the linked list. Before 
// last node is now last node which is linking with the NULL.   
template <class T>
void LinkedList<T>::delete_end() {
	if (head == NULL) {
		return;
	}
	if (head->link == NULL) {
		delete head;
		count--;
		head = NULL;
		return;
	}
	Node<T>* temp_head = head;
	while (temp_head->link->link != NULL) {
		temp_head = temp_head->link;
	}
	delete temp_head->link;
	count--;
	temp_head->link = NULL;
}
// Checking list is empty or not
// If head node == NULL then it returns 'TRUE'
//else returns 'FALSE'
template <class T>
bool LinkedList<T>::is_empty() {
	bool r = false;
	if (head == NULL) {
		r = true;
	}
	return r;
}

// Inserting a node to a given position of the linked list. 
// Pre:Value- T x , position- int index
// Post:Returns the node inserted.
template <class T>
Node<T>*LinkedList<T>::insert_at(T x, int index) {
	if (index == 0) {
		return insert(x);
	}
	int i = 0;
	Node<T>* temp_head = head;
	while (temp_head != NULL) {
		if (i == index - 1) {
			count++;
			Node<T>* new_node = new Node<T>(x, NULL);
			new_node->link = temp_head->link;
			temp_head->link = new_node;
			return temp_head;
		}
		temp_head = temp_head->link;
		i++;
	}
	if (index > (i + 1)) {
		std::cout << "There is no such position " << std::endl;
	}
	return NULL;

}


// Deleting a node from a given position in the linked list. 
// Pre: position- int index
// Post:If it deletes existing index returns true
      //else returns false.
template <class T>
bool LinkedList<T>::delete_at(int index) {

	if (index == 0) {
		delete_front();
		return true;
	}
	int i = 0;
	Node<T>* temp_head = head;
	while (temp_head != NULL) {
		if (i == index - 1) {
			Node<T>* node = temp_head->link;
			temp_head->link = temp_head->link->link;
			count--;
			delete node;
			break;
		}
		i++;
		temp_head = temp_head->link;
	}


	if (index > (i + 1)) {
		std::cout << "There is no such position " << std::endl;
		return false;
	}
	else
	{
		return true;
	}

}

// Deleting a node from a given value in the linked list. 
// Pre: Value -T target
// Post:If it deletes existing value return true
      //else returns false.
template <class T>
bool LinkedList<T>::delete_by_val(T target) {
	Node<T>* temp_head = head;
//	Node<T>* temp_tail = tail;

	if (temp_head == NULL) {
		return true;
	}
	if (temp_head->val == target) {
		delete_front();
		return true;
	}
	bool ret = false;
	while (temp_head->link != NULL) {
		if (temp_head->link->val == target) {
			Node<T>* node = temp_head->link;
			temp_head->link = temp_head->link->link;
			count--;
			delete node;
			ret = true;
			break;
		}
		temp_head = temp_head->link;
	}
	return ret;
}
// Returns count of the list items
template <class T>
int LinkedList<T>::count_of_items() {
	return count;
}


// Searchs by the given value
// Pre: Value -T target
// Post:If it existing value returns the node object
template <class T>
Node<T>* LinkedList<T>::search(T target) {
	Node<T>* temp = head;
	if (temp == NULL) {
		return NULL;
	}
	while (temp != NULL) {
		if (temp->val == target) {
			return temp;
		}
		temp = temp->link;
	}
	return NULL;
}
// Zeroing out the current linked list. assigning NULL to the head pointer.
template <class T>
void LinkedList<T>::clear() {
	Node<T>* temp = head;

	while (temp != NULL) {
		Node<T>* new_temp = temp;
		temp = temp->link;
		delete new_temp;
	}
	count = 0;
	head = NULL;
}