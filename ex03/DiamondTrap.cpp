/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 03:22:11 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/21 01:03:23 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(name_ + "_clap_name"), ScavTrap(name_), FragTrap(name_) {
	this->FragTrap::set_health(100);
	this->ScavTrap::set_energy(50);
	this->FragTrap::set_damage(30);
	std::cout << YELLOW "DiamondTrap " << this->ClapTrap::get_name() << " padrão montado." RESET << std::endl;
};

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name){
	this->FragTrap::set_health(100);
	this->ScavTrap::set_energy(50);
	this->FragTrap::set_damage(30);
	std::cout << YELLOW "DiamondTrap " << this->get_name() << " montado." RESET << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(), FragTrap() {
	*this = copy; // Copying the pointer, not the content, is a shallow copy.
	std::cout << ORANGE "Modelo do mesmo lote de " << copy.get_name() << " resgatado da reciclagem." RESET << std::endl;
};

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy) {
	this->ClapTrap::set_name(copy.name_);
	this->FragTrap::set_health(copy.health_);
	this->ScavTrap::set_energy(copy.energy_);
	this->FragTrap::set_damage(copy.damage_);
	std::cout << ORANGE "Sobrecarga do operador de atribuição e cópia! "
			  << "DiamondTrap " << copy.get_name() << " enviado para recall. " RESET << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << GREY << this->name_ << " foi para o ferro-velho do nada." RESET << std::endl;
	// name_.clear(); // Clearing the string is a good practice, but here it would make names disappear.
};

void	DiamondTrap::attack(const std::string &target) {
	this->ScavTrap::attack(target);
};

void	DiamondTrap::whoAmI