#include "Node.h"
#include <iostream>
#include <string>
#ifndef BASE_H
#define BASE_H
class Base: public Node
{
private:
	size_t _id;
	std::string _lastName;
	std::string _firstName;
	std::string _middleName;
	std::string _mailAddress;
	std::string _phoneNumber;
	std::string _data;
	std::string _note;

public:
	Base();

	Base(size_t id, 
		 std::string lastName, 
		 std::string firstName, 
		 std::string middleName, 
		 std::string mailAddress, 
		 std::string phoneNumber, 
		 std::string data, 
		 std::string note);

	size_t GetId();

	std::string GetLastName();

	std::string GetFirstName();

	std::string GetMiddleName();

	std::string GetMailAddress();

	std::string GetPhoneNumber();

	std::string GetData();

	std::string GetNote();

	void Print();
};

#endif