#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string str = "MyEmail:email@host...ru LOL11!!! asdfasdf";
    std::cmatch result;
    std::regex regular("(:)"
                       "([^\\o]*)"
                       "([\\.\\w\\s]{8})");

    if(std::regex_search(str.c_str(), result, regular))
        std::cout << "true\n";

    for(int i = 1; i < result.size(); ++i)
        std::cout << result[i] << std::endl;

    return 0;
}
