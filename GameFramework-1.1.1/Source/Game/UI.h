#pragma once
#include "../Library/gameutil.h"

class HDYLM_sys : public game_framework::CMovingBitmap {
public:
	HDYLM_sys() = default;
	~HDYLM_sys() = default;
	int how_much_do_you_love_me = 0;
	bool kill_man_earn_score(bool is_being_attack_state, int how_do_you_love_me_max);
	bool flirting_earn_score(bool is_stop_state);
private:
	bool flirting = false;
	bool killed = false;
	int cd_time = 0;
};

class Score : public game_framework::CMovingBitmap {
public:
	Score();
	~Score()=default;
	int score;					// 總成績
	int get_score();
	//! can't be used
	void load_ui_score_num();
	void show_score();
private:
	//! 收服的男生數量寫在男生那邊，UI這裡用一個 getter拿值，計算總成績
	int this_num;
	CMovingBitmap score_posision[8];		// 0 is the right
	CMovingBitmap score_board;
	CMovingBitmap score_num[10];
};


class Audio : public game_framework::CMovingBitmap {
public:
	Audio()=default;
	void load_ui_audio();
private:
	// min = 1;
	// max = 5;
	// to be fix
	int audio_levle;
	CMovingBitmap audio_button[4];
};

class Clock : public game_framework::CMovingBitmap {
public:
	Clock();
	int get_max_time_second();
	int get_time_left_second();
	void load_ui_clock_board();
	void load_ui_clock_tick();
private:
	int time;					// current time
	int time_left;				// max_time - time
	const int max_time = 60;			// maximum time of the game
	CMovingBitmap clock;
	CMovingBitmap clock_back;
	CMovingBitmap clock_pointer;
};

class HP : public game_framework::CMovingBitmap {
public:
	HP();
	static int hp;									// with maximum HP 900
	bool is_invincible();
	//! can't be used
	void load_ui_hp_board();
	void load_ui_hp_num();
	void show_hp();
	void shine_hp();
	void show_invincible();
	void show_invincible_start();
	void show_invincible_end();
	void show_invincible_bar();
	
	//! beauty time寫在女主角那邊，UI這裡用一個getter 拿布林，顯示無敵時間
	bool bool_invincible_state;

private:
	//! HP寫在女主角那邊，UI這裡用一個getter 拿值，再想怎麼load血量的圖片
	CMovingBitmap hp_board;
	CMovingBitmap hp_posision[9];			// 0 is the left
	CMovingBitmap hp_heart[20];
	CMovingBitmap hp_heart_warning;
	int shine_cd = 0;
	const int total_delay = 54;				// cycle
	int invincible_time = 0;
	CMovingBitmap invincible_board;
	CMovingBitmap invincible_inner;
	CMovingBitmap invincible_animate[6];
};

class Elevator : public game_framework::CMovingBitmap {
public:
	Elevator();
	void load_ui_elevator();
private:
	int current_floor;
	//! 上下樓梯的按鈕應該要放過來
	CMovingBitmap up;
	CMovingBitmap down;
}; 
