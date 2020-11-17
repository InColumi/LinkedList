#include "Node.h"
#include "List.h"
#ifndef	BASEANSBASELIST_H
#define BASEANSBASELIST_H
/// <summary>
/// Наследник Node
/// </summary>
class Base: public Node
{
private:

	/// <summary>
	/// Табельный номер
	/// </summary>
	size_t _id;
	/// <summary>
	/// Фамилия
	/// </summary>
	std::string _lastName;
	/// <summary>
	/// Имя
	/// </summary>
	std::string _firstName;
	/// <summary>
	/// Отчество
	/// </summary>
	std::string _middleName;
	/// <summary>
	/// Почтовый адрес
	/// </summary>
	std::string _mailAddress;
	/// <summary>
	/// Телефон
	/// </summary>
	std::string _phoneNumber;
	/// <summary>
	/// Дата
	/// </summary>
	std::string _data;
	/// <summary>
	/// Заметка
	/// </summary>
	std::string _note;

public:
	Base() {}

	Base(size_t id, std::string lastName, std::string firstName, std::string middleName, std::string mailAddress, std::string phoneNumber, std::string data, std::string note)
	{
		_id = id;
		_lastName = lastName;
		_firstName = firstName;
		_middleName = middleName;
		_mailAddress = mailAddress;
		_phoneNumber = phoneNumber;
		_data = data;
		_note = note;
	}

	/// <summary>
	/// Возвращает Дату 
	/// </summary>
	/// <returns></returns>
	std::string GetData()
	{
		return _data;
	}

	std::string GetFirstName()
	{
		return _lastName;
	}

	/// <summary>
	/// Возращет тип объкта по умолчанию 0
	/// </summary>
	/// <returns></returns>
	virtual std::size_t GetType()
	{
		return 0;
	}

	virtual void Input()
	{
		size_t id;
		std::string lastName;
		std::string firstName;
		std::string middleName;
		std::string mailAddress;
		std::string phoneNumber;
		std::string data;
		std::string note;

		std::cout << "Введите данные:\n";
		std::cout << "\tТабельный номер: "; std::cin >> id;
		std::cout << "\tФамилия: "; std::cin >> firstName;
		std::cout << "\tИмя: "; std::cin >> lastName;
		std::cout << "\tОтчество: "; std::cin >> middleName;
		std::cout << "\tПочтовый адрес: "; std::cin >> mailAddress;
		std::cout << "\tНомер телефона(формат +1 222 333-44-55) :"; std::cin >> phoneNumber;
		std::cout << "\tДата (дд.мм.гггг): "; std::cin >> data;
		std::cout << "\tТекстовая заметка: "; std::cin >> note;
		*this = Base(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note);
	}

	/// <summary>
	/// Возвращает табельный номер
	/// </summary>
	/// <returns></returns>
	size_t GetId()
	{
		return _id;
	}

	/// <summary>
	/// Возвращает Фамилие
	/// </summary>
	/// <returns></returns>
	std::string GetLastName() override
	{
		return _lastName;
	}

	/// <summary>
	/// Возвращает отчетво
	/// </summary>
	/// <returns></returns>
	std::string GetMiddleName()
	{
		return _middleName;
	}

	/// <summary>
	/// Возвращает телефон
	/// </summary>
	/// <returns></returns>
	std::string GetPhoneNumber()
	{
		return _phoneNumber;
	}

	/// <summary>
	/// Возвращает почту
	/// </summary>
	/// <returns></returns>
	std::string GetMailAddress()
	{
		return _mailAddress;
	}

	/// <summary>
	/// Возвращает заметку
	/// </summary>
	/// <returns></returns>
	std::string GetNote() override
	{
		return _note;
	}

	/// <summary>
	/// Выводит на монитор в зависимости от типа
	/// </summary>
	virtual void Print();
};

/// <summary>
/// Наследник List
/// </summary>
class BaseList: public List
{
private:

public:
	/// <summary>
	/// Выводит на монитор весь список
	/// </summary>
	void Print()
	{
		Node* head = GetHead();
		while(head != NULL)
		{
			head->Print();
			head = head->GetNext();
		}
		delete head;
	}

	/// <summary>
	/// Сортировка списка по убыванию фамилии А->Я
	/// </summary>
	void Sort()
	{
		Node* stepper = _head;
		Node* z, * g, * u;
		size_t size = GetSize(); //количество элементов списка
		//пузырьковая сортировка для списка
		for(size_t j = 0; j < size - 1; j++)
		{
			for(size_t i = 0; i < size - j - 1; i++)
			{
				if(Compere((stepper->GetLastName)(), (stepper->GetNext()->GetLastName)())) //сравниваем фамилии соседних элементов
				{
					//меняем их местами, если они не по порядку
					if(size == 2) //если в списке всего два элемента
					{
						z = stepper->GetNext();
						g = z->GetNext();
						SetNext(*stepper, g);
						SetNext(*z, stepper);
						SetPrev(*z, stepper->GetPrev());
						SetPrev(*stepper, z);
						_head = z;
					}
					else if(stepper == GetHead()) //если переставляем головной элемент
					{
						z = stepper->GetNext();
						g = z->GetNext();
						SetPrev(*g, stepper);
						SetNext(*stepper, g);
						SetNext(*z, stepper);
						SetPrev(*z, stepper->GetPrev());
						SetPrev(*stepper, z);
						_head = z;
					}
					else if(stepper->GetNext() != _tail) //если второй переставляемый не является хвостом
					{
						u = stepper->GetPrev();
						z = stepper->GetNext();
						g = z->GetNext();
						SetPrev(*g, stepper);
						SetNext(*stepper, g);
						SetNext(*z, stepper);
						SetPrev(*z, stepper->GetPrev());
						SetPrev(*stepper, z);
						SetNext(*u, z);
					}
					else //если p->next является хвостом списка
					{
						u = stepper->GetPrev();
						z = stepper->GetNext();

						g = z->GetNext();
						SetNext(*stepper, g);
						SetNext(*z, stepper);
						SetPrev(*z, stepper->GetPrev());
						SetPrev(*stepper, z);
						SetNext(*u, z);
						_tail = stepper;
					}
				}
				else
					stepper = stepper->GetNext(); //переход к следующей паре	
			}
			stepper = _head; //следующих проход начинаем с головного элемента
		}
	}

	/// <summary>
	/// Поиск по ключевому фразе в заметках(если находит совпадение, то выводит на экран)
	/// </summary>
	/// <param name="text">ключевая фраза</param>
	void Search(std::string text)
	{
		Node* stepper = _head;
		while(stepper != NULL)
		{
			if(stepper->GetNote().find(text) != std::string::npos)
			{
				((Base*) this)->Print();
			}
			stepper = stepper->GetNext();
		}
	}

private:
	/// <summary>
	/// Сравнение двух строк
	/// </summary>
	/// <param name="s1">первая строка</param>
	/// <param name="s2">вторая строка</param>
	/// <returns>true если первая строка больше(т.е. стоит выше в алфавите)</returns>
	bool Compere(std::string s1, std::string s2)
	{
		size_t count = 0;
		size_t size1 = s1.size();
		size_t size2 = s2.size();
		for(size_t i = 0; i < size1 && i < size2; i++)
		{
			if(s1[i] == s2[i])
			{
				count++;
				continue;
			}
			return s1[i] > s2[i];
		}
		return (count == size1) ? true : false;
	}
};

#endif