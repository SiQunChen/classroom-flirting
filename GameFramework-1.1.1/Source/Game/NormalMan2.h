#ifndef NORMALMAN2
#define NORMALMAN2
#include "Man.h"

class Normalman2 : public Man
{
public:
	Normalman2() = default;
	~Normalman2() {}
	void Load_alive_left() override;
	void Load_alive_right() override;
	void Load_dead_left() override;
	void Load_dead_right() override;
	void Load_follow_left() override;
	void Load_follow_right() override;
private:

};

#endif // !NORMALMAN_H