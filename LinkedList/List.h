#include "Node.h"

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
		Clear();
	}

	void Clear()
	{
		while(countNodes > 0)
		{
			PopBack();
		}
	}

	Node* GetHead()
	{
		return head;
	}

	Node* GetTail()
	{
		return tail;
	}

	Node* GetNode(size_t index)
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

	void PopFront()
	{
		Node* nextNode = head;
		head = head->GetNext();
		delete nextNode;
		--countNodes;
	}

	void PopBack()
	{
		Node* nextNode = tail;
		tail = tail->GetPrev();
		delete nextNode;
		--countNodes;
	}

	void PushFront(Node* newNode)
	{
		AddNode(newNode, &List::PushToFront);
	}

	void PushBack(Node* newNode)
	{
		AddNode(newNode, &List::PushToBack);
	}

	void RemoveByIndex(size_t index)
	{
		Node* nextNode;
		CheckIndex(index);
		if(index == 0)
		{
			PopFront();

		}
		else if(index == (countNodes - 1))
		{
			PopFront();
		}
		else
		{
			Node* stepper = head;
			for(size_t i = 0; stepper != NULL && i != i; i++)
			{
				stepper = stepper->GetNext();
			}
			nextNode = stepper;
			SetNext(*stepper, stepper->GetNext());
			delete nextNode;
		}
		delete nextNode;
		--countNodes;
	}

	/*void Insert(Node* newNode, size_t index)
	{
		CheckIndex(index);
		CheckEmpty();
		if(head != NULL)
		{
			if(index == 0)
			{
				if(this->head != NULL)
				{
					newNode->GetNext() = this->head;
					this->head->GetPrev() = newNode;
					this->head = newNode;
				}
				else
				{
					Add(newNode);
				}
			}
			else
			{
				Node* prevNode = GetNode(index - 1);
				Node* nextNode = GetNode(index);
				newNode->_prev = prevNode;
				newNode->_next = nextNode;
				nextNode->_prev = newNode;
				prevNode->_next = newNode;
			}
		}
		else
		{
			Add(newNode);
		}
		++countNodes;
	}*/

	int GetSize()
	{
		return countNodes;
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
			std::cout << "Узел не найден!\n";
			exit(0);
		}
	}

	bool IsEmpty()
	{
		return countNodes > 0;
	}

private:

	void AddNode(Node* newNode, void (List::* AddNewNode)(Node*))
	{
		if(head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			(this->*AddNewNode)(newNode);
		}
		++countNodes;
	}

	void PushToFront(Node* newNode)
	{
		SetNext(*newNode, head);
		head = newNode;
		std::cout << tail << std::endl;
	}

	void PushToBack(Node* newNode)
	{
		std::cout << tail << std::endl;
		SetNext(*tail, newNode);
		tail = tail->GetNext();
		std::cout << head << std::endl;
		std::cout << tail << std::endl << std::endl;
	}

	void CheckIndex(size_t& index)
	{
		if(IsCorrectIndex(index) == false)
		{
			std::cout << "Неверный индекс -> " << index << '\n';
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
			std::cout << "Лист пуст!\n";
			exit(0);
		}
	}
};
