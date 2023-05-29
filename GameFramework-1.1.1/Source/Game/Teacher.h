#pragma once

#include "../Library/gameutil.h"

class Teacher : public game_framework::CMovingBitmap
{
public:
	Teacher() = default;
	~Teacher() {}
	void Load();
	void ShowTeacher(bool left, int maingirl_state, int maingirl_left, bool evolution);
	void Setup(bool left);
	static bool bump;
protected:
	
private:
	void modify_hp();
	int girl;
	int count_girl(int maingirl_state, bool evolution);
	bool touch(int main, int target);
	int delay = 0;
	CMovingBitmap teacher_left;
	CMovingBitmap teacher_right;
};