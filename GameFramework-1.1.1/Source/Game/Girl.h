#ifndef GIRL
#define GIRL

#include "../Library/gameutil.h"

class Girl : public game_framework::CMovingBitmap
{
public:
	Girl() = default;
	virtual ~Girl() {}
	virtual void Load() = 0;
	void ShowGirl(int start, int end, int map, int maingirl_state, bool stop, int maingirl_left, bool beauty_time, bool evolution, int stop_man_left, int bump_delay);
	CMovingBitmap walk_left;
	CMovingBitmap walk_right;
	CMovingBitmap fly_left;
	CMovingBitmap fly_right;
	CMovingBitmap win_left;
	CMovingBitmap win_right;
	CMovingBitmap notice_left;
	CMovingBitmap notice_right;
	CMovingBitmap shoot_left;
	CMovingBitmap shoot_right;
	static std::vector<Girl*> dead_girl;
	static int how_many_girl;
protected:
	
private:
	int girl = 0;
	int count_girl(int maingirl_state, bool evolution, int bump_delay);
	void GirlMove(int start, int end, int map, int maingirl_state, bool evolution, int bump_delay);
	bool left = false;
	int delay = 0;
	bool girl_stop = false;
};

#endif