/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:03:18 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/23 21:00:31 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *heap = newZombie("Heap");
	heap->announce();

	randomChump("Stack1");

	{
		Zombie stack("Stack2");
		stack.announce();
	}
	Zombie stack("Stack3");
	delete heap;
	stack.announce();
}
