#ifndef NORMALMAN1
#define NORMALMAN1
#include "Man.h"

class Normalman1 : public Man
{
public:
	Normalman1() = default;
	~Normalman1() {}
	void Load_state() override;
	int get_score() override;
private:
	void heart(int maingirl_left, Score* score_sys) override;
	void modify_hp(Score* score_sys) override;
};

#endif // !NORMALMAN_H