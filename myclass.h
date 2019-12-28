
//#define _GLIBCXX_USE_CX11_ABI 0
#include <iostream>
#include <string>
#include <vector>
#include <chrono>



class MyClass
{
    public:
    std::vector<std::string> names;

    template<typename T>
    void logAndAdd(T&&);

    void printNames();

    void passInt(int i){}

};