#include <iostream>
#include "subj.h"
#include "BaseAndBaseList.h"
#include "TypeName.h"

using namespace std;

/// <summary>
/// ���������� �����, ��������� BaseList
/// </summary>
class DebugList: public BaseList
{
public:
	/// <summary>
	/// ����� ���� � ���������
	/// </summary>
	void ShowMenu()
	{
		cout << ("\n1 - ���� ������ ���� � ���������� ��� � ������)\n");
		cout << ("2 - ���������� ������\n");
		cout << ("3 - ����� �� ��������� �����\n");
		cout << ("4 - ������� ������\n");
		cout << ("5 - �������� ������\n");
		cout << ("0 - �����\n");
	}
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	DebugList debugList;

	cout << ("������ ������ ������:\n");
	//������ �� ������� ����� ����
	int command = -1;
	while(command != 0) //���� �� ������� ������� ������
	{
		debugList.ShowMenu();
		cout << ("\n������� ����� �������: ");
		cin >> command;
		//���������� �������� � ����������� �� ������ �������
		Node* item;
		switch(command)
		{
			case 1: //����������
			{
				Base base;

				int type;
				cout << "1 - Doctor:\n";
				cout << "2 - Teacher:\n";
				cout << "3 - Fireman:\n";

				cout << "�������� ���: "; cin >> type;
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
						cout << ("�������� ���!\n");
						system("TIMEOUT /T 4 /NOBREAK & cls");
						break;
				}
				cout << ("������� ��������!\n");
				system("TIMEOUT /T 1 /NOBREAK & cls");
				break;
			}
			case 2: //���������� �������
			{
				debugList.Sort();
				break;
			}
			case 3: //����� �� ��������� �����
			{
				string frace;
				cout << "������� �������� �����\n";
				cin >> frace;
				debugList.Search(frace);
				break;
			}
			case 4: //������� �� ������ � ������
			{
				debugList.Print();
				break;
			}
			case 5: //������� ������
			{
				debugList.Clear();
				cout << ("\n������ ������!\n");
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
				cout << ("�������� �������!\n");
				system("TIMEOUT /T 4 /NOBREAK & cls");
				break;
			}
		}
	}
	return 0;
}