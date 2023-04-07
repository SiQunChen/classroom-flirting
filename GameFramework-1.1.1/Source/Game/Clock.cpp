#include "stdafx.h"
#include "UI.h"

Clock::Clock() {
	time = 0;
	time_left = get_time_left_second();
}

int Clock::get_max_time_second() {
	return (max_time);
}

int Clock::get_time_left_second() {
	return (max_time - time);
}

void Clock::load_ui_clock_board() {
	clock.LoadBitmapByString({
		"./RES/UI/clock/clock.bmp"});
	clock_back.LoadBitmapByString({
		"./RES/UI/clock/clock_background.bmp"});
}

void Clock::load_ui_clock_tick() {
	clock_pointer.LoadBitmapByString({
		"./RES/UI/clock/clock_pointer.bmp"});
}
