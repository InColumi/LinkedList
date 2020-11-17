#include <iostream>
#include "List.h"

using namespace std;

//class DebugList: public List
//{
//public:
//	void PrintList()
//	{
//		cout << ("List: \tНачало: \tКонец:\n");
//		Node* stepper = head;
//		int i = 0;
//		for(size_t i = 0; stepper != NULL; i++)
//		{
//			cout << i << '\t' << stepper << '\t' << stepper->GetPrev() << '\t' << stepper->GetNext() << '\n';
//			stepper = stepper->GetNext();
//		}
//	}
//	void ShowMenu()
//	{
//		cout << ("\n1 - Добавить элемент в список\n");
//		cout << ("2 - Вставить элемент по номеру в списке\n");
//		cout << ("3 - Вывести список\n");
//		cout << ("4 - Узнать размер списка\n");
//		cout << ("5 - Удалить элемент по номеру в списке\n");
//		cout << ("6 - Очистить список\n");
//		cout << ("0 - Выход\n");
//	}
//};

int Iput(string text, size_t size)
{
	int index;
	cout << "Введите номер элемента для " << text << " (>= 0) И (<= %i): ";
	cin >> index;
	while(index < 0 && index >= size)
	{
		cout << ("Ошибка. Повторите попытку:\t");
	}
	return index;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");









	//DebugList debugList;

	//cout << ("Создан пустой список:\n");
	////работа со списком через меню
	//int command = -1;
	//while(command != 0) //пока не выбрана команда выхода
	//{
	//	debugList.ShowMenu();
	//	cout << ("\nВведите номер команды: ");
	//	cin >> command;
	//	//выполнение действия в зависимости от номера команды
	//	Node* item;
	//	switch(command)
	//	{
	//		case 1: //добавление
	//		{
	//			item = new Node();
	//			debugList.Add(item); //добавляем в список
	//			cout << ("Элемент добавлен!\n");
	//			system("TIMEOUT /T 1 /NOBREAK & cls");
	//			break;
	//		}
	//		case 2: //вставка по номеру
	//		{
	//			int index = Iput("вствки", debugList.GetSize());

	//			item = new Node();
	//			debugList.Insert(item, index);
	//			cout << ("Элемент добавлен!\n");
	//			system("TIMEOUT /T 2 /NOBREAK & cls");
	//			break;
	//		}
	//		case 3: //Вывод списка
	//		{
	//			cout << ("Текущий список:\n");
	//			debugList.PrintList();
	//			break;
	//		}
	//		case 4: //подсчет количества элементов
	//		{
	//			cout << ("Элементов в списке: ", debugList.GetSize());
	//			break;
	//		}
	//		case 5: //удалить по номеру в списке
	//		{
	//			int index = Iput("удаления", debugList.GetSize());

	//			debugList.RemoveByIndex(index);
	//			cout << ("\nЭлемент удален!\n");
	//			system("TIMEOUT /T 2 /NOBREAK & cls");
	//			break;
	//		}
	//		case 6: //очистить список
	//		{
	//			debugList.Clear();
	//			cout << ("\nСписок очищен!\n");
	//			system("TIMEOUT /T 2 /NOBREAK & cls");
	//			break;
	//		}
	//		case 0:
	//		{
	//			break;
	//		}
	//		default:
	//		{
	//			cout << ("Неверная команда!\n");
	//			system("TIMEOUT /T 4 /NOBREAK & cls");
	//			break;
	//		}
	//	}
	//}
	return 0;
}