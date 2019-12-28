//#define _GLIBCXX_USE_CX11_ABI 0
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <memory>

//#include "myclass.h"

using namespace std;

class MyClass
{
    public:
    MyClass() = default;

    //rule of 3 - default behavior
    MyClass(const MyClass& rhs) = default;
    MyClass& operator=(const MyClass&) = default;
    ~MyClass() = default;


    std::vector<std::string> names;

    //universal reference for move semantics
    template<typename T>
    void logAndAdd(T&&);

    void printNames();

    void passInt(int i){}
};

template<typename T>
void MyClass::logAndAdd(T&& name)
{
    auto now = std::chrono::system_clock::now();

    names.emplace_back(std::forward<T>(name));

}

void MyClass::printNames()
{
    for (const string& word : names)
    {
        cout << word << " ";
    }
    cout << endl;
}

//alias with template - list containing pairs of a type and MyClass<type>
template<typename T>
using MyList = vector<T>;

int main()
{
    //alias
    using TimeStamp = std::chrono::time_point<std::chrono::system_clock>;




    TimeStamp start, end;

    start = chrono::system_clock::now();
    // vector<string> msg {"Hello", "C++", "World", "from", "VS Code2!"};

    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;

    //MyClass* c = new MyClass();

    MyClass c;
    c.logAndAdd(R"(literal string)");
    string petname{"Chip"};
    c.logAndAdd(petname);
    c.logAndAdd(string("dale"));

    constexpr auto exp("autoexp");
    c.logAndAdd(exp);


    MyClass d(c);

    d.logAndAdd("added to d");

    d.printNames();

    c.printNames();


    end = chrono::system_clock::now();

    chrono::duration<double> elapsed = end - start;
    cout << "elapsed time: " << elapsed.count() << "s" << endl;
   
}





    