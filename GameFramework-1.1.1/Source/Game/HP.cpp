#include "stdafx.h"
#include "UI.h"

HP::HP() {
	hp = 230;
	bool_invincible_state = false;
}

bool HP::is_invincible() {
	return (bool_invincible_state);
}

void HP::load_ui_hp_board() {
	hp_board.LoadBitmapByString({
		"./RES/UI/heart/heartPointBoard.bmp"});
}

void HP::load_ui_hp_num() {
    hp_heart[19].LoadBitmapByString({			// <100%
    	"./RES/UI/heart/heart (20).bmp"});
    hp_heart[18].LoadBitmapByString({
    	"./RES/UI/heart/heart (19).bmp"});
    hp_heart[17].LoadBitmapByString({			// <90%
    	"./RES/UI/heart/heart (18).bmp"});
    hp_heart[16].LoadBitmapByString({
    	"./RES/UI/heart/heart (17).bmp"});
    hp_heart[15].LoadBitmapByString({			// 80%
    	"./RES/UI/heart/heart (16).bmp"});
    hp_heart[14].LoadBitmapByString({
    	"./RES/UI/heart/heart (15).bmp"});
    hp_heart[13].LoadBitmapByString({			// 70%
    	"./RES/UI/heart/heart (14).bmp"});
    hp_heart[12].LoadBitmapByString({
    	"./RES/UI/heart/heart (13).bmp"});
    hp_heart[11].LoadBitmapByString({			// 60%
    	"./RES/UI/heart/heart (12).bmp"});
    hp_heart[10].LoadBitmapByString({
    	"./RES/UI/heart/heart (11).bmp"});
    hp_heart[9].LoadBitmapByString({			// 50%
    	"./RES/UI/heart/heart (10).bmp"});
    hp_heart[8].LoadBitmapByString({
    	"./RES/UI/heart/heart (9).bmp"});
    hp_heart[7].LoadBitmapByString({			// 40%
    	"./RES/UI/heart/heart (8).bmp"});
    hp_heart[6].LoadBitmapByString({
    	"./RES/UI/heart/heart (7).bmp"});
    hp_heart[5].LoadBitmapByString({			// 30%
    	"./RES/UI/heart/heart (6).bmp"});
    hp_heart[4].LoadBitmapByString({
    	"./RES/UI/heart/heart (5).bmp"});
    hp_heart[3].LoadBitmapByString({			// 20%
    	"./RES/UI/heart/heart (4).bmp"});
    hp_heart[2].LoadBitmapByString({
    	"./RES/UI/heart/heart (3).bmp"});
    hp_heart[1].LoadBitmapByString({			// 10%
    	"./RES/UI/heart/heart (2).bmp"});
    hp_heart[0].LoadBitmapByString({
    	"./RES/UI/heart/heart (1).bmp"});
    hp_heart_warning.LoadBitmapByString({		// <0%
    	"./RES/UI/heart/warning (1).bmp",
    	"./RES/UI/heart/warning (2).bmp",
    	"./RES/UI/heart/warning (3).bmp"},
    	RGB(0, 0, 0));
	// hp_heart_warning.SetAnimation(200, false);
	// invincible_board.LoadBitmapByString();
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
