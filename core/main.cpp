#include <iostream>
#include "airdrop/base_extensions.hpp"
#include "airdrop/tar.cpp"

int main(int argc, char const *argv[])
{
    tar tar;

    std::vector<std::string> filesToArchive = 
    {
        "airdrop/test/blablabla.txt",
        "airdrop/test/hello.txt"
    };
    std::string archiveName = "test";

    tar.generate("airdrop/test/data/", archiveName, filesToArchive);
    // tar.extract("airdrop/test/data/", archiveName);

    std::string oldFileName = "airdrop/test/data/" + archiveName + EXT_TAR;
    std::string newFileName = "airdrop/test/data/" + archiveName + EXT_PACKAGE;

    std::string *pseudoname_old = &oldFileName;
    std::string *pseudoname_new = &newFileName;
    rename(pseudoname_old->c_str(), pseudoname_new->c_str());
    std::cout << "Processing package has been completed." << std::endl;

    return EXIT_SUCCESS;
}