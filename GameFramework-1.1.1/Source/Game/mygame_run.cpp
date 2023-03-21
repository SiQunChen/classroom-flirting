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
	POINT p;
	GetCursorPos(&p);
	HWND hwnd = FindWindowA(NULL, "Game");
	ScreenToClient(hwnd, &p);
	if (map.GetLeft() >= -2094 && map.GetLeft() <= 0) {
		MainGirlMove(p);
	}
	else {
		if (map.GetLeft() >= -50 && p.x < MainGirl_walk_right.GetLeft()) {
			maingirl = 5;	//左邊
			MainGirl.SetFrameIndexOfBitmap(0);
			MainGirl.SetTopLeft(450, 300);
			up.SetTopLeft(75, 170);
			down.SetTopLeft(90, 380);
		}
		else if (map.GetLeft() <= -2044 && p.x > MainGirl_walk_right.GetLeft()) {
			maingirl = 6;	//右邊
			MainGirl.SetFrameIndexOfBitmap(1);
			MainGirl.SetTopLeft(250, 300);
			up.SetTopLeft(535, 170);
			down.SetTopLeft(550, 380);
		}
		else {
			MainGirlMove(p);
		}
	}
}

void CGameStateRun::MainGirlMove(POINT p) {
	if (p.x - MainGirl_walk_right.GetLeft() > 0 && p.x - MainGirl_walk_right.GetLeft() < 300) {
		maingirl = 1;
		if (MainGirl_walk_right.GetLeft() > 250) {
			MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() - 5, 300);
		}
		map.SetTopLeft(map.GetLeft() - 5, 0);
	}
	else if (p.x - MainGirl_walk_right.GetLeft() >= 300) {
		maingirl = 2;
		MainGirl_run_right.SetTopLeft(MainGirl_walk_right.GetLeft(), 300);
		if (MainGirl_walk_right.GetLeft() > 250) {
			MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() - 10, 300);
		}
		map.SetTopLeft(map.GetLeft() - 10, 0);
	}
	else if (p.x - MainGirl_walk_right.GetLeft() > -300 && p.x - MainGirl_walk_right.GetLeft() <= 0) {
		maingirl = 3;
		MainGirl_walk_left.SetTopLeft(MainGirl_walk_right.GetLeft(), 300);
		if (MainGirl_walk_right.GetLeft() < 450) {
			MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() + 5, 300);
		}
		map.SetTopLeft(map.GetLeft() + 5, 0);
	}
	else {
		maingirl = 4;
		MainGirl_run_left.SetTopLeft(MainGirl_walk_right.GetLeft(), 300);
		if (MainGirl_walk_right.GetLeft() < 450) {
			MainGirl_walk_right.SetTopLeft(MainGirl_walk_right.GetLeft() + 10, 300);
		}
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
	if (floor == 1) {
		map.SetFrameIndexOfBitmap(0);
		map.ShowBitmap();
	}
	else if (floor == 2) {
		map.SetFrameIndexOfBitmap(1);
		map.ShowBitmap();
	}
	else if (floor == 3) {
		map.SetFrameIndexOfBitmap(2);
		map.ShowBitmap();
	}
	else {
		map.SetFrameIndexOfBitmap(3);
		map.ShowBitmap();
	}
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
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
		up.ShowBitmap(1.8);
		down.ShowBitmap(1.9);
	}
	else {
		MainGirl.ShowBitmap();
		up.ShowBitmap(1.8);
		down.ShowBitmap(1.9);
	}
}