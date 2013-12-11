#include <cstdlib>
#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "id_config.cpp"

using namespace std;

typedef std::map<std::string, boost::basic_regex<char>> config_type;

int main(int argc, char* argv[])
{
	config_type key_value;
	std::ifstream config_file;
	config_file.open("config.txt", std::fstream::in);
	key_value = read_config(config_file);
	int option;
	bool valid = 0;
	bool a, b, c, e, f, n, s;
	const char* reg = "[2-9][0-9]{2}[-.]?[2-9][0-9]{2}[-.]?[0-9]{4}";
	std::string name, bday, card, email, ssn;
	boost::basic_regex<char> bday_regex = boost::basic_regex<char>(reg);
	while((option = getopt(argc, argv, "abcefns")) != -1)
	{
		switch(option)
		{
			case 'a': 
				a = 1;
				break;
			case 'b': 
				b = 1;
				break;
			case 'c': 
				c = 1;
				break;
			case 'e': 
				e = 1;
				break;
			case 'f': 
				f = 1;
				break;
			case 'n': 
				n = 1;
				break;
			case 's': 
				s = 1;
				break;
			default:
				cerr << option << " is an invalid option." << endl;
		}
		
	}
	
	if(a | n) 
	{
		cout << "Enter your name: " << endl;
		cin >> name;
	}
	if(a | e)
	{
		cout << name << endl;
		cout << "Enter your email address: " << endl;
		cin >> email;
	}
	if(a | b)
	{
		cout << "Enter your birthday: (format: dd/mm/yyyy)" << endl;
		cin >> bday;
	}
	if(a | c)
	{
		cout << "Credit Card Number: ";
		cin >> card;
	}
	if(a | s)
	{
		cout << "Social Security Number: ";
		cin >> ssn;
	}


	return 0;
}
