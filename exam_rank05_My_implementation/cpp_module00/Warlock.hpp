#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock {
	private:
		std::string	name;
		std::string	title;

		Warlock();
		Warlock(const Warlock &);
		Warlock &operator=(const Warlock &);
	public:
		Warlock(std::string _name, std::string _title);
		~Warlock();

		std::string	getName() const;

		std::string	getTitle() const;

		void		setTitle(const std::string &newTitle);

		void		introduce() const;
};

#endif