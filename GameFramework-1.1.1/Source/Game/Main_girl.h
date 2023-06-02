#ifndef MAIN_GIRL
#define MAIN_GIRL

#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"

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
private:
	/* 
	POINT p;
	int maingirl = -1;
	int flag_girl_movement = -1;
	*/

    /*
     0: stand
     1: walk left
     2: walk right
     3: run left
     4: run right
     */
};

#endif