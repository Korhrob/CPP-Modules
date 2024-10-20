#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "invalid argument count\nexample ./program filename s1 s2" << std::endl;
		return 1;
	}

	if (argv[1] == "" || argv[2] == "" || argv[3] == "")
	{
		std::cout << "empty argument" << std::endl;
		return 1;
	}
	
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	if (filename.empty())
	{
		std::cout << "invalid filename" << std::endl;
		return 1;
	}

	std::ifstream src(filename);

	if (!src.is_open())
	{
		std::cout << "failed to open input file" << std::endl;
		return 1;
	}

	std::ofstream out(filename + ".replace");

	if (!out.is_open())
	{
		std::cout << "failed to open output file" << std::endl;
		return 1;
	}

	if (s1.empty())
	{
		src.close();
		out.close();
	}

	std::stringstream buffer;
	std::string str;
	std::string str_out;
	buffer << src.rdbuf();
	str = buffer.str();

	size_t curPos = 0;
	while (1)
	{
		size_t s1_pos = str.find(s1, curPos);

		if (s1_pos == std::string::npos) {
			str_out.append(str.substr(curPos));
			break;
		}
		str_out.append(str.substr(curPos, s1_pos - curPos));
		str_out.append(s2);
		if (s2.empty())
			curPos = s1_pos + 1;
		else
			curPos = s1_pos + s2.length();
	}

	out << str_out;
	src.close();
	out.close();
	return 0;
}
