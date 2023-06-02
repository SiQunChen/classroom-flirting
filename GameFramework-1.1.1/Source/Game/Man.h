#pragma once

#include "UI.h"
#include "../Library/gameutil.h"

class Man : public game_framework::CMovingBitmap
{
public:
	Man() = default;
	virtual ~Man() {}
	virtual void Load_state() = 0;
	void Load();
	void ShowMan(int start, int end, int map, int maingirl_state, bool stop, int maingirl_left, bool maingirl_stop_left, bool beauty_time, bool evolution, int bump_delay, Score* score_sys);
	void follow(int maingirl_state, int maingirl_left, int maingirl_top, bool maingirl_stop_left);
	bool const get_being_attacking_state();
	bool const get_stop_state();
	CMovingBitmap ManState[6];
	bool dead = false;
	static std::vector<Man*> dead_man;
	static int man_stop;
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
	CMovingBitmap man_on_bottom_small_heart;
	CMovingBitmap man_on_top_small_heart;
	CMovingBitmap man_on_bottom_big_heart;
	CMovingBitmap man_on_top_big_heart;
private:
	void modify_hp(Score* score_sys);
	bool get_small_heart = false;
	bool get_big_heart = false;
	int count_girl(int maingirl_state, bool evolution, int bump_delay);
	void ManMove(int start, int end, int map, int maingirl_state, bool evolution, int bump_delay);
	void heart(int maingirl_state, int maingirl_left, bool evolution, int bump_delay, Score* score_sys);
	bool touch(int main, int target);
	int blood_in_beauty_time = 1;
};