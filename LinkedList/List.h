#include "Node.h"
#include <iostream>

class List
{
protected:
	Node* head;
	Node* tail;
	size_t countNodes;
public:
	List(): head(NULL), tail(NULL), countNodes(0) {}

	~List()
	{
		while(countNodes != 0)
		{
			Delete(0);
		}
	}

	void Add(Node* newNode)
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

	size_t GetSize()
	{
		return countNodes;
	}

	Node* GetByIndex(size_t index)
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

	bool IsEmpty()
	{
		return countNodes > 0;
	}

	Node* RemoveByIndex(size_t index)
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

	void Delete(size_t index)
	{
		Node* oldNode = RemoveByIndex(index);
		if(oldNode != NULL)
		{
			delete oldNode;
		}
	}

	size_t GetIndex(Node* node)
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

	void Clear()
	{
		while(head != NULL)
		{
			Delete(0);
		}
	}

	void Insert(Node* item, size_t index)
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

private:

	void CheckIndex(size_t& index)
	{
		if(IsCorrectIndex(index) == false)
		{
			std::cout << "�������� ������ -> " << index << '\n';
			exit(0);
		}
	}

	bool IsCorrectIndex(size_t& index)
	{
		return index < countNodes;
	}

	void CheckEmpty()
	{
		if(IsEmpty() == false)
		{
			std::cout << "���� ����!\n";
			exit(0);
		}
	}
};
