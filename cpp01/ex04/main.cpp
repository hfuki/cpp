#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string replace_string(std::string content, const std::string& s1, const std::string& s2)
{
	if (s1.empty())
		return content;

	std::string result;
	int	pos = 0;
	std::string::size_type	found_pos;

	while ((found_pos = content.find(s1, pos)) != std::string::npos)
	{
		result.append(content, pos, found_pos - pos);
		result += s2;
		pos = found_pos + s1.length();
	}
	result.append(content, pos, std::string::npos);

	return result;
}

int	main(int ac, char ** av)
{
	if (ac != 4)
	{
		std::cerr << "Error: Usage: ./sed_is_for_loser <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	std::ifstream input_file(filename.c_str());
	if (!input_file.is_open())
	{
		std::cerr << "Error: Could not open file: " << filename << std::endl;
		return (1);
	}

	std::stringstream ss;
	ss << input_file.rdbuf();
	std::string content = ss.str();
	input_file.close();

	std::string modified_content = replace_string(content, s1, s2);

	std::ofstream output_file((filename + ".replace").c_str());
	if (!output_file.is_open())
	{
		std::cerr << "Error: Could not create file." << std::endl;
		return (1);
	}

	output_file << modified_content;
	output_file.close();

	return (0);
}
