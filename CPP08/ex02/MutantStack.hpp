#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack   :   public std::stack<T>
{
    private:

    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        // MutantStack& operator=(const MutantStack& rhs);
        virtual ~MutantStack();


        typedef typename std::stack<T>::container_type::iterator                    iterator; 
        typedef typename std::stack<T>::container_type::const_iterator              const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator			reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator		const_reverse_iterator;        

	    iterator				begin();
	    iterator				end();
    	reverse_iterator		rbegin();
	    reverse_iterator		rend();

    	const_iterator			cbegin() const;
    	const_iterator			cend() const;
	    const_reverse_iterator	crbegin() const;
	    const_reverse_iterator	crend() const;
};        

template <typename T>
MutantStack<T>::MutantStack()
{   
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
{
    *this = other;
    return *this;
}

// template <typename T>
// MutantStack& MutantStack<T>::operator=(const MutantStack& rhs)
// {
//     (void)rhs;
//     return *this;      
// }

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
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const
{
    return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}


#endif
