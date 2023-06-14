#pragma once
#include "../Library/gameutil.h"
#include "../Library/audio.h"

class Score : public game_framework::CMovingBitmap {
public:
	Score();
	~Score()=default;
	int score;					// 總成績
	int get_score();
	//! can't be used
	void load_ui_score_num();
	void show_score();
	void over();
private:
	//! 收服的男生數量寫在男生那邊，UI這裡用一個 getter拿值，計算總成績
	int this_num;
	CMovingBitmap score_posision[8];		// 0 is the right
	CMovingBitmap score_board;
	CMovingBitmap score_num[10];
	CMovingBitmap score_end[10];
};


class Audio_sys : public game_framework::CMovingBitmap {
public:
	Audio_sys()=default;
	void load_ui_audio_run();
	void load_ui_audio_init();
	void load_ui_audio_end();
	void load_ui_audio_man();
	void pause();
	void resume();
	void play_ui_audio(int audio_tag);
	void stop_ui_audio(int audio_tag);
private:
	game_framework::CAudio* audio;
	
	// min = 1;
	// max = 5;
	// to be fix
	int audio_levle;
	CMovingBitmap audio_button[4];
};

class Clock : public game_framework::CMovingBitmap {
public:
	void load_ui_clock_board();
	void load_ui_clock_pointer();
	void show_clock_sys();
	bool get_time_over();
	void over_cheat();
private:
	bool time_over = false;
	CMovingBitmap clock;
	CMovingBitmap clock_back;
	CMovingBitmap clock_pointer;
	CMovingBitmap color;
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
	bool show_invincible();
	void show_invincible_start();
	bool show_invincible_end();
	void show_invincible_bar();
	int get_default_hp();
	
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
