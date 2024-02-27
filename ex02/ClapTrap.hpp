/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:13:03 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/18 05:24:25 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define RED "\x1b[31m"
# define ORANGE "\x1b[38;5;202m"
# define YELLOW "\x1b[33m"
# define GREEN "\x1b[32m"
# define CYAN "\x1b[36m"
# define BLUE "\x1b[34m"
# define PURPLE "\x1b[38;5;53m"
# define MAGENTA "\x1b[35m"
# define WHITE "\x1b[37m"
# define GREY "\x1b[38;5;240m"
# define RESET "\x1b[0m"

# include <iostream>
# include <cstdlib>

class	ClapTrap {
	private:
		std::string	name_;
		int			health_;
		int			energy_;
		int			damage_;

	public:
		ClapTrap(void);
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &copy);
		ClapTrap	&operator=(const ClapTrap &copy);
		~ClapTrap(void);

		std::string	get_name(void) const;
		int			get_health(void) const;
		int			get_energy(void) const;
		int			get_damage(void) const;

		void	set_name(const std::string name);
		void	set_health(const int health);
		void	set_energy(const int energy);
		void	set_damage(const int damage);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	DisplayStats(void);
};

//std::ostream	&operator<<(std::ostream &output, const ClapTrap &claptrap);

#endif
