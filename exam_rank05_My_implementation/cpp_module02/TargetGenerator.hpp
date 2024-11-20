#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include "BrickWall.hpp"
#include <map>

class TargetGenerator
{
private:
	TargetGenerator(const TargetGenerator &);
	TargetGenerator &operator=(const TargetGenerator &other);
	std::map<std::string, ATarget *> book;

public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget *targetPtr);
	void forgetTargetType(std::string const &target);
	ATarget *createTarget(std::string const &target);
};

#endif