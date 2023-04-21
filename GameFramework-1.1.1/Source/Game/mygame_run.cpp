#include "stdafx.h"
#include "mygame.h"
#include<iostream>
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

void CGameStateRun::SetupMan(int floor, bool left) {
	if (left == true) {
		n1[floor * 2 - 2].ManState[0].SetTopLeft(750, 150);
		n1[floor * 2 - 2].ManState[1].SetTopLeft(750, 150);
		n2[floor * 2 - 2].ManState[0].SetTopLeft(1050, 350);
		n2[floor * 2 - 2].ManState[1].SetTopLeft(1050, 350);
		n3[floor * 2 - 2].ManState[0].SetTopLeft(1550, 350);
		n3[floor * 2 - 2].ManState[1].SetTopLeft(1550, 350);
		n1[floor * 2 - 1].ManState[0].SetTopLeft(1250, 150);
		n1[floor * 2 - 1].ManState[1].SetTopLeft(1250, 150);
		n2[floor * 2 - 1].ManState[0].SetTopLeft(1850, 350);
		n2[floor * 2 - 1].ManState[1].SetTopLeft(1850, 350);
		n3[floor * 2 - 1].ManState[0].SetTopLeft(2000, 150);
		n3[floor * 2 - 1].ManState[1].SetTopLeft(2000, 150);
	}
	else {
		n1[floor * 2 - 2].ManState[0].SetTopLeft(-1344, 150);
		n1[floor * 2 - 2].ManState[1].SetTopLeft(-1344, 150);
		n2[floor * 2 - 2].ManState[0].SetTopLeft(-1044, 350);
		n2[floor * 2 - 2].ManState[1].SetTopLeft(-1044, 350);
		n3[floor * 2 - 2].ManState[0].SetTopLeft(-544, 350);
		n3[floor * 2 - 2].ManState[1].SetTopLeft(-544, 350);
		n1[floor * 2 - 1].ManState[0].SetTopLeft(-844, 150);
		n1[floor * 2 - 1].ManState[1].SetTopLeft(-844, 150);
		n2[floor * 2 - 1].ManState[0].SetTopLeft(-244, 350);
		n2[floor * 2 - 1].ManState[1].SetTopLeft(-244, 350);
		n3[floor * 2 - 1].ManState[0].SetTopLeft(-94, 150);
		n3[floor * 2 - 1].ManState[1].SetTopLeft(-94, 150);
	}
}

void CGameStateRun::MainGirlMove() {
	if (p.x - main_girl[2].GetLeft() > 0 && p.x - main_girl[2].GetLeft() < 200) {
		maingirl = 1;
		if (main_girl[2].GetLeft() > 250) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, 250);
		}
		map.SetTopLeft(map.GetLeft() - 5, 0);
	}
	else if (p.x - main_girl[2].GetLeft() >= 200) {
		maingirl = 2;
		if (main_girl[2].GetLeft() > 250) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 10, 250);
		}
		main_girl[4].SetTopLeft(main_girl[2].GetLeft(), 250);
		map.SetTopLeft(map.GetLeft() - 10, 0);
	}
	else if (p.x - main_girl[2].GetLeft() > -200 && p.x - main_girl[2].GetLeft() <= 0) {
		maingirl = 3;
		if (main_girl[2].GetLeft() < 450) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, 250);
		}
		main_girl[1].SetTopLeft(main_girl[2].GetLeft(), 250);
		map.SetTopLeft(map.GetLeft() + 5, 0);
	}
	else {
		maingirl = 4;
		if (main_girl[2].GetLeft() < 450) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 10, 250);
		}
		main_girl[3].SetTopLeft(main_girl[2].GetLeft(), 250);
		map.SetTopLeft(map.GetLeft() + 10, 0);
	}
}

