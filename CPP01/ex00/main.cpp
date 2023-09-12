/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:03:18 by jonchoi           #+#    #+#             */
/*   Updated: 2023/08/13 16:34:07 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	/* stack test */
	Zombie stack("Stack3");
	stack.announce();

	/* heap test */
	Zombie *heap;

	heap = newZombie("Heap");
	heap->announce();
	delete heap;

	/* randomChump test */
	randomChump("Stack1");

	/* stackframe test*/
	{
		Zombie stack("Stack2");
		stack.announce();
	}

	return (0);
}
