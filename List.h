#pragma once
typedef int Datatype;
class List {
	Node * pHead;
	size_t size;

public:
	List();
	List(const List & otherList);
	~List();
	void insertFirst(Datatype data);
	void insertLast(Datatype data);
	void insert(Datatype data, size_t index=0);
	void removeFirst();
	void removeLast();
	void remove(size_t index);
	Datatype getFirst() const;
	Datatype getLast() const;
	Datatype get(size_t index) const;
	void setFirst(Datatype data);
	void setLast(Datatype data);
	void set(Datatype data, size_t index);
	size_t getSize() const;
	void clear();
	void print() const;
	bool isEmpty() const;
	List operator = (const List & otherList);
};
