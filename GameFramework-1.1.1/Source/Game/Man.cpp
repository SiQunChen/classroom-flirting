#include "stdafx.h"
#include "Man.h"
#include "UI.h"
#include "mygame.h"

std::vector<Man*> Man::dead_man;
int Man::man_stop = 0;
int Man::total_follower = 0;

void Man::Load() {
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

	man_on_bottom_small_heart.LoadBitmapByString({
		"./RES/Heart/small/heart_small_bottom (1).bmp",
		"./RES/Heart/small/heart_small_bottom (2).bmp",
		"./RES/Heart/small/heart_small_bottom (3).bmp",
		"./RES/Heart/small/heart_small_bottom (4).bmp",
		"./RES/Heart/small/heart_small_bottom (5).bmp",
		"./RES/Heart/small/heart_small_bottom (6).bmp",
		"./RES/Heart/small/heart_small_bottom (7).bmp",
		"./RES/Heart/small/heart_small_bottom (8).bmp",
		"./RES/Heart/small/heart_small_bottom (9).bmp", },
		RGB(255, 255, 255));
	man_on_bottom_small_heart.SetAnimation(50, true);
	man_on_bottom_small_heart.ToggleAnimation();

	man_on_top_small_heart.LoadBitmapByString({
		"./RES/Heart/small/heart_small_top (1).bmp",
		"./RES/Heart/small/heart_small_top (2).bmp",
		"./RES/Heart/small/heart_small_top (3).bmp",
		"./RES/Heart/small/heart_small_top (4).bmp",
		"./RES/Heart/small/heart_small_top (5).bmp",
		"./RES/Heart/small/heart_small_top (6).bmp",
		"./RES/Heart/small/heart_small_top (7).bmp",
		"./RES/Heart/small/heart_small_top (8).bmp",
		"./RES/Heart/small/heart_small_top (9).bmp",
		"./RES/Heart/small/heart_small_top (10).bmp",
		"./RES/Heart/small/heart_small_top (11).bmp",
		"./RES/Heart/small/heart_small_top (12).bmp",
		"./RES/Heart/small/heart_small_top (13).bmp",
		"./RES/Heart/small/heart_small_top (14).bmp",
		"./RES/Heart/small/heart_small_top (15).bmp", },
		RGB(255, 255, 255));
	man_on_top_small_heart.SetAnimation(30, true);
	man_on_top_small_heart.ToggleAnimation();

	man_on_bottom_big_heart.LoadBitmapByString({
		"./RES/Heart/big/heart_big_bottom (1).bmp",
		"./RES/Heart/big/heart_big_bottom (2).bmp",
		"./RES/Heart/big/heart_big_bottom (3).bmp",
		"./RES/Heart/big/heart_big_bottom (4).bmp",
		"./RES/Heart/big/heart_big_bottom (5).bmp",
		"./RES/Heart/big/heart_big_bottom (6).bmp",
		"./RES/Heart/big/heart_big_bottom (7).bmp",
		"./RES/Heart/big/heart_big_bottom (8).bmp",
		"./RES/Heart/big/heart_big_bottom (9).bmp", },
		RGB(255, 255, 255));
	man_on_bottom_big_heart.SetAnimation(50, true);
	man_on_bottom_big_heart.ToggleAnimation();

	man_on_top_big_heart.LoadBitmapByString({
		"./RES/Heart/big/heart_big_top (1).bmp",
		"./RES/Heart/big/heart_big_top (2).bmp",
		"./RES/Heart/big/heart_big_top (3).bmp",
		"./RES/Heart/big/heart_big_top (4).bmp",
		"./RES/Heart/big/heart_big_top (5).bmp",
		"./RES/Heart/big/heart_big_top (6).bmp",
		"./RES/Heart/big/heart_big_top (7).bmp",
		"./RES/Heart/big/heart_big_top (8).bmp",
		"./RES/Heart/big/heart_big_top (9).bmp",
		"./RES/Heart/big/heart_big_top (10).bmp",
		"./RES/Heart/big/heart_big_top (11).bmp",
		"./RES/Heart/big/heart_big_top (12).bmp",
		"./RES/Heart/big/heart_big_top (13).bmp",
		"./RES/Heart/big/heart_big_top (14).bmp",
		"./RES/Heart/big/heart_big_top (15).bmp", },
		RGB(255, 255, 255));
	man_on_top_big_heart.SetAnimation(30, true);
	man_on_top_big_heart.ToggleAnimation();
}

int Man::count_girl(int maingirl_state, bool evolution) {
	if (evolution == false && Teacher::bump == false) {
		if (maingirl_state == 1) {
			return -2;
		}
		if (maingirl_state == 2) {
			return -5;
		}
		if (maingirl_state == 3) {
			return 2;
		}
		if (maingirl_state == 4) {
			return 5;
		}
	}
	return 0;
}

bool Man::touch(int main, int target) {
	if (main <= target + 70 && main >= target - 70) {		//20, 150
		return true;
	}
	return false;
}

