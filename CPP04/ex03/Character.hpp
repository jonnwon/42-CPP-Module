#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *slot[4];

	public:
		Character();
		Character(std::string const& name);
		Character(const Character& other);
		Character& operator=(const Character& rhs);
		virtual ~Character();

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		// delete
		void	print_slot_addr()
		{
			for (int i = 0; i < 4; i++)
				printf("i[%d] : %p\n", i, slot[i]);
		}

		void	print_slot_idx(int idx)
		{
			std::cout << slot[idx]->getType() << std::endl;
		}
};

#endif
