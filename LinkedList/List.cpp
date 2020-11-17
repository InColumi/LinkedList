#include "List.h"

List::List()
{
	_head = NULL;
	_tail = NULL;
	_countNodes = 0;
}

List::~List()
{
	while(_countNodes != 0)
	{
		Delete(0);
	}
}

void List::Add(Node* newNode)
{
	if(_head != NULL) //если список не пуст
	{
		SetPrev(*newNode, _tail);
		//item->prev = tail;
		SetNext(*_tail, newNode);
		//tail->next = item;
		_tail = _tail->GetNext();
	}
	else //если список пуст, добавляем первый элемент
	{
		_head = newNode;
		_tail = newNode;
	}
	++_countNodes;
}

void List::CheckEmpty()
{
	if(IsEmpty() == false)
	{
		std::cout << "Лист пуст!\n";
		exit(0);
	}
}

void List::Clear()
{
	while(_head != NULL)
	{
		Delete(0);
	}
}

void List::Delete(size_t index)
{
	Node* oldNode = RemoveByIndex(index);
	if(oldNode != NULL)
	{
		oldNode = NULL;
	}
}

Node* List::GetByIndex(size_t index)
{
	CheckIndex(index);
	CheckEmpty();
	Node* stepper = _head;
	for(size_t i = 0; stepper != NULL && i != index; i++)
	{
		stepper = stepper->GetNext();
	}
	return stepper;
}

size_t List::GetIndex(Node* node)
{
	CheckEmpty();
	bool isFind = false;
	Node* stepper = _head;
	for(size_t i = 0; stepper != NULL; i++)
	{
		if(stepper == node)
		{
			return i;
		}
		stepper = stepper->GetNext();
	}

	if(isFind == false)
	{
		std::cout << "Узел не найден!\n";
		exit(0);
	}
}

size_t List::GetSize()
{
	return _countNodes;
}

void List::Insert(Node* item, size_t index)
{
	CheckIndex(index);
	if(index == 0) //если вставляем в начало списка
	{
		if(_head != NULL) //если список не пуст
		{
			SetNext(*item->GetNext(), _head);
			SetPrev(*_head->GetPrev(), item);
			_head = item;
		}
		else //если список пуст, добавляем первый элемент
		{
			_head = item;
			_tail = item;
		}
	}
	else
	{
		Node* beforeDelete = GetByIndex(index - 1);
		Node* afterDelete = GetByIndex(index);

		SetPrev(*item->GetPrev(), beforeDelete);
		SetNext(*item->GetNext(), afterDelete);

		SetNext(*beforeDelete->GetNext(), item);
		SetNext(*afterDelete->GetPrev(), item);
	}
}

void List::CheckIndex(size_t& index)
{
	if(IsCorrectIndex(index) == false)
	{
		std::cout << "Неверный индекс -> " << index << '\n';
		exit(0);
	}
}

bool List::IsCorrectIndex(size_t& index)
{
	return index < _countNodes;
}

bool List::IsEmpty()
{
	return _countNodes > 0;
}

Node* List::RemoveByIndex(size_t index)
{
	Node* oldNode = GetByIndex(index); //получаем элемент по номеру
	if(oldNode != NULL)
	{
		if(oldNode == _head) //если удаляем головной элемент
		{
			if(_head->GetNext() != NULL)
			{
				SetPrev(*_head->GetNext()->GetPrev(), NULL);
			}
			_head = _head->GetNext();
		}
		else if(oldNode == _tail) //если удаляем последний элемент
		{
			if(_tail->GetPrev() != NULL)
			{
				SetNext(*_tail->GetPrev()->GetNext(), NULL);
			}
			_tail = _tail->GetPrev();
		}
		else //обычный случай
		{
			SetNext(*oldNode->GetNext()->GetPrev(), oldNode->GetPrev());
			SetPrev(*oldNode->GetPrev()->GetNext(), oldNode->GetNext());
		}
	}
	--_countNodes;
	return oldNode;
}

Node* List::GetHead()
{
	return _head;
}

Node* List::GetTail()
{
	return _tail;
}