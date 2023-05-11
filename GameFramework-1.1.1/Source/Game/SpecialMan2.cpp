#include "stdafx.h"
#include "SpecialMan2.h"

void Specialman2::Load_alive_left() {
	ManState[0].LoadBitmapByString({
		"./RES/Man/specialMan2/alive/left/specialMan (1).bmp",
		"./RES/Man/specialMan2/alive/left/specialMan (2).bmp",
		"./RES/Man/specialMan2/alive/left/specialMan (3).bmp",
		"./RES/Man/specialMan2/alive/left/specialMan (4).bmp",
		"./RES/Man/specialMan2/alive/left/specialMan (5).bmp",
		"./RES/Man/specialMan2/alive/left/specialMan (6).bmp", },
		RGB(0,0,0));
	ManState[0].SetAnimation(150, false);
}
void Specialman2::Load_alive_right() {
	ManState[1].LoadBitmapByString({
		"./RES/Man/specialMan2/alive/right/specialMan (1).bmp",
		"./RES/Man/specialMan2/alive/right/specialMan (2).bmp",
		"./RES/Man/specialMan2/alive/right/specialMan (3).bmp",
		"./RES/Man/specialMan2/alive/right/specialMan (4).bmp",
		"./RES/Man/specialMan2/alive/right/specialMan (5).bmp",
		"./RES/Man/specialMan2/alive/right/specialMan (6).bmp", },
		RGB(0,0,0));
	ManState[1].SetAnimation(150, false);
}
void Specialman2::Load_dead_left() {
	ManState[2].LoadBitmapByString({
		"./RES/Man/specialMan2/dead/left/slave (1).bmp",
		"./RES/Man/specialMan2/dead/left/slave (2).bmp",
		"./RES/Man/specialMan2/dead/left/slave (3).bmp",
		"./RES/Man/specialMan2/dead/left/slave (4).bmp",
		"./RES/Man/specialMan2/dead/left/slave (5).bmp",
		"./RES/Man/specialMan2/dead/left/slave (6).bmp",
		"./RES/Man/specialMan2/dead/left/slave (7).bmp", },
		RGB(0,0,0));
	ManState[2].SetAnimation(150, true);
	ManState[2].ToggleAnimation();
}
void Specialman2::Load_dead_right() {
	ManState[3].LoadBitmapByString({
		"./RES/Man/specialMan2/dead/right/slave (1).bmp",
		"./RES/Man/specialMan2/dead/right/slave (2).bmp",
		"./RES/Man/specialMan2/dead/right/slave (3).bmp",
		"./RES/Man/specialMan2/dead/right/slave (4).bmp",
		"./RES/Man/specialMan2/dead/right/slave (5).bmp",
		"./RES/Man/specialMan2/dead/right/slave (6).bmp",
		"./RES/Man/specialMan2/dead/right/slave (7).bmp", },
		RGB(0,0,0));
	ManState[3].SetAnimation(150, true);
	ManState[3].ToggleAnimation();
}
void Specialman2::Load_follow_left() {
	ManState[4].LoadBitmapByString({
		"./RES/Man/specialMan2/follow/left/slave (1).bmp",
		"./RES/Man/specialMan2/follow/left/slave (2).bmp",
		"./RES/Man/specialMan2/follow/left/slave (3).bmp",
		"./RES/Man/specialMan2/follow/left/slave_girl (1).bmp",
		"./RES/Man/specialMan2/follow/left/slave_girl (2).bmp",
		"./RES/Man/specialMan2/follow/left/slave_girl (3).bmp", },
		RGB(0,0,0));
	ManState[4].SetAnimation(150, false);
}
void Specialman2::Load_follow_right() {
	ManState[5].LoadBitmapByString({
		"./RES/Man/specialMan2/follow/right/slave (1).bmp",
		"./RES/Man/specialMan2/follow/right/slave (2).bmp",
		"./RES/Man/specialMan2/follow/right/slave (3).bmp",
		"./RES/Man/specialMan2/follow/right/slave_girl (1).bmp",
		"./RES/Man/specialMan2/follow/right/slave_girl (2).bmp",
		"./RES/Man/specialMan2/follow/right/slave_girl (3).bmp", },
		RGB(0,0,0));
	ManState[5].SetAnimation(150, false);
}