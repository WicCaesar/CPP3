/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:13:10 by cnascime          #+#    #+#             */
/*   Updated: 2024/02/19 03:20:05 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	srand(time(NULL)); // Setting the seed for the random number generator.

	std::cout << RED "🤖 Boas-vindas à rinha de robôs! 🤖" RESET << std::string(2, '\n');

	std::cout << RED "🤖 Linha de produção, montagem e despacho! 🤖" RESET << std::endl;
	ClapTrap robot("Palmolívia");
	ScavTrap robot0("C4354R");
	ScavTrap robot1("Karacc");
	ClapTrap robot2(robot1);
	ClapTrap robot3;
	FragTrap robot4("C++rigor");
	FragTrap robot5;

	std::cout << std::endl;
	std::cout << RED "🤖 Bate aqui! 🤖" RESET << std::endl;
	robot4.highFivesGuys();

	std::cout << std::endl;
	std::cout << RED "🤖 Guardas! Guardas! 🤖" RESET << std::endl;
	robot1.guardGate();
	robot1.guardGate();

	std::cout << std::endl;
	std::cout << RED "🤖 Sobrecarga! Sobrecarga! 🤖" RESET << std::endl;
	std::string temp = robot1.get_name();
	robot4 = robot5;
	std::cout << "Agora " << temp << " se chama " << robot5.get_name() << "." << std::endl;

	std::cout << std::endl;
	std::cout << RED "🤖 Inicialização dos atributos! 🤖" RESET << std::endl;
	std::cout << robot5.get_name() << " é um modelo de ScavTrap com tecnologia de ponta. Seus atributos de fábrica são:" << std::endl;
	robot5.DisplayStats();
	robot1.DisplayStats();
	robot3.DisplayStats();

	std::cout << std::endl;
	std::cout << RED "🤖 Prazeres violentos têm fins violentos! 🤖" RESET << std::endl;
	robot1.attack(robot3.get_name());
	robot3.takeDamage(robot1.get_damage());
	robot3.beRepaired(robot1.get_damage());
	robot.attack("C4354R");
	robot0.takeDamage(4);
	robot0.beRepaired(2);
	robot0.attack("Palmolívia");
	robot.takeDamage(6);
	robot.beRepaired(1);
	robot.attack("C4354R");
	robot0.takeDamage(3);
	robot.beRepaired(2);
	robot0.attack("Palmolívia");
	robot.takeDamage(1);
	robot.attack("C4354R");
	robot0.takeDamage(3);
	robot.beRepaired(1);
	robot.beRepaired(1);
	robot.beRepaired(1);
	robot.beRepaired(2);
	robot0.attack("Palmolívia");
	robot.takeDamage(5);
	robot.beRepaired(1);
	robot.beRepaired(1);
	robot.attack("C4354R");
	robot0.attack("Palmolívia");
	robot.takeDamage(7);
	robot.beRepaired(1);
	robot0.DisplayStats();
	std::cout << std::endl;

	std::cout << RED "🤖 Reticulando retículos reticulados! 🤖" RESET << std::endl;
}
