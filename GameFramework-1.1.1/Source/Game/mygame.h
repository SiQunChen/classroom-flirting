/*
 * mygame.h: 本檔案儲遊戲本身的class的interface
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "Main_girl.h"
#include "Man.h"
#include "NormalMan1.h"
#include "NormalMan2.h"
#include "NormalMan3.h"
#include "SpecialMan1.h"
#include "SpecialMan2.h"
#include "SpecialMan3.h"
#include "UI.h"
#include "Teacher.h"
#include "Girl.h"
#include "NormalGirl1.h"
#include "NormalGirl2.h"
#include "SpecialGirl.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID {				// 定義各種音效的編號
		AUDIO_DING,				// 0
		AUDIO_LAKE,				// 1
		AUDIO_NTUT				// 2
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap logo;								// csie的logo
		void load_background();
		void load_tutorial();
		CMovingBitmap init_back;
		CMovingBitmap tutorial[7];						// 6 tutorial+ 1 tutorial_current_show (spare, to unshow scene)
		int tutorial_stage = 0;							// FLAG: tutorial stage
		int start_frame = 0;							// start frame
		CTextDraw mouse_tracking;
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	// 每個Member function的Implementation都要弄懂
	////////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun() override;
		void OnInit() override;  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT) override;
		void OnKeyUp(UINT, UINT, UINT) override;
		void OnLButtonDown(UINT nFlags, CPoint point) override;  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point) override;	// 處理滑鼠的動作
		void OnMouseMove(UINT nFlags, CPoint point) override;	// 處理滑鼠的動作 
		void OnRButtonUp(UINT nFlags, CPoint point) override;	// 處理滑鼠的動作
		void OnRButtonDown(UINT nFlags, CPoint point) override;  // 處理滑鼠的動作
		HDYLM_sys HDYLM;
		static Score score_sys;
	protected:
		CMovingBitmap map;
		void MainGirlMove();
		void OnBeginState() override;							// 設定每次重玩所需的變數
		void MainGirlMoveUpAndDown();
		void Setup(int floor, bool left);
		POINT p;
		// Elevator up;	//
		// Elevator down;	
		CMovingBitmap up;
		CMovingBitmap down;
		CMovingBitmap crosshair_on;
		CMovingBitmap focusing_front;
		CMovingBitmap focusing_behind;
		CMovingBitmap score_board;
		Clock clock_sys;
		CMovingBitmap hp_board;
		HP hp_sys;
		int up_down = 0; // 1 = 上樓，2 = 下樓
		int time = 0;
		int bump_delay = 0;
		int floor = 1;
		int maingirl_state = 1;
		int stop_man_left = 0;
		void OnMove() override;									// 移動遊戲元素
		void OnShow() override;									// 顯示這個狀態的遊戲畫面
		bool beauty_time = false;
		bool evolution = false;
		bool evo_left = false;
		bool bump_left = false;
		bool maingirl_stop_left = false;
		bool maingirl_stop_front = false;
		bool bool_moving_up_and_down_state = false;
		bool maingirl_start_on_left = false;
		/*
		0: stand
		1: walk left 2: walk right
		3: run left 4: run right
		5: beauty left 6: beauty right
		*/
		Main_girl main_girl[11];
		Normalman1 n1[8];
		Normalman2 n2[8];
		Normalman3 n3[8];
		Specialman1 s1;
		Specialman2 s2;
		Specialman3 s3;
		Teacher teacher;
		Normalgirl1 n1_girl[5];
		Normalgirl2 n2_girl[5];
		Specialgirl Sgirl;
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap end1_start;
		CMovingBitmap end1_loop;
		CMovingBitmap end2_start;
		CMovingBitmap end2_loop;
		CMovingBitmap end3_start;
		CMovingBitmap end3_loop;
		CMovingBitmap end4_start;
		CMovingBitmap end4_loop;
		CMovingBitmap end5_start;
		CMovingBitmap end5_loop;
		CMovingBitmap end6_start;
		CMovingBitmap end6_loop;
		int counter;									// 倒數之計數器
	};

}