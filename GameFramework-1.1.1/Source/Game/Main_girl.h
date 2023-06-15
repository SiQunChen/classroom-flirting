#pragma once

#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/gameutil.h"

class Main_girl : public game_framework::CMovingBitmap
{
public:
    Main_girl() = default;
	// int Move(int walk_right_position);
	void Load_main();
	void Load_walk_left();
	void Load_walk_right();
	void Load_run_left();
	void Load_run_right();
	void Load_beauty_time_left();
	void Load_beauty_time_right();
	void Load_bump_left();
	void Load_bump_right();
	void Load_lose_left();
	void Load_lose_right();
	void Load_over_notice_left();
	void Load_over_left();
	void Load_over_notice_right();
	void Load_over_right();
};
