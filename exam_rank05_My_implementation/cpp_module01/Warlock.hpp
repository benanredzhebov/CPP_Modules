#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "./ASpell.hpp"
#include "./ATarget.hpp"

class Warlock {
	private:
		std::string	name;
		std::string	title;

		Warlock();
		Warlock(const Warlock &);
		Warlock &operator=(const Warlock &);

		 std::map<std::string, ASpell *> book;
	public:
		Warlock(std::string _name, std::string _title);
		~Warlock();

		std::string	getName() const;

		std::string	getTitle() const;

		void		setTitle(const std::string &newTitle);

		void		introduce() const;

		void	learnSpell(ASpell* spellPtr);
		void	forgetSpell(std::string spell);
		void	launchSpell(std::string spell, ATarget const &target);
};

#endif