void CGameStateRun::OnBeginState()
{
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	map.LoadBitmapByString({
		"./RES/map1.bmp",
		"./RES/map2.bmp",
		"./RES/map3.bmp",
		"./RES/map4.bmp",});
	map.SetTopLeft(0, 0);
	
	main_girl[0].Load_main();
	main_girl[1].Load_walk_left();
	main_girl[2].Load_walk_right();
	main_girl[3].Load_run_left();
	main_girl[4].Load_run_right();

	up.LoadBitmapByString({
		"./RES/UI/elevator/up.bmp", 
		"./RES/UI/elevator/up_hover.bmp",},
		RGB(255, 255, 255));
	down.LoadBitmapByString({
		"./RES/UI/elevator/down.bmp", 
		"./RES/UI/elevator/down_hover.bmp",},
		RGB(255, 255, 255));
	
	score_board.LoadBitmapByString({
		"./RES/UI/number/scoreBoard.bmp"});
	score_board.SetTopLeft(430, -1);

	hp_board.LoadBitmapByString({
		"./RES/UI/heart/heartPointBoard.bmp"});
	hp_board.SetTopLeft(0, 0);
	
	clock_board.LoadBitmapByString({
		"./RES/UI/clock/clock.bmp",
		"./RES/UI/clock/clock_background.bmp"});
	clock_board.SetTopLeft(350, 0);

	for (int i = 0; i < 8; i++) {
		if (i < 2) {
			s1[i].Load_alive_left();
			s1[i].Load_alive_right();
			s1[i].Load_dead_left();
			s1[i].Load_dead_right();
			s1[i].Load_follow_left();
			s1[i].Load_follow_right();

			s2[i].Load_alive_left();
			s2[i].Load_alive_right();
			s2[i].Load_dead_left();
			s2[i].Load_dead_right();
			s2[i].Load_follow_left();
			s2[i].Load_follow_right();

			s3[i].Load_alive_left();
			s3[i].Load_alive_right();
			s3[i].Load_dead_left();
			s3[i].Load_dead_right();
			s3[i].Load_follow_left();
			s3[i].Load_follow_right();
		}
		n1[i].Load_alive_left();
		n1[i].Load_alive_right();
		n1[i].Load_dead_left();
		n1[i].Load_dead_right();
		n1[i].Load_follow_left();
		n1[i].Load_follow_right();

		n2[i].Load_alive_left();
		n2[i].Load_alive_right();
		n2[i].Load_dead_left();
		n2[i].Load_dead_right();
		n2[i].Load_follow_left();
		n2[i].Load_follow_right();

		n3[i].Load_alive_left();
		n3[i].Load_alive_right();
		n3[i].Load_dead_left();
		n3[i].Load_dead_right();
		n3[i].Load_follow_left();
		n3[i].Load_follow_right();
	}
	SetupMan(1, true);
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
	GetCursorPos(&p);
	HWND hwnd = FindWindowA(NULL, "Game");
	ScreenToClient(hwnd, &p);
	
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

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	/* //can't update hp
	while (hp_board.hp >= 10) {
		hp_board.hp -= 5;
	}*/
	GetCursorPos(&p);
	HWND hwnd = FindWindowA(NULL, "Game");
	ScreenToClient(hwnd, &p);
	if (map.GetLeft() >= -2094 && map.GetLeft() <= 0) {
		MainGirlMove();
	}
	else {
		if (up_down == 0) {
			if (map.GetLeft() >= -50 && p.x < main_girl[2].GetLeft()) {
				maingirl = 5;	//左邊
				main_girl[0].SetFrameIndexOfBitmap(0);
				main_girl[0].SetTopLeft(450, 250);
				main_girl[2].SetTopLeft(450, 250); //不設定的話，上下樓會造成短暫瞬間移動
				up.SetTopLeft(75, 170);
				down.SetTopLeft(90, 380);
			}
			else if (map.GetLeft() <= -2044 && p.x > main_girl[2].GetLeft()) {
				maingirl = 6;	//右邊
				main_girl[0].SetFrameIndexOfBitmap(1);
				main_girl[0].SetTopLeft(250, 250);
				main_girl[2].SetTopLeft(250, 250);
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
				if (main_girl[2].GetLeft() < 530) {
					main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, 250);
				}
				else {
					main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, main_girl[2].GetTop() - 5);
				}
				if (second_floor_arrive == false) {
					SetupMan(2, false);
				}
			}
			else if (maingirl == 3 && up_down == 1 && floor == 1) {
				if (main_girl[2].GetLeft() > 250) {
					main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, 250);
				}
				else {
					main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, main_girl[2].GetTop() - 5);
				}
				if (second_floor_arrive == false) {
					SetupMan(2, true);
				}
			}
			else if (maingirl == 1 && floor == 4) {
				main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 3, 250);
			}
			else if (maingirl == 3 && floor == 4) {
				main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 3, 250);
			}
			else if (maingirl == 1 && up_down == 1) {
				if (main_girl[2].GetLeft() < 380) {
					main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, 250);
				}
				else {
					main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, main_girl[2].GetTop() - 5);
				}
				if (second_floor_arrive == false) {
					if (floor == 2) {
						SetupMan(3, false);
					}
					else {
						SetupMan(4, false);
					}
				}
			}
			else if (maingirl == 1 && up_down == 2) {
				if (main_girl[2].GetLeft() < 600) {
					main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, 250);
				}
				else {
					main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, main_girl[2].GetTop() + 5);
				}
			}
			else if (maingirl == 3 && up_down == 1) {
				if (main_girl[2].GetLeft() > 330) {
					main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, 250);
				}
				else {
					main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, main_girl[2].GetTop() - 5);
				}
				if (floor == 2) {
					SetupMan(3, true);
				}
				else {
					SetupMan(4, true);
				}
			}
			else if (maingirl == 3 && up_down == 2) {
				if (main_girl[2].GetLeft() > 120) {
					main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, 250);
				}
				else {
					main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, main_girl[2].GetTop() + 5);
				}
			}
			main_girl[1].SetTopLeft(main_girl[2].GetLeft(), main_girl[2].GetTop());
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
					main_girl[2].SetTopLeft(400, 250);
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
					main_girl[2].SetTopLeft(300, 250);
				}
				up_down = 0;
				time = 0;
			}
		}
	}
}

void CGameStateRun::OnShow() {
	map.ShowBitmap();

	score_board.ShowBitmap();

	hp_board.ShowBitmap();

	clock_board.ShowBitmap();

	hp_board.show_hp();

	n1[floor * 2 - 2].ShowMan(500, 800, map.GetLeft(), maingirl);
	n2[floor * 2 - 2].ShowMan(750, 1150, map.GetLeft(), maingirl);
	n3[floor * 2 - 2].ShowMan(1350, 1650, map.GetLeft(), maingirl);
	n1[floor * 2 - 1].ShowMan(1150, 1300, map.GetLeft(), maingirl);
	n2[floor * 2 - 1].ShowMan(1700, 1900, map.GetLeft(), maingirl);
	n3[floor * 2 - 1].ShowMan(1950, 2200, map.GetLeft(), maingirl);

	if (maingirl == 1) {
		main_girl[2].ShowBitmap();
	}
	else if (maingirl == 2) {
		main_girl[4].ShowBitmap();
	}
	else if (maingirl == 3) {
		main_girl[1].ShowBitmap();
	}
	else if (maingirl == 4) {
		main_girl[3].ShowBitmap();
	}
	else if (maingirl == 5) {
		main_girl[0].ShowBitmap();
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
		main_girl[0].ShowBitmap();
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