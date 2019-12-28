#include <string>
#include <iostream>
#include <vector>
#include <functional>

class Widget {
    public:
    Widget():filters(){};
    using FilterContainer = std::vector<std::function<bool(int)>>;

    FilterContainer filters;

    void addFilter() 
    {
        filters.emplace_back([divisor=divisor]  //copy divisor into closure
            (int value){return value % divisor ==0;});
    }

    private:
    int divisor = 3;
};



int main()
{
    //  signature of lambda is void lambda(const std::string& str);
    auto lambda = [](const std::string& str) -> void
    {
        std::cout << str << std::endl;
    };

    std::string hello("Hello Lambda!");
    lambda(hello);

    Widget w;
    w.addFilter();

    auto funct = w.filters.front();

    if (funct(3))
        lambda("3 its true");
    
    if (funct(2))
    {

    } else
        lambda("2 is false");
    



    return 0;
};