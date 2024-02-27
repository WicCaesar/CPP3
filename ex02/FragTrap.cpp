/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 02:40:23 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/19 03:11:21 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap(get_name()) {	
	this->set_health(100);
	this->set_energy(100);
	this->set_damage(30);
	std::cout << YELLOW "FragTrap " << this->get_name() << " padrão montado." RESET << std::endl;
};

FragTrap::FragTrap(const std::string &name) : ClapTrap(name){
	this->set_health(100);
	this->set_energy(100);
	this->set_damage(30);
	std::cout << YELLOW "FragTrap " << this->get_name() << " montado." RESET << std::endl;
};

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	*this = copy; // Copying the pointer, not the content, is a shallow copy.
	std::cout << ORANGE "Modelo do mesmo lote de " << copy.get_name() << " resgatado da reciclagem." RESET << std::endl;
};

FragTrap	&FragTrap::operator=(const FragTrap &copy) {
	this->set_name(copy.get_name());
	this->set_health(copy.get_health());
	this->set_energy(copy.get_energy());
	this->set_damage(copy.get_damage());
	std::cout << ORANGE "Sobrecarga do operador de atribuição e cópia! "
			  << "FragTrap " << copy.get_name() << " enviado para recall. " RESET << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << GREY << this->get_name() << " foi para o ferro-velho do inferno." RESET << std::endl;
	// name_.clear(); // Clearing the string is a good practice, but here it would make names disappear.
};

void	FragTrap::attack(const std::string &target) {
	if (this->get_energy() > 0) {
		this->set_energy(get_energy() - 1);
		std::cout << RED << this->get_name() << " esmurrou " << target << "!" RESET << std::endl;
		//target.takeDamage(this->damage_);
	} else {
		std::cout << CYAN << this->get_name() << " já não aguenta nem segurar um cotonete!" RESET << std::endl;
	}
};

void	FragTrap::highFivesGuys(void) {
	std::cout << BLUE << this->get_name() << " saúda os colegas!" RESET << std::endl;
};
