#pragma once

#include "Man.h"

class Normalman2 : public Man
{
public:
	Normalman2() = default;
	~Normalman2() {}
	void Load_state() override;
	int get_score() override;
private:
	int heart(int maingirl_left, Score* score_sys) override;
	int modify_hp(Score* score_sys) override;
};
