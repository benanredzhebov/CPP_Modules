#include "ATarget.hpp"

ATarget::ATarget(const std::string &type) : _type(type) {}
ATarget::ATarget(const ATarget &other)
{
	*this = other;
}
ATarget::~ATarget() {}

ATarget &ATarget::operator=(const ATarget &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

std::string ATarget::getType() const
{
	return _type;
}

void	ATarget::getHitBySpell(const ASpell &hit) const {
	std::cout << _type << " has been " << hit.getEffects() << "!" <<std::endl;
}