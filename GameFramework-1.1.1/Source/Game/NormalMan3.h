#ifndef NORMALMAN3
#define NORMALMAN3
#include "Man.h"

class Normalman3 : public Man
{
public:
	Normalman3() = default;
	~Normalman3() {}
	void Load_state() override;
	int get_score() override;
private:
	void heart(int maingirl_left, Score* score_sys) override;
	void modify_hp(Score* score_sys) override;
};

#endif // !NORMALMAN_H