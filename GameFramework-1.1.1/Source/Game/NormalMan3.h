#pragma once

#include "Man.h"

class Normalman3 : public Man
{
public:
	Normalman3() = default;
	~Normalman3() {}
	void Load_state() override;
	int get_score() override;
private:
	int heart(int maingirl_left, Score* score_sys) override;
	int modify_hp(Score* score_sys) override;
};
