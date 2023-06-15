#include "stdafx.h"
#include "Role.h"
#include "UI.h"
#include "mygame.h"

bool Teacher::bump = false;

void Teacher::Load() {
	teacher_left.LoadBitmapByString({
		"./RES/teacher/left/left (1).bmp",
		"./RES/teacher/left/left (2).bmp",
		"./RES/teacher/left/left (3).bmp",
		"./RES/teacher/left/left (4).bmp",
		"./RES/teacher/left/left (5).bmp",},
		RGB(230, 230, 196));
	teacher_left.SetTopLeft(2000, 250);
	teacher_left.SetAnimation(150, false);

	teacher_right.LoadBitmapByString({
		"./RES/teacher/right/right (1).bmp",
		"./RES/teacher/right/right (2).bmp",
		"./RES/teacher/right/right (3).bmp",
		"./RES/teacher/right/right (4).bmp",
		"./RES/teacher/right/right (5).bmp", },
		RGB(230, 230, 196));
	teacher_right.SetTopLeft(-2000, 250);
	teacher_right.SetAnimation(150, false);
}

int Teacher::count_girl(int maingirl_state, bool evolution, int bump_delay, int over_delay) {
	if (evolution == false && bump == false && bump_delay == 0 && over_delay == 0 && Man::click == false) {
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

bool Teacher::touch(int main, int target) {
	if (main <= target + 70 && main >= target - 70) {
		modify_hp();
		delay++;
		return true;
	}
	return false;
}

void Teacher::ShowTeacher(bool left, int maingirl_state, int maingirl_left, bool evolution, int bump_delay, int over_delay, bool up_down_floor) {
	girl = count_girl(maingirl_state, evolution, bump_delay, over_delay);
	if (left == true) {
		teacher_left.SetTopLeft(teacher_left.GetLeft() - 3 + girl, 220);
		teacher_left.ShowBitmap();
	}
	else {
		teacher_right.SetTopLeft(teacher_right.GetLeft() + 3 + girl, 220);
		teacher_right.ShowBitmap();
	}
	if (delay == 0 && up_down_floor == false) {
		if (left == true) {
			bump = touch(maingirl_left, teacher_left.GetLeft());
		}
		else {
			bump = touch(maingirl_left, teacher_right.GetLeft());
		}
	}
	else if(delay == 50){
		delay = 0;
	}
	else {
		delay++;
	}
}

void Teacher::Setup(bool left) {
	if (left == true) {
		teacher_left.SetTopLeft(2000, 250);
	}
	else {
		teacher_right.SetTopLeft(-2000, 250);
	}
}

void Teacher::modify_hp()
{
		HP::hp -= 150;
}
 