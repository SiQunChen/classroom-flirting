#pragma once

#include "Role.h"

class Specialgirl : public Girl
{
public:
	Specialgirl() = default;
	~Specialgirl() {}
	void Load() override;
};
