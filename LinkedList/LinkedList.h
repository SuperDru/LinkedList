#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

template <typename T>
struct Node{
public:
	T value;
	Node *next,
		 *prev;

	Node(T value, Node* next, Node* prev) :
		value(value),
		next(next),
		prev(prev) {}
};

template <typename T>
class LinkedList{
private:
	int size;
	Node<T> *head, *tail;
public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	void add(T value) noexcept{
		Node<T> *node = new Node<T>(value, nullptr, tail);
		if (size == 0) 
			head = node;
		else 
			(*tail).next = node;
		tail = node;
		size++;
	}

	void addBegin(T value) noexcept{
		Node<T> *node = new Node<T>(value, head, nullptr);
		if (size == 0)
			tail = node;
		else
			tail->prev = node;
		head = node;
		size++;
	}

	int indexOf(T value) noexcept{
		Node<T> *node = head;
		int i = 0;
		while (i++ != size) {
			if (node->value == value)
				return --i;
			node = node->next;
		}
		return -1;
	}

	T& get(int index) throw(){
		if (index < 0 || index >= size)
			throw out_of_range("Index out of range of the list");
		Node<T> *node = head;
		for (int i = 0; i < index; i++) {
			node = node->next;
		}
		return node->value;
	}

	void remove(int index) throw(){
		if (index < 0 || index >= size)
			throw out_of_range("Index out of range of the list");
		if (index == 0) {
			head = head->next;
			if (head != nullptr)
				head->prev = nullptr;
		}
		else if (index == size - 1) {
			tail = tail->prev;
			if (tail != nullptr)
				tail->next = nullptr;
		}
		else{
			Node<T> *node = head;
			for (int i = 0; i < index; i++) {
				node = (*node).next;
			}
			(*(*node).prev).next = (*node).next;
			(*(*node).next).prev = (*node).prev;
		}
		size--;
	}

	int getSize() {
		return size;
	}

	~LinkedList() {
	}
};

