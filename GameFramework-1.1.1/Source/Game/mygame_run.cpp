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

//設定男生初始的位置，因為上樓有分左右邊，所以要先判斷從哪邊上樓再進行設定
void CGameStateRun::Setup(int floor, bool left) {
	maingirl_start_on_left = left;
	if (left == true) {
		if (floor == 2) {
			s1.ManState[0].SetTopLeft(1650, 150);
			s1.ManState[1].SetTopLeft(1650, 150);
		}
		else if (floor == 3) {
			s2.ManState[0].SetTopLeft(1650, 150);
			s2.ManState[1].SetTopLeft(1650, 150);
			n1_girl[0].walk_left.SetTopLeft(850, 200);
			n1_girl[0].walk_right.SetTopLeft(850, 200);
			n2_girl[0].walk_left.SetTopLeft(1450, 200);
			n2_girl[0].walk_right.SetTopLeft(1450, 200);
			n1_girl[1].walk_left.SetTopLeft(1550, 300);
			n1_girl[1].walk_right.SetTopLeft(1550, 300);
			n2_girl[1].walk_left.SetTopLeft(1750, 120);
			n2_girl[1].walk_right.SetTopLeft(1750, 120);
		}
		else if (floor == 4) {
			s3.ManState[0].SetTopLeft(1650, 150);
			s3.ManState[1].SetTopLeft(1650, 150);
			n1_girl[2].walk_left.SetTopLeft(850, 200);
			n1_girl[2].walk_right.SetTopLeft(850, 200);
			n2_girl[2].walk_left.SetTopLeft(1450, 200);
			n2_girl[2].walk_right.SetTopLeft(1450, 200);
			n1_girl[3].walk_left.SetTopLeft(1550, 300);
			n1_girl[3].walk_right.SetTopLeft(1550, 300);
			n2_girl[3].walk_left.SetTopLeft(1750, 120);
			n2_girl[3].walk_right.SetTopLeft(1750, 120);
			n1_girl[4].walk_left.SetTopLeft(1000, 300);
			n1_girl[4].walk_right.SetTopLeft(1000, 300);
			n2_girl[4].walk_left.SetTopLeft(1000, 300);
			n2_girl[4].walk_right.SetTopLeft(1000, 300);
			Sgirl.walk_left.SetTopLeft(1600, 200);
			Sgirl.walk_right.SetTopLeft(1600, 200);
		}
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
		if (floor == 2) {
			s1.ManState[0].SetTopLeft(-444, 150);
			s1.ManState[1].SetTopLeft(-444, 150);
		}
		else if (floor == 3) {
			s2.ManState[0].SetTopLeft(-444, 150);
			s2.ManState[1].SetTopLeft(-444, 150);
		}
		else if (floor == 4) {
			s3.ManState[0].SetTopLeft(-444, 150);
			s3.ManState[1].SetTopLeft(-444, 150);
		}
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

//如果滑鼠游標在男生身上，女主會停住，被指到的男生會出現準心，1~9則分別代表9位男生(6位普、3位帥)。
//當滑鼠游標不在男生身上，則會根據游標離女主的距離進行走或跑的動作。
void CGameStateRun::MainGirlMove() {
	if (p.x > n1[floor * 2 - 2].ManState[0].GetLeft() && p.x < n1[floor * 2 - 2].ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && n1[floor * 2 - 2].dead == false) {
		maingirl_state = 6;
		maingirl_stop_front = false;
		crosshair_on.SetTopLeft(n1[floor * 2 - 2].ManState[0].GetLeft() + 5, 150);
	}
	else if (p.x > n1[floor * 2 - 1].ManState[0].GetLeft() && p.x < n1[floor * 2 - 1].ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && n1[floor * 2 - 1].dead == false) {
		maingirl_state = 6;
		maingirl_stop_front = false;
		crosshair_on.SetTopLeft(n1[floor * 2 - 1].ManState[0].GetLeft() + 5, 150);
	}
	else if (p.x > n3[floor * 2 - 1].ManState[0].GetLeft() && p.x < n3[floor * 2 - 1].ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && n3[floor * 2 - 1].dead == false) {
		maingirl_state = 6;
		maingirl_stop_front = false;
		crosshair_on.SetTopLeft(n3[floor * 2 - 1].ManState[0].GetLeft() + 5, 150);
	}
	else if (p.x > s1.ManState[0].GetLeft() && p.x < s1.ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && s1.dead == false && floor == 2) {
		maingirl_state = 6;
		maingirl_stop_front = false;
		crosshair_on.SetTopLeft(s1.ManState[0].GetLeft() + 5, 150);
	}
	else if (p.x > s2.ManState[0].GetLeft() && p.x < s2.ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && s2.dead == false && floor == 3) {
		maingirl_state = 6;
		maingirl_stop_front = false;
		crosshair_on.SetTopLeft(s2.ManState[0].GetLeft() + 5, 150);
	}
	else if (p.x > s3.ManState[0].GetLeft() && p.x < s3.ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && s3.dead == false && floor == 4) {
		maingirl_state = 6;
		maingirl_stop_front = false;
		crosshair_on.SetTopLeft(s3.ManState[0].GetLeft() + 5, 150);
	}
	else if (p.x > n2[floor * 2 - 2].ManState[0].GetLeft() && p.x < n2[floor * 2 - 2].ManState[0].GetLeft() + 65 && p.y > 350 && p.y < 430 && n2[floor * 2 - 2].dead == false) {
		maingirl_state = 6;
		maingirl_stop_front = true;
		crosshair_on.SetTopLeft(n2[floor * 2 - 2].ManState[0].GetLeft() + 5, 350);
	}
	else if (p.x > n3[floor * 2 - 2].ManState[0].GetLeft() && p.x < n3[floor * 2 - 2].ManState[0].GetLeft() + 65 && p.y > 350 && p.y < 430 && n3[floor * 2 - 2].dead == false) {
		maingirl_state = 6;
		maingirl_stop_front = true;
		crosshair_on.SetTopLeft(n3[floor * 2 - 2].ManState[0].GetLeft() + 5, 350);
	}
	else if (p.x > n2[floor * 2 - 1].ManState[0].GetLeft() && p.x < n2[floor * 2 - 1].ManState[0].GetLeft() + 65 && p.y > 350 && p.y < 430 && n2[floor * 2 - 1].dead == false) {
		maingirl_state = 6;
		maingirl_stop_front = true;
		crosshair_on.SetTopLeft(n2[floor * 2 - 1].ManState[0].GetLeft() + 5, 350);
	}
	else if (p.x - main_girl[2].GetLeft() > 0 && p.x - main_girl[2].GetLeft() < 200) {
		maingirl_state = 1;
		if (main_girl[2].GetLeft() > 250) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 2, 250);
		}
		map.SetTopLeft(map.GetLeft() - 2, 0);
	}
	else if (p.x - main_girl[2].GetLeft() >= 200) {
		maingirl_state = 2;
		if (main_girl[2].GetLeft() > 250) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, 250);
		}
		main_girl[4].SetTopLeft(main_girl[2].GetLeft(), 250);
		map.SetTopLeft(map.GetLeft() - 5, 0);
	}
	else if (p.x - main_girl[2].GetLeft() > -200 && p.x - main_girl[2].GetLeft() <= 0) {
		maingirl_state = 3;
		if (main_girl[2].GetLeft() < 450) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 2, 250);
		}
		main_girl[1].SetTopLeft(main_girl[2].GetLeft(), 250);
		map.SetTopLeft(map.GetLeft() + 2, 0);
	}
	else {
		maingirl_state = 4;
		if (main_girl[2].GetLeft() < 450) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, 250);
		}
		main_girl[3].SetTopLeft(main_girl[2].GetLeft(), 250);
		map.SetTopLeft(map.GetLeft() + 5, 0);
	}
}

