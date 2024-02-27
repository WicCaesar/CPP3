/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:58:45 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/19 03:04:49 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
static std::string	OilBaptism(void) {
	std::string	names[] = {"Scrappy", "Skavva", "Fossora", "Cavucar-cavucar",
	"Karranka", "Trölla-Gabba", "Annorex", "Partevacas", "Amanda Noodles",
	"Jooj Trappynho", "Arroboboi", "0xumar3", "Kwenkwen", "Enzo", "Sovaco"};
	return (names[rand() % 15]);
};
*/

ScavTrap::ScavTrap(void) : ClapTrap(get_name()) {
	//this->set_name(OilBaptism());
	this->set_health(100);
	this->set_energy(50);
	this->set_damage(20);
	this->is_guarding_ = false;
	std::cout << YELLOW "ScavTrap " << this->get_name() << " padrão montado." RESET << std::endl;
};

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name){
	this->set_health(100);
	this->set_energy(50);
	this->set_damage(20);
	this->is_guarding_ = false;
	std::cout << YELLOW "ScavTrap " << this->get_name() << " montado." RESET << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	*this = copy; // Copying the pointer, not the content, is a shallow copy.
	std::cout << ORANGE "Modelo do mesmo lote de " << copy.get_name() << " resgatado da reciclagem." RESET << std::endl;
};

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy) {
	this->set_name(copy.get_name());
	this->set_health(copy.get_health());
	this->set_energy(copy.get_energy());
	this->set_damage(copy.get_damage());
	this->is_guarding_ = copy.is_guarding_;
	std::cout << ORANGE "Sobrecarga do operador de atribuição e cópia! "
			  << "ScavTrap " << copy.get_name() << " enviado para recall. " RESET << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << GREY << this->get_name() << " foi para o ferro-velho do umbral." RESET << std::endl;
	// name_.clear(); // Clearing the string is a good practice, but here it would make names disappear.
};

void	ScavTrap::attack(const std::string &target) {
	if (this->get_energy() > 0) {
		this->set_energy(get_energy() - 1);
		std::cout << RED << this->get_name() << " esmurrou " << target << "!" RESET << std::endl;
		//target.takeDamage(this->damage_);
	} else {
		std::cout << CYAN << this->get_name() << " já não aguenta nem segurar um palito de fósforo!" RESET << std::endl;
	}
};

void	ScavTrap::guardGate(void) {
	if (this->is_guarding_ == true) {
		std::cout << PURPLE << this->get_name() << " já está vigiando o umbral." RESET << std::endl;
	} else {
		this->is_guarding_ = true;
		std::cout << PURPLE << this->get_name() << " vai vigiar o umbral." RESET << std::endl;
	}
}
