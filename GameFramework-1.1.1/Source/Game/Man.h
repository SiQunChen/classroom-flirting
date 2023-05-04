#ifndef MAN
#define MAN

#include "../Library/gameutil.h"

class Man : public game_framework::CMovingBitmap
{
public:
	Man() = default;
	virtual ~Man() {}
	virtual void Load_alive_left() = 0;
	virtual void Load_alive_right() = 0;
	virtual void Load_dead_left() = 0;
	virtual void Load_dead_right() = 0;
	virtual void Load_follow_left() = 0;
	virtual void Load_follow_right() = 0;
	void ShowMan(int start, int end, int map, int maingirl_state, bool stop, int maingirl_left);
	CMovingBitmap ManState[6];
protected:

private:
	int girl = 0;
	bool left = false;
};

#endif