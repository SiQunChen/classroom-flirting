#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
 #include "mygame.h"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	GetCursorPos(&p);
	HWND hwnd = FindWindowA(NULL, "Game");
	ScreenToClient(hwnd, &p);
	if (map.GetLeft() >= -2094 && map.GetLeft() <= 0) {
		MainGirlMove();
	}
	else {
		if (up_down == 0) {
			if (map.GetLeft() >= -50 && p.x < MainGirl_walk_right.GetLeft()) {
				maingirl = 5;	//左邊
				MainGirl.SetFrameIndexOfBitmap(0);
				MainGirl.SetTopLeft(450, 300);
				MainGirl_walk_right.SetTopLeft(450, 300); //不設定的話，上下樓會造成短暫瞬間移動
				up.SetTopLeft(75, 170);
				down.SetTopLeft(90, 380);
			}
			else if (map.GetLeft() <= -2044 && p.x > MainGirl_walk_right.GetLeft()) {
				maingirl = 6;	//右邊
				MainGirl.SetFrameIndexOfBitmap(1);
				MainGirl.SetTopLeft(250, 300);
				MainGirl_walk_right.SetTopLeft(250, 300);
				up.SetTopLeft(535, 170);
				down.SetTopLeft(550, 380);
			}
			else {
				MainGirlMove();
			}
		}
		else { //這一大串全部都在做上下樓動畫==
			time++;
			if (maingirl == 1 && up_down == 1 && floor == 1) {
				if (MainGirl_walk_right.GetLeft() < 500) {
					MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() + 5, 300);
				}
				else {
					MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() + 5, MainGirl_walk_right.GetTop() - 5);
				}
			}
			else if (maingirl == 3 && up_down == 1 && floor == 1) {
				if (MainGirl_walk_right.GetLeft() > 270) {
					MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() - 5, 300);
				}
				else {
					MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() - 5, MainGirl_walk_right.GetTop() - 5);
				}
			}
			else if (maingirl == 1 && floor == 4) {
				MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() + 5, 300);
			}
			else if (maingirl == 3 && floor == 4) {
				MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() - 5, 300);
			}
			else if (maingirl == 1 && up_down == 1) {
				if (MainGirl_walk_right.GetLeft() < 380) {
					MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() + 5, 300);
				}
				else {
					MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() + 5, MainGirl_walk_right.GetTop() - 5);
				}
			}
			else if (maingirl == 1 && up_down == 2) {
				if (MainGirl_walk_right.GetLeft() < 650) {
					MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() + 5, 300);
				}
				else {
					MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() + 5, MainGirl_walk_right.GetTop() + 5);
				}
			}
			else if (maingirl == 3 && up_down == 1) {
				if (MainGirl_walk_right.GetLeft() > 330) {
					MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() - 5, 300);
				}
				else {
					MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() - 5, MainGirl_walk_right.GetTop() - 5);
				}
			}
			else if (maingirl == 3 && up_down == 2) {
				if (MainGirl_walk_right.GetLeft() > 70) {
					MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() - 5, 300);
				}
				else {
					MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() - 5, MainGirl_walk_right.GetTop() + 5);
				}
			}
			MainGirl_walk_left.SetTopLeft(MainGirl_walk_right.GetLeft(), MainGirl_walk_right.GetTop());
			if (time == 100) {
				if (up_down == 1) {
					if (floor == 1) {
						floor = 2;
						map.SetFrameIndexOfBitmap(1);
					}
					else if (floor == 2) {
						floor = 3;
						map.SetFrameIndexOfBitmap(2);
					}
					else if (floor == 3) {
						floor = 4;
						map.SetFrameIndexOfBitmap(3);
					}
					maingirl = 5;
					MainGirl_walk_right.SetTopLeft(400, 300);
				}
				else if (up_down == 2) {
					if (floor == 2) {
						floor = 1;
						map.SetFrameIndexOfBitmap(0);
					}
					else if (floor == 3) {
						floor = 2;
						map.SetFrameIndexOfBitmap(1);
					}
					else if (floor == 4) {
						floor = 3;
						map.SetFrameIndexOfBitmap(2);
					}
					maingirl = 6;
					MainGirl_walk_right.SetTopLeft(300, 300);
				}
				up_down = 0;
				time = 0;
			}
		}
	}
}

