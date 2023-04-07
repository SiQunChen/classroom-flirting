#pragma once
#include "../Library/gameutil.h"

class UI : public game_framework::CMovingBitmap{
public:
	UI();
};

/**
 * dirive class below
 */

class Score : public UI {
public:
	Score();
	int get_score();
	//! can't be used
	void load_ui_score_board();
	void load_ui_score_num();
private:
	//! 收服的男生數量寫在男生那邊，UI這裡用一個 getter拿值，計算總成績
	int score;					// 總成績
	CMovingBitmap score_board;
	CMovingBitmap score_num[8];
};


class Audio : public UI {
public:
	Audio();
	void load_ui_audio();
private:
	/*
	 * min = 1;
	 * max = 5;
	 * to be fix
	 */
	int audio_levle;
	CMovingBitmap audio_button[4];
};

class Clock : public UI {
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

class HP : public UI {
public:
	HP();
	float get_hp();
	bool is_invincible();
	//! can't be used
	void load_ui_hp_board();
	void load_ui_hp_num();
private:
	//! HP寫在女主角那邊，UI這裡用一個getter 拿值，再想怎麼load血量的圖片
	float hp;					// HP
	CMovingBitmap hp_board;
	CMovingBitmap hp_heart[20];
	CMovingBitmap hp_heart_warning;
	
	//! beauty time寫在女主角那邊，UI這裡用一個getter 拿布林，顯示無敵時間
	bool bool_invincible_state;
	CMovingBitmap invincible_board;
};

class Elevator : public UI {
public:
	Elevator();
	void load_ui_elevator();
private:
	int current_floor;
	//! 上下樓梯的按鈕應該要放過來
	CMovingBitmap up;
	CMovingBitmap down;
}; 
