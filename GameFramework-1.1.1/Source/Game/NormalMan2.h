#ifndef NORMALMAN2
#define NORMALMAN2
#include "Man.h"

class Normalman2 : public Man
{
public:
	Normalman2() = default;
	~Normalman2() {}
	void Load_state() override;
	int get_score() override;
private:
	void heart(int maingirl_left, Score* score_sys) override;
	void modify_hp(Score* score_sys) override;
};

#endif // !NORMALMAN_H