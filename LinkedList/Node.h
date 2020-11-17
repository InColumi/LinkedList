#ifndef NODE_H
#define NODE_H
class Node
{
private:
	Node* _prev;
	Node* _next;
public:
	Node();

	Node(Node* prev, Node* next);

	Node* GetPrev();

	Node* GetNext();

	friend void SetPrev(Node& node, Node* prev);

	friend void SetNext(Node& node, Node* next);
};
#endif