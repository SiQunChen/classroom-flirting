#ifndef TEACHER
#define TEACHER

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
	int girl;
	int count_girl(int maingirl_state, bool evolution);
	void touch(int main, int target);
	CMovingBitmap teacher_left;
	CMovingBitmap teacher_right;
};

#endif