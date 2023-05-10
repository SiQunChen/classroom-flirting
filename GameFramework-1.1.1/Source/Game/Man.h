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
	void Load_flash_and_weakening();
	void ShowMan(int start, int end, int map, int maingirl_state, bool stop, int maingirl_left);
	bool const get_being_attacking_state();
	CMovingBitmap ManState[6];
protected:
	bool being_attacking = false;
private:
	int girl = 0;
	bool left = false;
	CMovingBitmap flash;
	CMovingBitmap weakening;
};

#endif