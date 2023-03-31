#include "stdafx.h"
#include "mygame.h"

using namespace game_framework;
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0, "Start Initialize...");	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//
	//Sleep(200);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep

	load_background();
	load_tutorial();

	ShowInitProgress(66, "Initializing...");

	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
}

void CGameStateInit::OnBeginState()
{

}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (start_frame == 1) {
		if (tutorial_stage == 0) {
			if (nChar == VK_RIGHT) {
				tutorial_stage = 1;					// assign to ensure safety
			}
		}
		else if (tutorial_stage == 5) {
			if (nChar == VK_LEFT) {
				tutorial_stage = 4;					// assign to ensure safety
			}
		}
		else {
			if (nChar == VK_RIGHT) {
				tutorial_stage += 1;
			}
			else if (nChar == VK_LEFT) {
				tutorial_stage -= 1;
			}
		}
		if (nChar == VK_RETURN) {
			GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
		}
	}
	
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (start_frame == 1) {
		POINT p;
		GetCursorPos(&p);
		HWND hwnd = FindWindowA(NULL, "Game");
		ScreenToClient(hwnd, &p);
		if (p.x >= 300 && p.x <= 500 && p.y >= 520 && p.y <= 600) {
			GotoGameState(GAME_STATE_RUN);
		}
		else if (tutorial_stage == 0) {
			if (p.x >= 730 && p.x <= 760 && p.y >= 300 && p.y <= 450) {
				tutorial_stage = 1;					// assign to ensure safety
			}
		}
		else if (tutorial_stage == 5) {
			if (p.x >= 40 && p.x <= 70 && p.y >= 300 && p.y <= 450) {
				tutorial_stage = 4;					// assign to ensure safety
			}
		}
		else {
			if (p.x >= 730 && p.x <= 760 && p.y >= 300 && p.y <= 450) {
				tutorial_stage += 1;
			}
			else if (p.x >= 40 && p.x <= 70 && p.y >= 300 && p.y <= 450) {
				tutorial_stage -= 1;
			}
		}
	}
	start_frame = 1;
}

void CGameStateInit::OnShow()
{
	init_back.ShowBitmap();
	if (start_frame == 1) {
		if (tutorial_stage == 0) {
			tutorial[6].UnshowBitmap();
			tutorial[0].ShowBitmap();
			tutorial[6] = tutorial[0];
		}
		else if (tutorial_stage == 1) {
			tutorial[6].UnshowBitmap();
			tutorial[1].ShowBitmap();
			tutorial[6] = tutorial[1];
		}
		else if (tutorial_stage == 2) {
			tutorial[6].UnshowBitmap();
			tutorial[2].ShowBitmap();
			tutorial[6] = tutorial[2];
		}
		else if (tutorial_stage == 3) {
			tutorial[6].UnshowBitmap();
			tutorial[3].ShowBitmap();
			tutorial[6] = tutorial[3];
		}
		else if (tutorial_stage == 4) {
			tutorial[6].UnshowBitmap();
			tutorial[4].ShowBitmap();
			tutorial[6] = tutorial[4];
		}
		else if (tutorial_stage == 5) {
			tutorial[6].UnshowBitmap();
			tutorial[5].ShowBitmap();
			tutorial[6] = tutorial[5];
		}
	} 
}

void CGameStateInit::load_background() {
	init_back.LoadBitmapByString({ "./RES/initScreen2.bmp" });
	init_back.SetTopLeft(0, 0);
}

