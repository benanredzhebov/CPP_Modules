#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it = book.begin();
	if (it != book.end())
	{
		delete it->second;
		it++;
	}
	book.clear();
}
void SpellBook::learnSpell(ASpell *spellPtr)
{
	if (spellPtr)
		book.insert(std::pair<std::string, ASpell *>(spellPtr->getName(), spellPtr->clone()));
}
void SpellBook::forgetSpell(std::string const &spell)
{
	if (book.find(spell) != book.end())
		delete book[spell];
	book.erase(spell);
}
ASpell *SpellBook::createSpell(std::string const &spell) {
	if (book.find(spell) != book.end())
		return book[spell];
	return NULL;
}