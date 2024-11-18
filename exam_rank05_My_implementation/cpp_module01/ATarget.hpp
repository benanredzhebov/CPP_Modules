#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "./ASpell.hpp"

class ASpell;

class ATarget {
	protected:
		std::string	type;

	public:
		ATarget(const std::string &_type);
		ATarget(const ATarget &other);
		virtual ~ATarget();

		ATarget &operator=(const ATarget &other);

		std::string getType() const;

		virtual ATarget* clone() const = 0;

		void	getHitBySpell(const ASpell &spell) const;
};

#endif