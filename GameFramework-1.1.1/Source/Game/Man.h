#ifndef MAN
#define MAN

#include "../Library/gameutil.h"

class Man : public game_framework::CMovingBitmap
{
public:
	Man() = default;
	virtual ~Man(){}
	virtual void Load_alive_left() = 0;
	virtual void Load_alive_right() = 0;
	virtual void Load_dead_left() = 0;
	virtual void Load_dead_right() = 0;
	virtual void Load_follow_left() = 0;
	virtual void Load_follow_right() = 0;
protected:

};

#endif