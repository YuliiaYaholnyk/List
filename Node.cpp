#include "Node.h"

Node::Node(const Datatype& _data, Node* _pNext) {
	data = _data;
	pNext = _pNext;
}
void Node::setData(const Datatype& _data) {
	data = _data;
}
Datatype Node::getData()const {
	return data;
}
void Node::setpNext(Node* _pNext) {
	pNext = _pNext;
}
Node* Node::getpNext() {
	return pNext;
}
const Node* Node::getpNext()const {
	return pNext;
}
