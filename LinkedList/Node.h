#ifndef NODE_H
#define NODE_H
/// <summary>
/// Класс узел
/// </summary>
class Node
{
private:
	/// <summary>
	/// Указатель на предыдущий элемент
	/// </summary>
	Node* _prev;
	/// <summary>
	/// Указатель на следующий элемент
	/// </summary>
	Node* _next;
public:
	Node();

	Node(Node* prev, Node* next);

	/// <summary>
	/// Возвращает указатель на предыдущий
	/// </summary>
	/// <returns></returns>
	Node* GetPrev();

	/// <summary>
	/// Возвращает указатель на следующий 
	/// </summary>
	/// <returns></returns>
	Node* GetNext();

	/// <summary>
	/// Дружественная функцию для изменения приватного поля _prev
	/// </summary>
	/// <param name="node">Объек</param>
	/// <param name="prev">новый параметр</param>
	friend void SetPrev(Node& node, Node* prev);

	/// <summary>
	/// Дружественная функцию для изменения приватного поля _next
	/// </summary>
	/// <param name="node">Объек</param>
	/// <param name="next">новый параметр</param>
	friend void SetNext(Node& node, Node* next);
};
#endif