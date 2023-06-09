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
	bool ShowMan(int start, int end, int map, int maingirl_state, bool stop, int maingirl_left, bool maingirl_stop_left, bool beauty_time, bool evolution, int bump_delay, Score* score_sys, int over_delay);
	void follow(int maingirl_state, int maingirl_left, int maingirl_top, bool maingirl_stop_left);
	bool const get_being_attacking_state();
	bool const get_stop_state();
	int const get_vector_size();
	void over(Score* score_sys, bool over_left);
	CMovingBitmap ManState[6];
	bool dead = false;
	static std::vector<Man*> dead_man;
	static int man_stop;
protected:
	CMovingBitmap clicking_bar[68];
	bool get_heart = false;
	int count_girl(int maingirl_state, bool evolution, int bump_delay, int over_delay);
	bool touch(int main, int target);
	virtual int modify_hp(Score* score_sys) = 0;
	virtual int heart(int maingirl_left, Score* score_sys) = 0;
	virtual int get_score() = 0;
	bool being_attacking = false;
	bool not_stop_state = false;
	int girl = 0;
	int score = 0;
	int delay = 0;
	static int total_follower;
	int follower_rank = 0;
	bool left = false;
	CMovingBitmap flash;
	CMovingBitmap weakening;
	CMovingBitmap blood;
	CMovingBitmap man_on_bottom_small_heart;
	CMovingBitmap man_on_top_small_heart;
	CMovingBitmap man_on_top_big_heart;
	CMovingBitmap over_score;
private:
	void ManMove(int start, int end, int map);
	int blood_in_beauty_time = 1;
	bool add = false;
};