#include <iostream>
#include "airdrop/tar.cpp"

int main(int argc, char const *argv[])
{
    airdrop::tar tar;

    std::vector<std::string> filesToArchive = 
    {
        "airdrop/test/blablabla.txt",
        "airdrop/test/example.png",
        "airdrop/test/hello.txt"
    };
    std::string archiveName = "test";

    tar.generate("airdrop/test/data/", archiveName, filesToArchive);
    // tar.extract("airdrop/test/data/", archiveName);

    return EXIT_SUCCESS;
}
