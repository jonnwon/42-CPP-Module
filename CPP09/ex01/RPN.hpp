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
		

		static void checkInput(const char *input);
	//	static int	calculate(const char *input);


	class	InputException : public std::exception
	{
		public:
			virtual	const char * what() const throw();
	};

//	class	TooLargeException : public std::exception
//	{
//		public:
//			virtual	const char * what() throw();
//	};
};

#endif
