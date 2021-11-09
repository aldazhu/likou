#include <iostream>//°üº¬std::cout
#include <fstream>// include std::fstream

char * CPPreadImage(const std::string &imagePath)
{
	std::fstream inputStream(imagePath,std::ifstream::in||std::ifstream::binary);

	if (!inputStream)
	{
		std::cout << "open file error!\n";
		return nullptr;
	}

	//get the length of the file
	inputStream.seekg(0, inputStream.end);
	int len = inputStream.tellg();
	inputStream.seekg(0, inputStream.beg);

	char * buffer = new char[len];

	inputStream.read(buffer, len);
	/*if (!inputStream.read(buffer, len))
		std::cout << "read error\n";*/

	inputStream.close();
	delete[] buffer;
}

int main_readimage()
{
	std::string imagePath = "k:\\deepImage\\baseball.jpg";
	CPPreadImage(imagePath);
	return 0;
}
