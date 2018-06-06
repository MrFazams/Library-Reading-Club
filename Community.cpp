#include "Community.h"



Community::Community()
{
}


Community::~Community()
{
}

int Community::getReadingRank() const
{
	int max = 0;
	for (int i = 0; i < this->getSize(); i++) {
		if ((*this)[i].getReadingRank() > max) max = (*this)[i].getReadingRank();
	}
	return max;
}
