#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "./ATarget.hpp"

class ATarget;

class ASpell {
	protected:
		std::string	name;
		std::string effects;

	public:
		ASpell(const std::string &_name, const std::string &_effects);
		ASpell(const ASpell &other);
		virtual ~ASpell();
		
		ASpell &operator=(const ASpell &other);
		
		std::string	getName() const;
		std::string	getEffects() const;

		virtual ASpell* clone() const = 0;

		void	launch(const ATarget& target);

};

#endif