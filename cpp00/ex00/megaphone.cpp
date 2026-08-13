#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{

    if(argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return(0);
    }
    int i(0);
    int o(1);
    while(argv[o])
    {
        i = 0;
        while(argv[o][i])
        {
            std::cout << (char)toupper(argv[o][i]);
            i++;
        }
        o++;
    }
    if(argv[1])
        std::cout << std::endl;
    return (0);
}




