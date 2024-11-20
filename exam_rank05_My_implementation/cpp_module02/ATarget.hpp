#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
private:
	std::string _type;

public:
	ATarget(const std::string &type);
	ATarget(const ATarget &other);
	virtual ~ATarget();

	ATarget &operator=(const ATarget &other);

	std::string getType() const;
	void	getHitBySpell(const ASpell &hit) const;
	virtual ATarget *clone() const = 0;
};

#endif