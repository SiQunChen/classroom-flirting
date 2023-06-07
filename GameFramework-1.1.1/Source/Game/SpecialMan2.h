#ifndef SPECIALMAN2
#define SPECIALMAN2
#include "Man.h"

class Specialman2 : public Man
{
public:
	Specialman2() = default;
	~Specialman2() {}
	void Load_state() override;
	int get_score() override;
private:
	void heart(int maingirl_left, Score* score_sys) override;
	void modify_hp(Score* score_sys) override;
};

#endif // !SPECIAL_H