void CGameStateRun::MainGirlMoveUpAndDown() {
	bool_moving_up_and_down_state = true;
	time++;
	if (maingirl_state == 1 && up_down == 1 && floor == 1) {
		if (main_girl[2].GetLeft() < 500) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, 300);
		}
		else {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, main_girl[2].GetTop() - 5);
		}
		Setup(2, false);
	}
	else if (maingirl_state == 3 && up_down == 1 && floor == 1) {
		if (main_girl[2].GetLeft() > 270) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, 300);
		}
		else {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, main_girl[2].GetTop() - 5);
		}
		Setup(2, true);
	}
	else if (maingirl_state == 1 && floor == 4) {
		main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 3, 300);
	}
	else if (maingirl_state == 3 && floor == 4) {
		main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 3, 300);
	}
	else if (maingirl_state == 1 && up_down == 1) {
		if (main_girl[2].GetLeft() < 380) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, 300);
		}
		else {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, main_girl[2].GetTop() - 5);
		}
		if (floor == 2) {
			Setup(3, false);
		}
		else {
			Setup(4, false);
		}
	}
	else if (maingirl_state == 1 && up_down == 2) {
		if (main_girl[2].GetLeft() < 650) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, 300);
		}
		else {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() + 5, main_girl[2].GetTop() + 5);
		}
	}
	else if (maingirl_state == 3 && up_down == 1) {
		if (main_girl[2].GetLeft() > 330) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, 300);
		}
		else {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, main_girl[2].GetTop() - 5);
		}
		if (floor == 2) {
			Setup(3, true);
		}
		else {
			Setup(4, true);
		}
	}
	else if (maingirl_state == 3 && up_down == 2) {
		if (main_girl[2].GetLeft() > 70) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, 300);
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
			maingirl_state = 5;
			main_girl[2].SetTopLeft(400, 300);
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
			maingirl_state = 5;
			main_girl[2].SetTopLeft(300, 300);
		}
		up_down = 0;
		time = 0;
		bool_moving_up_and_down_state = false;
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
		"./RES/map4.bmp", });
	map.SetTopLeft(0, 0);

	main_girl[0].Load_main();
	main_girl[1].Load_walk_left();
	main_girl[2].Load_walk_right();
	main_girl[3].Load_run_left();
	main_girl[4].Load_run_right();
	main_girl[5].Load_beauty_time_left();
	main_girl[6].Load_beauty_time_right();
	main_girl[7].Load_bump_left();
	main_girl[8].Load_bump_right();

	up.LoadBitmapByString({
		"./RES/UI/elevator/up.bmp",
		"./RES/UI/elevator/up_hover.bmp", },
		RGB(255, 255, 255));
	down.LoadBitmapByString({
		"./RES/UI/elevator/down.bmp",
		"./RES/UI/elevator/down_hover.bmp", },
		RGB(255, 255, 255));

	score_board.LoadBitmapByString({
		"./RES/UI/number/scoreBoard.bmp" });
	score_board.SetTopLeft(430, -1);
	score_sys.load_ui_score_num();

	hp_board.LoadBitmapByString({
		"./RES/UI/heart/heartPointBoard.bmp" });
	hp_board.SetTopLeft(0, 0);
	hp_sys.load_ui_hp_num();

	// clock_sys.LoadBitmapByString({
	// 	"./RES/UI/clock/clock.bmp",
	// 	"./RES/UI/clock/clock_background.bmp" });
	clock_sys.load_ui_clock_pointer();
	clock_sys.load_ui_clock_board();

	crosshair_on.LoadBitmapByString({
		"./RES/maingirl/focus_point_on (3).bmp", },
		RGB(230, 230, 196));

	focusing_behind.LoadBitmapByString({
		"./RES/maingirl/left/focusing_behind.bmp",
		"./RES/maingirl/right/focusing_behind.bmp", },
		RGB(230, 230, 196));

	focusing_front.LoadBitmapByString({
		"./RES/maingirl/left/focusing_front.bmp",
		"./RES/maingirl/right/focusing_front.bmp", },
		RGB(0, 0, 0));

	for (int i = 0; i < 8; i++) {
		n1[i].Load_state();
		n1[i].Load();

		n2[i].Load_state();
		n2[i].Load();

		n3[i].Load_state();
		n3[i].Load();

		if (i < 5) {
			n1_girl[i].Load();
			n2_girl[i].Load();
		}
	}
	Sgirl.Load();

	s1.Load_state();
	s1.Load();

	s2.Load_state();
	s2.Load();

	s3.Load_state();
	s3.Load();
	Setup(1, true);

	teacher.Load();
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
}


