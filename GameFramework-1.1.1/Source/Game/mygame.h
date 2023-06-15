#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "Role.h"
#include "NormalMan.h"
#include "SpecialMan.h"
#include "NormalGirl.h"
#include "SpecialGirl.h"
#include "UI.h"

namespace game_framework {
	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
		Audio_sys audio_sys;
	private:
		POINT p;
		CMovingBitmap logo;								// csie的logo
		void load_background();
		void load_tutorial();
		CMovingBitmap init_back;
		CMovingBitmap about;
		CMovingBitmap tutorial[6];
		int tutorial_stage = 0;							// FLAG: tutorial stage
		int start_frame = 0;							// start frame
		CTextDraw mouse_tracking;
		int delay = 0;
		CMovingBitmap voice_on;
		CMovingBitmap voice_on_hover;
		CMovingBitmap voice_off;
		CMovingBitmap voice_off_hover;
	};

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
		static Score score_sys;
		static bool show_voice_off;
	protected:
		CMovingBitmap map;
		void MainGirlMove();
		void OnBeginState() override;							// 設定每次重玩所需的變數
		void MainGirlMoveUpAndDown();
		void PlayAudio();
		void Setup(int floor, bool left);
		POINT p;
		CMovingBitmap up;
		CMovingBitmap down;
		CMovingBitmap crosshair_on;
		CMovingBitmap focusing_front;
		CMovingBitmap focusing_behind;
		CMovingBitmap score_board;
		Clock clock_sys;
		CMovingBitmap hp_board;
		HP hp_sys;
		Audio_sys audio_sys;
		CMovingBitmap voice_on;
		CMovingBitmap voice_on_hover;
		CMovingBitmap voice_off;
		CMovingBitmap voice_off_hover;
		int up_down = 0; // 1 = 上樓，2 = 下樓
		int time = 0;
		int bump_delay = 0;
		int over_delay = 0;
		int floor = 1;
		int maingirl_state = 1;
		int stop_man_left = 0;
		void OnMove() override;									// 移動遊戲元素
		void OnShow() override;									// 顯示這個狀態的遊戲畫面
		bool beauty_time = false;
		bool evolution = false;
		bool evo_left = false;
		bool bump_left = false;
		bool over_left = false;
		bool maingirl_stop_left = false;
		bool maingirl_stop_front = false;
		bool bool_moving_up_and_down_state = false;
		bool maingirl_start_on_left = false;
		bool sub_blood_flag = false;
		/*
		 0: stand
		 1: walk left		   2: walk right
		 3: run left		   4: run right
		 5: beauty left		   6: beauty right
		 7: bump left		   8: bump right
		 9: lose left		  10: lose right
	    11: over notice left  12: over left
	    13: over notice right 14: over right
		*/
		Main_girl main_girl[15];
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

		// audio flag, play on true state
		bool af_run = false;
		bool af_bell = false;
		int af_bump = 0;
		int af_flying = 0;
		int af_laser = 0;
		bool af_press = false;
		bool af_reinforcing = false;
		int af_snatch = 0;
		int af_summarize = 0;
		int af_warning = 0;
		int af_lose = 0;
	};

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		POINT p;
		Audio_sys audio_sys;
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
		CMovingBitmap voice_on;
		CMovingBitmap voice_on_hover;
		CMovingBitmap voice_off;
		CMovingBitmap voice_off_hover;
		int counter;									// 倒數之計數器
		bool af_end = false;
	};
}
