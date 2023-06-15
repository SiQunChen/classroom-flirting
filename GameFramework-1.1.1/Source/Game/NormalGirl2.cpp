#include "stdafx.h"
#include "NormalGirl.h"

void Normalgirl2::Load() {
	walk_left.LoadBitmapByString({
		"./RES/girl/normalGirl2/left/normalGirl (1).bmp",
		"./RES/girl/normalGirl2/left/normalGirl (2).bmp",
		"./RES/girl/normalGirl2/left/normalGirl (3).bmp",
		"./RES/girl/normalGirl2/left/normalGirl (4).bmp",
		"./RES/girl/normalGirl2/left/normalGirl (5).bmp", },
		RGB(255, 255, 255));
	walk_left.SetAnimation(150, false);

	walk_right.LoadBitmapByString({
		"./RES/girl/normalGirl2/right/normalGirl (1).bmp",
		"./RES/girl/normalGirl2/right/normalGirl (2).bmp",
		"./RES/girl/normalGirl2/right/normalGirl (3).bmp",
		"./RES/girl/normalGirl2/right/normalGirl (4).bmp",
		"./RES/girl/normalGirl2/right/normalGirl (5).bmp", },
		RGB(255, 255, 255));
	walk_right.SetAnimation(150, false);

	fly_left.LoadBitmapByString({
		"./RES/girl/normalGirl2/left/flying (1).bmp",
		"./RES/girl/normalGirl2/left/flying (2).bmp",
		"./RES/girl/normalGirl2/left/flying (3).bmp",
		"./RES/girl/normalGirl2/left/flying (4).bmp", },
		RGB(255, 255, 255));
	fly_left.SetAnimation(150, true);
	fly_left.ToggleAnimation();

	fly_right.LoadBitmapByString({
		"./RES/girl/normalGirl2/right/flying (1).bmp",
		"./RES/girl/normalGirl2/right/flying (2).bmp",
		"./RES/girl/normalGirl2/right/flying (3).bmp",
		"./RES/girl/normalGirl2/right/flying (4).bmp", },
		RGB(255, 255, 255));
	fly_right.SetAnimation(150, true);
	fly_right.ToggleAnimation();

	win_left.LoadBitmapByString({
		"./RES/girl/normalGirl2/left/win (1).bmp",
		"./RES/girl/normalGirl2/left/win (2).bmp",
		"./RES/girl/normalGirl2/left/win (3).bmp",
		"./RES/girl/normalGirl2/left/win (4).bmp",
		"./RES/girl/normalGirl2/left/win (5).bmp",
		"./RES/girl/normalGirl2/left/win (6).bmp",
		"./RES/girl/normalGirl2/left/win (7).bmp", },
		RGB(255, 255, 255));
	win_left.SetAnimation(150, false);

	win_right.LoadBitmapByString({
		"./RES/girl/normalGirl2/right/win (1).bmp",
		"./RES/girl/normalGirl2/right/win (2).bmp",
		"./RES/girl/normalGirl2/right/win (3).bmp",
		"./RES/girl/normalGirl2/right/win (4).bmp",
		"./RES/girl/normalGirl2/right/win (5).bmp",
		"./RES/girl/normalGirl2/right/win (6).bmp",
		"./RES/girl/normalGirl2/right/win (7).bmp", },
		RGB(255, 255, 255));
	win_right.SetAnimation(150, false);

	notice_left.LoadBitmapByString({ "./RES/girl/normalGirl2/left/notice.bmp" }, RGB(255, 255, 255));

	notice_right.LoadBitmapByString({ "./RES/girl/normalGirl2/right/notice.bmp" }, RGB(255, 255, 255));

	shoot_left.LoadBitmapByString({ "./RES/girl/normalGirl2/left/shooting.bmp" }, RGB(255, 255, 255));

	shoot_right.LoadBitmapByString({ "./RES/girl/normalGirl2/right/shooting.bmp" }, RGB(255, 255, 255));
}
