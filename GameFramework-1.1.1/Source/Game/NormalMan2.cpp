#include "stdafx.h"
#include "NormalMan.h"

void Normalman2::Load_state() {
	ManState[0].LoadBitmapByString({ //left walking
		"./RES/Man/normalMan2/alive/left/normalMan (1).bmp",
		"./RES/Man/normalMan2/alive/left/normalMan (2).bmp",
		"./RES/Man/normalMan2/alive/left/normalMan (3).bmp",
		"./RES/Man/normalMan2/alive/left/normalMan (4).bmp",
		"./RES/Man/normalMan2/alive/left/normalMan (5).bmp",
		"./RES/Man/normalMan2/alive/left/normalMan (6).bmp", },
		RGB(255, 255, 255));
	ManState[0].SetAnimation(150, false);

	ManState[1].LoadBitmapByString({ //right walking
		"./RES/Man/normalMan2/alive/right/normalMan (1).bmp",
		"./RES/Man/normalMan2/alive/right/normalMan (2).bmp",
		"./RES/Man/normalMan2/alive/right/normalMan (3).bmp",
		"./RES/Man/normalMan2/alive/right/normalMan (4).bmp",
		"./RES/Man/normalMan2/alive/right/normalMan (5).bmp",
		"./RES/Man/normalMan2/alive/right/normalMan (6).bmp", },
		RGB(255, 255, 255));
	ManState[1].SetAnimation(150, false);

	ManState[2].LoadBitmapByString({ //left dead 
		"./RES/Man/normalMan2/dead/left/slave (1).bmp",
		"./RES/Man/normalMan2/dead/left/slave (2).bmp",
		"./RES/Man/normalMan2/dead/left/slave (3).bmp",
		"./RES/Man/normalMan2/dead/left/slave (4).bmp",
		"./RES/Man/normalMan2/dead/left/slave (5).bmp",
		"./RES/Man/normalMan2/dead/left/slave (6).bmp",
		"./RES/Man/normalMan2/dead/left/slave (7).bmp", },
		RGB(255, 255, 255));
	ManState[2].SetAnimation(100, true);
	ManState[2].ToggleAnimation();

	ManState[3].LoadBitmapByString({ //right dead
		"./RES/Man/normalMan2/dead/right/slave (1).bmp",
		"./RES/Man/normalMan2/dead/right/slave (2).bmp",
		"./RES/Man/normalMan2/dead/right/slave (3).bmp",
		"./RES/Man/normalMan2/dead/right/slave (4).bmp",
		"./RES/Man/normalMan2/dead/right/slave (5).bmp",
		"./RES/Man/normalMan2/dead/right/slave (6).bmp",
		"./RES/Man/normalMan2/dead/right/slave (7).bmp", },
		RGB(255, 255, 255));
	ManState[3].SetAnimation(100, true);
	ManState[3].ToggleAnimation();

	ManState[4].LoadBitmapByString({ //left follow
		"./RES/Man/normalMan2/follow/left/slave (1).bmp",
		"./RES/Man/normalMan2/follow/left/slave (2).bmp",
		"./RES/Man/normalMan2/follow/left/slave (3).bmp",
		"./RES/Man/normalMan2/follow/left/slave_girl (1).bmp",
		"./RES/Man/normalMan2/follow/left/slave_girl (2).bmp",
		"./RES/Man/normalMan2/follow/left/slave_girl (3).bmp", },
		RGB(255, 255, 255));
	ManState[4].SetAnimation(150, false);

	ManState[5].LoadBitmapByString({ //right follow
		"./RES/Man/normalMan2/follow/right/slave (1).bmp",
		"./RES/Man/normalMan2/follow/right/slave (2).bmp",
		"./RES/Man/normalMan2/follow/right/slave (3).bmp",
		"./RES/Man/normalMan2/follow/right/slave_girl (1).bmp",
		"./RES/Man/normalMan2/follow/right/slave_girl (2).bmp",
		"./RES/Man/normalMan2/follow/right/slave_girl (3).bmp", },
		RGB(255, 255, 255));
	ManState[5].SetAnimation(150, false);

	over_score.LoadBitmapByString({
		"./RES/Man/1000 (1).bmp",
		"./RES/Man/1000 (2).bmp",
		"./RES/Man/1000 (3).bmp",
		"./RES/Man/1000 (4).bmp",
		"./RES/Man/1000 (5).bmp", },
		RGB(255, 255, 255));
	over_score.SetAnimation(150, true);
	over_score.ToggleAnimation();
}

int Normalman2::heart(int maingirl_left, Score* score_sys) {
	if (this->ManState[0].GetTop() > 300) {
		man_on_bottom_small_heart.SetTopLeft(man_on_bottom_small_heart.GetLeft() + girl, man_on_bottom_small_heart.GetTop());
		man_on_bottom_small_heart.ShowBitmap();
		get_heart = touch(maingirl_left, man_on_bottom_small_heart.GetLeft());
	}
	else {
		man_on_top_small_heart.SetTopLeft(man_on_top_small_heart.GetLeft() + girl, man_on_top_small_heart.GetTop());
		man_on_top_small_heart.ShowBitmap();
		get_heart = touch(maingirl_left, man_on_top_small_heart.GetLeft());
	}
	if (modify_hp(score_sys)) {
		return 1;
	}
	return 0;
}

int Normalman2::modify_hp(Score* score_sys)
{
	if (get_heart) {
		HP::hp += 100;
		(*score_sys).score += 500;
		return 1;
	}
	return 0;
}

int Normalman2::get_score()
{
	return 1000;
}
