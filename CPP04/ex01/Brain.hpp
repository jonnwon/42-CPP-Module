#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& rhs);
		~Brain();

		void	set_Idea_At_Index(int index, const std::string& idea);
		std::string getIdeaAtIndex(int index) const;

	private:
		std::string ideas[100];
};

#endif
