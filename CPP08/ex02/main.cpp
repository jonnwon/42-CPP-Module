#include "MutantStack.hpp"

int main()
{
    MutantStack<int> s;

    s.push(1);
    s.push(2);

    for (MutantStack<int>::iterator i=s.begin(); i != s.end(); i++)
    {
        *i = *i + 1;    // no error
        std::cout << *i << " ";
    }

    std::cout << std::endl;

    for (MutantStack<int>::const_iterator i=s.begin(); i != s.end(); i++)
    {
        //*i = *i + 1;     // error
        std::cout << *i << " ";
    }

    std::cout << std::endl;

    for (MutantStack<int>::reverse_iterator i=s.rbegin(); i != s.rend(); i++)
    {
        *i = *i + 1;    // no error
        std::cout << *i << " ";
    }

    std::cout << std::endl;

    for (MutantStack<int>::const_reverse_iterator i=s.rbegin(); i != s.rend(); i++)
    {
        //*i = *i + 1;    //error
        std::cout << *i << " ";
    }


}