void CGameStateRun::MainGirlMove() {
	if (p.x - MainGirl_walk_right.GetLeft() > 0 && p.x - MainGirl_walk_right.GetLeft() < 200) {
		maingirl = 1;
		if (MainGirl_walk_right.GetLeft() > 250) {
			MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() - 5, 300);
		}
		map.SetTopLeft(map.GetLeft() - 5, 0);
	}
	else if (p.x - MainGirl_walk_right.GetLeft() >= 200) {
		maingirl = 2;
		if (MainGirl_walk_right.GetLeft() > 250) {
			MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() - 10, 300);
		}
		MainGirl_run_right.SetTopLeft(MainGirl_walk_right.GetLeft(), 300);
		map.SetTopLeft(map.GetLeft() - 10, 0);
	}
	else if (p.x - MainGirl_walk_right.GetLeft() > -200 && p.x - MainGirl_walk_right.GetLeft() <= 0) {
		maingirl = 3;
		if (MainGirl_walk_right.GetLeft() < 450) {
			MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() + 5, 300);
		}
		MainGirl_walk_left.SetTopLeft(MainGirl_walk_right.GetLeft(), 300);
		map.SetTopLeft(map.GetLeft() + 5, 0);
	}
	else {
		maingirl = 4;
		if (MainGirl_walk_right.GetLeft() < 450) {
			MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() + 10, 300);
		}
		MainGirl_run_left.SetTopLeft(MainGirl_walk_right.GetLeft(), 300);
		map.SetTopLeft(map.GetLeft() + 10, 0);
	}
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	map.LoadBitmapByString({
		"../../RES/map1.bmp",
		"../../RES/map2.bmp",
		"../../RES/map3.bmp",
		"../../RES/map4.bmp",
		});
	map.SetTopLeft(0, 0);

	up.LoadBitmapByString({"../../RES/UI/up.bmp", "../../RES/UI/up_hover.bmp",}, RGB(255, 255, 255));

	down.LoadBitmapByString({"../../RES/UI/down.bmp", "../../RES/UI/down_hover.bmp",}, RGB(255, 255, 255));

	MainGirl.LoadBitmapByString({ "../../RES/mainGirl/left/stand.bmp", "../../RES/mainGirl/right/stand.bmp", }, RGB(0, 0, 0));
	MainGirl.SetTopLeft(250, 300);

	MainGirl_walk_left.LoadBitmapByString({
		"../../RES/mainGirl/left/girl_walk (1).bmp",
		"../../RES/mainGirl/left/girl_walk (2).bmp",
		"../../RES/mainGirl/left/girl_walk (3).bmp",
		"../../RES/mainGirl/left/girl_walk (4).bmp",
		"../../RES/mainGirl/left/girl_walk (5).bmp",
		"../../RES/mainGirl/left/girl_walk (6).bmp",
		"../../RES/mainGirl/left/girl_walk (7).bmp", },
		RGB(230, 230, 196));
	MainGirl_walk_left.SetTopLeft(250, 300);
	MainGirl_walk_left.SetAnimation(150, false);

	MainGirl_run_left.LoadBitmapByString({
		"../../RES/mainGirl/left/girl_run (1).bmp",
		"../../RES/mainGirl/left/girl_run (2).bmp",
		"../../RES/mainGirl/left/girl_run (3).bmp",
		"../../RES/mainGirl/left/girl_run (4).bmp",
		"../../RES/mainGirl/left/girl_run (5).bmp",
		"../../RES/mainGirl/left/girl_run (6).bmp",
		"../../RES/mainGirl/left/girl_run (7).bmp", },
		RGB(0, 0, 0));
	MainGirl_run_left.SetTopLeft(250, 300);
	MainGirl_run_left.SetAnimation(150, false);

	MainGirl_walk_right.LoadBitmapByString({
		"../../RES/mainGirl/right/girl_walk (1).bmp",
		"../../RES/mainGirl/right/girl_walk (2).bmp",
		"../../RES/mainGirl/right/girl_walk (3).bmp",
		"../../RES/mainGirl/right/girl_walk (4).bmp",
		"../../RES/mainGirl/right/girl_walk (5).bmp",
		"../../RES/mainGirl/right/girl_walk (6).bmp",
		"../../RES/mainGirl/right/girl_walk (7).bmp", },
		RGB(230, 230, 196));
	MainGirl_walk_right.SetTopLeft(250, 300);
	MainGirl_walk_right.SetAnimation(150, false);

	MainGirl_run_right.LoadBitmapByString({
		"../../RES/mainGirl/right/girl_run (1).bmp",
		"../../RES/mainGirl/right/girl_run (2).bmp",
		"../../RES/mainGirl/right/girl_run (3).bmp",
		"../../RES/mainGirl/right/girl_run (4).bmp",
		"../../RES/mainGirl/right/girl_run (5).bmp",
		"../../RES/mainGirl/right/girl_run (6).bmp",
		"../../RES/mainGirl/right/girl_run (7).bmp", },
		RGB(0, 0, 0));
	MainGirl_run_right.SetTopLeft(250, 300);
	MainGirl_run_right.SetAnimation(150, false);
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	if ((p.x >= 100 && p.x <= 215) && (p.y >= 230 && p.y <= 340)) { //左邊上樓
		maingirl = 3;
		up_down = 1;
	}
	else if ((p.x >= 560 && p.x <= 675) && (p.y >= 230 && p.y <= 340)) { //右邊上樓
		maingirl = 1;
		up_down = 1;
	}
	else if ((p.x >= 95 && p.x <= 215) && (p.y >= 385 && p.y <= 505)) { //左邊下樓
		maingirl = 3;
		up_down = 2;
	}
	else if ((p.x >= 555 && p.x <= 675) && (p.y >= 385 && p.y <= 505)) { //右邊下樓
		maingirl = 1;
		up_down = 2;
	}
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	map.ShowBitmap();
	if (maingirl == 1) {
		MainGirl_walk_right.ShowBitmap();
	}
	else if (maingirl == 2) {
		MainGirl_run_right.ShowBitmap();
	}
	else if (maingirl == 3) {
		MainGirl_walk_left.ShowBitmap();
	}
	else if (maingirl == 4) {
		MainGirl_run_left.ShowBitmap();
	}
	else if (maingirl == 5) {
		MainGirl.ShowBitmap();
		if ((p.x >= 100 && p.x <= 215) && (p.y >= 230 && p.y <= 340)) {
			up.SetFrameIndexOfBitmap(1);
		}
		else if ((p.x >= 95 && p.x <= 215) && (p.y >= 385 && p.y <= 505)) {
			down.SetFrameIndexOfBitmap(1);
		}
		else {
			up.SetFrameIndexOfBitmap(0);
			down.SetFrameIndexOfBitmap(0);
		}
		if (floor != 4) {
			up.ShowBitmap(1.8);
		}
		if (floor != 1) {
			down.ShowBitmap(1.9);
		}
	}
	else {
		MainGirl.ShowBitmap();
		if ((p.x >= 560 && p.x <= 675) && (p.y >= 230 && p.y <= 340)) {
			up.SetFrameIndexOfBitmap(1);
		}
		else if ((p.x >= 555 && p.x <= 675) && (p.y >= 385 && p.y <= 505)) {
			down.SetFrameIndexOfBitmap(1);
		}
		else {
			up.SetFrameIndexOfBitmap(0);
			down.SetFrameIndexOfBitmap(0);
		}
		if (floor != 4) {
			up.ShowBitmap(1.8);
		}
		if (floor != 1) {
			down.ShowBitmap(1.9);
		}
	}
}