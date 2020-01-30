#include <iostream>
#include <string>

class Data 
{
	private:
		unsigned int _id;
		std::string _string;
	public:
		Data();
		Data(int id);
		Data(std::string string);
		Data(int id, std::string string);
		~Data();
		int GetId();
		void SetId(int id);
		std::string GetString();
		void SetString(std::string string);
};

void PrintData(Data d);