void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	if (maingirl_state == 6) {
		if (p.x > n1[floor * 2 - 2].ManState[0].GetLeft() && p.x < n1[floor * 2 - 2].ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && n1[floor * 2 - 2].dead == false) {
			Man::man_stop = 1;
			stop_man_left = n1[floor * 2 - 2].ManState[0].GetLeft();
		}
		else if (p.x > n1[floor * 2 - 1].ManState[0].GetLeft() && p.x < n1[floor * 2 - 1].ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && n1[floor * 2 - 1].dead == false) {
			Man::man_stop = 2;
			stop_man_left = n1[floor * 2 - 1].ManState[0].GetLeft();
		}
		else if (p.x > n3[floor * 2 - 1].ManState[0].GetLeft() && p.x < n3[floor * 2 - 1].ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && n3[floor * 2 - 1].dead == false) {
			Man::man_stop = 3;
			stop_man_left = n3[floor * 2 - 1].ManState[0].GetLeft();
		}
		else if (p.x > s1.ManState[0].GetLeft() && p.x < s1.ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && s1.dead == false) {
			Man::man_stop = 4;
			stop_man_left = s1.ManState[0].GetLeft();
		}
		else if (p.x > s2.ManState[0].GetLeft() && p.x < s2.ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && s2.dead == false) {
			Man::man_stop = 5;
			stop_man_left = s2.ManState[0].GetLeft();
		}
		else if (p.x > s3.ManState[0].GetLeft() && p.x < s3.ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && s3.dead == false) {
			Man::man_stop = 6;
			stop_man_left = s3.ManState[0].GetLeft();
		}
		else if (p.x > n2[floor * 2 - 2].ManState[0].GetLeft() && p.x < n2[floor * 2 - 2].ManState[0].GetLeft() + 65 && p.y > 350 && p.y < 430 && n2[floor * 2 - 2].dead == false) {
			Man::man_stop = 7;
			stop_man_left = n2[floor * 2 - 2].ManState[0].GetLeft();
		}
		else if (p.x > n3[floor * 2 - 2].ManState[0].GetLeft() && p.x < n3[floor * 2 - 2].ManState[0].GetLeft() + 65 && p.y > 350 && p.y < 430 && n3[floor * 2 - 2].dead == false) {
			Man::man_stop = 8;
			stop_man_left = n3[floor * 2 - 2].ManState[0].GetLeft();
		}
		else if (p.x > n2[floor * 2 - 1].ManState[0].GetLeft() && p.x < n2[floor * 2 - 1].ManState[0].GetLeft() + 65 && p.y > 350 && p.y < 430 && n2[floor * 2 - 1].dead == false) {
			Man::man_stop = 9;
			stop_man_left = n2[floor * 2 - 1].ManState[0].GetLeft();
		}
	}
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	GetCursorPos(&p);
	HWND hwnd = FindWindowA(NULL, "Game");
	ScreenToClient(hwnd, &p);

	if (maingirl_state == 5) {
		if ((p.x >= 100 && p.x <= 215) && (p.y >= 230 && p.y <= 340)) { //左邊上樓
			maingirl_state = 3;
			up_down = 1;
		}
		else if ((p.x >= 560 && p.x <= 675) && (p.y >= 230 && p.y <= 340)) { //右邊上樓
			maingirl_state = 1;
			up_down = 1;
		}
		else if ((p.x >= 95 && p.x <= 215) && (p.y >= 385 && p.y <= 505)) { //左邊下樓
			maingirl_state = 3;
			up_down = 2;
		}
		else if ((p.x >= 555 && p.x <= 675) && (p.y >= 385 && p.y <= 505)) { //右邊下樓
			maingirl_state = 1;
			up_down = 2;
		}
	}
	Man::man_stop = 0;
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

