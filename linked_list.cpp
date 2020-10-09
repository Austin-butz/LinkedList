
#include "linked_list.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename T> 
void LinkedList<T>::push_back(T item){
	Node<T> *n = new Node<T>;
	n->data = item;
	numItems++;
	

	if(head == nullptr){
		head = n;
		tail = n;
		return;
	}

	tail->next = n;
	n->prev = tail;
	tail = n;	
}

template <typename T>
void LinkedList<T>::insert(size_t pos, T item) {
	size_t i = 0;
	Node<T> *current = head;
	Node<T> *newnode = new Node<T>;
	newnode->data = item;
	for (size_t i = 1; i < pos; i++) current = current->next;
	Node<T>* nextnode = current->next;
	current->next = newnode;
	nextnode->prev = newnode;
	newnode->next = nextnode;
	newnode->prev = current;
	numItems += 1;
}

template <typename T>
void LinkedList<T>::push_front(T item){
	Node<T> *n = new Node<T>;
	n->data = item;
	numItems++;

	if(head == nullptr){
		head = n;
		tail = n;
		return;
	}

	head->prev = n;
	n->next = head;
	head = n;
}


template <typename T>
T LinkedList<T>::at(size_t idx){
	if(idx >= numItems){
		throw std::invalid_argument("List index out of range: " + std::to_string(idx));
	}

	Node<T> *n = get_node(idx);
	return n->data;
}


template <typename T>
Node<T> *LinkedList<T>::get_node(size_t idx){

	size_t i = 0;
	Node<T> *cur = head;
	while(i < idx){
		cur = cur->next;
		i++;
	}

	return cur;
}



