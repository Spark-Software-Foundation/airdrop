/*
 * tar.cpp
 * (c) 2025 Spark Software Foundation
 * https://ssf.pw
 */
#include "tar.hpp"

void airdrop::tar::generate(const std::string& path, const std::string& pkgName, const std::vector<std::string>& files)
{
    std::ofstream tar(path + pkgName + ".tar", std::ios::binary);
	if (!tar)
	{
		std::cerr << "Cannot open '" + pkgName + ".tar'" << std::endl;
		return;
	}
	
	for (auto& file : files)
	{
		std::ifstream inputFile(file, std::ios::binary);
		if (!inputFile)
		{
			std::cerr << "Cannot open file '" + file + "'" << std::endl;
			continue;
		}
		
		std::string fileName = std::filesystem::path(file).filename().string();
        size_t nameLength = fileName.length();
        tar.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        tar.write(fileName.data(), nameLength);

		inputFile.seekg(0, std::ios::end);
        size_t fileSize = inputFile.tellg();
        inputFile.seekg(0, std::ios::beg);
        tar.write(reinterpret_cast<const char*>(&fileSize), sizeof(fileSize));
        tar << inputFile.rdbuf();

		inputFile.close();
	}
	
	std::cout << "Archiving is complete." << std::endl;
	tar.close();
}

void airdrop::tar::extract(const std::string& path, const std::string& pkgName)
{
	std::ifstream tar(path + pkgName + ".tar", std::ios::binary);
	if (!tar)
	{
		std::cerr << "Failed to open '" + pkgName + ".tar' for reading." << std::endl;
		return;
	}
	
	while (true) {
        size_t nameLength;
        tar.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        if (tar.eof()) break;

        std::string fileName(nameLength, '\0');
        tar.read(&fileName[0], nameLength);

        size_t fileSize;
        tar.read(reinterpret_cast<char*>(&fileSize), sizeof(fileSize));

        std::ofstream outputFile(fileName, std::ios::binary);
        if (!outputFile) {
            std::cerr << "Failed to create '" + fileName + "'" << std::endl;
            continue;
        }

        std::vector<char> buffer(fileSize);
        tar.read(buffer.data(), fileSize);
        outputFile.write(buffer.data(), fileSize);

        outputFile.close();
    } 

	std::cout << "Extracting is complete." << std::endl;
    tar.close();
}
