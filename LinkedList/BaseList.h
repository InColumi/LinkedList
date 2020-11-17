#include "List.h"
#include "Base.h"
#include <iostream>
#include <string>
#ifndef BASELIST_H
#define BASELIST_H
class BaseList: public List
{
private:

public:
	void Show();

	void Input(ItemType);

	void Sort();

	void Search(std::string text);

private:

	bool Compere(std::string s1, std::string s2);
};

#endif