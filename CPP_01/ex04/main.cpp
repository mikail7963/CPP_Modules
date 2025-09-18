#include <string>
#include <iostream>
#include <fstream>

void replaceString(std::string& str, const std::string& s1, const std::string& s2)
{
	size_t pos = 0;
    while ((pos = str.find(s1, pos)) != std::string::npos)
    {
        str.erase(pos, s1.length());
        str.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int argc, char **args)
{
	
	if (argc != 4)
	{
		std::cerr << "invalid argument" <<  std::endl 
		<< "Usage :  [file] [str1] [str2]" << std::endl; 
		return 1;
	}
	if (args[2][0] == '\0')
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return 1;
	}
	std::string currentFile = args[1];
	std::ifstream infile(currentFile.c_str());
	if (!infile)
	{
		std::cerr << "file can't open" << std::endl;
		return 1;
	}

	std::string newfile = currentFile + ".replace";
	std::ofstream outFile(newfile.c_str());
	if (!outFile)
    {
        std::cerr << "output file can't be created" << std::endl;
        infile.close();
        return 1;
    }
	std::string line;
    while (std::getline(infile, line))
	{
		replaceString(line, args[2], args[3]);
        outFile << line;
		if (!infile.eof())
			outFile << std::endl;
    }
	infile.close();
	outFile.close();
	return (0);
}
