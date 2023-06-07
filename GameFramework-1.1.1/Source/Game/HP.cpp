#include "stdafx.h"

#include <string>

#include "UI.h"

#define DEFAULT_HP 400
#define INNER_OVERLAP 160
#define CYCLE 4

int HP::hp = DEFAULT_HP;

HP::HP() {
	bool_invincible_state = false;
}

bool HP::is_invincible() {
	return (bool_invincible_state);
}

void HP::load_ui_hp_board() {
	hp_board.LoadBitmapByString({
		"./RES/UI/heart/heartPointBoard.bmp"});
}

void HP::load_ui_hp_num()
{
	for (int i = 20; i > 0; i--) {
		auto I = std::to_string(i);
		hp_heart[i-1].LoadBitmapByString({
			"./RES/UI/heart/heart ("+I+").bmp"});
	}
	
	hp_heart_warning.LoadBitmapByString({		// <0%
		"./RES/UI/heart/warning (1).bmp",
		"./RES/UI/heart/warning (2).bmp",
		"./RES/UI/heart/warning (3).bmp"},
		RGB(0, 0, 0));

	for (int i = 0; i < 6; i++) {
		auto I = std::to_string(i+1);
		invincible_animate[i].LoadBitmapByString({
			"./RES/UI/reinforced/reinforced_bar (" + I + ").bmp"
			}, RGB(255, 255, 255));
	}
	
	invincible_board.LoadBitmapByString({"./RES/UI/reinforced/reinforced_bar.bmp"}, RGB(255, 255, 255));
	invincible_inner.LoadBitmapByString({"./RES/UI/reinforced/reinforced_bar_inner.bmp"},RGB(255, 255, 255));
}

void HP::show_hp() {
	for (int i = 0; i < (hp / 100); i++) {
		hp_heart[19].SetTopLeft(35*i+5, 45);
		hp_heart[19].ShowBitmap();
	}
	hp_heart[hp % 100/5].SetTopLeft(35*(hp / 100)+5, 45);
	hp_heart[hp % 100/5].ShowBitmap();
	for (int i = (hp / 100)+1; i < 9; i++) {
		hp_heart[0].SetTopLeft(35*i+5, 45);
		hp_heart[0].ShowBitmap();
	}
}

void HP::shine_hp()
{
	for (int j = 0; j<3; j++) {
		if (shine_cd++ % total_delay >= total_delay/6*j) {			// 54 - 54/2/3*1
			hp_heart_warning.SetFrameIndexOfBitmap(j);
			for (int i = 0; i < 9; i++) {
				hp_heart_warning.SetTopLeft(35*i+0, 39);
				hp_heart_warning.ShowBitmap();
			}
		}
		else {
			show_hp();
		}
	}
}

int HP::show_invincible()
{
	if(bool_invincible_state && ++invincible_time < 6 * CYCLE) {
		show_invincible_start();
	}
	else if (invincible_time < (6 + INNER_OVERLAP) * CYCLE) {
		bool_invincible_state = false;
		show_invincible_bar();
	}
	else {
		show_invincible_end();
		return 1;
	}
	return 0;
}

void HP::show_invincible_start()
{
	invincible_animate[invincible_time / CYCLE].SetTopLeft(20, 34);
	invincible_animate[invincible_time / CYCLE].ShowBitmap();
}

void HP::show_invincible_bar()
{
	invincible_inner.SetTopLeft(20 - (invincible_time - 6 * CYCLE)/CYCLE, 34);
	invincible_inner.ShowBitmap();
	invincible_board.SetTopLeft(0, 34);
	invincible_board.ShowBitmap();
}

void HP::show_invincible_end()
{
	invincible_animate[5 - (invincible_time - (6 + INNER_OVERLAP) * CYCLE)/ CYCLE].SetTopLeft(20, 34);
	invincible_animate[5 - (invincible_time - (6 + INNER_OVERLAP) * CYCLE)/ CYCLE].ShowBitmap();

	if(invincible_time >= (12 + INNER_OVERLAP) * CYCLE) {
		invincible_time = 0;
		hp = DEFAULT_HP;
	}
}