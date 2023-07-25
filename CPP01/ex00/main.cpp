/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:03:18 by jonchoi           #+#    #+#             */
/*   Updated: 2023/07/24 02:47:35 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *heap;

	heap = newZombie("Heap");
	heap->announce();

	randomChump("Stack1");

	{
		Zombie stack("Stack2");
		stack.announce();
	}
	Zombie stack("Stack3");
	delete heap;
	stack.announce();
	return (0);
}
