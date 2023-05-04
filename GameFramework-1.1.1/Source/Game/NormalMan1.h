#ifndef NORMALMAN1
#define NORMALMAN1
#include "Man.h"

class Normalman1 : public Man
{
public:
	Normalman1() = default;
	~Normalman1() {}
	void Load_alive_left() override;
	void Load_alive_right() override;
	void Load_dead_left() override;
	void Load_dead_right() override;
	void Load_follow_left() override;
	void Load_follow_right() override;
private:
	
};

#endif // !NORMALMAN_H