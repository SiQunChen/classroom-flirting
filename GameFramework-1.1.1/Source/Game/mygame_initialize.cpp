#include "stdafx.h"

#include <string>

#include "mygame.h"

using namespace game_framework;

bool CGameStateRun::show_voice_off = false;

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	ShowInitProgress(0, "Start Initialize...");	// 一開始的loading進度為0%
	
	voice_on.LoadBitmapByString({"./RES/end/voice_button_on.bmp"}, RGB(255, 255, 255));
	voice_on.SetTopLeft(585, 510);
	voice_off.LoadBitmapByString({"./RES/end/voice_button_off.bmp"}, RGB(255, 255, 255));
	voice_off.SetTopLeft(585, 510);
	voice_on_hover.LoadBitmapByString({ "./RES/end/voice_button_on_hover.bmp" }, RGB(255, 255, 255));
	voice_on_hover.SetTopLeft(588, 512);
	voice_off_hover.LoadBitmapByString({"./RES/end/voice_button_off_hover.bmp"}, RGB(255, 255, 255));
	voice_off_hover.SetTopLeft(588, 512);

	ShowInitProgress(10, "Initializing...");
	
	load_background();
	load_tutorial();
	audio_sys.load_ui_audio_init();

	audio_sys.play_ui_audio(0);
	ShowInitProgress(20, "Initializing...");
}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (start_frame == 2) {
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
			if (CGameStateRun::show_voice_off == false) {
				audio_sys.stop_ui_audio(0);
				audio_sys.play_ui_audio(3);
			}
			delay = 1;
		}
	}

}

void CGameStateInit::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (start_frame == 0) {
		start_frame = 1;
	}
	else if (start_frame == 1) {
		start_frame = 2;
	}
	else if (start_frame == 2 && delay == 0) {
		if (p.x >= 300 && p.x <= 500 && p.y >= 520 && p.y <= 600) {
			if (CGameStateRun::show_voice_off == false) {
				audio_sys.stop_ui_audio(0);
				audio_sys.play_ui_audio(3);
			}
			delay = 1;
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

void CGameStateInit::OnShow()
{
	GetCursorPos(&p);
	HWND hwnd = FindWindowA(NULL, "Game");
	ScreenToClient(hwnd, &p);

	if (start_frame == 0) {
		init_back.ShowBitmap();
	}
	else if (start_frame == 1) {
		about.ShowBitmap();
	}
	else{
		if (tutorial_stage == 0) {
			tutorial[0].ShowBitmap();
		}
		else if (tutorial_stage == 1) {
			tutorial[1].ShowBitmap();
		}
		else if (tutorial_stage == 2) {
			tutorial[2].ShowBitmap();
		}
		else if (tutorial_stage == 3) {
			tutorial[3].ShowBitmap();
		}
		else if (tutorial_stage == 4) {
			tutorial[4].ShowBitmap();
		}
		else if (tutorial_stage == 5) {
			tutorial[5].ShowBitmap();
		}
		else {
			tutorial[6].ShowBitmap();
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
	}

	if (delay != 0 && delay < 120) {
		delay++;
	}
	else if(delay > 49){
		GotoGameState(GAME_STATE_RUN);
	}
}

void CGameStateInit::load_background() {
	init_back.LoadBitmapByString({ "./RES/initScreen2.bmp" });
	init_back.SetTopLeft(0, 0);

	about.LoadBitmapByString({ "./RES/About_oop.bmp" });
	about.SetTopLeft(0, 0);
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

	for (int i = 0; i < 6; i++) {
		tutorial[i].SetTopLeft(0, 0);
		tutorial[i].SetAnimation(150, false);
	}
}
