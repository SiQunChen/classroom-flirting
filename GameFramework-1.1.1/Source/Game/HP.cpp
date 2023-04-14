#include "stdafx.h"
#include "UI.h"

HP::HP() {
	hp = 900;
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
    hp_heart[19].LoadBitmapByString({
    	"./RES/UI/heart/heart (20).bmp"});
    hp_heart[18].LoadBitmapByString({
    	"./RES/UI/heart/heart (19).bmp"});
    hp_heart[17].LoadBitmapByString({
    	"./RES/UI/heart/heart (18).bmp"});
    hp_heart[16].LoadBitmapByString({
    	"./RES/UI/heart/heart (17).bmp"});
    hp_heart[15].LoadBitmapByString({
    	"./RES/UI/heart/heart (16).bmp"});
    hp_heart[14].LoadBitmapByString({
    	"./RES/UI/heart/heart (15).bmp"});
    hp_heart[13].LoadBitmapByString({
    	"./RES/UI/heart/heart (14).bmp"});
    hp_heart[12].LoadBitmapByString({
    	"./RES/UI/heart/heart (13).bmp"});
    hp_heart[11].LoadBitmapByString({
    	"./RES/UI/heart/heart (12).bmp"});
    hp_heart[10].LoadBitmapByString({
    	"./RES/UI/heart/heart (11).bmp"});
    hp_heart[9].LoadBitmapByString({
    	"./RES/UI/heart/heart (10).bmp"});
    hp_heart[8].LoadBitmapByString({
    	"./RES/UI/heart/heart (9).bmp"});
    hp_heart[7].LoadBitmapByString({
    	"./RES/UI/heart/heart (8).bmp"});
    hp_heart[6].LoadBitmapByString({
    	"./RES/UI/heart/heart (7).bmp"});
    hp_heart[5].LoadBitmapByString({
    	"./RES/UI/heart/heart (6).bmp"});
    hp_heart[4].LoadBitmapByString({
    	"./RES/UI/heart/heart (5).bmp"});
    hp_heart[3].LoadBitmapByString({
    	"./RES/UI/heart/heart (4).bmp"});
    hp_heart[2].LoadBitmapByString({
    	"./RES/UI/heart/heart (3).bmp"});
    hp_heart[1].LoadBitmapByString({
    	"./RES/UI/heart/heart (2).bmp"});
    hp_heart[0].LoadBitmapByString({
    	"./RES/UI/heart/heart (1).bmp"});
    hp_heart_warning.LoadBitmapByString({
    	"./RES/UI/heart/warning (1).bmp",
    	"./RES/UI/heart/warning (2).bmp",
    	"./RES/UI/heart/warning (3).bmp"});
	//invincible_board.LoadBitmapByString();
}

void HP::show_hp() {
	const  int hp_floor = hp / 100;
	int hp_decimal = hp % 100;

	for (int i = 0; i < hp_floor; i++) {
		hp_posision[i].LoadBitmapByString({
			"./RES/UI/heart/heart (20).bmp"});
	}
	
	if (hp_floor < 900) {
		if (hp_decimal >= 95) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (19).bmp"});
		}
		else if (hp_decimal >= 90) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (18).bmp"});
		}
		else if (hp_decimal >= 85) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (17).bmp"});
		}
		else if (hp_decimal >= 80) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (16).bmp"});
		}
		else if (hp_decimal >= 75) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (15).bmp"});
		}
		else if (hp_decimal >= 70) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (14).bmp"});
		}
		else if (hp_decimal >= 65) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (13).bmp"});
		}
		else if (hp_decimal >= 60) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (12).bmp"});
		}
		else if (hp_decimal >= 55) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (11).bmp"});
		}
		else if (hp_decimal >= 50) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (10).bmp"});
		}
		else if (hp_decimal >= 45) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (9).bmp"});
		}
		else if (hp_decimal >= 40) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (8).bmp"});
		}
		else if (hp_decimal >= 35) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (7).bmp"});
		}
		else if (hp_decimal >= 30) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (6).bmp"});
		}
		else if (hp_decimal >= 25) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (5).bmp"});
		}
		else if (hp_decimal >= 20) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (4).bmp"});
		}
		else if (hp_decimal >= 15) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (3).bmp"});
		}
		else if (hp_decimal >= 10) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (2).bmp"});
		}
		else if (hp_decimal >= 5) {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (1).bmp"});
		}
		else {
			hp_posision[hp_floor].LoadBitmapByString({
				"./RES/UI/heart/heart (1).bmp"});
		}

		// show 0
		for (int i = hp_floor+1; i<9; i++) {
			hp_posision[i].LoadBitmapByString({
				"./RES/UI/heart/heart (1).bmp"});
		}
	}

	for (int i = 0; i<9; i++) {
		hp_posision[i].SetTopLeft(35*i+5, 45);
		hp_posision[i].ShowBitmap();
	}
	
	
}
