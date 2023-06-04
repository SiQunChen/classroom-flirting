#include "stdafx.h"
#include "SpecialMan1.h"

void Specialman1::Load_state() {
	ManState[0].LoadBitmapByString({
		"./RES/Man/specialMan1/alive/left/specialMan (1).bmp",
		"./RES/Man/specialMan1/alive/left/specialMan (2).bmp",
		"./RES/Man/specialMan1/alive/left/specialMan (3).bmp",
		"./RES/Man/specialMan1/alive/left/specialMan (4).bmp",
		"./RES/Man/specialMan1/alive/left/specialMan (5).bmp",
		"./RES/Man/specialMan1/alive/left/specialMan (6).bmp",
		"./RES/Man/specialMan1/alive/left/specialMan (7).bmp",
		"./RES/Man/specialMan1/alive/left/specialMan (8).bmp", },
		RGB(0,0,0));
	ManState[0].SetAnimation(150, false);

	ManState[1].LoadBitmapByString({
		"./RES/Man/specialMan1/alive/right/specialMan (1).bmp",
		"./RES/Man/specialMan1/alive/right/specialMan (2).bmp",
		"./RES/Man/specialMan1/alive/right/specialMan (3).bmp",
		"./RES/Man/specialMan1/alive/right/specialMan (4).bmp",
		"./RES/Man/specialMan1/alive/right/specialMan (5).bmp",
		"./RES/Man/specialMan1/alive/right/specialMan (6).bmp",
		"./RES/Man/specialMan1/alive/right/specialMan (7).bmp",
		"./RES/Man/specialMan1/alive/right/specialMan (8).bmp", },
		RGB(0, 0, 0));
	ManState[1].SetAnimation(150, false);

	ManState[2].LoadBitmapByString({
		"./RES/Man/specialMan1/dead/left/slave (1).bmp",
		"./RES/Man/specialMan1/dead/left/slave (2).bmp",
		"./RES/Man/specialMan1/dead/left/slave (3).bmp",
		"./RES/Man/specialMan1/dead/left/slave (4).bmp",
		"./RES/Man/specialMan1/dead/left/slave (5).bmp",
		"./RES/Man/specialMan1/dead/left/slave (6).bmp",
		"./RES/Man/specialMan1/dead/left/slave (7).bmp", },
		RGB(255, 255, 255));
	ManState[2].SetAnimation(150, true);
	ManState[2].ToggleAnimation();

	ManState[3].LoadBitmapByString({
		"./RES/Man/specialMan1/dead/right/slave (1).bmp",
		"./RES/Man/specialMan1/dead/right/slave (2).bmp",
		"./RES/Man/specialMan1/dead/right/slave (3).bmp",
		"./RES/Man/specialMan1/dead/right/slave (4).bmp",
		"./RES/Man/specialMan1/dead/right/slave (5).bmp",
		"./RES/Man/specialMan1/dead/right/slave (6).bmp",
		"./RES/Man/specialMan1/dead/right/slave (7).bmp", },
		RGB(255, 255, 255));
	ManState[3].SetAnimation(150, true);
	ManState[3].ToggleAnimation();

	ManState[4].LoadBitmapByString({
		"./RES/Man/specialMan1/follow/left/slave (1).bmp",
		"./RES/Man/specialMan1/follow/left/slave (2).bmp",
		"./RES/Man/specialMan1/follow/left/slave (3).bmp",
		"./RES/Man/specialMan1/follow/left/slave_girl (1).bmp",
		"./RES/Man/specialMan1/follow/left/slave_girl (2).bmp",
		"./RES/Man/specialMan1/follow/left/slave_girl (3).bmp", },
		RGB(255, 255, 255));
	ManState[4].SetAnimation(150, false);

	ManState[5].LoadBitmapByString({
		"./RES/Man/specialMan1/follow/right/slave (1).bmp",
		"./RES/Man/specialMan1/follow/right/slave (2).bmp",
		"./RES/Man/specialMan1/follow/right/slave (3).bmp",
		"./RES/Man/specialMan1/follow/right/slave_girl (1).bmp",
		"./RES/Man/specialMan1/follow/right/slave_girl (2).bmp",
		"./RES/Man/specialMan1/follow/right/slave_girl (3).bmp", },
		RGB(255, 255, 255));
	ManState[5].SetAnimation(150, false);
}

void Specialman1::heart(int maingirl_state, int maingirl_left, bool evolution, int bump_delay, Score* score_sys) {
	girl = count_girl(maingirl_state, evolution, bump_delay);
	if (this->ManState[0].GetTop() > 300) {
		man_on_bottom_big_heart.SetTopLeft(man_on_bottom_big_heart.GetLeft() + girl, man_on_bottom_big_heart.GetTop());
		man_on_bottom_big_heart.ShowBitmap();
		get_heart = touch(maingirl_left, man_on_bottom_big_heart.GetLeft());
	}
	else {
		man_on_top_big_heart.SetTopLeft(man_on_top_big_heart.GetLeft() + girl, man_on_top_big_heart.GetTop());
		man_on_top_big_heart.ShowBitmap();
		get_heart = touch(maingirl_left, man_on_top_big_heart.GetLeft());
	}
	modify_hp(score_sys);
}

void Specialman1::modify_hp(Score* score_sys)
{
	if (get_heart) {
		HP::hp += 150;
		(*score_sys).score += 10000;
	}
}