#include "header.h"

//constructor
Data::Data()
{
	_id = 0;
	_string = "";
}
Data::Data(int id)
{
	_id = id;
	_string = "";
}
Data::Data(std::string string)
{
	_id = 0;
	_string = string;
}
Data::Data(int id, std::string string)
{
	_id = id;
	_string = string;
}

//de-constructor
Data::~Data()
{
	// unsigned int* ptrId = _id;
	// std::string* ptrString = _string;
	// delete ptrId;
	// delete ptrString;
}

int Data::GetId()
{
	return _id;
}
void Data::SetId(int id)
{
	_id = id;
}

std::string Data::GetString()
{
	return _string;
}
void Data::SetString(std::string string)
{
	_string = string;
}

void PrintData(Data d)
{
	std::cout << "Id: " << d.GetId() << std::endl;
	std::cout << "String: \"" << d.GetString() << "\"" << std::endl << std::endl;
}

