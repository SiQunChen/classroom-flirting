#include "stdafx.h"
#include "Girl.h"
#include "mygame.h"

std::vector<Girl*> Girl::dead_girl;
int Girl::how_many_girl = 0;

void Girl::Load() {
	
}

int Girl::count_girl(int maingirl_state, bool evolution, int bump_delay) {
	if (evolution == false && Teacher::bump == false && bump_delay == 0) {
		if (maingirl_state == 1) {
			return -2;
		}
		else if (maingirl_state == 2) {
			return -5;
		}
		else if (maingirl_state == 3) {
			return 2;
		}
		else if (maingirl_state == 4) {
			return 5;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

void Girl::GirlMove(int start, int end, int map, int maingirl_state, bool evolution, int bump_delay) {
	girl = count_girl(maingirl_state, evolution, bump_delay);
	if (this->walk_right.GetLeft() >= map + end + girl) {
		left = true;
	}
	else if (this->walk_left.GetLeft() < map + start + girl) {
		left = false;
	}
	if (left == true) {
		this->walk_left.ShowBitmap(0.9);
		this->walk_left.SetTopLeft(walk_left.GetLeft() - 1 + girl, walk_left.GetTop());
		this->walk_right.SetTopLeft(walk_right.GetLeft() - 1 + girl, walk_right.GetTop());
	}
	else {
		this->walk_right.ShowBitmap(0.9);
		this->walk_left.SetTopLeft(walk_left.GetLeft() + 1 + girl, walk_left.GetTop());
		this->walk_right.SetTopLeft(walk_right.GetLeft() + 1 + girl, walk_right.GetTop());
	}
}

void Girl::ShowGirl(int start, int end, int map, int maingirl_state, bool stop, int maingirl_left, bool beauty_time, bool evolution, int stop_man_left, int bump_delay) {
	if (Man::man_stop != 0 && this->walk_left.GetLeft() >10 && this->walk_left.GetLeft() < 790) {
		if (girl_stop == false) {
			how_many_girl++;
			girl_stop = true;
		}
		if (this->walk_left.GetLeft() > stop_man_left) {
			left = true;
		}
		else {
			left = false;
		}
		if (left == true) {
			if (delay != 15) {
				delay++;
				this->notice_left.SetTopLeft(this->walk_left.GetLeft(), this->walk_left.GetTop());
				this->notice_left.ShowBitmap();
			}
			else {
				this->shoot_left.SetTopLeft(this->walk_left.GetLeft(), this->walk_left.GetTop());
				this->shoot_left.ShowBitmap();
			}
		}
		else {
			if (delay != 15) {
				delay++;
				this->notice_right.SetTopLeft(this->walk_left.GetLeft(), this->walk_left.GetTop());
				this->notice_right.ShowBitmap();
			}
			else {
				this->shoot_right.SetTopLeft(this->walk_left.GetLeft(), this->walk_left.GetTop());
				this->shoot_right.ShowBitmap();
			}
		}
	}
	else {
		delay = 0;
		GirlMove(start, end, map, maingirl_state, evolution, bump_delay);
		girl_stop = false;
	}
}