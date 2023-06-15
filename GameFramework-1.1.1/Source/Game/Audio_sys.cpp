#include "stdafx.h"
#include "UI.h"
#include "../Library/audio.h"

void Audio_sys::load_ui_audio_man()
{
	audio = game_framework::CAudio::Instance();

	audio->Load(7, "./Sounds/eatheart.mp3");
}


void Audio_sys::load_ui_audio_init()
{
	audio = game_framework::CAudio::Instance();

	audio->Load(0, "./Sounds/init.mp3");
	audio->Load(3, "./Sounds/press.mp3");
}


void Audio_sys::load_ui_audio_run()
{
	audio = game_framework::CAudio::Instance();

	audio->Load(2, "./Sounds/game.mp3");
	audio->Load(16, "./Sounds/warning.mp3");
	audio->Load(11, "./Sounds/lose.mp3");
	audio->Load(1, "./Sounds/bell.mp3");
	audio->Load(5, "./Sounds/bump.mp3");
	audio->Load(9, "./Sounds/flying.mp3");
	audio->Load(14, "./Sounds/laser.mp3");
	audio->Load(15, "./Sounds/reinforcing.mp3");
	audio->Load(17, "./Sounds/snatch.mp3");
	audio->Load(19, "./Sounds/summarize.mp3");
}

void Audio_sys::load_ui_audio_end()
{
	audio = game_framework::CAudio::Instance();

	audio->Load(4, "./Sounds/end1.mp3");
	audio->Load(6, "./Sounds/end2.mp3");
	audio->Load(8, "./Sounds/end3.mp3");
	audio->Load(10, "./Sounds/end4.mp3");
	audio->Load(12, "./Sounds/end5.mp3");
}

void Audio_sys::play_ui_audio(int audio_tag)
{
	audio->Play(audio_tag, audio_tag % 2 == 0);
}

void Audio_sys::pause()
{
	audio->Pause();
}

void Audio_sys::stop_ui_audio(int audio_tag)
{
	audio->Stop(audio_tag);
}

void Audio_sys::resume()
{
	audio->Resume();
}
