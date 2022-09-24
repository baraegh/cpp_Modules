/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:12:43 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/09/23 22:33:47 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(std::string	name);
		~Zombie();
		void	announce(void);
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif