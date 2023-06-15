#pragma once

#include "Man.h"

class Specialman1 : public Man
{
public:
	Specialman1() = default;
	~Specialman1() {}
	void Load_state() override;
	int get_score() override;
private:
	int heart(int maingirl_left, Score* score_sys) override;
	int modify_hp(Score* score_sys) override;
};
