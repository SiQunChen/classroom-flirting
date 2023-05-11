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
void CGameStateRun::SetupMan(int floor, bool left) {
	if (left == true) {
		if (floor == 2) {
			s1.ManState[0].SetTopLeft(1650, 150);
			s1.ManState[1].SetTopLeft(1650, 150);
		}
		else if (floor == 3) {
			s2.ManState[0].SetTopLeft(1650, 150);
			s2.ManState[1].SetTopLeft(1650, 150);
		}
		else if (floor == 4) {
			s3.ManState[0].SetTopLeft(1650, 150);
			s3.ManState[1].SetTopLeft(1650, 150);
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
	else if (p.x > s1.ManState[0].GetLeft() && p.x < s1.ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && s1.dead == false) {
		maingirl_state = 6;
		maingirl_stop_front = false;
		crosshair_on.SetTopLeft(s1.ManState[0].GetLeft() + 5, 150);
	}
	else if (p.x > s2.ManState[0].GetLeft() && p.x < s2.ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && s2.dead == false) {
		maingirl_state = 6;
		maingirl_stop_front = false;
		crosshair_on.SetTopLeft(s2.ManState[0].GetLeft() + 5, 150);
	}
	else if (p.x > s3.ManState[0].GetLeft() && p.x < s3.ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && s3.dead == false) {
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
		if (second_floor_arrive == false) {
			SetupMan(2, false);
		}
	}
	else if (maingirl_state == 3 && up_down == 1 && floor == 1) {
		if (main_girl[2].GetLeft() > 270) {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, 300);
		}
		else {
			main_girl[2].SetTopLeft(main_girl[2].GetLeft() - 5, main_girl[2].GetTop() - 5);
		}
		if (second_floor_arrive == false) {
			SetupMan(2, true);
		}
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
		if (second_floor_arrive == false) {
			if (floor == 2) {
				SetupMan(3, false);
			}
			else {
				SetupMan(4, false);
			}
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
			SetupMan(3, true);
		}
		else {
			SetupMan(4, true);
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
			maingirl_state = 6;
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
	score_sys.load_ui_score_num();

	hp_board.LoadBitmapByString({
		"./RES/UI/heart/heartPointBoard.bmp"});
	hp_board.SetTopLeft(0, 0);
	hp_sys.load_ui_hp_num();
	
	clock_board.LoadBitmapByString({
		"./RES/UI/clock/clock.bmp",
		"./RES/UI/clock/clock_background.bmp"});
	clock_board.SetTopLeft(350, 0);

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
		n1[i].Load_alive_left();
		n1[i].Load_alive_right();
		n1[i].Load_dead_left();
		n1[i].Load_dead_right();
		n1[i].Load_follow_left();
		n1[i].Load_follow_right();
		n1[i].Load_attack();

		n2[i].Load_alive_left();
		n2[i].Load_alive_right();
		n2[i].Load_dead_left();
		n2[i].Load_dead_right();
		n2[i].Load_follow_left();
		n2[i].Load_follow_right();
		n2[i].Load_attack();

		n3[i].Load_alive_left();
		n3[i].Load_alive_right();
		n3[i].Load_dead_left();
		n3[i].Load_dead_right();
		n3[i].Load_follow_left();
		n3[i].Load_follow_right();
		n3[i].Load_attack();
	}

	s1.Load_alive_left();
	s1.Load_alive_right();
	s1.Load_dead_left();
	s1.Load_dead_right();
	s1.Load_follow_left();
	s1.Load_follow_right();
	s1.Load_attack();

	s2.Load_alive_left();
	s2.Load_alive_right();
	s2.Load_dead_left();
	s2.Load_dead_right();
	s2.Load_follow_left();
	s2.Load_follow_right();
	s2.Load_attack();

	s3.Load_alive_left();
	s3.Load_alive_right();
	s3.Load_dead_left();
	s3.Load_dead_right();
	s3.Load_follow_left();
	s3.Load_follow_right();
	s3.Load_attack();
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
	if (maingirl_state == 6) {
		if (p.x > n1[floor * 2 - 2].ManState[0].GetLeft() && p.x < n1[floor * 2 - 2].ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && n1[floor * 2 - 2].dead == false) {
			man_stop = 1;
		}
		else if (p.x > n1[floor * 2 - 1].ManState[0].GetLeft() && p.x < n1[floor * 2 - 1].ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && n1[floor * 2 - 1].dead == false) {
			man_stop = 2;
		}
		else if (p.x > n3[floor * 2 - 1].ManState[0].GetLeft() && p.x < n3[floor * 2 - 1].ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && n3[floor * 2 - 1].dead == false) {
			man_stop = 3;
		}
		else if (p.x > s1.ManState[0].GetLeft() && p.x < s1.ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && s1.dead == false) {
			man_stop = 4;
		}
		else if (p.x > s2.ManState[0].GetLeft() && p.x < s2.ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && s2.dead == false) {
			man_stop = 5;
		}
		else if (p.x > s3.ManState[0].GetLeft() && p.x < s3.ManState[0].GetLeft() + 65 && p.y > 150 && p.y < 230 && s3.dead == false) {
			man_stop = 6;
		}
		else if (p.x > n2[floor * 2 - 2].ManState[0].GetLeft() && p.x < n2[floor * 2 - 2].ManState[0].GetLeft() + 65 && p.y > 350 && p.y < 430 && n2[floor * 2 - 2].dead == false) {
			man_stop = 7;
		}
		else if (p.x > n3[floor * 2 - 2].ManState[0].GetLeft() && p.x < n3[floor * 2 - 2].ManState[0].GetLeft() + 65 && p.y > 350 && p.y < 430 && n3[floor * 2 - 2].dead == false) {
			man_stop = 8;
		}
		else if (p.x > n2[floor * 2 - 1].ManState[0].GetLeft() && p.x < n2[floor * 2 - 1].ManState[0].GetLeft() + 65 && p.y > 350 && p.y < 430 && n2[floor * 2 - 1].dead == false) {
			man_stop = 9;
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
	if (maingirl_state == 6) {
		man_stop = 0;
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

//在地圖範圍內的話，女主做移動，否則就上下樓。
void CGameStateRun::OnMove()							// 移動遊戲元素{
{

	if (!(bool_moving_up_and_down_state)) {
		if(HDYLM.flirting_earn_score(man_stop!=0)) {
			score_sys.score += 1;
			hp_sys.hp -= 1;
		}
	}
	
	
	if (hp_sys.hp < -100) {
		GotoGameState(GAME_STATE_OVER);
	}
	
	GetCursorPos(&p);
	HWND hwnd = FindWindowA(NULL, "Game");
	ScreenToClient(hwnd, &p);
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

void CGameStateRun::OnShow() {
	map.ShowBitmap();
	
	clock_board.ShowBitmap();

	hp_board.ShowBitmap();
	hp_sys.show_hp();

	score_board.ShowBitmap();
	score_sys.show_score();
	
	if (man_stop != 1) {
		n1[floor * 2 - 2].ShowMan(500, 800, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	else {
		n1[floor * 2 - 2].ShowMan(500, 800, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	if (man_stop != 2) {
		n1[floor * 2 - 1].ShowMan(1150, 1300, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	else {
		n1[floor * 2 - 1].ShowMan(500, 800, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	if (man_stop != 3) {
		n3[floor * 2 - 1].ShowMan(1950, 2200, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	else {
		n3[floor * 2 - 1].ShowMan(500, 800, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	if (man_stop != 4 && floor == 2) {
		s1.ShowMan(1600, 1700, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	else if(floor == 2) {
		s1.ShowMan(500, 800, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	if (man_stop != 5 && floor == 3) {
		s2.ShowMan(1600, 1700, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	else if (floor == 3) {
		s2.ShowMan(500, 800, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	if (man_stop != 6 && floor == 4) {
		s3.ShowMan(1600, 1700, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	else if (floor == 4) {
		s3.ShowMan(500, 800, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left);
	}

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
	//圖層問題，故把這三個人和準心show在maingirl_state下面
	if (man_stop != 7) {
		n2[floor * 2 - 2].ShowMan(750, 1150, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	else {
		n2[floor * 2 - 2].ShowMan(750, 1150, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	if (man_stop != 8) {
		n3[floor * 2 - 2].ShowMan(1350, 1650, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	else {
		n3[floor * 2 - 2].ShowMan(750, 1150, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	if (man_stop != 9) {
		n2[floor * 2 - 1].ShowMan(1700, 1900, map.GetLeft(), maingirl_state, false, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	else {
		n2[floor * 2 - 1].ShowMan(750, 1150, map.GetLeft(), maingirl_state, true, main_girl[2].GetLeft(), maingirl_stop_left);
	}
	if (maingirl_state == 6 && man_stop == 0) {
		crosshair_on.ShowBitmap();
	}
}