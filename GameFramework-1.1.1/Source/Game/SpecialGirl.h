#pragma once

#include "Girl.h"

class Specialgirl : public Girl
{
public:
	Specialgirl() = default;
	~Specialgirl() {}
	void Load() override;
};
