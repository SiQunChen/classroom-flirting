#include "stdafx.h"
#include "mygame.h"

using namespace game_framework;

Score CGameStateRun::score_sys;

////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
////////////////////////////////////

CGameStateOver::CGameStateOver(CGame *g): CGameState(g)
{
}

void CGameStateOver::OnMove()
{
	// GotoGameState(GAME_STATE_INIT);
}

void CGameStateOver::OnBeginState()
{
}

void CGameStateOver::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(66, "Initialize...");	// 接個前一個狀態的進度，此處進度視為66%
	//
	// 開始載入資料
	//
	// Sleep(1000);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 最終進度為100%
	//
	end1_start.LoadBitmapByString({
		"./RES/end/end1/start (1).bmp" ,
		"./RES/end/end1/start (2).bmp" ,
		"./RES/end/end1/start (3).bmp" ,
		"./RES/end/end1/start (4).bmp" ,
		"./RES/end/end1/start (5).bmp" ,
		"./RES/end/end1/start (6).bmp" ,
		"./RES/end/end1/start (7).bmp" ,
		"./RES/end/end1/start (8).bmp" ,
		"./RES/end/end1/start (9).bmp" ,
		"./RES/end/end1/start (10).bmp" ,
		});
	end1_start.SetTopLeft(0, 0);
	end1_start.SetAnimation(200, true);
	end1_start.ToggleAnimation();

	end1_loop.LoadBitmapByString({
		"./RES/end/end1/loop (1).bmp" ,
		"./RES/end/end1/loop (2).bmp" ,
		"./RES/end/end1/loop (3).bmp" ,
		"./RES/end/end1/loop (4).bmp" ,
		"./RES/end/end1/loop (5).bmp" ,
		});
	end1_loop.SetTopLeft(0, 0);
	end1_loop.SetAnimation(200, false);

	end2_start.LoadBitmapByString({
		"./RES/end/end2/start (1).bmp" ,
		"./RES/end/end2/start (2).bmp" ,
		"./RES/end/end2/start (3).bmp" ,
		"./RES/end/end2/start (4).bmp" ,
		"./RES/end/end2/start (5).bmp" ,
		"./RES/end/end2/start (6).bmp" ,
		});
	end2_start.SetTopLeft(0, 0);
	end2_start.SetAnimation(200, true);
	end2_start.ToggleAnimation();

	end2_loop.LoadBitmapByString({
		"./RES/end/end2/loop (1).bmp" ,
		"./RES/end/end2/loop (2).bmp" ,
		"./RES/end/end2/loop (3).bmp" ,
		"./RES/end/end2/loop (4).bmp" ,
		"./RES/end/end2/loop (5).bmp" ,
		"./RES/end/end2/loop (6).bmp" ,
		"./RES/end/end2/loop (7).bmp" ,
		"./RES/end/end2/loop (8).bmp" ,
		});
	end2_loop.SetTopLeft(0, 0);
	end2_loop.SetAnimation(200, false);

	end3_start.LoadBitmapByString({
		"./RES/end/end3/start (1).bmp" ,
		"./RES/end/end3/start (2).bmp" ,
		"./RES/end/end3/start (3).bmp" ,
		"./RES/end/end3/start (4).bmp" ,
		"./RES/end/end3/start (5).bmp" ,
		});
	end3_start.SetTopLeft(0, 0);
	end3_start.SetAnimation(200, true);
	end3_start.ToggleAnimation();

	end3_loop.LoadBitmapByString({
		"./RES/end/end3/loop (1).bmp" ,
		"./RES/end/end3/loop (2).bmp" ,
		"./RES/end/end3/loop (3).bmp" ,
		"./RES/end/end3/loop (4).bmp" ,
		"./RES/end/end3/loop (5).bmp" ,
		"./RES/end/end3/loop (6).bmp" ,
		"./RES/end/end3/loop (7).bmp" ,
		});
	end3_loop.SetTopLeft(0, 0);
	end3_loop.SetAnimation(200, false);

	end4_start.LoadBitmapByString({
		"./RES/end/end4/start (1).bmp" ,
		"./RES/end/end4/start (2).bmp" ,
		"./RES/end/end4/start (3).bmp" ,
		"./RES/end/end4/start (4).bmp" ,
		"./RES/end/end4/start (5).bmp" ,
		});
	end4_start.SetTopLeft(0, 0);
	end4_start.SetAnimation(200, true);
	end4_start.ToggleAnimation();

	end4_loop.LoadBitmapByString({
		"./RES/end/end4/loop (1).bmp" ,
		"./RES/end/end4/loop (2).bmp" ,
		"./RES/end/end4/loop (3).bmp" ,
		"./RES/end/end4/loop (4).bmp" ,
		"./RES/end/end4/loop (5).bmp" ,
		"./RES/end/end4/loop (6).bmp" ,
		"./RES/end/end4/loop (7).bmp" ,
		});
	end4_loop.SetTopLeft(0, 0);
	end4_loop.SetAnimation(200, false);

	end5_start.LoadBitmapByString({
		"./RES/end/end5/start (1).bmp" ,
		"./RES/end/end5/start (2).bmp" ,
		"./RES/end/end5/start (3).bmp" ,
		"./RES/end/end5/start (4).bmp" ,
		"./RES/end/end5/start (5).bmp" ,
		"./RES/end/end5/start (6).bmp" ,
		"./RES/end/end5/start (7).bmp" ,
		});
	end5_start.SetTopLeft(0, 0);
	end5_start.SetAnimation(200, true);
	end5_start.ToggleAnimation();

	end5_loop.LoadBitmapByString({
		"./RES/end/end5/loop (1).bmp" ,
		"./RES/end/end5/loop (2).bmp" ,
		"./RES/end/end5/loop (3).bmp" ,
		"./RES/end/end5/loop (4).bmp" ,
		"./RES/end/end5/loop (5).bmp" ,
		});
	end5_loop.SetTopLeft(0, 0);
	end5_loop.SetAnimation(200, false);

	end6_start.LoadBitmapByString({"./RES/end/end6/start (1).bmp" ,});
	end6_start.SetTopLeft(0, 0);

	end6_loop.LoadBitmapByString({
		"./RES/end/end6/loop (1).bmp" ,
		"./RES/end/end6/loop (2).bmp" ,
		"./RES/end/end6/loop (3).bmp" ,
		"./RES/end/end6/loop (4).bmp" ,
		"./RES/end/end6/loop (5).bmp" ,
		});
	end6_loop.SetTopLeft(0, 0);
	end6_loop.SetAnimation(200, false);

	ShowInitProgress(100, "OK!");

	Sleep(1000);
}

