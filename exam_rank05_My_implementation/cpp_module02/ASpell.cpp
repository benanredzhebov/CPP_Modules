#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects) : _name(name), _effects(effects) {}
ASpell::ASpell(const ASpell &other)
{
	*this = other;
}
ASpell::~ASpell() {}

ASpell &ASpell::operator=(const ASpell &other)
{
	if (this != &other)
	{
		_name = other._name;
		_effects = other._effects;
	}
	return *this;
}

std::string ASpell::getName() const
{
	return _name;
}
std::string ASpell::getEffects() const
{
	return _effects;
}

void	ASpell::launch(ATarget &launch) const {
	launch.getHitBySpell(*this);
}