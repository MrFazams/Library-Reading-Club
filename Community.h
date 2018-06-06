#ifndef COMMUNITY_H
#define COMMUNITY_H

#include "Set.h"
#include "Reader.h"

class Community : public Set<Reader>
{
public:

	Community();
	~Community();

	int getReadingRank() const;

};

#endif COMMUNITY_H