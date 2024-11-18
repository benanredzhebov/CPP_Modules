#include "./ASpell.hpp"

ASpell::ASpell(const std::string &_name, const std::string &_effects) : name(_name), effects(_effects) {}

ASpell::ASpell(const ASpell &other) {
	*this = other;
}

ASpell::~ASpell() {}

ASpell &ASpell::operator=(const ASpell &other) {
	if (this != &other) {
		name = other.name;
		effects = other.effects;
	}
	return *this;
}

std::string	ASpell::getName() const {
	return name;
}

std::string	ASpell::getEffects() const {
	return effects;
}

void	ASpell::launch(const ATarget& target) {
	target.getHitBySpell(*this);
}
