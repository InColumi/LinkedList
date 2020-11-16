#include "List.h"
enum ItemType { itDog = 1, itCat, itCrocodile };

class Base: public Node
{
private:
	ItemType _type;

public:
	void Print(void);

private:
	void Input(Base* p);
	void Print(Base* p);

	void Sort(List* lst);
	void Search(const List* lst, char* key_word); 
	void PrintListData(const List* lst);
};