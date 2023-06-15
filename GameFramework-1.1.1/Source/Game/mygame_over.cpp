#include "stdafx.h"
#include "mygame.h"

using namespace game_framework;

Score CGameStateRun::score_sys;

CGameStateOver::CGameStateOver(CGame *g): CGameState(g)
{
}

void CGameStateOver::OnMove()
{
}

void CGameStateOver::OnBeginState()
{
}

void CGameStateOver::OnInit()
{
	ShowInitProgress(80, "Almost...");	// 接個前一個狀態的進度，此處進度視為66%
	voice_on.LoadBitmapByString({ "./RES/end/voice_button_on.bmp" }, RGB(255, 255, 255));
	voice_on.SetTopLeft(595, 515);
	voice_off.LoadBitmapByString({ "./RES/end/voice_button_off.bmp" }, RGB(255, 255, 255));
	voice_off.SetTopLeft(595, 515);
	voice_on_hover.LoadBitmapByString({ "./RES/end/voice_button_on_hover.bmp" }, RGB(255, 255, 255));
	voice_on_hover.SetTopLeft(598, 517);
	voice_off_hover.LoadBitmapByString({ "./RES/end/voice_button_off_hover.bmp" }, RGB(255, 255, 255));
	voice_off_hover.SetTopLeft(598, 517);
	
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

	ShowInitProgress(90, "Almost...");	// 接個前一個狀態的進度，此處進度視為66%

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

	audio_sys.load_ui_audio_end();
	ShowInitProgress(100, "Ready!");	// 接個前一個狀態的進度，此處進度視為66%
}

void CGameStateOver::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (p.x >= 600 && p.x <= 650 && p.y >= 525 && p.y <= 575) {
		if (CGameStateRun::show_voice_off) {
			audio_sys.resume();
		}
		else {
			audio_sys.pause();
		}
		CGameStateRun::show_voice_off = !CGameStateRun::show_voice_off;
	}
}

void CGameStateOver::OnShow()
{
	GetCursorPos(&p);
	HWND hwnd = FindWindowA(NULL, "Game");
	ScreenToClient(hwnd, &p);

	if (CGameStateRun::score_sys.score < 20000) {
		if (!af_end && !CGameStateRun::show_voice_off) {
			audio_sys.play_ui_audio(4);
			af_end = !af_end;
		}
		if (end1_start.GetFrameIndexOfBitmap() == 9) {
			end1_loop.ShowBitmap();
		}
		else {
			end1_start.ShowBitmap();
		}
	}
	else if (CGameStateRun::score_sys.score < 50000) {
		if (!af_end && !CGameStateRun::show_voice_off) {
			audio_sys.play_ui_audio(6);
			af_end = !af_end;
		}
		if (end2_start.GetFrameIndexOfBitmap() == 5) {
			end2_loop.ShowBitmap();
		}
		else {
			end2_start.ShowBitmap();
		}
	}
	else if (CGameStateRun::score_sys.score < 80000) {
		if (!af_end && !CGameStateRun::show_voice_off) {
			audio_sys.play_ui_audio(6);
			af_end = !af_end;
		}
		if (end3_start.GetFrameIndexOfBitmap() == 4) {
			end3_loop.ShowBitmap();
		}
		else {
			end3_start.ShowBitmap();
		}
	}
	else if (CGameStateRun::score_sys.score < 110000) {
		if (!af_end && !CGameStateRun::show_voice_off) {
			audio_sys.play_ui_audio(8);
			af_end = !af_end;
		}
		if (end4_start.GetFrameIndexOfBitmap() == 4) {
			end4_loop.ShowBitmap();
		}
		else {
			end4_start.ShowBitmap();
		}
	}
	else if (CGameStateRun::score_sys.score < 150000) {
		if (!af_end && !CGameStateRun::show_voice_off) {
			audio_sys.play_ui_audio(10);
			af_end = !af_end;
		}
		if (end5_start.GetFrameIndexOfBitmap() == 6) {
			end5_loop.ShowBitmap();
		}
		else {
			end5_start.ShowBitmap();
		}
	}
	else {
		if (!af_end && !CGameStateRun::show_voice_off) {
			audio_sys.play_ui_audio(12);
			af_end = !af_end;
		}
		end6_start.ShowBitmap();
		end6_loop.ShowBitmap();
	}

	if (p.x >= 590 && p.x <= 640 && p.y >= 515 && p.y <= 585) {
		if (CGameStateRun::show_voice_off) {
			voice_off_hover.ShowBitmap();
		}
		else {
			voice_on_hover.ShowBitmap();
		}
	}
	else {
		if (CGameStateRun::show_voice_off) {
			voice_off.ShowBitmap();
		}
		else {
			voice_on.ShowBitmap();
		}
	}
	CGameStateRun::score_sys.over();
}
