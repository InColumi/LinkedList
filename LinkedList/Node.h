class Node
{
private:
	Node* _prev;
	Node* _next;
public:
	Node(): _prev(NULL), _next(NULL) {}

	Node(Node* prev, Node* next)
	{
		this->_prev = prev;
		this->_next = next;
	}
	
	friend void SetPrev(Node& node, Node* prev)
	{
		node._prev = prev;
	}

	friend void SetNext(Node& node, Node* next)
	{
		node._next = next;
	}

	Node* GetPrev()
	{
		return _prev;
	}

	Node* GetNext()
	{
		return _next;
	}
};