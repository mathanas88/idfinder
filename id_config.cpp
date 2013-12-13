#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>

typedef std::map<std::string, std::string> config_type;

config_type read_config(std::istream& file)
{
	config_type config;
        size_t pos = 0;
        std::string s;
        std::string key, value;
	int i = 0;
        while(std::getline(file, s))
        {
		i++;
		pos = s.find(":");
                key = s.substr(0, pos);
                value = s.substr(pos+1, s.size());
		config[key] = value;
        }
	return config;
}
