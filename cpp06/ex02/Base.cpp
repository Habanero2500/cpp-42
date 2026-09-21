#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{

}
void identify(Base* p)
{
    if(dynamic_cast<A *>(p)) // Cast à l'éxécution plutôt qu'à la compil 
        std::cout << "Real type of this base is A" << std::endl;
    else if(dynamic_cast<B *>(p))
        std::cout << "Real type of this base is B" << std::endl;
    else if(dynamic_cast<C *>(p))
        std::cout << "Real type of this base is C" << std::endl;

}
void identify(Base& p)
{

}