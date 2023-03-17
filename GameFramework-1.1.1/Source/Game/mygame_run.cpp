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
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	LoadStuff();
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (tutorial_stage == 0) {
		if (nChar == VK_UP) {
			tutorial_stage += 1;
		}
	}
	else if (tutorial_stage == 5) {
		if (nChar == VK_DOWN) {
			tutorial_stage -= 1;
		}
	}
	else {
		if (nChar == VK_UP) {
			tutorial_stage += 1;
		}
		else if (nChar == VK_DOWN) {
			tutorial_stage -= 1;
		}
	}
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
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

void CGameStateRun::LoadStuff()
{
	game_back1.LoadBitmapByString({ "../../RES/map1.bmp" });// 1st floor
	game_back1.SetTopLeft(0, 0);

	game_back2.LoadBitmapByString({ "../../RES/map2.bmp" });// 2nd floor
	game_back2.SetTopLeft(0, 0);

	game_back3.LoadBitmapByString({ "../../RES/map2.bmp" });// 3rd floor
	game_back3.SetTopLeft(0, 0);

	game_back4.LoadBitmapByString({ "../../RES/map2.bmp" });// 4th floor
	game_back4.SetTopLeft(0, 0);

	tutorial[0].LoadBitmapByString({							// load tutorial animation
		"../../RES/init/intro/intro1/intro1 (1).bmp",
		"../../RES/init/intro/intro1/intro1 (2).bmp",
		"../../RES/init/intro/intro1/intro1 (3).bmp",
		"../../RES/init/intro/intro1/intro1 (4).bmp",
		"../../RES/init/intro/intro1/intro1 (5).bmp",
		"../../RES/init/intro/intro1/intro1 (6).bmp",
		"../../RES/init/intro/intro1/intro1 (7).bmp",
		"../../RES/init/intro/intro1/intro1 (8).bmp",
		"../../RES/init/intro/intro1/intro1 (9).bmp",
		"../../RES/init/intro/intro1/intro1 (10).bmp",
		"../../RES/init/intro/intro1/intro1 (11).bmp",
		"../../RES/init/intro/intro1/intro1 (12).bmp",
		"../../RES/init/intro/intro1/intro1 (13).bmp",
		"../../RES/init/intro/intro1/intro1 (14).bmp",
		"../../RES/init/intro/intro1/intro1 (15).bmp",
		"../../RES/init/intro/intro1/intro1 (16).bmp",
		"../../RES/init/intro/intro1/intro1 (17).bmp",
		"../../RES/init/intro/intro1/intro1 (18).bmp",
		"../../RES/init/intro/intro1/intro1 (19).bmp",
		"../../RES/init/intro/intro1/intro1 (20).bmp",
		"../../RES/init/intro/intro1/intro1 (21).bmp",
		"../../RES/init/intro/intro1/intro1 (22).bmp",
		"../../RES/init/intro/intro1/intro1 (23).bmp",
		"../../RES/init/intro/intro1/intro1 (24).bmp",
		"../../RES/init/intro/intro1/intro1 (25).bmp",
		"../../RES/init/intro/intro1/intro1 (26).bmp",
		"../../RES/init/intro/intro1/intro1 (27).bmp",
		"../../RES/init/intro/intro1/intro1 (28).bmp"
		});

	tutorial[1].LoadBitmapByString({							// load tutorial animation
		"../../RES/init/intro/intro2/intro2 (1).bmp",
		"../../RES/init/intro/intro2/intro2 (2).bmp",
		"../../RES/init/intro/intro2/intro2 (3).bmp",
		"../../RES/init/intro/intro2/intro2 (4).bmp",
		"../../RES/init/intro/intro2/intro2 (5).bmp",
		"../../RES/init/intro/intro2/intro2 (6).bmp",
		"../../RES/init/intro/intro2/intro2 (7).bmp",
		"../../RES/init/intro/intro2/intro2 (8).bmp",
		"../../RES/init/intro/intro2/intro2 (9).bmp",
		"../../RES/init/intro/intro2/intro2 (10).bmp",
		"../../RES/init/intro/intro2/intro2 (11).bmp",
		"../../RES/init/intro/intro2/intro2 (12).bmp",
		"../../RES/init/intro/intro2/intro2 (13).bmp",
		"../../RES/init/intro/intro2/intro2 (14).bmp",
		"../../RES/init/intro/intro2/intro2 (15).bmp",
		"../../RES/init/intro/intro2/intro2 (16).bmp",
		"../../RES/init/intro/intro2/intro2 (17).bmp",
		"../../RES/init/intro/intro2/intro2 (18).bmp",
		"../../RES/init/intro/intro2/intro2 (19).bmp",
		"../../RES/init/intro/intro2/intro2 (20).bmp",
		"../../RES/init/intro/intro2/intro2 (21).bmp",
		"../../RES/init/intro/intro2/intro2 (22).bmp"
		});

	tutorial[2].LoadBitmapByString({							// load tutorial animation
		"../../RES/init/intro/intro3/intro3 (1).bmp",
		"../../RES/init/intro/intro3/intro3 (2).bmp",
		"../../RES/init/intro/intro3/intro3 (3).bmp",
		"../../RES/init/intro/intro3/intro3 (4).bmp",
		"../../RES/init/intro/intro3/intro3 (5).bmp",
		"../../RES/init/intro/intro3/intro3 (6).bmp",
		"../../RES/init/intro/intro3/intro3 (7).bmp",
		"../../RES/init/intro/intro3/intro3 (8).bmp",
		"../../RES/init/intro/intro3/intro3 (9).bmp",
		"../../RES/init/intro/intro3/intro3 (10).bmp",
		"../../RES/init/intro/intro3/intro3 (11).bmp",
		"../../RES/init/intro/intro3/intro3 (12).bmp",
		"../../RES/init/intro/intro3/intro3 (13).bmp",
		"../../RES/init/intro/intro3/intro3 (14).bmp"
		});

	tutorial[3].LoadBitmapByString({							// load tutorial animation
		"../../RES/init/intro/intro4/intro4 (1).bmp",
		"../../RES/init/intro/intro4/intro4 (2).bmp",
		"../../RES/init/intro/intro4/intro4 (3).bmp",
		"../../RES/init/intro/intro4/intro4 (4).bmp",
		"../../RES/init/intro/intro4/intro4 (5).bmp"
		});

	tutorial[4].LoadBitmapByString({							// load tutorial animation
		"../../RES/init/intro/intro5/intro5 (1).bmp",
		"../../RES/init/intro/intro5/intro5 (2).bmp",
		"../../RES/init/intro/intro5/intro5 (3).bmp",
		"../../RES/init/intro/intro5/intro5 (4).bmp",
		"../../RES/init/intro/intro5/intro5 (5).bmp",
		"../../RES/init/intro/intro5/intro5 (6).bmp",
		"../../RES/init/intro/intro5/intro5 (7).bmp",
		"../../RES/init/intro/intro5/intro5 (8).bmp",
		"../../RES/init/intro/intro5/intro5 (9).bmp",
		"../../RES/init/intro/intro5/intro5 (10).bmp",
		"../../RES/init/intro/intro5/intro5 (11).bmp",
		"../../RES/init/intro/intro5/intro5 (12).bmp",
		"../../RES/init/intro/intro5/intro5 (13).bmp",
		"../../RES/init/intro/intro5/intro5 (14).bmp",
		"../../RES/init/intro/intro5/intro5 (15).bmp"
		});

	tutorial[5].LoadBitmapByString({							// load tutorial animation
		"../../RES/init/intro/intro6/intro6 (1).bmp",
		"../../RES/init/intro/intro6/intro6 (2).bmp",
		"../../RES/init/intro/intro6/intro6 (3).bmp",
		"../../RES/init/intro/intro6/intro6 (4).bmp"
		});

	tutorial[6].LoadEmptyBitmap(800, 600);						// spared, in order to unshow picture

	for (int i = 0; i < 6; i++) {
		tutorial[i].SetTopLeft(0, 0);
		tutorial[i].SetAnimation(280, false);
	}
}