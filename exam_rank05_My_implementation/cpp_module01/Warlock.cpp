#include "./Warlock.hpp"

Warlock::Warlock(std::string _name, std::string _title) : name(_name), title(_title) {
	std::cout << name << ": " << "This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << name << ": " << "My job here is done!" << std::endl;
	std::map<std::string, ASpell *>::iterator it = book.begin();
	while (it != book.end()) {
		delete it->second;
		++it;
	}
	book.clear();
}


std::string Warlock::getName() const {
	return name;
}

std::string Warlock::getTitle() const {
	return title;
}

void	Warlock::setTitle(const std::string &newTitle) {
	title = newTitle;
}

void	Warlock::introduce() const {
	std::cout << name << ": " << "I am " << name << ", " << title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spellPtr) {
	if (spellPtr)
		book.insert(std::pair<std::string, ASpell *>(spellPtr->getName(), spellPtr->clone()));
}

void	Warlock::forgetSpell(std::string spell) {
	if (book.find(spell) != book.end())
		delete book[spell];
	book.erase(spell);
}

void	Warlock::launchSpell(std::string spell, ATarget const &target) {
	if (book.find(spell) != book.end())
		book[spell]->launch(target);
}