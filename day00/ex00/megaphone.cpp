#include <iostream>
#include <string>

int main(int ac, char **av){

    if (ac == 1)
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";

    for (int i = 1; i < ac; i++){
        std::string str(av[i]);
        for (int j = 0; (size_t)j < str.length(); j++){
            std::cout<<(char)toupper(str[j]);
        }
    }
    std::cout<<std::endl;
    return 0;
}