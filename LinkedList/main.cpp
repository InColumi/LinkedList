#include <iostream>
#include "List.h"

using namespace std;

//class DebugList: public List
//{
//public:
//	void PrintList()
//	{
//		cout << ("List: \t������: \t�����:\n");
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
//		cout << ("\n1 - �������� ������� � ������\n");
//		cout << ("2 - �������� ������� �� ������ � ������\n");
//		cout << ("3 - ������� ������\n");
//		cout << ("4 - ������ ������ ������\n");
//		cout << ("5 - ������� ������� �� ������ � ������\n");
//		cout << ("6 - �������� ������\n");
//		cout << ("0 - �����\n");
//	}
//};

int Iput(string text, size_t size)
{
	int index;
	cout << "������� ����� �������� ��� " << text << " (>= 0) � (<= %i): ";
	cin >> index;
	while(index < 0 && index >= size)
	{
		cout << ("������. ��������� �������:\t");
	}
	return index;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");









	//DebugList debugList;

	//cout << ("������ ������ ������:\n");
	////������ �� ������� ����� ����
	//int command = -1;
	//while(command != 0) //���� �� ������� ������� ������
	//{
	//	debugList.ShowMenu();
	//	cout << ("\n������� ����� �������: ");
	//	cin >> command;
	//	//���������� �������� � ����������� �� ������ �������
	//	Node* item;
	//	switch(command)
	//	{
	//		case 1: //����������
	//		{
	//			item = new Node();
	//			debugList.Add(item); //��������� � ������
	//			cout << ("������� ��������!\n");
	//			system("TIMEOUT /T 1 /NOBREAK & cls");
	//			break;
	//		}
	//		case 2: //������� �� ������
	//		{
	//			int index = Iput("������", debugList.GetSize());

	//			item = new Node();
	//			debugList.Insert(item, index);
	//			cout << ("������� ��������!\n");
	//			system("TIMEOUT /T 2 /NOBREAK & cls");
	//			break;
	//		}
	//		case 3: //����� ������
	//		{
	//			cout << ("������� ������:\n");
	//			debugList.PrintList();
	//			break;
	//		}
	//		case 4: //������� ���������� ���������
	//		{
	//			cout << ("��������� � ������: ", debugList.GetSize());
	//			break;
	//		}
	//		case 5: //������� �� ������ � ������
	//		{
	//			int index = Iput("��������", debugList.GetSize());

	//			debugList.RemoveByIndex(index);
	//			cout << ("\n������� ������!\n");
	//			system("TIMEOUT /T 2 /NOBREAK & cls");
	//			break;
	//		}
	//		case 6: //�������� ������
	//		{
	//			debugList.Clear();
	//			cout << ("\n������ ������!\n");
	//			system("TIMEOUT /T 2 /NOBREAK & cls");
	//			break;
	//		}
	//		case 0:
	//		{
	//			break;
	//		}
	//		default:
	//		{
	//			cout << ("�������� �������!\n");
	//			system("TIMEOUT /T 4 /NOBREAK & cls");
	//			break;
	//		}
	//	}
	//}
	return 0;
}