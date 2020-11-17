#ifndef NODE_H
#define NODE_H
/// <summary>
/// ����� ����
/// </summary>
class Node
{
private:
	/// <summary>
	/// ��������� �� ���������� �������
	/// </summary>
	Node* _prev;
	/// <summary>
	/// ��������� �� ��������� �������
	/// </summary>
	Node* _next;
public:
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	Node();

	/// <summary>
	/// ����������� � �����������
	/// </summary>
	/// <param name="prev">��������� �� ���������� �������</param>
	/// <param name="next">��������� �� ��������� �������</param>
	Node(Node* prev, Node* next);

	/// <summary>
	/// ���������� ��������� �� ����������
	/// </summary>
	/// <returns></returns>
	Node* GetPrev();

	/// <summary>
	/// ���������� ��������� �� ��������� 
	/// </summary>
	/// <returns></returns>
	Node* GetNext();

	/// <summary>
	/// ������������� ������� ��� ��������� ���������� ���� _prev
	/// </summary>
	/// <param name="node">�����</param>
	/// <param name="prev">����� ��������</param>
	friend void SetPrev(Node& node, Node* prev);

	/// <summary>
	/// ������������� ������� ��� ��������� ���������� ���� _next
	/// </summary>
	/// <param name="node">�����</param>
	/// <param name="next">����� ��������</param>
	friend void SetNext(Node& node, Node* next);
};
#endif