void Man::heart(int maingirl_state, int maingirl_left, bool evolution) {
	girl = count_girl(maingirl_state, evolution);
	if (this->ManState[0].GetTop() > 300) {
		man_on_bottom_small_heart.SetTopLeft(man_on_bottom_small_heart.GetLeft() + girl, man_on_bottom_small_heart.GetTop());
		man_on_bottom_small_heart.ShowBitmap();
		get_small_heart = touch(maingirl_left, man_on_bottom_small_heart.GetLeft());
	}
	else {
		man_on_top_small_heart.SetTopLeft(man_on_top_small_heart.GetLeft() + girl, man_on_top_small_heart.GetTop());
		man_on_top_small_heart.ShowBitmap();
		get_small_heart = touch(maingirl_left, man_on_top_small_heart.GetLeft());
	}
	modify_hp();
}

void Man::ManMove(int start, int end, int map, int maingirl_state, bool evolution) {
	girl = count_girl(maingirl_state, evolution);
	if (dead == false) {
		if (this->ManState[0].GetLeft() >= map + end + girl) {
			left = true;
		}
		else if (this->ManState[0].GetLeft() < map + start + girl) {
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
		if (this->ManState[0].GetLeft() >= girl) {
			left = true;
		}
		else if (this->ManState[0].GetLeft() < girl) {
			left = false;
		}
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

void Man::ShowMan(int start, int end, int map, int maingirl_state, bool stop, int maingirl_left, bool maingirl_stop_left, bool beauty_time, bool evolution) {
	if (dead == false) {
		being_attacking = false;
		not_stop_state = true;
		if (stop == 0) {
			not_stop_state = false;
			ManMove(start, end, map, maingirl_state, evolution);
		}
		else {
			being_attacking = true;

			flash.SetTopLeft(ManState[0].GetLeft() - 40, ManState[0].GetTop() - 30);
			flash.ShowBitmap();

			weakening.SetTopLeft(ManState[0].GetLeft() - 20, ManState[0].GetTop() - 20);
			weakening.ShowBitmap();

			blood.SetTopLeft(ManState[0].GetLeft(), ManState[0].GetTop() - 50);
			if (beauty_time == false) {
				blood.ShowBitmap();
			}
			else {
				blood_in_beauty_time = blood_in_beauty_time + 2;
				blood.SetFrameIndexOfBitmap(blood_in_beauty_time);
				blood.ShowBitmap();
			}

			if (blood.GetFrameIndexOfBitmap() == 13) {
				dead = true;
				man_stop = 0;
				if (total_follower >= 0) {
					total_follower++;
				}
				else {
					total_follower--;
				}
				follower_rank = total_follower;
				this->ManState[2].SetTopLeft(this->ManState[0].GetLeft(), this->ManState[0].GetTop());
				this->ManState[3].SetTopLeft(this->ManState[0].GetLeft(), this->ManState[0].GetTop());
				man_on_bottom_small_heart.SetTopLeft(this->ManState[0].GetLeft(), this->ManState[0].GetTop() - 30);
				man_on_top_small_heart.SetTopLeft(this->ManState[0].GetLeft(), this->ManState[0].GetTop() - 50);
				man_on_bottom_big_heart.SetTopLeft(this->ManState[0].GetLeft(), this->ManState[0].GetTop() - 30);
				man_on_top_big_heart.SetTopLeft(this->ManState[0].GetLeft(), this->ManState[0].GetTop() - 50);
			}
		}
	}
	else {
		if (delay < 25) {
			delay++;
			ManMove(start, end, map, maingirl_state, evolution);
		}
		else if (delay == 25) {
			delay++;
			dead_man.push_back(this);
			if (left == true) {
				this->ManState[4].SetTopLeft(this->ManState[2].GetLeft(), this->ManState[2].GetTop());
			}
			else {
				this->ManState[4].SetTopLeft(this->ManState[3].GetLeft(), this->ManState[3].GetTop());
			}
		}
		if (get_small_heart == false) {
			heart(maingirl_state, maingirl_left, evolution);
		}
	}
}

void Man::follow(int maingirl_state, int maingirl_left, int maingirl_top, bool maingirl_stop_left) {
	this->ManState[5].SetTopLeft(this->ManState[4].GetLeft(), this->ManState[4].GetTop());

	if (this->ManState[4].GetLeft() >= maingirl_left) {
		this->ManState[4].ShowBitmap();
	}
	else {
		this->ManState[5].ShowBitmap();
	}

	if (maingirl_state == 1 || maingirl_state == 2 || (maingirl_stop_left == false && (maingirl_state == 6 || maingirl_state == 5))) {
		if (follower_rank > 0) {
			follower_rank = follower_rank * (-1);
		}
	}
	else {
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
	if (this->ManState[4].GetTop() < maingirl_top - 10) {
		this->ManState[4].SetTopLeft(this->ManState[4].GetLeft(), this->ManState[4].GetTop() + 10);
	}
	else if (this->ManState[4].GetTop() > maingirl_top + 10) {
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

void Man::modify_hp()
{
	if(get_big_heart) {
		HP::hp += 150;
	}
	else if(get_small_heart) {
		HP::hp += 100;
	}
}
