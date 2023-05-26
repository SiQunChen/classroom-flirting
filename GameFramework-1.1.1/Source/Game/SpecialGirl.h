#ifndef SPECIALGIRL
#define SPECIALGIRL
#include "Girl.h"

class Specialgirl : public Girl
{
public:
	Specialgirl() = default;
	~Specialgirl() {}
	void Load() override;
private:

};

#endif