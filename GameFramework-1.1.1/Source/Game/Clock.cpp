#include "stdafx.h"
#include "UI.h"
#include <string>

void Clock::load_ui_clock_board() {
	clock.LoadBitmapByString({
		"./RES/UI/clock/clock.bmp"});
	clock.SetTopLeft(350, 0);
}

void Clock::load_ui_clock_pointer() {
	for (int i = 0; i < 360; i++) {
		auto I = std::to_string(i);
		color.LoadBitmapByString({ "./RES/UI/coloring/coloring (" + I + ").bmp" }, RGB(255, 255, 255));
		clock_pointer.LoadBitmapByString({"./RES/UI/Cpointer/pointer (" + I + ").bmp"}, RGB(255, 255, 255));
	}
	color.SetTopLeft(362, 5);
	color.SetAnimation(300, true);
	color.ToggleAnimation();
	clock_pointer.SetTopLeft(375, 15);
	clock_pointer.SetAnimation(300, true);
	clock_pointer.ToggleAnimation();
}

void Clock::show_clock_sys()
{
	if (clock_pointer.GetFrameIndexOfBitmap() == 359) {
		time_over = true;
	}
	clock.ShowBitmap();
	color.ShowBitmap(1.5);
	clock_pointer.ShowBitmap();
}

bool Clock::get_time_over() {
	return time_over;
}

void Clock::over_cheat() {
	time_over = true;
}
