#ifndef SPECIALMAN2
#define SPECIALMAN2
#include "Man.h"

class Specialman2 : public Man
{
public:
	Specialman2() = default;
	~Specialman2() {}
	void Load_alive_left() override;
	void Load_alive_right() override;
	void Load_dead_left() override;
	void Load_dead_right() override;
	void Load_follow_left() override;
	void Load_follow_right() override;
private:
	
};

#endif // !SPECIAL_H