#pragma once

#include "Role.h"

class Normalman1 : public Man
{
public:
	Normalman1() = default;
	~Normalman1() {}
	void Load_state() override;
	int get_score() override;
private:
	int heart(int maingirl_left, Score* score_sys) override;
	int modify_hp(Score* score_sys) override;
};

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