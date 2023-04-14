#ifndef NORMALMAN3
#define NORMALMAN3
#include "Man.h"

class Normalman3 : public Man
{
public:
	Normalman3() = default;
	~Normalman3() {}
	void Load_alive_left() override;
	void Load_alive_right() override;
	void Load_dead_left() override;
	void Load_dead_right() override;
	void Load_follow_left() override;
	void Load_follow_right() override;
private:

};

#endif // !NORMALMAN_H
