#include "Node.h"
#include "List.h"
#include "TypeName.h"
#include "BaseAndBaseList.h"
#include <string>

using namespace std;

/// <summary>
/// Класс Доктор, Наследник Base
/// </summary>
class Doctor: public Base
{
	
public:
	/// <summary>
	/// Конструктор с параметрами
	/// </summary>
	Doctor(size_t id,
		   std::string lastName,
		   std::string firstName,
		   std::string middleName,
		   std::string mailAddress,
		   std::string phoneNumber,
		   std::string data,
		   std::string note
	): Base(EDoctor, id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note)
	{}
	/// <summary>
	/// Уникальная функцию класса Doctor
	/// </summary>
	void Print()
	{
		cout << "Я - доктор!\n";
	}
};

/// <summary>
/// Класс Учитель, Наследник Base
/// </summary>
class Teacher: public Base
{

public:
	/// <summary>
	/// Конструктор с параметрами
	/// </summary>
	Teacher(size_t id,
		   std::string lastName,
		   std::string firstName,
		   std::string middleName,
		   std::string mailAddress,
		   std::string phoneNumber,
		   std::string data,
		   std::string note
	): Base(ETeacher, id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note)
	{}
	/// <summary>
	/// Уникальная функцию класса Teacher
	/// </summary>
	void Print()
	{
		cout << "Я - учитель!\n";
	}
};

/// <summary>
/// Класс Пожарный, Наследник Base
/// </summary>
class Fireman: public Base
{
public:
	/// <summary>
	/// Конструктор с параметрами
	/// </summary>
	Fireman(size_t id,
		   std::string lastName,
		   std::string firstName,
		   std::string middleName,
		   std::string mailAddress,
		   std::string phoneNumber,
		   std::string data,
		   std::string note
	): Base(EFireman, id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note)
	{}
	/// <summary>
	/// Уникальная функцию класса Fireman
	/// </summary>
	void Print()
	{
		cout << "Я - пожарный!\n";
	}
};

/// <summary>
/// Диспетчеризация через явное приведение типов
/// </summary>
void Base::Print()
{
	switch(_itemType)
	{
		case EDoctor:
			((Doctor*) this)->Print();
			break;
		case ETeacher:
			((Teacher*) this)->Print();
			break;
		case EFireman:
			((Fireman*) this)->Print();
			break;

		default:
			cout << "Не верный тип!\n";
			break;
	}

	cout << "Табельный номер: " << _id << '\n';
	cout << "ФИО: " << _lastName << ' ' << _firstName << ' ' << _middleName << '\n';
	cout << "Почтовый адрес: " << _mailAddress << '\n';
	cout << "Номер телефона(формат +1 222 333-44-55): " << _phoneNumber << '\n';
	cout << "Дата (дд.мм.гггг): " << _data << '\n';
	cout << "Текстовая заметка: " << _note << "\n\n";
}