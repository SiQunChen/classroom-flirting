#include "stdafx.h"
#include <string>

#include "UI.h"
#include "config.h"

#define FRAME_PER_SEC (1000/ GAME_CYCLE_TIME)

Clock::Clock() {
	frame_count = 0;
	time = 0;
}

void Clock::load_ui_clock_board() {
	clock.LoadBitmapByString({
		"./RES/UI/clock/clock.bmp"});
}

void Clock::load_ui_clock_pointer() {
	for (int i = 0; i < 360; i++) {
		auto I = std::to_string(i);
		clock_pointer[i].LoadBitmapByString({"./RES/UI/Cpointer/pointer (" + I + ").bmp"}, RGB(255, 255, 255));
		color[i].LoadBitmapByString({ "./RES/UI/coloring/coloring (" + I + ").bmp" }, RGB(255, 255, 255));
	}
}

void Clock::show_clock_sys()
{
	clock.SetTopLeft(350, 0);
	clock.ShowBitmap();
	frame = int(time/0.25);
	if (frame > 359) {
		frame = 359;
	}
	clock_pointer[frame].SetTopLeft(375, 15);
	color[frame].SetTopLeft(362, 5);
	color[frame].ShowBitmap(1.5);
	clock_pointer[frame].ShowBitmap();
}

void Clock::time_sys()
{
	if (get_time_left() <= 0) {
		time_over = true;
	}
	else if (++frame_count >= FRAME_PER_SEC/4) {
		frame_count -= FRAME_PER_SEC/4;
		time += 0.25;
	}
}

double Clock::get_time_left()
{
	return (max_time - time);
}

bool Clock::get_time_over() {
	return time_over;
}

void Clock::over_cheat() {
	time_over = true;
}