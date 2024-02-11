# include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    for (int i = 0; i < 4; i++)
        v.push_back(i);
    try
    {
        std::vector<int>::iterator it = easyfind(v, 5);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}