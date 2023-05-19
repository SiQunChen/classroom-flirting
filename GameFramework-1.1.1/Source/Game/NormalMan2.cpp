#include "stdafx.h"
#include "NormalMan2.h"

void Normalman2::Load_alive_left() {
	ManState[0].LoadBitmapByString({ //left walking
		"./RES/Man/normalMan2/alive/left/normalMan (1).bmp",
		"./RES/Man/normalMan2/alive/left/normalMan (2).bmp",
		"./RES/Man/normalMan2/alive/left/normalMan (3).bmp",
		"./RES/Man/normalMan2/alive/left/normalMan (4).bmp",
		"./RES/Man/normalMan2/alive/left/normalMan (5).bmp",
		"./RES/Man/normalMan2/alive/left/normalMan (6).bmp", },
		RGB(255, 255, 255));
	ManState[0].SetAnimation(150, false);
}
void Normalman2::Load_alive_right() {
	ManState[1].LoadBitmapByString({ //right walking
		"./RES/Man/normalMan2/alive/right/normalMan (1).bmp",
		"./RES/Man/normalMan2/alive/right/normalMan (2).bmp",
		"./RES/Man/normalMan2/alive/right/normalMan (3).bmp",
		"./RES/Man/normalMan2/alive/right/normalMan (4).bmp",
		"./RES/Man/normalMan2/alive/right/normalMan (5).bmp",
		"./RES/Man/normalMan2/alive/right/normalMan (6).bmp", },
		RGB(255, 255, 255));
	ManState[1].SetAnimation(150, false);
}
void Normalman2::Load_dead_left() {
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
}
void Normalman2::Load_dead_right() {
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
}
void Normalman2::Load_follow_left() {
	ManState[4].LoadBitmapByString({ //left follow
		"./RES/Man/normalMan2/follow/left/slave (1).bmp",
		"./RES/Man/normalMan2/follow/left/slave (2).bmp",
		"./RES/Man/normalMan2/follow/left/slave (3).bmp",
		"./RES/Man/normalMan2/follow/left/slave_girl (1).bmp",
		"./RES/Man/normalMan2/follow/left/slave_girl (2).bmp",
		"./RES/Man/normalMan2/follow/left/slave_girl (3).bmp", },
		RGB(255, 255, 255));
	ManState[4].SetAnimation(150, false);
}
void Normalman2::Load_follow_right() {
	ManState[5].LoadBitmapByString({ //right follow
		"./RES/Man/normalMan2/follow/right/slave (1).bmp",
		"./RES/Man/normalMan2/follow/right/slave (2).bmp",
		"./RES/Man/normalMan2/follow/right/slave (3).bmp",
		"./RES/Man/normalMan2/follow/right/slave_girl (1).bmp",
		"./RES/Man/normalMan2/follow/right/slave_girl (2).bmp",
		"./RES/Man/normalMan2/follow/right/slave_girl (3).bmp", },
		RGB(255, 255, 255));
	ManState[5].SetAnimation(150, false);
}