void CGameStateInit::load_tutorial()
{
	tutorial[0].LoadBitmapByString({							// load tutorial animation
		"./RES/init/intro/intro1/intro1 (1).bmp",
		"./RES/init/intro/intro1/intro1 (2).bmp",
		"./RES/init/intro/intro1/intro1 (3).bmp",
		"./RES/init/intro/intro1/intro1 (4).bmp",
		"./RES/init/intro/intro1/intro1 (5).bmp",
		"./RES/init/intro/intro1/intro1 (6).bmp",
		"./RES/init/intro/intro1/intro1 (7).bmp",
		"./RES/init/intro/intro1/intro1 (8).bmp",
		"./RES/init/intro/intro1/intro1 (9).bmp",
		"./RES/init/intro/intro1/intro1 (10).bmp",
		"./RES/init/intro/intro1/intro1 (11).bmp",
		"./RES/init/intro/intro1/intro1 (12).bmp",
		"./RES/init/intro/intro1/intro1 (13).bmp",
		"./RES/init/intro/intro1/intro1 (14).bmp",
		"./RES/init/intro/intro1/intro1 (15).bmp",
		"./RES/init/intro/intro1/intro1 (16).bmp",
		"./RES/init/intro/intro1/intro1 (17).bmp",
		"./RES/init/intro/intro1/intro1 (18).bmp",
		"./RES/init/intro/intro1/intro1 (19).bmp",
		"./RES/init/intro/intro1/intro1 (20).bmp",
		"./RES/init/intro/intro1/intro1 (21).bmp",
		"./RES/init/intro/intro1/intro1 (22).bmp",
		"./RES/init/intro/intro1/intro1 (23).bmp",
		"./RES/init/intro/intro1/intro1 (24).bmp",
		"./RES/init/intro/intro1/intro1 (25).bmp",
		"./RES/init/intro/intro1/intro1 (26).bmp",
		"./RES/init/intro/intro1/intro1 (27).bmp",
		"./RES/init/intro/intro1/intro1 (28).bmp"
		});

	tutorial[1].LoadBitmapByString({							// load tutorial animation
		"./RES/init/intro/intro2/intro2 (1).bmp",
		"./RES/init/intro/intro2/intro2 (2).bmp",
		"./RES/init/intro/intro2/intro2 (3).bmp",
		"./RES/init/intro/intro2/intro2 (4).bmp",
		"./RES/init/intro/intro2/intro2 (5).bmp",
		"./RES/init/intro/intro2/intro2 (6).bmp",
		"./RES/init/intro/intro2/intro2 (7).bmp",
		"./RES/init/intro/intro2/intro2 (8).bmp",
		"./RES/init/intro/intro2/intro2 (9).bmp",
		"./RES/init/intro/intro2/intro2 (10).bmp",
		"./RES/init/intro/intro2/intro2 (11).bmp",
		"./RES/init/intro/intro2/intro2 (12).bmp",
		"./RES/init/intro/intro2/intro2 (13).bmp",
		"./RES/init/intro/intro2/intro2 (14).bmp",
		"./RES/init/intro/intro2/intro2 (15).bmp",
		"./RES/init/intro/intro2/intro2 (16).bmp",
		"./RES/init/intro/intro2/intro2 (17).bmp",
		"./RES/init/intro/intro2/intro2 (18).bmp",
		"./RES/init/intro/intro2/intro2 (19).bmp",
		"./RES/init/intro/intro2/intro2 (20).bmp",
		"./RES/init/intro/intro2/intro2 (21).bmp",
		"./RES/init/intro/intro2/intro2 (22).bmp"
		});

	tutorial[2].LoadBitmapByString({							// load tutorial animation
		"./RES/init/intro/intro3/intro3 (1).bmp",
		"./RES/init/intro/intro3/intro3 (2).bmp",
		"./RES/init/intro/intro3/intro3 (3).bmp",
		"./RES/init/intro/intro3/intro3 (4).bmp",
		"./RES/init/intro/intro3/intro3 (5).bmp",
		"./RES/init/intro/intro3/intro3 (6).bmp",
		"./RES/init/intro/intro3/intro3 (7).bmp",
		"./RES/init/intro/intro3/intro3 (8).bmp",
		"./RES/init/intro/intro3/intro3 (9).bmp",
		"./RES/init/intro/intro3/intro3 (10).bmp",
		"./RES/init/intro/intro3/intro3 (11).bmp",
		"./RES/init/intro/intro3/intro3 (12).bmp",
		"./RES/init/intro/intro3/intro3 (13).bmp",
		"./RES/init/intro/intro3/intro3 (14).bmp"
		});

	tutorial[3].LoadBitmapByString({							// load tutorial animation
		"./RES/init/intro/intro4/intro4 (1).bmp",
		"./RES/init/intro/intro4/intro4 (2).bmp",
		"./RES/init/intro/intro4/intro4 (3).bmp",
		"./RES/init/intro/intro4/intro4 (4).bmp",
		"./RES/init/intro/intro4/intro4 (5).bmp"
		});

	tutorial[4].LoadBitmapByString({							// load tutorial animation
		"./RES/init/intro/intro5/intro5 (1).bmp",
		"./RES/init/intro/intro5/intro5 (2).bmp",
		"./RES/init/intro/intro5/intro5 (3).bmp",
		"./RES/init/intro/intro5/intro5 (4).bmp",
		"./RES/init/intro/intro5/intro5 (5).bmp",
		"./RES/init/intro/intro5/intro5 (6).bmp",
		"./RES/init/intro/intro5/intro5 (7).bmp",
		"./RES/init/intro/intro5/intro5 (8).bmp",
		"./RES/init/intro/intro5/intro5 (9).bmp",
		"./RES/init/intro/intro5/intro5 (10).bmp",
		"./RES/init/intro/intro5/intro5 (11).bmp",
		"./RES/init/intro/intro5/intro5 (12).bmp",
		"./RES/init/intro/intro5/intro5 (13).bmp",
		"./RES/init/intro/intro5/intro5 (14).bmp",
		"./RES/init/intro/intro5/intro5 (15).bmp"
		});

	tutorial[5].LoadBitmapByString({							// load tutorial animation
		"./RES/init/intro/intro6/intro6 (1).bmp",
		"./RES/init/intro/intro6/intro6 (2).bmp",
		"./RES/init/intro/intro6/intro6 (3).bmp",
		"./RES/init/intro/intro6/intro6 (4).bmp"
		});

	tutorial[6].LoadEmptyBitmap(800, 600);						// spared, in order to unshow picture

	for (int i = 0; i < 6; i++) {
		tutorial[i].SetTopLeft(0, 0);
		tutorial[i].SetAnimation(280, false);
	}
}
