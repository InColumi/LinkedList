#include "Node.h"
#include <iostream>

Node::Node()
{
	_prev = NULL;
	_next = NULL;
}

Node::Node(Node* prev, Node* next)
{
	_prev = prev;
	_next = next;
}

Node* Node::GetNext()
{
	return _next;
}

Node* Node::GetPrev()
{
	return _prev;
}

void SetPrev(Node& node, Node* prev)
{
	node._prev = prev;
}

void SetNext(Node& node, Node* next)
{
	node._next = next;
}
