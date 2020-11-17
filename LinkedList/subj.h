#include "Node.h"
#include "List.h"
#include "BaseAndBaseList.h"
#include <string>

using namespace std;

/// <summary>
/// Класс Доктор, Наследник Base
/// </summary>
class Doctor: public Base
{

public:
	Doctor() {}
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
	): Base(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note)
	{}

	size_t GetType() override
	{
		return 1;
	}

	void Input() override
	{
		size_t id;
		std::string lastName;
		std::string firstName;
		std::string middleName;
		std::string mailAddress;
		std::string phoneNumber;
		std::string data;
		std::string note;

		std::cout << "Введите данные для доктора:\n";
		std::cout << "\tТабельный номер: "; std::cin >> id;
		std::cout << "\tФамилия: "; std::cin >> firstName;
		std::cout << "\tИмя: "; std::cin >> lastName;
		std::cout << "\tОтчество: "; std::cin >> middleName;
		std::cout << "\tПочтовый адрес: "; std::cin >> mailAddress;
		std::cout << "\tНомер телефона(формат +1 222 333-44-55) :"; std::cin >> phoneNumber;
		std::cout << "\tДата (дд.мм.гггг): "; std::cin >> data;
		std::cout << "\tТекстовая заметка: "; std::cin >> note;

		*this = Doctor(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note);
	}

	/// <summary>
	/// Уникальная функцию класса Doctor
	/// </summary>
	void Print()
	{
		cout << "Я - доктор!\n";
		cout << "Табельный номер: " << GetId() << '\n';
		cout << "ФИО: " << GetLastName() << ' ' << GetLastName() << ' ' << GetMiddleName() << '\n';
		cout << "Почтовый адрес: " << GetMailAddress() << '\n';
		cout << "Номер телефона(формат +1 222 333-44-55): " << GetPhoneNumber() << '\n';
		cout << "Дата (дд.мм.гггг): " << GetData() << '\n';
		cout << "Текстовая заметка: " << GetNote() << "\n\n";
	}
};

/// <summary>
/// Класс Учитель, Наследник Base
/// </summary>
class Teacher: public Base
{
public:
	Teacher() {}
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
	): Base(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note)
	{}

	size_t GetType() override
	{
		return 1;
	}

	void Input() override
	{
		size_t id;
		std::string lastName;
		std::string firstName;
		std::string middleName;
		std::string mailAddress;
		std::string phoneNumber;
		std::string data;
		std::string note;

		std::cout << "Введите данные для учителя:\n";
		std::cout << "\tТабельный номер: "; std::cin >> id;
		std::cout << "\tФамилия: "; std::cin >> firstName;
		std::cout << "\tИмя: "; std::cin >> lastName;
		std::cout << "\tОтчество: "; std::cin >> middleName;
		std::cout << "\tПочтовый адрес: "; std::cin >> mailAddress;
		std::cout << "\tНомер телефона(формат +1 222 333-44-55) :"; std::cin >> phoneNumber;
		std::cout << "\tДата (дд.мм.гггг): "; std::cin >> data;
		std::cout << "\tТекстовая заметка: "; std::cin >> note;

		*this = Teacher(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note);
	}

	/// <summary>
	/// Уникальная функцию класса Teacher
	/// </summary>
	void Print()
	{
		cout << "Я - учитель!\n";
		cout << "Табельный номер: " << GetId() << '\n';
		cout << "ФИО: " << GetLastName() << ' ' << GetLastName() << ' ' << GetMiddleName() << '\n';
		cout << "Почтовый адрес: " << GetMailAddress() << '\n';
		cout << "Номер телефона(формат +1 222 333-44-55): " << GetPhoneNumber() << '\n';
		cout << "Дата (дд.мм.гггг): " << GetData() << '\n';
		cout << "Текстовая заметка: " << GetNote() << "\n\n";
	}
};

/// <summary>
/// Класс Пожарный, Наследник Base
/// </summary>
class Fireman: public Base
{
public:
	Fireman() {}
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
	): Base(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note)
	{}

	size_t GetType() override
	{
		return 3;
	}

	void Input() override
	{
		size_t id;
		std::string lastName;
		std::string firstName;
		std::string middleName;
		std::string mailAddress;
		std::string phoneNumber;
		std::string data;
		std::string note;

		std::cout << "Введите данные для доктора:\n";
		std::cout << "\tТабельный номер: "; std::cin >> id;
		std::cout << "\tФамилия: "; std::cin >> firstName;
		std::cout << "\tИмя: "; std::cin >> lastName;
		std::cout << "\tОтчество: "; std::cin >> middleName;
		std::cout << "\tПочтовый адрес: "; std::cin >> mailAddress;
		std::cout << "\tНомер телефона(формат +1 222 333-44-55) :"; std::cin >> phoneNumber;
		std::cout << "\tДата (дд.мм.гггг): "; std::cin >> data;
		std::cout << "\tТекстовая заметка: "; std::cin >> note;

		*this = Fireman(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note);
	}

	/// <summary>
	/// Уникальная функцию класса Fireman
	/// </summary>
	void Print() override
	{
		cout << "Я - пожарный!\n";
		cout << "Табельный номер: " << GetId() << '\n';
		cout << "ФИО: " << GetLastName() << ' ' << GetLastName() << ' ' << GetMiddleName() << '\n';
		cout << "Почтовый адрес: " << GetMailAddress() << '\n';
		cout << "Номер телефона(формат +1 222 333-44-55): " << GetPhoneNumber() << '\n';
		cout << "Дата (дд.мм.гггг): " << GetData() << '\n';
		cout << "Текстовая заметка: " << GetNote() << "\n\n";
	}
};

/// <summary>
/// Диспетчеризация через явное приведение типов
/// </summary>
void Base::Print()
{
	cout << "Табельный номер: " << _id << '\n';
	cout << "ФИО: " << _lastName << ' ' << _firstName << ' ' << _middleName << '\n';
	cout << "Почтовый адрес: " << _mailAddress << '\n';
	cout << "Номер телефона(формат +1 222 333-44-55): " << _phoneNumber << '\n';
	cout << "Дата (дд.мм.гггг): " << _data << '\n';
	cout << "Текстовая заметка: " << _note << "\n\n";
}