#include "stdafx.h"
#include "Girl.h"
#include "mygame.h"

std::vector<Girl*> Girl::shooting_girl;
int Girl::fly_out = 0;

int Girl::count_girl(int maingirl_state, bool evolution, int bump_delay, int over_delay) {
	if (evolution == false && Teacher::bump == false && bump_delay == 0 && over_delay == 0 && Man::click == false) {
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

void Girl::GirlMove(int start, int end, int map) {
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

void Girl::ShowGirl(int start, int end, int map, int maingirl_state, bool stop, int maingirl_left, bool beauty_time, bool evolution, int stop_man_left, int bump_delay, int over_delay) {
	if (dead == false) {
		girl = count_girl(maingirl_state, evolution, bump_delay, over_delay);
		if ((Man::man_stop != 0 || Man::click == true) && this->walk_left.GetLeft() > 10 && this->walk_left.GetLeft() < 790) {
			if (Man::click == true && shooting_girl.size() == 0) {
				girl_stop = false;
			}
			if (girl_stop == false) {
				shooting_girl.push_back(this);
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
			auto it = std::find(shooting_girl.begin(), shooting_girl.end(), this);

			if (it != shooting_girl.end()) {
				if (Man::click_win == true) {
					this->fly_left.SetTopLeft(this->walk_left.GetLeft(), this->walk_left.GetTop());
					this->fly_right.SetTopLeft(this->walk_left.GetLeft(), this->walk_left.GetTop());
					dead = true;
				}
				else {
					if (!init_delay) {
						delay = 0;
						init_delay = true;
					}
					if (delay == 0) {
						this->win_left.SetTopLeft(this->walk_left.GetLeft(), this->walk_left.GetTop());
						this->win_right.SetTopLeft(this->walk_left.GetLeft(), this->walk_left.GetTop());
					}
					if (this->walk_left.GetLeft() > maingirl_left) {
						left = true;
					}
					else {
						left = false;
					}
					if (left == true) {
						if (delay < 80) {
							delay++;
							this->win_right.SetTopLeft(this->win_right.GetLeft() + 5, this->walk_left.GetTop());
							this->win_right.ShowBitmap();
						}
						else {
							dead = true;
						}
					}
					else {
						if (delay < 80) {
							delay++;
							this->win_left.SetTopLeft(this->win_left.GetLeft() - 5, this->walk_left.GetTop());
							this->win_left.ShowBitmap();
						}
						else {
							dead = true;
						}
					}
				}
			}
			else {
				delay = 0;
				girl_stop = false;
				GirlMove(start, end, map);
			}
		}
	}
}

int Girl::get_how_many_girl_in_view()
{
	return (shooting_girl.size());
}

void Girl::fly() {
	if (left == true) {
		this->fly_left.SetTopLeft(this->fly_left.GetLeft() + 50, this->fly_left.GetTop() - 50);
		this->fly_left.ShowBitmap();
		if (this->fly_left.GetFrameIndexOfBitmap() == 3) {
			fly_out++;
		}
	}
	else {
		this->fly_right.SetTopLeft(this->fly_right.GetLeft() - 50, this->fly_right.GetTop() - 50);
		this->fly_right.ShowBitmap();
		if (this->fly_right.GetFrameIndexOfBitmap() == 3) {
			fly_out++;
		}
	}
}
