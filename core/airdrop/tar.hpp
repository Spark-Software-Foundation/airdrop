/*
 * tar.hpp
 * (c) 2025 Spark Software Foundation
 * https://ssf.pw
 */
#ifndef TAR_HPP
#define TAR_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

namespace airdrop
{ 

class tar
{
private:
    
public:
    void generate(const std::string& path, const std::string& pkgName, const std::vector<std::string>& files);
    void extract(const std::string& path, const std::string& pkgName);
};

}

#endif // TAR_HPP