void CGameStateOver::OnShow()
{
	if (CGameStateRun::score_sys.score < 5000) {
		if (end1_start.GetFrameIndexOfBitmap() == 9) {
			end1_loop.ShowBitmap();
		}
		else {
			end1_start.ShowBitmap();
		}
	}
	else if (CGameStateRun::score_sys.score < 10000) {
		if (end2_start.GetFrameIndexOfBitmap() == 5) {
			end2_loop.ShowBitmap();
		}
		else {
			end2_start.ShowBitmap();
		}
	}
	else if (CGameStateRun::score_sys.score < 50000) {
		if (end3_start.GetFrameIndexOfBitmap() == 4) {
			end3_loop.ShowBitmap();
		}
		else {
			end3_start.ShowBitmap();
		}
	}
	else if (CGameStateRun::score_sys.score < 80000) {
		if (end4_start.GetFrameIndexOfBitmap() == 4) {
			end4_loop.ShowBitmap();
		}
		else {
			end4_start.ShowBitmap();
		}
	}
	else if (CGameStateRun::score_sys.score < 100000) {
		if (end5_start.GetFrameIndexOfBitmap() == 6) {
			end5_loop.ShowBitmap();
		}
		else {
			end5_start.ShowBitmap();
		}
	}
	else {
		end6_start.ShowBitmap();
		end6_loop.ShowBitmap();
	}
	
	CGameStateRun::score_sys.over();
}
