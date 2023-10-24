#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>

class	RPN
{
	private:
		RPN(const RPN& other);
		RPN& operator=(const RPN& rhs);
		RPN();
		~RPN();

	public:
		static	void printTest()
		{
			std::cout << "printTest" << std::endl;
		}
		
		static void		parseInput(const char *input);
		static double	calculate(std::stack<double> &stack, char &op);

	class	InputException : public std::exception
	{
		public:
			virtual	const char * what() const throw();
	};
};

template <typename T>
void printStack(const std::stack<T>& s)
{
    std::stack<T> copy = s;

    while (!copy.empty())
	{
        T element = copy.top();
        std::cout << element << " ";
        copy.pop();
    }
    std::cout << std::endl;
}

#endif
