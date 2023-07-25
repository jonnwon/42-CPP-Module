#include <iostream>
#include <string>
#include <fstream>

std::string ft_replace(const std::string& str, const std::string& s1, const std::string& s2)
{
	std::string	res;
	size_t		start = 0;
	size_t		pos = str.find(s1);

	while (pos != std::string::npos)
	{
		res += str.substr(start, pos - start) + s2;
		start = pos + s1.length();
		pos = str.find(s1, start);
	}
	res += str.substr(start);
	return res;
}

int main(int argc, char **argv)
{
	std::string str;

	if (argc != 4)
	{
		std::cout << "Error: Invlid number of arguments" << std::endl;
		return (1);
	}
	std::ifstream ifs(argv[1]);
	if (!ifs.is_open())
	{
		std::cout << "Error: Failed to open the file" << std::endl;
		return (1);
	}
	std::ofstream ofs(argv[1] + std::string(".replace"));
	if (!ofs.is_open())
	{
		std::cerr << "Error: Unable to open output file" << std::endl;
		return (1);
	}
	while (std::getline(ifs, str))
		ofs << ft_replace(str, argv[2], argv[3]) << std::endl;
	ifs.close();
	ofs.close();
	return (0);
}
