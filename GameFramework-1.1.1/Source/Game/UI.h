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
	bool bool_invincible_state;
private:
	CMovingBitmap hp_board;
	CMovingBitmap hp_posision[9];			// 0 is the left
	CMovingBitmap hp_heart[20];
	CMovingBitmap hp_heart_warning;
	CMovingBitmap invincible_board;
	CMovingBitmap invincible_inner;
	CMovingBitmap invincible_animate[6];
	const int total_delay = 54;				// cycle
	int shine_cd = 0;
	int invincible_time = 0;
};
