#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
private:
	std::string _name;
	std::string _effects;

public:
	ASpell(const std::string &name, const std::string &effects);
	ASpell(const ASpell &other);
	virtual ~ASpell();

	ASpell &operator=(const ASpell &other);

	std::string getName() const;
	std::string getEffects() const;
	void	launch(ATarget &launch) const;
	virtual ASpell *clone() const = 0;
};

#endif