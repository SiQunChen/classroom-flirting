#include "stdafx.h"
#include "Man.h"

void Man::ShowMan(int start, int end, int map, int maingirl_state, bool stop, int maingirl_left) {
	if (maingirl_state == 1) {
		girl = -5;
	}
	else if (maingirl_state == 2) {
		girl = -10;
	}
	else if (maingirl_state == 3) {
		girl = 5;
	}
	else if (maingirl_state == 4) {
		girl = 10;
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
			this->ManState[0].SetTopLeft(ManState[0].GetLeft() - 2 + girl, ManState[0].GetTop());
			this->ManState[1].SetTopLeft(ManState[1].GetLeft() - 2 + girl, ManState[1].GetTop());
		}
		else {
			this->ManState[1].ShowBitmap();
			this->ManState[0].SetTopLeft(ManState[0].GetLeft() + 2 + girl, ManState[0].GetTop());
			this->ManState[1].SetTopLeft(ManState[1].GetLeft() + 2 + girl, ManState[1].GetTop());
		}
	}
	else {
		if (this->ManState[0].GetLeft() >= maingirl_left) {
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
		}
		this->ManState[0].SetTopLeft(ManState[0].GetLeft() + girl, ManState[0].GetTop());
		this->ManState[1].SetTopLeft(ManState[1].GetLeft() + girl, ManState[1].GetTop());
	}
}