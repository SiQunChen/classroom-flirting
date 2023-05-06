#ifndef SPECIALMAN1
#define SPECIALMAN1
#include "Man.h"

class Specialman1 : public Man
{
public:
	Specialman1() = default;
	~Specialman1() {}
	void Load_alive_left() override;
	void Load_alive_right() override;
	void Load_dead_left() override;
	void Load_dead_right() override;
	void Load_follow_left() override;
	void Load_follow_right() override;
private:
	
};

#endif // !SPECIAL_H