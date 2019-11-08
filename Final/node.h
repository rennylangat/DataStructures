#pragma once
#include <iostream>
#include <string>

template <class T> class Node
{

public:
	T val;
	Node * link;

public:
	Node<T>() {
		//default value should be assigned by constructor for objects or zero if primitive
		link = nullptr;
	}

	Node<T>(T a, Node*l) {
		val = a;
		link = l;
	}
	void setvlue(T a) { val = a; }
	void setlink(Node<T>* l) { link = l; }
	T getvlue() const { return val; }
	Node<T>* getlink() const { return link; }
};