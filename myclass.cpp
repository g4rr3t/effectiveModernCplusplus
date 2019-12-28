//#define _GLIBCXX_USE_CX11_ABI 0
#include "myclass.h"

using namespace std;

template<typename T>
void MyClass::logAndAdd(T&& name)
{
    auto now = chrono::system_clock::now();

    names.push_back(std::forward<T>(name));
}

void MyClass::printNames()
{
    for (const string& word : names)
    {
        cout << word << " ";
    }
    cout << endl;
}