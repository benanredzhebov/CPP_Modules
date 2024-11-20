#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it = book.begin();
	if (it != book.end())
	{
		delete it->second;
		++it;
	}
	book.clear();
}
// TargetGenerator &operator=(const TargetGenerator &other);

void TargetGenerator::learnTargetType(ATarget *targetPtr)
{
	if (targetPtr)
	{
		book.insert(std::pair<std::string, ATarget *>(targetPtr->getType(), targetPtr->clone()));
	}
}
void TargetGenerator::forgetTargetType(std::string const &target) {
	if (book.find(target) != book.end())
		delete book[target];
	book.erase(target);
}
ATarget *TargetGenerator::createTarget(std::string const &target) {
	if (book.find(target) != book.end())
		return book[target];
	return NULL;
}