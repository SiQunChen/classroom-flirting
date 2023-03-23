using namespace game_framework {

	class UI{
		public:
			UI();						// constructor
			void init();
			void load_ui_pictures();
		private:
			int time;					// current time
			int time_left;				// max_time - time
			const int max_time;			// maximum time of the game
			CMovingBitmap clock;
			//! 上下樓梯的按鈕應該要放過來
			//! HP寫在女主角那邊，UI這裡用一個getter 拿值，再想怎麼load血量的圖片
			float hp;					// HP
			CMovingBitmap hp_board;
			CMovingBitmap hp_heart[9];
			//! beauty time寫在女主角那邊，UI這裡用一個getter 拿布林，顯示無敵時間
			bool is_invincible;
			CMovingBitmap invincible_board;
			//! 收服的男生數量寫在男生那邊，UI這裡用一個 getter拿值，計算總成績
			int score;					// 總成績
			CMovingBitmap score_board;
			CMovingBitmap score_num[8];
	};
}