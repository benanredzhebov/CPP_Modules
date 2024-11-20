#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
private:
	SpellBook(const SpellBook &other);
	SpellBook &operator=(const SpellBook &other);
	std::map<std::string, ASpell *> book;

public:
	SpellBook();
	~SpellBook();
	void learnSpell(ASpell *spellPtr);
	void forgetSpell(std::string const &spell);
	ASpell* createSpell(std::string const &target);
};

#endif