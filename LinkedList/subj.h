#include "Node.h"
#include "List.h"
#include <string>

using namespace std;

enum ItemType { itDog = 1, itCat, itCrocodile };

class Base: public Node
{
private:
	size_t _id;
	string _lastName;
	string _firstName;
	string _middleName;
	string _mailAddress;
	string _phoneNumber;
	string _data;
	string _note;

public:
	Base(string lastName, string firstName, string middleName, string mailAddress, string phoneNumber, string data)
	{
		_lastName = lastName;
		_firstName = firstName;
		_middleName = middleName;
		_mailAddress = mailAddress;
		_phoneNumber = phoneNumber;
		_data = data;

	}

	size_t GetId()
	{
		return _id;
	}

	string GetLastName()
	{
		return _lastName;
	}

	string GetFirstName()
	{
		return _firstName;
	}

	string GetMiddleName()
	{
		return _middleName;
	}

	string GeMailAddress()
	{
		return _mailAddress;
	}

	string GetPhoneNumber()
	{
		return _phoneNumber;
	}

	string GetData()
	{
		return _data;
	}

	string GetNote()
	{
		return _note;
	}
};

class SubjList: public List
{

public:
	SubjList();
	~SubjList();

private:
	void Print(size_t index)
	{

		cout << "Табельный номер: " << _id << '\n';
		cout << "ФИО: " << _firstName << ' ' << _lastName << ' ' << _middleName << '\n';
		cout << "Почтовый адрес: " << _mailAddress << '\n';
		cout << "Номер телефона(формат +1 222 333-44-55) :" << _phoneNumber << '\n';
		cout << "Дата: (дд.мм.гггг)" << _data << '\n';
		cout << "Текстовая заметка: " << _note << '\n';
	}

	void Input()
	{
		cout << "Введите данные:\n";
		cout << "\tТабельный номер: "; std::cin >> _id;
		cout << "\tФамилия: "; std::cin >> _firstName;
		cout << "\tИмя: "; std::cin >> _lastName;
		cout << "\tОтчество: "; std::cin >> _middleName;
		cout << "\tПочтовый адрес: "; std::cin >> _mailAddress;
		cout << "\tНомер телефона(формат +1 222 333-44-55) :"; std::cin >> _phoneNumber;
		cout << "\tДата (дд.мм.гггг): "; std::cin >> _data;
		cout << "\tТекстовая заметка: "; std::cin >> _note;
	}

	void Sort()
	{
		Base* p = _head;
		Base* z, * g, * u;
		int k, j, i;
		int n = this; //количество элементов списка
		//пузырьковая сортировка для списка
		for(j = 0; j < n - 1; j++)
		{
			for(i = 0; i < n - j - 1; i++)
			{
				if(strcmp(p->surname, ((Base*) p->next)->surname) > 0) //сравниваем фамилии соседних элементов
				{
					//меняем их местами, если они не по порядку
					if(n == 2) //если в списке всего два элемента
					{
						z = p->next;
						g = z->next;
						p->next = g;
						z->next = p;
						z->prev = p->prev;
						p->prev = z;
						_head = z;
					}
					else if(p == _head) //если переставляем головной элемент
					{
						z = p->next;
						g = z->next;
						g->prev = p;
						p->next = g;
						z->next = p;
						z->prev = p->prev;
						p->prev = z;
						_head = z;
					}
					else if(p->next != _tail) //если второй переставляемый не является хвостом
					{
						u = p->prev;
						z = p->next;
						g = z->next;
						g->prev = p;
						p->next = g;
						z->next = p;
						z->prev = p->prev;
						p->prev = z;
						u->next = z;
					}
					else //если p->next является хвостом списка
					{
						u = p->prev;
						z = p->next;
						g = z->next;
						p->next = g;
						z->next = p;
						z->prev = p->prev;
						p->prev = z;
						u->next = z;
						_tail = p;
					}
				}
				else
					p = p->next; //переход к следующей паре	
			}
			p = _head; //следующих проход начинаем с головного элемента
		}
		void Search(const List * lst, char* key_word);
		void PrintListData(const List * lst);
	};

};

class Doctor: public Base, public SubjList
{
public:
	Doctor();
	~Doctor();

private:

};
