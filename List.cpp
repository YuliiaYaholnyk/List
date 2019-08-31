#include "Node.h"
#include "List.h"
#include<iostream>

List::List() : pHead(nullptr), size(0) {};

List::List(const List & otherList) {
	this->pHead = new Node(otherList.getFirst());
	for (Node* pCur = otherList.pHead; pCur != nullptr; pCur = pCur->getpNext()) {
		Node* pNew = new Node(pCur->getData());
		pCur = pNew;
		pNew->setpNext(nullptr);
	}
	size = otherList.size;
}

List::~List() {
	Node* pNext;
	for (Node* pCur = pHead; pCur != nullptr; pCur = pNext) {
		pNext = pCur->getpNext();
		delete[] pCur;
	}
}


void List::insertFirst(Datatype data) {
	Node* pCur = pHead;
	pHead = new Node(data, pHead);
	pHead->setpNext(pCur);
	size++;
}

void List::insertLast(Datatype data) {
	
		Node* pTail = nullptr;
		Node* pNew = new Node(data);
		pNew->setpNext(nullptr);
		for (Node* pCur = pHead; pCur != nullptr; pCur = pCur->getpNext()) {
			if (pCur->getpNext() == nullptr) {
				pTail = pCur;
			}
		}
		pTail->setpNext(pNew);
		size++;
	
}

void List::insert(Datatype data, size_t index) {
	if ((pHead == nullptr)) {
		pHead = new Node(data, pHead);
		pHead->setpNext(nullptr);
		size++;
	}
	else {
		Node* pMid = nullptr;
		Node* pNew = new Node(data);
		Node* pCur = pHead;
		for (size_t i = 0; i < index; i++) {
			if (index == i + 1) {
				pMid = pCur;
			}
			pCur = pCur->getpNext();
		}
		pMid->setpNext(pNew);
		pNew->setpNext(pCur);
		size++;
	}
}

void List::removeFirst() {
	if (pHead == nullptr) {
		return;
	}
	Node* temp = pHead;
	pHead = pHead->getpNext();
	delete temp;
	size--;
}

void List::removeLast() {
	if (pHead == nullptr) {
		return;
	}
	else {
		Node* pTail = nullptr;
		for (Node* pCur = pHead; pCur->getpNext() != nullptr; pCur = pCur->getpNext()) {
			pTail = pCur;
		}
		delete pTail->getpNext();
		pTail->setpNext(nullptr);
		size--;
	}
}

void List::remove(size_t index) {
	if (pHead == nullptr) {
		return;
	}
	else {
		Node* pPrev = nullptr;
		Node* pNext = nullptr;
		Node* pCur = pHead;
		for (size_t i = 0; i < index; i++) {
			if (index == i + 1) {
				pPrev = pCur;
				pNext = pCur->getpNext();
			}
			pCur = pCur->getpNext();
		}
		pPrev->setpNext(pNext->getpNext());
		delete pNext;
		size--;
	}
}

Datatype List::getFirst() const {
	return pHead->getData();
}

Datatype List::getLast() const {
	Node* pTail = nullptr;
	for (Node* pCur = pHead; pCur != nullptr; pCur = pCur->getpNext()) {
		pTail = pCur;
	}
	return pTail->getData();
}

Datatype List::get(size_t index) const {
	Node* pMid = nullptr;
	Node* pCur = pHead;
	for (size_t i = 0; i < index; i++) {
		if (index == i + 1) {
			pMid = pCur->getpNext();
		}
		pCur = pCur->getpNext();
	}
	return pMid->getData();
}

void List::setFirst(Datatype value) {
	pHead->setData(value);
}

void List::setLast(Datatype value) {
	Node* pTail = nullptr;
	for (Node* pCur = pHead; pCur != nullptr; pCur = pCur->getpNext()) {
		pTail = pCur;
	}
	pTail->setData(value);
}

void List::set(Datatype value, size_t index) {
	Node* pMid = nullptr;
	Node* pCur = pHead;
	for (size_t i = 0; i < index; i++) {
		if (index == i + 1) {
			pMid = pCur->getpNext();
		}
		pCur = pCur->getpNext();
	}
	pMid->setData(value);
}

size_t List::getSize() const {
	return size;
}

void List::clear() {
	Node* pNext;
	for (Node* pCur = pHead; pCur != nullptr; pCur = pNext) {
		pNext = pCur->getpNext();
		delete[] pCur;
	}
	pHead = nullptr;
	size = 0;
}

void List::print() const {
	for (Node* pCur = pHead; pCur != nullptr; pCur = pCur->getpNext()) {
		std::cout << pCur->getData() << ' ';
	}
	std::cout << std::endl;
}

bool List::isEmpty() const {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

List List:: operator=(const List & otherList) {
	if (this->pHead==otherList.pHead)
	{
		return *this;
	}
	this->clear();
	for (Node * pCur = otherList.pHead; pCur != nullptr; pCur = pCur->getpNext()) {
		this->insertLast(pCur->getData());
	}
	size = otherList.size;
	return *this;
}
