#include "stdafx.h"
#include "NormalMan3.h"

void Normalman3::Load_state() {
	ManState[0].LoadBitmapByString({
		"./RES/Man/normalMan3/alive/left/normalMan (1).bmp",
		"./RES/Man/normalMan3/alive/left/normalMan (2).bmp",
		"./RES/Man/normalMan3/alive/left/normalMan (3).bmp",
		"./RES/Man/normalMan3/alive/left/normalMan (4).bmp",
		"./RES/Man/normalMan3/alive/left/normalMan (5).bmp",
		"./RES/Man/normalMan3/alive/left/normalMan (6).bmp", },
		RGB(255, 255, 255));
	ManState[0].SetAnimation(150, false);

	ManState[1].LoadBitmapByString({
		"./RES/Man/normalMan3/alive/right/normalMan (1).bmp",
		"./RES/Man/normalMan3/alive/right/normalMan (2).bmp",
		"./RES/Man/normalMan3/alive/right/normalMan (3).bmp",
		"./RES/Man/normalMan3/alive/right/normalMan (4).bmp",
		"./RES/Man/normalMan3/alive/right/normalMan (5).bmp",
		"./RES/Man/normalMan3/alive/right/normalMan (6).bmp", },
		RGB(255, 255, 255));
	ManState[1].SetAnimation(150, false);

	ManState[2].LoadBitmapByString({
		"./RES/Man/normalMan3/dead/left/slave (1).bmp",
		"./RES/Man/normalMan3/dead/left/slave (2).bmp",
		"./RES/Man/normalMan3/dead/left/slave (3).bmp",
		"./RES/Man/normalMan3/dead/left/slave (4).bmp",
		"./RES/Man/normalMan3/dead/left/slave (5).bmp",
		"./RES/Man/normalMan3/dead/left/slave (6).bmp",
		"./RES/Man/normalMan3/dead/left/slave (7).bmp", },
		RGB(255, 255, 255));
	ManState[2].SetAnimation(150, true);
	ManState[2].ToggleAnimation();

	ManState[3].LoadBitmapByString({
		"./RES/Man/normalMan3/dead/right/slave (1).bmp",
		"./RES/Man/normalMan3/dead/right/slave (2).bmp",
		"./RES/Man/normalMan3/dead/right/slave (3).bmp",
		"./RES/Man/normalMan3/dead/right/slave (4).bmp",
		"./RES/Man/normalMan3/dead/right/slave (5).bmp",
		"./RES/Man/normalMan3/dead/right/slave (6).bmp",
		"./RES/Man/normalMan3/dead/right/slave (7).bmp", },
		RGB(255, 255, 255));
	ManState[3].SetAnimation(150, true);
	ManState[3].ToggleAnimation();

	ManState[4].LoadBitmapByString({
		"./RES/Man/normalMan3/follow/left/slave (1).bmp",
		"./RES/Man/normalMan3/follow/left/slave (2).bmp",
		"./RES/Man/normalMan3/follow/left/slave (3).bmp",
		"./RES/Man/normalMan3/follow/left/slave_girl (1).bmp",
		"./RES/Man/normalMan3/follow/left/slave_girl (2).bmp",
		"./RES/Man/normalMan3/follow/left/slave_girl (3).bmp", },
		RGB(255, 255, 255));
	ManState[4].SetAnimation(150, false);

	ManState[5].LoadBitmapByString({
		"./RES/Man/normalMan3/follow/right/slave (1).bmp",
		"./RES/Man/normalMan3/follow/right/slave (2).bmp",
		"./RES/Man/normalMan3/follow/right/slave (3).bmp",
		"./RES/Man/normalMan3/follow/right/slave_girl (1).bmp",
		"./RES/Man/normalMan3/follow/right/slave_girl (2).bmp",
		"./RES/Man/normalMan3/follow/right/slave_girl (3).bmp", },
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

int Normalman3::heart(int maingirl_left, Score* score_sys) {
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

int Normalman3::modify_hp(Score* score_sys)
{
	if (get_heart) {
		HP::hp += 100;
		(*score_sys).score += 500;
		return 1;
	}
	return 0;
}

int Normalman3::get_score()
{
	return 1000;
}
