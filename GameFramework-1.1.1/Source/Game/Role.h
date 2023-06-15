#pragma once

#include "UI.h"
#include "../Library/gameutil.h"

class Main_girl : public game_framework::CMovingBitmap
{
public:
	Main_girl() = default;
	void Load_main();
	void Load_walk_left();
	void Load_walk_right();
	void Load_run_left();
	void Load_run_right();
	void Load_beauty_time_left();
	void Load_beauty_time_right();
	void Load_bump_left();
	void Load_bump_right();
	void Load_lose_left();
	void Load_lose_right();
	void Load_over_notice_left();
	void Load_over_left();
	void Load_over_notice_right();
	void Load_over_right();
};

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
	CMovingBitmap clicking_bar;
	bool dead = false;
	static std::vector<Man*> dead_man;
	static int man_stop;
	static bool click;
	static bool click_win;
	static bool click_lose;
	bool lose = false;
	static bool clicking;
protected:
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
	CMovingBitmap man_on_bottom_small_heart;
	CMovingBitmap man_on_top_small_heart;
	CMovingBitmap man_on_top_big_heart;
	CMovingBitmap over_score;
private:
	CMovingBitmap flash;
	CMovingBitmap flash_multiple;
	CMovingBitmap weakening;
	CMovingBitmap blood;
	void ManMove(int start, int end, int map);
	int blood_in_beauty_time = 1;
	bool add = false;
	bool this_man_is_be_clicked = false;
	int attack = 5;
	bool set_click_bar = false;
};

class Girl : public game_framework::CMovingBitmap
{
public:
	Girl() = default;
	virtual ~Girl() {}
	virtual void Load() = 0;
	void ShowGirl(int start, int end, int map, int maingirl_state, bool stop, int maingirl_left, bool beauty_time, bool evolution, int stop_man_left, int bump_delay, int over_delay);
	void fly();
	int get_how_many_girl_in_view();
	static int fly_out;
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
	static std::vector<Girl*> shooting_girl;
private:
	int girl = 0;
	int count_girl(int maingirl_state, bool evolution, int bump_delay, int over_delay);
	void GirlMove(int start, int end, int map);
	bool left = false;
	int delay = 0;
	bool girl_stop = false;
	bool dead = false;
	bool init_delay = false;
};

class Teacher : public game_framework::CMovingBitmap
{
public:
	Teacher() = default;
	~Teacher() {}
	void Load();
	void ShowTeacher(bool left, int maingirl_state, int maingirl_left, bool evolution, int bump_delay, int over_delay, bool up_down_floor);
	void Setup(bool left);
	static bool bump;
private:
	void modify_hp();
	int girl;
	int count_girl(int maingirl_state, bool evolution, int bump_delay, int over_delay);
	bool touch(int main, int target);
	int delay = 0;
	CMovingBitmap teacher_left;
	CMovingBitmap teacher_right;
};