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
	void Load_attack();
	void ShowMan(int start, int end, int map, int maingirl_state, bool stop, int maingirl_left, bool maingirl_stop_left);
	void follow(int maingirl_state, int maingirl_left, int maingirl_top, bool maingirl_stop_left);
	bool const get_being_attacking_state();
	bool const get_stop_state();
	CMovingBitmap ManState[6];
	bool dead = false;
	static std::vector<Man*> dead_man;
protected:
	bool being_attacking = false;
	bool not_stop_state = false;
	int girl = 0;
	int delay = 0;
	static int total_follower;
	int follower_rank = 0;
	bool left = false;
	CMovingBitmap flash;
	CMovingBitmap weakening;
	CMovingBitmap blood;
private:
	void ManMove(int start, int end, int map, int maingirl_state);
};

#endif