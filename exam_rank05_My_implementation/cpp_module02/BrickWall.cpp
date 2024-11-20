#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}
BrickWall::BrickWall(const std::string &type) : ATarget(type) {}
BrickWall::~BrickWall() {}

BrickWall *BrickWall::clone() const
{
	return new BrickWall;
}