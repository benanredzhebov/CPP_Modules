#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall : public ATarget
{
public:
	BrickWall();
	BrickWall(const std::string &type);
	~BrickWall();

	virtual BrickWall *clone() const;
};

#endif