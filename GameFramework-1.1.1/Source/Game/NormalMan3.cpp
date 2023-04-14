#include "stdafx.h"
#include "NormalMan3.h"

void Normalman3::Load_alive_left() {
	LoadBitmapByString({ //左邊走路
		"../../RES/Man/normalMan3/alive/left/normalMan (1).bmp",
		"../../RES/Man/normalMan3/alive/left/normalMan (2).bmp",
		"../../RES/Man/normalMan3/alive/left/normalMan (3).bmp",
		"../../RES/Man/normalMan3/alive/left/normalMan (4).bmp",
		"../../RES/Man/normalMan3/alive/left/normalMan (5).bmp",
		"../../RES/Man/normalMan3/alive/left/normalMan (6).bmp", },
		RGB(0, 0, 0));
}
void Normalman3::Load_alive_right() {
	LoadBitmapByString({ //右邊走路
		"../../RES/Man/normalMan3/alive/right/normalMan (1).bmp",
		"../../RES/Man/normalMan3/alive/right/normalMan (2).bmp",
		"../../RES/Man/normalMan3/alive/right/normalMan (3).bmp",
		"../../RES/Man/normalMan3/alive/right/normalMan (4).bmp",
		"../../RES/Man/normalMan3/alive/right/normalMan (5).bmp",
		"../../RES/Man/normalMan3/alive/right/normalMan (6).bmp", },
		RGB(0, 0, 0));
}
void Normalman3::Load_dead_left() {
	LoadBitmapByString({ //左邊死亡
		"../../RES/Man/normalMan3/dead/left/slave (1).bmp",
		"../../RES/Man/normalMan3/dead/left/slave (2).bmp",
		"../../RES/Man/normalMan3/dead/left/slave (3).bmp",
		"../../RES/Man/normalMan3/dead/left/slave (4).bmp",
		"../../RES/Man/normalMan3/dead/left/slave (5).bmp",
		"../../RES/Man/normalMan3/dead/left/slave (6).bmp",
		"../../RES/Man/normalMan3/dead/left/slave (7).bmp", },
		RGB(0, 0, 0));
}
void Normalman3::Load_dead_right() {
	LoadBitmapByString({ //右邊死亡
		"../../RES/Man/normalMan3/dead/right/slave (1).bmp",
		"../../RES/Man/normalMan3/dead/right/slave (2).bmp",
		"../../RES/Man/normalMan3/dead/right/slave (3).bmp",
		"../../RES/Man/normalMan3/dead/right/slave (4).bmp",
		"../../RES/Man/normalMan3/dead/right/slave (5).bmp",
		"../../RES/Man/normalMan3/dead/right/slave (6).bmp",
		"../../RES/Man/normalMan3/dead/right/slave (7).bmp", },
		RGB(0, 0, 0));
}
void Normalman3::Load_follow_left() {
	LoadBitmapByString({ //左邊跟隨
		"../../RES/Man/normalMan3/follow/left/slave (1).bmp",
		"../../RES/Man/normalMan3/follow/left/slave (2).bmp",
		"../../RES/Man/normalMan3/follow/left/slave (3).bmp",
		"../../RES/Man/normalMan3/follow/left/slave_girl (1).bmp",
		"../../RES/Man/normalMan3/follow/left/slave_girl (2).bmp",
		"../../RES/Man/normalMan3/follow/left/slave_girl (3).bmp", },
		RGB(0, 0, 0));
}
void Normalman3::Load_follow_right() {
	LoadBitmapByString({ //右邊跟隨
		"../../RES/Man/normalMan3/follow/right/slave (1).bmp",
		"../../RES/Man/normalMan3/follow/right/slave (2).bmp",
		"../../RES/Man/normalMan3/follow/right/slave (3).bmp",
		"../../RES/Man/normalMan3/follow/right/slave_girl (1).bmp",
		"../../RES/Man/normalMan3/follow/right/slave_girl (2).bmp",
		"../../RES/Man/normalMan3/follow/right/slave_girl (3).bmp", },
		RGB(0, 0, 0));
}