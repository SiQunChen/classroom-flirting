#include "stdafx.h"
#include "SpecialMan3.h"

void Specialman3::Load_alive_left() {
	LoadBitmapByString({ //左邊走路
		"../../RES/Man/specialMan3/alive/left/specialMan (1).bmp",
		"../../RES/Man/specialMan3/alive/left/specialMan (2).bmp",
		"../../RES/Man/specialMan3/alive/left/specialMan (3).bmp",
		"../../RES/Man/specialMan3/alive/left/specialMan (4).bmp",
		"../../RES/Man/specialMan3/alive/left/specialMan (5).bmp",
		"../../RES/Man/specialMan3/alive/left/specialMan (6).bmp",
		"../../RES/Man/specialMan3/alive/left/specialMan (7).bmp", },
		RGB(0, 0, 0));
}
void Specialman3::Load_alive_right() {
	LoadBitmapByString({ //右邊走路
		"../../RES/Man/specialMan3/alive/right/specialMan (1).bmp",
		"../../RES/Man/specialMan3/alive/right/specialMan (2).bmp",
		"../../RES/Man/specialMan3/alive/right/specialMan (3).bmp",
		"../../RES/Man/specialMan3/alive/right/specialMan (4).bmp",
		"../../RES/Man/specialMan3/alive/right/specialMan (5).bmp",
		"../../RES/Man/specialMan3/alive/right/specialMan (6).bmp",
		"../../RES/Man/specialMan3/alive/right/specialMan (7).bmp", },
		RGB(0, 0, 0));
}
void Specialman3::Load_dead_left() {
	LoadBitmapByString({ //左邊死亡
		"../../RES/Man/specialMan3/dead/left/slave (1).bmp",
		"../../RES/Man/specialMan3/dead/left/slave (2).bmp",
		"../../RES/Man/specialMan3/dead/left/slave (3).bmp",
		"../../RES/Man/specialMan3/dead/left/slave (4).bmp",
		"../../RES/Man/specialMan3/dead/left/slave (5).bmp",
		"../../RES/Man/specialMan3/dead/left/slave (6).bmp",
		"../../RES/Man/specialMan3/dead/left/slave (7).bmp", },
		RGB(0, 0, 0));
}
void Specialman3::Load_dead_right() {
	LoadBitmapByString({ //右邊死亡
		"../../RES/Man/specialMan3/dead/right/slave (1).bmp",
		"../../RES/Man/specialMan3/dead/right/slave (2).bmp",
		"../../RES/Man/specialMan3/dead/right/slave (3).bmp",
		"../../RES/Man/specialMan3/dead/right/slave (4).bmp",
		"../../RES/Man/specialMan3/dead/right/slave (5).bmp",
		"../../RES/Man/specialMan3/dead/right/slave (6).bmp",
		"../../RES/Man/specialMan3/dead/right/slave (7).bmp", },
		RGB(0, 0, 0));
}
void Specialman3::Load_follow_left() {
	LoadBitmapByString({ //左邊跟隨
		"../../RES/Man/specialMan3/follow/left/slave (1).bmp",
		"../../RES/Man/specialMan3/follow/left/slave (2).bmp",
		"../../RES/Man/specialMan3/follow/left/slave (3).bmp",
		"../../RES/Man/specialMan3/follow/left/slave_girl (1).bmp",
		"../../RES/Man/specialMan3/follow/left/slave_girl (2).bmp",
		"../../RES/Man/specialMan3/follow/left/slave_girl (3).bmp", },
		RGB(0, 0, 0));
}
void Specialman3::Load_follow_right() {
	LoadBitmapByString({ //右邊跟隨
		"../../RES/Man/specialMan3/follow/right/slave (1).bmp",
		"../../RES/Man/specialMan3/follow/right/slave (2).bmp",
		"../../RES/Man/specialMan3/follow/right/slave (3).bmp",
		"../../RES/Man/specialMan3/follow/right/slave_girl (1).bmp",
		"../../RES/Man/specialMan3/follow/right/slave_girl (2).bmp",
		"../../RES/Man/specialMan3/follow/right/slave_girl (3).bmp", },
		RGB(0, 0, 0));
}