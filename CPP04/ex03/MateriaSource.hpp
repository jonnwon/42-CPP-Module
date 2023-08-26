#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *slot[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& rhs);
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);

		void print_slot()			// delete
		{
			std::cout << " MateriaSource " << std::endl;
			for (int i = 0; i < 4; i++)
				printf("i[%d] : %p\n", i, slot[i]);
		}
};

#endif
