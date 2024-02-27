/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 02:35:30 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/19 03:06:22 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &copy);
		FragTrap	&operator=(const FragTrap &copy);
		~FragTrap(void);
		
		void	attack(const std::string &target);
		void	highFivesGuys(void);
};

#endif
