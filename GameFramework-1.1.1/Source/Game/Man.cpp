#include "stdafx.h"
#include "Man.h"
#include "UI.h"
#include "mygame.h"

int Man::total_follower = 0;

void Man::Load_attack() {
	flash.LoadBitmapByString({
		"./RES/Man/flash (1).bmp",
		"./RES/Man/flash (2).bmp",
		"./RES/Man/flash (3).bmp",
		"./RES/Man/flash (4).bmp", },
		RGB(255, 255, 255));
	flash.SetAnimation(150, false);

	weakening.LoadBitmapByString({
		"./RES/Man/weakening (1).bmp",
		"./RES/Man/weakening (2).bmp", },
		RGB(255, 255, 255));
	weakening.SetAnimation(150, false);

	blood.LoadBitmapByString({
		"./RES/Man/blood (1).bmp",
		"./RES/Man/blood (2).bmp",
		"./RES/Man/blood (3).bmp",
		"./RES/Man/blood (4).bmp",
		"./RES/Man/blood (5).bmp",
		"./RES/Man/blood (6).bmp",
		"./RES/Man/blood (7).bmp",
		"./RES/Man/blood (8).bmp",
		"./RES/Man/blood (9).bmp",
		"./RES/Man/blood (10).bmp",
		"./RES/Man/blood (11).bmp",
		"./RES/Man/blood (12).bmp",
		"./RES/Man/blood (13).bmp",
		"./RES/Man/blood (14).bmp", },
		RGB(0, 0, 0));
	blood.SetAnimation(150, true);
	blood.ToggleAnimation();
}

void Man::ManMove(int start, int end, int map, int maingirl_state) {
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
	if (this->ManState[0].GetLeft() >= map + end + girl) {
		left = true;
	}
	else if (this->ManState[0].GetLeft() < map + start + girl) {
		left = false;
	}
	if (dead == false) {
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
		if (left == true) {
			this->ManState[2].SetTopLeft(ManState[2].GetLeft() + girl, ManState[2].GetTop());
			this->ManState[2].ShowBitmap();
		}
		else {
			this->ManState[3].SetTopLeft(ManState[3].GetLeft() + girl, ManState[3].GetTop());
			this->ManState[3].ShowBitmap();
		}
	}
}

void Man::ShowMan(int start, int end, int map, int maingirl_state, bool stop, int maingirl_left, bool maingirl_stop_left) {
	if (dead == false) {
		being_attacking = false;
		not_stop_state = true;
		if (stop == 0) {
			not_stop_state = false;
			ManMove(start, end, map, maingirl_state);
		}
		else {
			being_attacking = true;

			flash.SetTopLeft(ManState[0].GetLeft() - 40, ManState[0].GetTop() - 30);
			flash.ShowBitmap();

			weakening.SetTopLeft(ManState[0].GetLeft() - 20, ManState[0].GetTop() - 20);
			weakening.ShowBitmap();

			blood.SetTopLeft(ManState[0].GetLeft(), ManState[0].GetTop() - 50);
			blood.ShowBitmap();

			if (blood.GetFrameIndexOfBitmap() == 13) {
				dead = true;
				if (total_follower >= 0) {
					total_follower++;
				}
				else {
					total_follower--;
				}
				follower_rank = total_follower;
				this->ManState[2].SetTopLeft(this->ManState[0].GetLeft(), this->ManState[0].GetTop());
				this->ManState[3].SetTopLeft(this->ManState[0].GetLeft(), this->ManState[0].GetTop());
			}
		}
	}
	else {
		if (delay < 25) {
			delay++;
			ManMove(start, end, map, maingirl_state);
			if (delay == 25) {
				if (left == true) {
					this->ManState[4].SetTopLeft(this->ManState[2].GetLeft(), this->ManState[2].GetTop());
				}
				else {
					this->ManState[4].SetTopLeft(this->ManState[3].GetLeft(), this->ManState[3].GetTop());
				}
			}
		}
		else {
			follow(maingirl_state, maingirl_left, maingirl_stop_left);
		}
	}
}

void Man::follow(int maingirl_state, int maingirl_left, bool maingirl_stop_left) {
	this->ManState[5].SetTopLeft(this->ManState[4].GetLeft(), this->ManState[4].GetTop());

	if (this->ManState[4].GetLeft() >= maingirl_left) {
		this->ManState[4].ShowBitmap();
	}
	else {
		this->ManState[5].ShowBitmap();
	}

	if (maingirl_state == 1 || maingirl_state == 2 || maingirl_stop_left == false) {
		if (follower_rank > 0) {
			follower_rank = follower_rank * (-1);
		}
	}
	if (maingirl_state == 3 || maingirl_state == 4 || maingirl_stop_left == true) {//I don't know why here use "else" will be broken = =
		if (follower_rank < 0) {
			follower_rank = follower_rank * (-1);
		}
	}

	if (this->ManState[4].GetLeft() < maingirl_left + 80 * follower_rank - 10) {
		this->ManState[4].SetTopLeft(this->ManState[4].GetLeft() + 10, this->ManState[4].GetTop());
	}
	else if (this->ManState[4].GetLeft() > maingirl_left + 80 * follower_rank + 10) {
		this->ManState[4].SetTopLeft(this->ManState[4].GetLeft() - 10, this->ManState[4].GetTop());
	}
	if (this->ManState[4].GetTop() < 220) {
		this->ManState[4].SetTopLeft(this->ManState[4].GetLeft(), this->ManState[4].GetTop() + 10);
	}
	else if (this->ManState[4].GetTop() > 220) {
		this->ManState[4].SetTopLeft(this->ManState[4].GetLeft(), this->ManState[4].GetTop() - 10);
	}
}

bool const Man::get_being_attacking_state()
{
	return (being_attacking);
}

bool const Man::get_stop_state()
{
	return (not_stop_state);
}
