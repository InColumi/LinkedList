#include "List.h"

List::List()
{
	head = NULL;
	tail = NULL;
	countNodes = 0;
}

List::~List()
{
	while(countNodes != 0)
	{
		Delete(0);
	}
}

void List::Add(Node* newNode)
{
	if(head != NULL) //���� ������ �� ����
	{
		SetPrev(*newNode, tail);
		//item->prev = tail;
		SetNext(*tail, newNode);
		//tail->next = item;
		tail = tail->GetNext();
	}
	else //���� ������ ����, ��������� ������ �������
	{
		head = newNode;
		tail = newNode;
	}
	++countNodes;
}

void List::CheckEmpty()
{
	if(IsEmpty() == false)
	{
		std::cout << "���� ����!\n";
		exit(0);
	}
}

void List::Clear()
{
	while(head != NULL)
	{
		Delete(0);
	}
}

void List::Delete(size_t index)
{
	Node* oldNode = RemoveByIndex(index);
	if(oldNode != NULL)
	{
		delete oldNode;
	}
}

Node* List::GetByIndex(size_t index)
{
	CheckIndex(index);
	CheckEmpty();
	Node* stepper = head;
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
	Node* stepper = head;
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
		std::cout << "���� �� ������!\n";
		exit(0);
	}
}

size_t List::GetSize()
{
	return countNodes;
}

void List::Insert(Node* item, size_t index)
{
	CheckIndex(index);
	if(index == 0) //���� ��������� � ������ ������
	{
		if(head != NULL) //���� ������ �� ����
		{
			SetNext(*item->GetNext(), head);
			SetPrev(*head->GetPrev(), item);
			head = item;
		}
		else //���� ������ ����, ��������� ������ �������
		{
			head = item;
			tail = item;
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
		std::cout << "�������� ������ -> " << index << '\n';
		exit(0);
	}
}

bool List::IsCorrectIndex(size_t& index)
{
	return index < countNodes;
}

bool List::IsEmpty()
{
	return countNodes > 0;
}

Node* List::RemoveByIndex(size_t index)
{
	Node* oldNode = GetByIndex(index); //�������� ������� �� ������
	if(oldNode != NULL)
	{
		if(oldNode == head) //���� ������� �������� �������
		{
			if(head->GetNext() != NULL)
			{
				SetPrev(*head->GetNext()->GetPrev(), NULL);
			}
			head = head->GetNext();
		}
		else if(oldNode == tail) //���� ������� ��������� �������
		{
			if(tail->GetPrev() != NULL)
			{
				SetNext(*tail->GetPrev()->GetNext(), NULL);
			}
			tail = tail->GetPrev();
		}
		else //������� ������
		{
			SetNext(*oldNode->GetNext()->GetPrev(), oldNode->GetPrev());
			SetPrev(*oldNode->GetPrev()->GetNext(), oldNode->GetNext());
		}
	}
	return oldNode;
}