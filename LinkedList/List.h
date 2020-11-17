#include "Node.h"
#include <iostream>

#ifndef LIST_H
#define LIST_H

class List
{
protected:
	Node* head;
	Node* tail;
	size_t countNodes;
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

private:

	void CheckIndex(size_t& index);

	bool IsCorrectIndex(size_t& index);

};

#endif