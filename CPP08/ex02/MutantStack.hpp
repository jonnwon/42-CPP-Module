#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack   :   public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack<T>& operator=(const MutantStack& rhs);
        virtual ~MutantStack();

		typedef typename std::stack<T>::container_type::iterator		iterator; 
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator; 

	    iterator		begin();
	    iterator		end();
		const_iterator	begin() const;
		const_iterator	end() const;
};        

template <typename T>
MutantStack<T>::MutantStack()
{   
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
:std::stack<T>(other)
{
    *this = other;
 }

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& rhs)
{
	(void)rhs;
	if (this != &rhs)
		this->c = rhs.c;
	return *this; 
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const
{
    return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const
{
    return this->c.end();
}


#endif
