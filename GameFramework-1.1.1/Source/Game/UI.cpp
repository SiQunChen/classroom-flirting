#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "UI.h"


using namespace game_framework;

void UI::UI{}

void UI::init() {
	int time = 0;						// by second
	const int max_time = 60;			//! not sure the actuall time yet
	int hp = 9.0;
	bool is_invincible = false;
	int score = 0;
}