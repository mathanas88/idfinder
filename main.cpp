#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "id_config.cpp"
#include <unistd.h>

using namespace std;

typedef std::map<std::string, std::string> config_type;

int main(int argc, char* argv[])
{
	config_type reg_ex;
	std::ifstream config_file;
	config_file.open("config.txt", std::ifstream::in);
	reg_ex = read_config(config_file);
	int option;
	bool a = 0, b = 0, c = 0, e = 0, n = 0, o = 0, p = 0, s = 0;
	std::string first, last, bday, phone, card, email, ssn;
	int map_size = reg_ex.size();
	std::string keys[map_size];
	std::string values[map_size];
	while((option = getopt(argc, argv, "abceonps")) != -1)
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
			case 'o':
				o = 1;
				break;
			case 'n': 
				n = 1;
				break;
			case 'p':
				p = 1;
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
		cin >> first;
		cin >> last;
		
	}
	if(a | e)
	{
		cout << "Enter your email address: " << endl;
		cin >> email;
	}
	if(a | b)
	{
		cout << "Enter your birthday: (format: dd/mm/yyyy)" << endl;
		cin >> bday;
	}
	if(a | p)
	{
		cout << "Enter your phone number: (format: XXX-XXX-XXXX)" << endl;
		cin >> phone;
	}
	if(a | c)
	{
		cout << "Credit Card Number: (format: XXXX-XXXX-XXXX-XXXX)" << endl;
		cin >> card;
	}
	if(a | s)
	{
		cout << "Social Security Number: (format: XXX-XX-XXXX)" << endl;
		cin >> ssn;
	}

	int i = 0;
	for(std::map<string, string>::iterator it = reg_ex.begin(); it != reg_ex.end(); ++it)
	{
		keys[i] = it->first;
		values[i] = it->second;
		i++;
	}
	
	std::string grep = "grep -E -o ";
	std::string uniq = " | uniq -c";
	std::string cmd;
	
	if(a | b | c | e | n | p | s) cout << "In " << argv[argc - 1] << " found:" << endl;
	if(a | n)
	{
		cmd = grep + "\"" + first + "\" " + argv[argc - 1] + uniq;
		system(cmd.c_str());
		cout << endl;
                cmd = grep + "\"" + last + "\" " + argv[argc - 1] + uniq;
                system(cmd.c_str());
                cout << endl;
	}
	if(a | e)
	{
		cmd = grep + "\"" + email + "\" " + argv[argc - 1] + uniq;
		system(cmd.c_str());
		cout << endl;
	}
	if(a | b)
	{
		cmd = grep + "\"" + bday + "\" " + argv[argc - 1] + uniq;
                system(cmd.c_str());
      		cout << endl;
	}
	if(a | p)
        {
                cmd = grep + "\"" + phone + "\" " + argv[argc - 1] + uniq;
                system(cmd.c_str());
                cout << endl;
        }
	if(a | c)
        {
                cmd = grep + "\"" + card + "\" " + argv[argc - 1] + uniq;
                system(cmd.c_str());
                cout << endl;
        }
	if(a | s)
        {
                cmd = grep + "\"" + ssn + "\" " + argv[argc - 1] + uniq;
                system(cmd.c_str());
                cout << endl;
        }

	if(!o)
	{
		cout << endl;
		for(i = 0; i < map_size; i++)
		{	
			cout << keys[i] << ":" << endl;
			cmd = grep + "\"" + values[i] + "\" " + argv[argc - 1];
			system(cmd.c_str());
			cout << endl;
		}
	}

	return 0;
}
