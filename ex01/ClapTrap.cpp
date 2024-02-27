/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:13:06 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/16 11:22:49 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static std::string	OilBaptism(void) {
	std::string	names[] = {"Crankrants", "Recramarquim", "Carabroca", "Robayt",
	"Marlene macOS", "Tony RAM", "Bariatrik", "Craquenilson", "Robodrigo Xoox",
	"Jujoodopix", "Méquistil", "Cliftcloftistil", "Bibip", "Crinjj", "Sucato"};
	return (names[rand() % 15]);
};

ClapTrap::ClapTrap(void) {
	this->name_ = OilBaptism();
	this->health_ = 10;
	this->energy_ = 10;
	this->damage_ = 0;
	std::cout << YELLOW "ClapTrap " << this->name_ << " padrão montado." RESET << std::endl;
};

ClapTrap::ClapTrap(const std::string &name) {
	this->name_ = name;
	this->health_ = 10;
	this->energy_ = 10;
	this->damage_ = 0;
	std::cout << YELLOW "ClapTrap " << this->name_ << " montado." RESET << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy; // Copying the pointer, not the content, is a shallow copy.
	std::cout << ORANGE "Modelo do mesmo lote de " << copy.name_ << " resgatado da reciclagem." RESET << std::endl;
};

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy) {
	this->set_name(copy.name_);
	this->set_health(copy.health_);
	this->set_energy(copy.energy_);
	this->set_damage(copy.damage_);
	std::cout << ORANGE "Sobrecarga do operador de atribuição e cópia! "
			  << "ClapTrap " << copy.get_name() << " enviado para recall. " RESET << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << GREY << this->name_ << " foi para o ferro-velho do céu." RESET << std::endl;
	// name_.clear(); // Clearing the string is a good practice, but here it would make names disappear.
};

std::string	ClapTrap::get_name(void) const {
	return (this->name_);
};

int	ClapTrap::get_health(void) const {
	return (this->health_);
};

int	ClapTrap::get_energy(void) const {
	return (this->energy_);
};

int	ClapTrap::get_damage(void) const {
	return (this->damage_);
};

void	ClapTrap::set_name(const std::string name) {
	this->name_ = name;
};

void	ClapTrap::set_health(int health) {
	this->health_ = health;
};

void	ClapTrap::set_energy(int energy) {
	this->energy_ = energy;
};

void	ClapTrap::set_damage(int damage) {
	this->damage_ = damage;
};

void	ClapTrap::attack(const std::string &target) {
	if (this->energy_ > 0) {
		this->energy_--;
		std::cout << RED << this->name_ << " atacou " << target << "!" RESET << std::endl;
		//target.takeDamage(this->damage_);
	} else {
		std::cout << CYAN << this->name_ << " já não aguenta nem segurar uma chave de fenda!" RESET << std::endl;
	}
};

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << RED << this->name_ << " apanhou e perdeu " << amount << " de vigor." RESET << std::endl;
	this->health_ -= amount;
	if (this->health_ <= 0) {
		std::cout << RED "Circuitos internos foram completamente danificados." RESET << std::endl;
		this->~ClapTrap();
	}
};

// Displays a random repair action.
static std::string	RandomAction(void) {
	std::string	actions[] = {" apertou uns parafusos", " soldou placas soltas",
	" passou bastante lubrificante", " reiniciou o sistema operacional",
	" esvaziou a lixeira", " limpou o cache", " desfragmentou seu disco rígido",
	" trocou a bateria", " atualizou o firmware", " aspirou o pó dos coolers",
	" tirou todos os cabos do roteador e os religou após 10 segundos"};
	return (actions[rand() % 11]);
};

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->health_ <= 0) {
		std::cout << GREY << this->name_ << " já virou sucata, não há reparo." RESET << std::endl;
		return ;
	}
	/*
	if (this->health_ >= 10) {
		std::cout << CYAN << this->name_ << " está tinindo, não precisa de reparos." RESET << std::endl;
		return ;
	}
	*/
	if (this->energy_ <= 0) {
		std::cout << CYAN << this->name_ << " não tem mais fôlego nem para assoprar a poeira!" RESET << std::endl;
		return ;
	}
	this->energy_--;
	this->health_ += amount;
	std::cout << GREEN << this->name_ << RandomAction() << " e agora aguenta \
mais porrada! Seu vigor atual é " << this->health_ << "." RESET << std::endl;
}

void	ClapTrap::DisplayStats(void) {
	std::cout << MAGENTA << "Nome: " << this->name_ << "\t"
			  << "Vigor: " << this->health_ << "\t"
			  << "Bateria: " << this->energy_ << "\t"
			  << "Dano: " << this->damage_ << std::endl;
};

/*
std::ostream	&operator<<(std::ostream &output, const ClapTrap &claptrap) {
	output << claptrap.get_name();
	return (output);
}
*/
