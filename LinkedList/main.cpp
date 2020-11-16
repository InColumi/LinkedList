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
//			cout << i << '\t' << stepper << '\t' << stepper->_prev << '\t' << stepper->_next << '\n';
//			stepper = stepper->_next;
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
	List list;
	size_t size = 10;
	Node* nodes = new Node[size];
	for(size_t i = 0; i < size; i++)
	{
		nodes = new Node();
	}

	for(size_t i = 0; i < size; i++)
	{
		cout << &nodes[i] << endl;
	}
	cout << endl;

	for(size_t i = 0; i < size; i++)
	{
		list.PushBack(&nodes[i]);
	}
	cout << list.GetIndex(&nodes[0]) << endl;
	cout << list.GetIndex(&nodes[5]) << endl;
	cout << list.GetIndex(&nodes[size - 1]) << endl;
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
	//			break;
	//		}
	//		case 2: //������� �� ������
	//		{
	//			int index = Iput("������", debugList.GetSize());

	//			item = new Node();
	//			debugList.Insert(item, index);
	//			cout << ("������� ��������!\n");
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
	//			break;
	//		}
	//		case 6: //�������� ������
	//		{
	//			debugList.Clear();
	//			cout << ("\n������ ������!\n");
	//			break;
	//		}
	//		case 0:
	//		{
	//			break;
	//		}
	//		default:
	//		{
	//			cout << ("�������� �������!\n");
	//			break;
	//		}
	//	}
	//}
	return 0;
}