#include "./ATarget.hpp"

ATarget::ATarget(const std::string &_type) : type(_type) {}

ATarget::ATarget(const ATarget &other) {
	*this = other;
}

ATarget::~ATarget() {}

ATarget &ATarget::operator=(const ATarget &other) {
	if (this != &other) {
		type = other.type;
	}
	return (*this);
}

std::string ATarget::getType() const {
	return type;
}

void ATarget::getHitBySpell(const ASpell &spell) const{
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}