#include "stdafx.h"
#include "NormalMan3.h"

void Normalman3::Load_alive_left() {
	ManState[0].LoadBitmapByString({
		"./RES/Man/normalMan3/alive/left/normalMan (1).bmp",
		"./RES/Man/normalMan3/alive/left/normalMan (2).bmp",
		"./RES/Man/normalMan3/alive/left/normalMan (3).bmp",
		"./RES/Man/normalMan3/alive/left/normalMan (4).bmp",
		"./RES/Man/normalMan3/alive/left/normalMan (5).bmp",
		"./RES/Man/normalMan3/alive/left/normalMan (6).bmp", },
		RGB(255, 255, 255));
	ManState[0].SetAnimation(150, false);
}
void Normalman3::Load_alive_right() {
	ManState[1].LoadBitmapByString({
		"./RES/Man/normalMan3/alive/right/normalMan (1).bmp",
		"./RES/Man/normalMan3/alive/right/normalMan (2).bmp",
		"./RES/Man/normalMan3/alive/right/normalMan (3).bmp",
		"./RES/Man/normalMan3/alive/right/normalMan (4).bmp",
		"./RES/Man/normalMan3/alive/right/normalMan (5).bmp",
		"./RES/Man/normalMan3/alive/right/normalMan (6).bmp", },
		RGB(255, 255, 255));
	ManState[1].SetAnimation(150, false);
}
void Normalman3::Load_dead_left() {
	ManState[2].LoadBitmapByString({
		"./RES/Man/normalMan3/dead/left/slave (1).bmp",
		"./RES/Man/normalMan3/dead/left/slave (2).bmp",
		"./RES/Man/normalMan3/dead/left/slave (3).bmp",
		"./RES/Man/normalMan3/dead/left/slave (4).bmp",
		"./RES/Man/normalMan3/dead/left/slave (5).bmp",
		"./RES/Man/normalMan3/dead/left/slave (6).bmp",
		"./RES/Man/normalMan3/dead/left/slave (7).bmp", },
		RGB(255, 255, 255));
	ManState[2].SetAnimation(150, false);
}
void Normalman3::Load_dead_right() {
	ManState[3].LoadBitmapByString({
		"./RES/Man/normalMan3/dead/right/slave (1).bmp",
		"./RES/Man/normalMan3/dead/right/slave (2).bmp",
		"./RES/Man/normalMan3/dead/right/slave (3).bmp",
		"./RES/Man/normalMan3/dead/right/slave (4).bmp",
		"./RES/Man/normalMan3/dead/right/slave (5).bmp",
		"./RES/Man/normalMan3/dead/right/slave (6).bmp",
		"./RES/Man/normalMan3/dead/right/slave (7).bmp", },
		RGB(255, 255, 255));
	ManState[3].SetAnimation(150, false);
}
void Normalman3::Load_follow_left() {
	ManState[4].LoadBitmapByString({
		"./RES/Man/normalMan3/follow/left/slave (1).bmp",
		"./RES/Man/normalMan3/follow/left/slave (2).bmp",
		"./RES/Man/normalMan3/follow/left/slave (3).bmp",
		"./RES/Man/normalMan3/follow/left/slave_girl (1).bmp",
		"./RES/Man/normalMan3/follow/left/slave_girl (2).bmp",
		"./RES/Man/normalMan3/follow/left/slave_girl (3).bmp", },
		RGB(255, 255, 255));
	ManState[4].SetAnimation(150, false);
}
void Normalman3::Load_follow_right() {
	ManState[5].LoadBitmapByString({
		"./RES/Man/normalMan3/follow/right/slave (1).bmp",
		"./RES/Man/normalMan3/follow/right/slave (2).bmp",
		"./RES/Man/normalMan3/follow/right/slave (3).bmp",
		"./RES/Man/normalMan3/follow/right/slave_girl (1).bmp",
		"./RES/Man/normalMan3/follow/right/slave_girl (2).bmp",
		"./RES/Man/normalMan3/follow/right/slave_girl (3).bmp", },
		RGB(255, 255, 255));
	ManState[5].SetAnimation(150, false);
}