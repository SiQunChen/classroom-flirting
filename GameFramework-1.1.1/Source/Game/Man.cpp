#include "stdafx.h"
#include "Man.h"
#include "UI.h"
#include "mygame.h"

void Man::Load_flash_and_weakening() {
	flash.LoadBitmapByString({
		"./RES/Man/flash (1).bmp",
		"./RES/Man/flash (2).bmp",
		"./RES/Man/flash (3).bmp",
		"./RES/Man/flash (4).bmp",},
		RGB(255, 255, 255));
	flash.SetAnimation(150, false);

	weakening.LoadBitmapByString({
		"./RES/Man/weakening (1).bmp",
		"./RES/Man/weakening (2).bmp",},
		RGB(255, 255, 255));
	weakening.SetAnimation(150, false);
}

void Man::ShowMan(int start, int end, int map, int maingirl_state, bool stop, int maingirl_left) {
	being_attacking = true;
	
	if (maingirl_state == 1) {
		girl = -2;
	}
	else if (maingirl_state == 2) {
		girl = -5;
	}
	else if (maingirl_state == 3) {
		girl = 2;
	}
	else if (maingirl_state == 4) {
		girl = 5;
	}
	else {
		girl = 0;
	}
	if (stop == 0) {
		if (this->ManState[0].GetLeft() >= map + end + girl) {
			left = true;
		}
		else if (this->ManState[0].GetLeft() <= map + start + girl) {
			left = false;
		}
		if (left == true) {
			this->ManState[0].ShowBitmap();
			this->ManState[0].SetTopLeft(ManState[0].GetLeft() - 1 + girl, ManState[0].GetTop());
			this->ManState[1].SetTopLeft(ManState[1].GetLeft() - 1 + girl, ManState[1].GetTop());
		}
		else {
			this->ManState[1].ShowBitmap();
			this->ManState[0].SetTopLeft(ManState[0].GetLeft() + 1 + girl, ManState[0].GetTop());
			this->ManState[1].SetTopLeft(ManState[1].GetLeft() + 1 + girl, ManState[1].GetTop());
		}
	}
	else {
		/*if (this->ManState[0].GetLeft() >= maingirl_left) {
			left = true;
		}
		else if (this->ManState[0].GetLeft() < maingirl_left) {
			left = false;
		}
		if (left == true) {
			this->ManState[0].SetFrameIndexOfBitmap(0);
			this->ManState[0].ShowBitmap();
		}
		else {
			this->ManState[1].SetFrameIndexOfBitmap(0);
			this->ManState[1].ShowBitmap();
		}*/
		being_attacking = true;
		
		flash.SetTopLeft(ManState[0].GetLeft() - 40, ManState[0].GetTop() - 30);
		flash.ShowBitmap();

		weakening.SetTopLeft(ManState[0].GetLeft() - 20, ManState[0].GetTop() - 20);
		weakening.ShowBitmap();
	}
}

bool const Man::get_being_attacking_state()
{
	return (being_attacking);
}
