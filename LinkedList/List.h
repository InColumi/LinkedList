#include "Node.h"
#include <iostream>

#ifndef LIST_H
#define LIST_H

class List
{
private:
	size_t _countNodes;

protected:
	Node* _head;
	Node* _tail;

public:
	List();

	~List();

	void Add(Node* newNode);

	void CheckEmpty();

	void Clear();

	void Delete(size_t index);

	Node* GetByIndex(size_t index);

	size_t GetSize();

	void Insert(Node* item, size_t index);

	bool IsEmpty();

	Node* RemoveByIndex(size_t index);

	size_t GetIndex(Node* node);

	Node* GetHead();

	Node* GetTail();
	/*void Swap(size_t indexFirst, size_t indexSecond)
	{
		if(_countNodes == 1)
		{
			std::cout << "Нельза менять элементы местами. Список содержит один элемент.\n";
			exit(0);
		}
		std::cout << _head << std::endl;
		std::cout << _tail << std::endl;
		Node* firstNode = GetByIndex(indexFirst);
		Node* secondNod = GetByIndex(indexSecond);

		Node* prevFirstNode = firstNode->GetPrev();
		Node* nextFirstNode = firstNode->GetNext();

		SetPrev(*firstNode, secondNod->GetPrev());
		SetNext(*firstNode, secondNod->GetNext());

		SetPrev(*secondNod, prevFirstNode);
		SetNext(*secondNod, nextFirstNode);

		std::cout << _head << std::endl;
		std::cout << _tail << std::endl;
	}*/

private:

	void CheckIndex(size_t& index);

	bool IsCorrectIndex(size_t& index);

};
#endif