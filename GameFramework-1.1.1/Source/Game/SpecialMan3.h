#ifndef SPECIALMAN3
#define SPECIALMAN3
#include "Man.h"

class Specialman3 : public Man
{
public:
	Specialman3() = default;
	~Specialman3() {}
	void Load_alive_left() override;
	void Load_alive_right() override;
	void Load_dead_left() override;
	void Load_dead_right() override;
	void Load_follow_left() override;
	void Load_follow_right() override;
private:
	
};

#endif // !SPECIAL_H