#include "Node.h"
#include <iostream>

#ifndef LIST_H
#define LIST_H
/// <summary>
/// ��������������� ������
/// </summary>
class List
{
private:
	/// <summary>
	/// ������� ���-�� ������� � ������
	/// </summary>
	size_t _countNodes;

protected:
	/// <summary>
	/// ��������� �� ������ ������
	/// </summary>
	Node* _head;
	/// <summary>
	/// ��������� �� ����� ������
	/// </summary>
	Node* _tail;

public:
	List();

	~List();

	/// <summary>
	/// ���������� ���� � ����� ������
	/// </summary>
	/// <param name="newNode">����� ����</param>
	void Add(Node* newNode);

	/// <summary>
	/// �������� �� �������
	/// </summary>
	void CheckEmpty();

	/// <summary>
	/// ������� ������
	/// </summary>
	void Clear();

	/// <summary>
	/// �������� ���� �� �������
	/// </summary>
	/// <param name="index">������ ����, ��� ��������</param>
	void Delete(size_t index);

	/// <summary>
	/// ��������� ���� �� �������
	/// </summary>
	/// <param name="index">������ ����</param>
	/// <returns>����</returns>
	Node* GetByIndex(size_t index);

	/// <summary>
	/// ��������� ������� ������
	/// </summary>
	/// <returns></returns>
	size_t GetSize();

	/// <summary>
	/// ������� ���� �� �������
	/// </summary>
	/// <param name="item"></param>
	/// <param name="index"></param>
	void Insert(Node* item, size_t index);

	/// <summary>
	/// �������� �� �������
	/// </summary>
	/// <returns></returns>
	bool IsEmpty();

	/// <summary>
	/// �������� ���� �� ������
	/// </summary>
	/// <param name="index">������ ��� ��������</param>
	/// <returns>����, ������� ��������� �� ������</returns>
	Node* RemoveByIndex(size_t index);

	/// <summary>
	/// ��������� ������� ����
	/// </summary>
	/// <param name="node">����</param>
	/// <returns>������ ����</returns>
	size_t GetIndex(Node* node);

	/// <summary>
	/// ���������� ��������� �� ������ ������
	/// </summary>
	/// <returns></returns>
	Node* GetHead();

	/// <summary>
	/// ���������� ��������� �� ����� ������
	/// </summary>
	/// <returns></returns>
	Node* GetTail();
	
private:
	/// <summary>
	/// �������� ������� �� ������������
	/// </summary>
	/// <param name="index"></param>
	void CheckIndex(size_t& index);

	/// <summary>
	/// �������� ������� �� ������������
	/// </summary>
	/// <param name="index"></param>
	/// <returns>true/false</returns>
	bool IsCorrectIndex(size_t& index);

};
#endif