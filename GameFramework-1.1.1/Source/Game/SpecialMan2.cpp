#include "stdafx.h"
#include "SpecialMan.h"

void Specialman2::Load_state() {
	ManState[0].LoadBitmapByString({
		"./RES/Man/specialMan2/alive/left/specialMan (1).bmp",
		"./RES/Man/specialMan2/alive/left/specialMan (2).bmp",
		"./RES/Man/specialMan2/alive/left/specialMan (3).bmp",
		"./RES/Man/specialMan2/alive/left/specialMan (4).bmp",
		"./RES/Man/specialMan2/alive/left/specialMan (5).bmp",
		"./RES/Man/specialMan2/alive/left/specialMan (6).bmp", },
		RGB(0,0,0));
	ManState[0].SetAnimation(150, false);

	ManState[1].LoadBitmapByString({
		"./RES/Man/specialMan2/alive/right/specialMan (1).bmp",
		"./RES/Man/specialMan2/alive/right/specialMan (2).bmp",
		"./RES/Man/specialMan2/alive/right/specialMan (3).bmp",
		"./RES/Man/specialMan2/alive/right/specialMan (4).bmp",
		"./RES/Man/specialMan2/alive/right/specialMan (5).bmp",
		"./RES/Man/specialMan2/alive/right/specialMan (6).bmp", },
		RGB(0, 0, 0));
	ManState[1].SetAnimation(150, false);

	ManState[2].LoadBitmapByString({
		"./RES/Man/specialMan2/dead/left/slave (1).bmp",
		"./RES/Man/specialMan2/dead/left/slave (2).bmp",
		"./RES/Man/specialMan2/dead/left/slave (3).bmp",
		"./RES/Man/specialMan2/dead/left/slave (4).bmp",
		"./RES/Man/specialMan2/dead/left/slave (5).bmp",
		"./RES/Man/specialMan2/dead/left/slave (6).bmp",
		"./RES/Man/specialMan2/dead/left/slave (7).bmp", },
		RGB(255, 255, 255));
	ManState[2].SetAnimation(150, true);
	ManState[2].ToggleAnimation();

	ManState[3].LoadBitmapByString({
		"./RES/Man/specialMan2/dead/right/slave (1).bmp",
		"./RES/Man/specialMan2/dead/right/slave (2).bmp",
		"./RES/Man/specialMan2/dead/right/slave (3).bmp",
		"./RES/Man/specialMan2/dead/right/slave (4).bmp",
		"./RES/Man/specialMan2/dead/right/slave (5).bmp",
		"./RES/Man/specialMan2/dead/right/slave (6).bmp",
		"./RES/Man/specialMan2/dead/right/slave (7).bmp", },
		RGB(255, 255, 255));
	ManState[3].SetAnimation(150, true);
	ManState[3].ToggleAnimation();

	ManState[4].LoadBitmapByString({
		"./RES/Man/specialMan2/follow/left/slave (1).bmp",
		"./RES/Man/specialMan2/follow/left/slave (2).bmp",
		"./RES/Man/specialMan2/follow/left/slave (3).bmp",
		"./RES/Man/specialMan2/follow/left/slave_girl (1).bmp",
		"./RES/Man/specialMan2/follow/left/slave_girl (2).bmp",
		"./RES/Man/specialMan2/follow/left/slave_girl (3).bmp", },
		RGB(255, 255, 255));
	ManState[4].SetAnimation(150, false);

	ManState[5].LoadBitmapByString({
		"./RES/Man/specialMan2/follow/right/slave (1).bmp",
		"./RES/Man/specialMan2/follow/right/slave (2).bmp",
		"./RES/Man/specialMan2/follow/right/slave (3).bmp",
		"./RES/Man/specialMan2/follow/right/slave_girl (1).bmp",
		"./RES/Man/specialMan2/follow/right/slave_girl (2).bmp",
		"./RES/Man/specialMan2/follow/right/slave_girl (3).bmp", },
		RGB(255, 255, 255));
	ManState[5].SetAnimation(150, false);

	over_score.LoadBitmapByString({
		"./RES/Man/30000 (1).bmp",
		"./RES/Man/30000 (2).bmp",
		"./RES/Man/30000 (3).bmp",
		"./RES/Man/30000 (4).bmp",
		"./RES/Man/30000 (5).bmp", },
		RGB(255, 255, 255));
	over_score.SetAnimation(150, true);
	over_score.ToggleAnimation();
}

int Specialman2::heart(int maingirl_left, Score* score_sys) {
	man_on_top_big_heart.SetTopLeft(man_on_top_big_heart.GetLeft() + girl, -50);
	man_on_top_big_heart.ShowBitmap(1.5);
	get_heart = touch(maingirl_left, man_on_top_big_heart.GetLeft());
	if (modify_hp(score_sys)) {
		return 1;
	}
	return 0;
}

int Specialman2::modify_hp(Score* score_sys)
{
	if (get_heart) {
		HP::hp += 150;
		(*score_sys).score += 10000;
		return 1;
	}
	return 0;
}

int Specialman2::get_score()
{
	return 30000;
}
