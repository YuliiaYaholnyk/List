#pragma once
typedef int Datatype;


class Node {
private:
	Datatype data;
	Node* pNext;
public:
	Node(const Datatype& _data = Datatype(), Node* _pNext = nullptr);
	void setData(const Datatype& _data);
	Datatype getData()const;
	void setpNext(Node* _pNext);
	Node* getpNext();
	const Node* getpNext()const;
};
