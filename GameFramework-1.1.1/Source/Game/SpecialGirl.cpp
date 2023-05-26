#include "stdafx.h"
#include "SpecialGirl.h"

void Specialgirl::Load() {
	walk_left.LoadBitmapByString({
		"./RES/girl/specialGirl/left/specialGirl (1).bmp",
		"./RES/girl/specialGirl/left/specialGirl (2).bmp",
		"./RES/girl/specialGirl/left/specialGirl (3).bmp",
		"./RES/girl/specialGirl/left/specialGirl (4).bmp",
		"./RES/girl/specialGirl/left/specialGirl (5).bmp", },
		RGB(255, 255, 255));
	walk_left.SetAnimation(150, false);

	walk_right.LoadBitmapByString({
		"./RES/girl/specialGirl/right/specialGirl (1).bmp",
		"./RES/girl/specialGirl/right/specialGirl (2).bmp",
		"./RES/girl/specialGirl/right/specialGirl (3).bmp",
		"./RES/girl/specialGirl/right/specialGirl (4).bmp",
		"./RES/girl/specialGirl/right/specialGirl (5).bmp", },
		RGB(255, 255, 255));
	walk_right.SetAnimation(150, false);

	fly_left.LoadBitmapByString({
		"./RES/girl/specialGirl/left/flying (1).bmp",
		"./RES/girl/specialGirl/left/flying (2).bmp",
		"./RES/girl/specialGirl/left/flying (3).bmp",
		"./RES/girl/specialGirl/left/flying (4).bmp", },
		RGB(255, 255, 255));
	fly_left.SetAnimation(150, true);
	fly_left.ToggleAnimation();

	fly_right.LoadBitmapByString({
		"./RES/girl/specialGirl/right/flying (1).bmp",
		"./RES/girl/specialGirl/right/flying (2).bmp",
		"./RES/girl/specialGirl/right/flying (3).bmp",
		"./RES/girl/specialGirl/right/flying (4).bmp", },
		RGB(255, 255, 255));
	fly_right.SetAnimation(150, true);
	fly_right.ToggleAnimation();

	win_left.LoadBitmapByString({
		"./RES/girl/specialGirl/left/win (1).bmp",
		"./RES/girl/specialGirl/left/win (2).bmp",
		"./RES/girl/specialGirl/left/win (3).bmp",
		"./RES/girl/specialGirl/left/win (4).bmp",
		"./RES/girl/specialGirl/left/win (5).bmp", },
		RGB(255, 255, 255));
	win_left.SetAnimation(150, false);

	win_right.LoadBitmapByString({
		"./RES/girl/specialGirl/right/win (1).bmp",
		"./RES/girl/specialGirl/right/win (2).bmp",
		"./RES/girl/specialGirl/right/win (3).bmp",
		"./RES/girl/specialGirl/right/win (4).bmp",
		"./RES/girl/specialGirl/right/win (5).bmp", },
		RGB(255, 255, 255));
	win_right.SetAnimation(150, false);

	notice_left.LoadBitmapByString({ "./RES/girl/specialGirl/left/notice.bmp" }, RGB(255, 255, 255));

	notice_right.LoadBitmapByString({ "./RES/girl/specialGirl/right/notice.bmp" }, RGB(255, 255, 255));

	shoot_left.LoadBitmapByString({ "./RES/girl/specialGirl/left/shooting.bmp" }, RGB(255, 255, 255));

	shoot_right.LoadBitmapByString({ "./RES/girl/specialGirl/right/shooting.bmp" }, RGB(255, 255, 255));
}