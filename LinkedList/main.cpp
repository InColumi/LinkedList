#include <iostream>
#include "subj.h"
#include "BaseAndBaseList.h"
#include "TypeName.h"

using namespace std;

/// <summary>
/// Отладочный класс, наследник BaseList
/// </summary>
class DebugList: public BaseList
{
public:
	/// <summary>
	/// Вывод меню с командами
	/// </summary>
	void ShowMenu()
	{
		cout << ("\n1 - Ввод нового типа и добавление его в список)\n");
		cout << ("2 - Сортировка списка\n");
		cout << ("3 - Поиск по ключевому слову\n");
		cout << ("4 - Вывести список\n");
		cout << ("5 - Очистить список\n");
		cout << ("0 - Выход\n");
	}
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	DebugList debugList;

	cout << ("Создан пустой список:\n");
	//работа со списком через меню
	int command = -1;
	while(command != 0) //пока не выбрана команда выхода
	{
		debugList.ShowMenu();
		cout << ("\nВведите номер команды: ");
		cin >> command;
		//выполнение действия в зависимости от номера команды
		Node* item;
		switch(command)
		{
			case 1: //добавление
			{
				Base base;

				int type;
				cout << "1 - Doctor:\n";
				cout << "2 - Teacher:\n";
				cout << "3 - Fireman:\n";

				cout << "Выберете тип: "; cin >> type;
				switch(type)
				{
					case 1: 
					{
						debugList.Input(EDoctor);
						break;
					}
					case 2:
					{
						debugList.Input(ETeacher);
						break;
					}
					case 3:
					{
						debugList.Input(EFireman);
						break;
					}
					default:
						cout << ("Неверный тип!\n");
						system("TIMEOUT /T 4 /NOBREAK & cls");
						break;
				}
				cout << ("Элемент добавлен!\n");
				system("TIMEOUT /T 1 /NOBREAK & cls");
				break;
			}
			case 2: //Сортировка сиписка
			{
				debugList.Sort();
				break;
			}
			case 3: //Поиск по ключевому слову
			{
				string frace;
				cout << "Введите ключевую фразу\n";
				cin >> frace;
				debugList.Search(frace);
				break;
			}
			case 4: //удалить по номеру в списке
			{
				debugList.Print();
				break;
			}
			case 5: //Вывести список
			{
				debugList.Clear();
				cout << ("\nСписок очищен!\n");
				system("TIMEOUT /T 2 /NOBREAK & cls");
				break;
			}
			case 0:
			{
				command = 0;
				break;
			}
			default:
			{
				cout << ("Неверная команда!\n");
				system("TIMEOUT /T 4 /NOBREAK & cls");
				break;
			}
		}
	}
	return 0;
}