#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <map>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
	Warlock();
	Warlock(const Warlock &);
	Warlock &operator=(const Warlock &);
	std::string _name;
	std::string _title;

	// std::map<std::string, ASpell *> book;
	SpellBook book;

public:
	Warlock(const std::string &name, const std::string &title);
	~Warlock();
	std::string getName() const;
	std::string getTitle() const;
	void setTitle(const std::string &newTitle);
	void introduce() const;

	void learnSpell(ASpell *spellPtr);
	void forgetSpell(std::string spell);
	void launchSpell(std::string spell, ATarget &target);
};

#endif