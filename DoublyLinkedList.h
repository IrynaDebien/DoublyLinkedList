#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

template<typename T>
class Node {
public:
	T data;
	Node* next;
	Node* prev;

	Node(T d) : data(d), next(nullptr), prev(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
private:
	Node<T>* head;
	Node<T>* tail;

public:
	DoublyLinkedList() : head(nullptr), tail(nullptr) {}
	~DoublyLinkedList();

	void addToEnd(T data);
	Node<T>* clone() const;
	Node<T>* operator+(const DoublyLinkedList& other) const;
	Node<T>* operator*(const DoublyLinkedList& other) const;
	void initializeListFromNode(Node<T>* headNode, DoublyLinkedList<T>& list) const;
	void display() const;
	void swapHeadAndTail();
};

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	Node<T>* current = head;
	while (current != nullptr) {
		Node<T>* next = current->next;
		delete current;
		current = next;
	}
}

template<typename T>
void DoublyLinkedList<T>::addToEnd(T data) {
	Node<T>* newNode = new Node<T>(data);
	if (tail == nullptr) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

template<typename T>
Node<T>* DoublyLinkedList<T>::clone() const {
	DoublyLinkedList<T>* newList = new DoublyLinkedList<T>();
	Node<T>* current = head;
	while (current != nullptr) {
		newList->addToEnd(current->data);
		current = current->next;
	}
	return newList->head;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::operator+(const DoublyLinkedList& other) const {
	DoublyLinkedList<T>* newList = new DoublyLinkedList<T>();
	Node<T>* current = head;
	while (current != nullptr) {
		newList->addToEnd(current->data);
		current = current->next;
	}
	current = other.head;
	while (current != nullptr) {
		newList->addToEnd(current->data);
		current = current->next;
	}
	return newList->head;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::operator*(const DoublyLinkedList& other) const {
	DoublyLinkedList<T>* newList = new DoublyLinkedList<T>();
	Node<T>* current = head;
	while (current != nullptr) {
		Node<T>* otherCurrent = other.head;
		while (otherCurrent != nullptr) {
			if (current->data == otherCurrent->data) {
				newList->addToEnd(current->data);
				break;
			}
			otherCurrent = otherCurrent->next;
		}
		current = current->next;
	}
	return newList->head;
}

template<typename T>
void DoublyLinkedList<T>::initializeListFromNode(Node<T>* headNode, DoublyLinkedList<T>& list) const {
	Node<T>* current = headNode;
	while (current != nullptr) {
		list.addToEnd(current->data);
		current = current->next;
	}
}

template<typename T>
void DoublyLinkedList<T>::display() const {
	Node<T>* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

template<typename T>
void DoublyLinkedList<T>::swapHeadAndTail() {
	Node<T>* current = head;
	Node<T>* prev = nullptr;
	Node<T>* next = nullptr;

	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}

	Node<T>* temp = head;
	head = tail;
	tail = temp;
}
