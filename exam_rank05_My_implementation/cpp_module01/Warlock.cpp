#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	std::map<std::string, ASpell *>::iterator it = book.begin();
	if (it != book.end())
	{
		delete it->second;
		++it;
	}
	book.clear();
}
std::string Warlock::getName() const
{
	return _name;
}
std::string Warlock::getTitle() const
{
	return _title;
}
void Warlock::setTitle(const std::string &newTitle)
{
	_title = newTitle;
}
void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spellPtr)
{
	if (spellPtr)
		book.insert(std::pair<std::string, ASpell *>(spellPtr->getName(), spellPtr->clone()));
}
void Warlock::forgetSpell(std::string spell)
{
	if (book.find(spell) != book.end()){
		delete book[spell];
	}
	book.erase(spell);
}
void Warlock::launchSpell(std::string spell, ATarget &target)
{
	if (book.find(spell) != book.end())
		book[spell]->launch(target);
}