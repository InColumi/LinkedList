#include "Node.h"
#include <iostream>

#ifndef LIST_H
#define LIST_H
/// <summary>
/// Двунаправленный список
/// </summary>
class List
{
private:
	/// <summary>
	/// Подсчет кол-ва звеньев в списке
	/// </summary>
	size_t _countNodes;

protected:
	/// <summary>
	/// Указатель на Начало списка
	/// </summary>
	Node* _head;
	/// <summary>
	/// Указатель на Конец списка
	/// </summary>
	Node* _tail;

public:
	List();

	~List();

	/// <summary>
	/// Добавление узел в конец списка
	/// </summary>
	/// <param name="newNode">новый узел</param>
	void Add(Node* newNode);

	/// <summary>
	/// Проверка на пустоту
	/// </summary>
	void CheckEmpty();

	/// <summary>
	/// Очистка списка
	/// </summary>
	void Clear();

	/// <summary>
	/// Удаление узла по индексу
	/// </summary>
	/// <param name="index">индекс узла, для удаления</param>
	void Delete(size_t index);

	/// <summary>
	/// Получение узла по индексу
	/// </summary>
	/// <param name="index">индекс узла</param>
	/// <returns>узел</returns>
	Node* GetByIndex(size_t index);

	/// <summary>
	/// Получение размера списка
	/// </summary>
	/// <returns></returns>
	size_t GetSize();

	/// <summary>
	/// Вставка узла по позиции
	/// </summary>
	/// <param name="item"></param>
	/// <param name="index"></param>
	void Insert(Node* item, size_t index);

	/// <summary>
	/// Проверка на пустоту
	/// </summary>
	/// <returns></returns>
	bool IsEmpty();

	/// <summary>
	/// Удаление узла по идексу
	/// </summary>
	/// <param name="index">индекс для удаления</param>
	/// <returns>узел, который исключили из списка</returns>
	Node* RemoveByIndex(size_t index);

	/// <summary>
	/// Получение индекса узла
	/// </summary>
	/// <param name="node">узел</param>
	/// <returns>индекс узла</returns>
	size_t GetIndex(Node* node);

	/// <summary>
	/// Возвращает указатель на начало списка
	/// </summary>
	/// <returns></returns>
	Node* GetHead();

	/// <summary>
	/// Возвращает указатель на конец списка
	/// </summary>
	/// <returns></returns>
	Node* GetTail();
	
private:
	/// <summary>
	/// Проверка индекса на корректность
	/// </summary>
	/// <param name="index"></param>
	void CheckIndex(size_t& index);

	/// <summary>
	/// Проверка индекса на корректность
	/// </summary>
	/// <param name="index"></param>
	/// <returns>true/false</returns>
	bool IsCorrectIndex(size_t& index);

};
#endif