//在地圖範圍內的話，女主做移動，否則就上下樓。
void CGameStateRun::OnMove()							// 移動遊戲元素{
{
	if (!(bool_moving_up_and_down_state)) {
		clock_sys.time_sys();
		if (HDYLM.flirting_earn_score(Man::man_stop != 0)) {
			score_sys.score += 1;
			hp_sys.hp -= 1;
		}
	}

	if (hp_sys.hp < 0) {
		GotoGameState(GAME_STATE_OVER);
	}

	GetCursorPos(&p);
	HWND hwnd = FindWindowA(NULL, "Game");
	ScreenToClient(hwnd, &p);
	if (evolution == false && Teacher::bump == false) {
		if (map.GetLeft() >= -2094 && map.GetLeft() <= 0) {
			MainGirlMove();
		}
		else {
			if (up_down == 0) {
				maingirl_state = 5;
				if (map.GetLeft() >= -50 && p.x < main_girl[2].GetLeft()) {
					maingirl_stop_left = true;
					main_girl[0].SetFrameIndexOfBitmap(0);
					main_girl[0].SetTopLeft(450, 250);
					main_girl[2].SetTopLeft(450, 250); //不設定的話，上下樓會造成短暫瞬間移動
					up.SetTopLeft(75, 170);
					down.SetTopLeft(90, 380);
				}
				else if (map.GetLeft() <= -2044 && p.x > main_girl[2].GetLeft()) {
					maingirl_stop_left = false;
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
			else {
				MainGirlMoveUpAndDown();
			}
		}
	}
}

void CGameStateRun::OnShow() {
	map.ShowBitmap();

	clock_sys.show_clock_sys();

	hp_board.ShowBitmap();

	if ((hp_sys.hp >= 900 && !bool_moving_up_and_down_state) || beauty_time == true) {
		hp_sys.hp = 900;
		evolution = true;
		beauty_time = true;
		if (maingirl_state == 1 || maingirl_state == 2 || (maingirl_stop_left == false && (maingirl_state == 6 || maingirl_state == 5))) {
			evo_left = false;
			main_girl[6].SetTopLeft(main_girl[2].GetLeft() - 150, main_girl[2].GetTop() - 300);
		}
		else{
			evo_left = true;
			main_girl[5].SetTopLeft(main_girl[2].GetLeft() - 150, main_girl[2].GetTop() - 300);
		}
		hp_sys.bool_invincible_state = true;
		if (hp_sys.show_invincible() == 1) {
			beauty_time = false;
		}
	}
	else if (hp_sys.hp > 300) {
		hp_sys.show_hp();
	}
	else if (hp_sys.hp > 0) {
		hp_sys.shine_hp();
	}
	else {
		GotoGameState(GAME_STATE_OVER);
	}

	if (evolution == true) {
		if (main_girl[5].GetFrameIndexOfBitmap() == 31 || main_girl[6].GetFrameIndexOfBitmap() == 31) {
			evolution = false;
		}
	}

	if (floor == 3) {
		n2_girl[1].ShowGirl(1550, 1950, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), beauty_time, evolution, stop_man_left);
	}

	score_board.ShowBitmap();
	score_sys.show_score();

	if (Man::man_stop != 1) {
		n1[floor * 2 - 2].ShowMan(500, 800, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	else {
		n1[floor * 2 - 2].ShowMan(500, 800, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	if (Man::man_stop != 2) {
		n1[floor * 2 - 1].ShowMan(1150, 1300, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	else {
		n1[floor * 2 - 1].ShowMan(500, 800, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	if (Man::man_stop != 3) {
		n3[floor * 2 - 1].ShowMan(1950, 2200, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	else {
		n3[floor * 2 - 1].ShowMan(500, 800, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	if (Man::man_stop != 4 && floor == 2) {
		s1.ShowMan(1600, 1700, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	else if (floor == 2) {
		s1.ShowMan(500, 800, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	if (Man::man_stop != 5 && floor == 3) {
		s2.ShowMan(1600, 1700, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	else if (floor == 3) {
		s2.ShowMan(500, 800, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	if (Man::man_stop != 6 && floor == 4) {
		s3.ShowMan(1600, 1700, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	else if (floor == 4) {
		s3.ShowMan(500, 800, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	if (floor == 3) {
		n1_girl[0].ShowGirl(550, 750, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), beauty_time, evolution, stop_man_left);
		n2_girl[0].ShowGirl(1350, 1650, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), beauty_time, evolution, stop_man_left);
	}
	if (evolution == false && Teacher::bump == false) {
		if (maingirl_state == 1) {
			main_girl[2].ShowBitmap(0.9);
		}
		else if (maingirl_state == 2) {
			main_girl[4].ShowBitmap(0.9);
		}
		else if (maingirl_state == 3) {
			main_girl[1].ShowBitmap(0.9);
		}
		else if (maingirl_state == 4) {
			main_girl[3].ShowBitmap(0.9);
		}
		else if (maingirl_state == 5) {
			main_girl[0].ShowBitmap(0.9);
			if (maingirl_stop_left == true) {
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
		else if (maingirl_state == 6) {
			if (p.x > main_girl[2].GetLeft()) {
				maingirl_stop_left = false;
			}
			else {
				maingirl_stop_left = true;
			}
			if (maingirl_stop_left == true && maingirl_stop_front == true) {
				focusing_front.SetFrameIndexOfBitmap(0);
				focusing_front.SetTopLeft(main_girl[2].GetLeft(), 250);
				focusing_front.ShowBitmap(0.9);
			}
			else if (maingirl_stop_left == true && maingirl_stop_front == false) {
				focusing_behind.SetFrameIndexOfBitmap(0);
				focusing_behind.SetTopLeft(main_girl[2].GetLeft(), 250);
				focusing_behind.ShowBitmap(0.9);
			}
			else if (maingirl_stop_left == false && maingirl_stop_front == true) {
				focusing_front.SetFrameIndexOfBitmap(1);
				focusing_front.SetTopLeft(main_girl[2].GetLeft(), 250);
				focusing_front.ShowBitmap(0.9);
			}
			else {
				focusing_behind.SetFrameIndexOfBitmap(1);
				focusing_behind.SetTopLeft(main_girl[2].GetLeft(), 250);
				focusing_behind.ShowBitmap(0.9);
			}
		}
	}
	else {
		if (evolution == true) {
			if (evo_left == true) {
				main_girl[5].ShowBitmap();
			}
			else {
				main_girl[6].ShowBitmap();
			}
		}
		else {
			if (bump_left == true) {
				main_girl[7].ShowBitmap();
			}
			else {
				main_girl[8].ShowBitmap();
			}
		}
	}

	for (auto &m : Man::dead_man) {
		m->follow(maingirl_state, main_girl[2].GetLeft(), main_girl[2].GetTop(), maingirl_stop_left);
	}

	if (floor == 2 || floor == 4) {
		teacher.ShowTeacher(maingirl_start_on_left, maingirl_state, main_girl[2].GetLeft(), evolution);
	}
	else if ((floor == 1 && up_down == 1) || (floor == 3 && up_down == 2)) {
		teacher.Setup(maingirl_start_on_left);
	}

	if (Teacher::bump == true && evolution == false) {
		if (main_girl[7].GetFrameIndexOfBitmap() == 18 || main_girl[8].GetFrameIndexOfBitmap() == 18) {
			Teacher::bump = false;
			main_girl[7].SetFrameIndexOfBitmap(0);
			main_girl[8].SetFrameIndexOfBitmap(0);
		}

		if (maingirl_state == 1 || maingirl_state == 2 || (maingirl_stop_left == false && (maingirl_state == 6 || maingirl_state == 5))) {
			bump_left = false;
			main_girl[8].SetTopLeft(main_girl[2].GetLeft(), 270);
		}
		else {
			bump_left = true;
			main_girl[7].SetTopLeft(main_girl[2].GetLeft(), 270);
		}
	}

	//圖層問題
	if (floor == 3) {
		n1_girl[1].ShowGirl(1350, 1550, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), beauty_time, evolution, stop_man_left);
	}
	if (Man::man_stop != 7) {
		n2[floor * 2 - 2].ShowMan(750, 1150, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	else {
		n2[floor * 2 - 2].ShowMan(750, 1150, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	if (Man::man_stop != 8) {
		n3[floor * 2 - 2].ShowMan(1350, 1650, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	else {
		n3[floor * 2 - 2].ShowMan(750, 1150, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	if (Man::man_stop != 9) {
		n2[floor * 2 - 1].ShowMan(1700, 1900, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	else {
		n2[floor * 2 - 1].ShowMan(750, 1150, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left, beauty_time, evolution);
	}
	if (maingirl_state == 6 && Man::man_stop == 0) {
		crosshair_on.ShowBitmap();
	}
}