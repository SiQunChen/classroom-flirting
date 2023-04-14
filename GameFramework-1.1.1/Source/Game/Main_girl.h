#ifndef MAIN_GIRL
#define MAIN_GIRL

#include "../Library/gameutil.h"

class Main_girl : public game_framework::CMovingBitmap
{
public:
    Main_girl() = default;
	~Main_girl(){}
	// int Move(int walk_right_position);
	void Load_main();
	void Load_walk_left();
	void Load_walk_right();
	void Load_run_left();
	void Load_run_right();
private:

	POINT p;
	int maingirl = -1;
	int flag_girl_movement = -1;

	CMovingBitmap MainGirl;
};

#endif