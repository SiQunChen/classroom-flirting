#include "stdafx.h"
#include "Main_girl.h"

/* int Main_girl::Move(int walk_right_position)
{
    GetCursorPos(&p);
    HWND hwnd = FindWindowA(NULL, "Game");
    ScreenToClient(hwnd, &p);
    
    if (p.x - walk_right_position > 0 && p.x - walk_right_position < 200) {
        maingirl = 1;

        //! map.SetTopLeft(map.GetLeft() - 5, 0);
        flag_girl_movement = 1;
        if (walk_right_position > 250) {
            //! MainGirl[2].SetTopLeft(main_girl[2].GetLeft() - 5, 300);
            flag_girl_movement = 2;
        }
    }
    else if (p.x - walk_right_position >= 200) {
        maingirl = 2;

        //! MainGirl[4].SetTopLeft(main_girl[2].GetLeft(), 300);
        //! map.SetTopLeft(map.GetLeft() - 10, 0);
        flag_girl_movement = 3;
        if (walk_right_position > 250) {
            //! MainGirl[2].SetTopLeft(main_girl[2].GetLeft() - 10, 300);
            flag_girl_movement = 4;
        }
    }
    else if (p.x - walk_right_position > -200 && p.x - walk_right_position <= 0) {
        maingirl = 3;

        //! MainGirl[1].SetTopLeft(main_girl[2].GetLeft(), 300);
        //! map.SetTopLeft(map.GetLeft() + 5, 0);
        flag_girl_movement = 5;
        if (walk_right_position < 450) {
            //! MainGirl[2].SetTopLeft(main_girl[2].GetLeft() + 5, 300);
            flag_girl_movement = 6;
        }
    }
    else {
        maingirl = 4;

        //! MainGirl[3].SetTopLeft(main_girl[2].GetLeft(), 300);
        //! map.SetTopLeft(map.GetLeft() + 10, 0);
        flag_girl_movement = 7;
        if (walk_right_position < 450) {
            //! MainGirl[2].SetTopLeft(main_girl[2].GetLeft() + 10, 300);
            flag_girl_movement = 8;
        }
    }
    return (flag_girl_movement);
} */

void Main_girl::Load_main() {
    LoadBitmapByString({ 
        "./RES/mainGirl/left/stand.bmp", 
        "./RES/mainGirl/right/stand.bmp", },
        RGB(0, 0, 0));
    SetTopLeft(250, 250);
}

void Main_girl::Load_walk_left() {
    LoadBitmapByString({
        "./RES/mainGirl/left/girl_walk (1).bmp",
        "./RES/mainGirl/left/girl_walk (2).bmp",
        "./RES/mainGirl/left/girl_walk (3).bmp",
        "./RES/mainGirl/left/girl_walk (4).bmp",
        "./RES/mainGirl/left/girl_walk (5).bmp",
        "./RES/mainGirl/left/girl_walk (6).bmp",
        "./RES/mainGirl/left/girl_walk (7).bmp", },
        RGB(230, 230, 196));
    SetTopLeft(250, 250);
    SetAnimation(150, false);
}

void Main_girl::Load_walk_right() {
    LoadBitmapByString({
        "./RES/mainGirl/right/girl_walk (1).bmp",
        "./RES/mainGirl/right/girl_walk (2).bmp",
        "./RES/mainGirl/right/girl_walk (3).bmp",
        "./RES/mainGirl/right/girl_walk (4).bmp",
        "./RES/mainGirl/right/girl_walk (5).bmp",
        "./RES/mainGirl/right/girl_walk (6).bmp",
        "./RES/mainGirl/right/girl_walk (7).bmp", },
        RGB(230, 230, 196));
    SetTopLeft(250, 250);
    SetAnimation(150, false);
}

void Main_girl::Load_run_left() {
    LoadBitmapByString({
        "./RES/mainGirl/left/girl_run (1).bmp",
        "./RES/mainGirl/left/girl_run (2).bmp",
        "./RES/mainGirl/left/girl_run (3).bmp",
        "./RES/mainGirl/left/girl_run (4).bmp",
        "./RES/mainGirl/left/girl_run (5).bmp",
        "./RES/mainGirl/left/girl_run (6).bmp",
        "./RES/mainGirl/left/girl_run (7).bmp", },
        RGB(0, 0, 0));
    SetTopLeft(250, 250);
    SetAnimation(150, false);
}

void Main_girl::Load_run_right() {
    LoadBitmapByString({
        "./RES/mainGirl/right/girl_run (1).bmp",
        "./RES/mainGirl/right/girl_run (2).bmp",
        "./RES/mainGirl/right/girl_run (3).bmp",
        "./RES/mainGirl/right/girl_run (4).bmp",
        "./RES/mainGirl/right/girl_run (5).bmp",
        "./RES/mainGirl/right/girl_run (6).bmp",
        "./RES/mainGirl/right/girl_run (7).bmp", },
        RGB(0, 0, 0));
    SetTopLeft(250, 250);
    SetAnimation(150, false);  
}

void Main_girl::Load_beauty_time_left() {
	LoadBitmapByString({
		"./RES/mainGirl/left/reinforcing (1).bmp",
		"./RES/mainGirl/left/reinforcing (2).bmp",
		"./RES/mainGirl/left/reinforcing (3).bmp",
		"./RES/mainGirl/left/reinforcing (4).bmp",
		"./RES/mainGirl/left/reinforcing (5).bmp",
		"./RES/mainGirl/left/reinforcing (6).bmp",
		"./RES/mainGirl/left/reinforcing (7).bmp", 
		"./RES/mainGirl/left/reinforcing (8).bmp",
		"./RES/mainGirl/left/reinforcing (9).bmp",
		"./RES/mainGirl/left/reinforcing (10).bmp",
		"./RES/mainGirl/left/reinforcing (11).bmp",
		"./RES/mainGirl/left/reinforcing (12).bmp",
		"./RES/mainGirl/left/reinforcing (13).bmp",
		"./RES/mainGirl/left/reinforcing (14).bmp", 
		"./RES/mainGirl/left/reinforcing (15).bmp",
		"./RES/mainGirl/left/reinforcing (16).bmp",
		"./RES/mainGirl/left/reinforcing (17).bmp",
		"./RES/mainGirl/left/reinforcing (18).bmp",
		"./RES/mainGirl/left/reinforcing (19).bmp",
		"./RES/mainGirl/left/reinforcing (20).bmp",
		"./RES/mainGirl/left/reinforcing (21).bmp", 
		"./RES/mainGirl/left/reinforcing (22).bmp",
		"./RES/mainGirl/left/reinforcing (23).bmp",
		"./RES/mainGirl/left/reinforcing (24).bmp",
		"./RES/mainGirl/left/reinforcing (25).bmp",
		"./RES/mainGirl/left/reinforcing (26).bmp",
		"./RES/mainGirl/left/reinforcing (27).bmp",
		"./RES/mainGirl/left/reinforcing (28).bmp", 
		"./RES/mainGirl/left/reinforcing (29).bmp",
		"./RES/mainGirl/left/reinforcing (30).bmp",
		"./RES/mainGirl/left/reinforcing (31).bmp",
		"./RES/mainGirl/left/reinforcing (32).bmp",},
		RGB(0, 0, 0));
	SetTopLeft(250, 250);
	SetAnimation(100, true);
	ToggleAnimation();
}

void Main_girl::Load_beauty_time_right() {
	LoadBitmapByString({
		"./RES/mainGirl/right/reinforcing (1).bmp",
		"./RES/mainGirl/right/reinforcing (2).bmp",
		"./RES/mainGirl/right/reinforcing (3).bmp",
		"./RES/mainGirl/right/reinforcing (4).bmp",
		"./RES/mainGirl/right/reinforcing (5).bmp",
		"./RES/mainGirl/right/reinforcing (6).bmp",
		"./RES/mainGirl/right/reinforcing (7).bmp",
		"./RES/mainGirl/right/reinforcing (8).bmp",
		"./RES/mainGirl/right/reinforcing (9).bmp",
		"./RES/mainGirl/right/reinforcing (10).bmp",
		"./RES/mainGirl/right/reinforcing (11).bmp",
		"./RES/mainGirl/right/reinforcing (12).bmp",
		"./RES/mainGirl/right/reinforcing (13).bmp",
		"./RES/mainGirl/right/reinforcing (14).bmp",
		"./RES/mainGirl/right/reinforcing (15).bmp",
		"./RES/mainGirl/right/reinforcing (16).bmp",
		"./RES/mainGirl/right/reinforcing (17).bmp",
		"./RES/mainGirl/right/reinforcing (18).bmp",
		"./RES/mainGirl/right/reinforcing (19).bmp",
		"./RES/mainGirl/right/reinforcing (20).bmp",
		"./RES/mainGirl/right/reinforcing (21).bmp",
		"./RES/mainGirl/right/reinforcing (22).bmp",
		"./RES/mainGirl/right/reinforcing (23).bmp",
		"./RES/mainGirl/right/reinforcing (24).bmp",
		"./RES/mainGirl/right/reinforcing (25).bmp",
		"./RES/mainGirl/right/reinforcing (26).bmp",
		"./RES/mainGirl/right/reinforcing (27).bmp",
		"./RES/mainGirl/right/reinforcing (28).bmp",
		"./RES/mainGirl/right/reinforcing (29).bmp",
		"./RES/mainGirl/right/reinforcing (30).bmp",
		"./RES/mainGirl/right/reinforcing (31).bmp",
		"./RES/mainGirl/right/reinforcing (32).bmp", },
		RGB(0, 0, 0));
	SetTopLeft(250, 250);
	SetAnimation(100, true);
	ToggleAnimation();
}

void Main_girl::Load_bump_left() {
	LoadBitmapByString({
		"./RES/mainGirl/left/bump (1).bmp",
		"./RES/mainGirl/left/bump (2).bmp",
		"./RES/mainGirl/left/bump (3).bmp",
		"./RES/mainGirl/left/bump (4).bmp",
		"./RES/mainGirl/left/bump (5).bmp",
		"./RES/mainGirl/left/bump (6).bmp",
		"./RES/mainGirl/left/bump (7).bmp",
		"./RES/mainGirl/left/bump (8).bmp",
		"./RES/mainGirl/left/bump (9).bmp",
		"./RES/mainGirl/left/bump (10).bmp",
		"./RES/mainGirl/left/bump (11).bmp",
		"./RES/mainGirl/left/bump (12).bmp",
		"./RES/mainGirl/left/bump (13).bmp",
		"./RES/mainGirl/left/bump (14).bmp",
		"./RES/mainGirl/left/bump (15).bmp",
		"./RES/mainGirl/left/bump (16).bmp",
		"./RES/mainGirl/left/bump (17).bmp",
		"./RES/mainGirl/left/bump (18).bmp",
		"./RES/mainGirl/left/bump (19).bmp",},
		RGB(255, 255, 255));
	SetTopLeft(250, 250);
	SetAnimation(150, true);
	ToggleAnimation();
}

void Main_girl::Load_bump_right() {
	LoadBitmapByString({
		"./RES/mainGirl/right/bump (1).bmp",
		"./RES/mainGirl/right/bump (2).bmp",
		"./RES/mainGirl/right/bump (3).bmp",
		"./RES/mainGirl/right/bump (4).bmp",
		"./RES/mainGirl/right/bump (5).bmp",
		"./RES/mainGirl/right/bump (6).bmp",
		"./RES/mainGirl/right/bump (7).bmp",
		"./RES/mainGirl/right/bump (8).bmp",
		"./RES/mainGirl/right/bump (9).bmp",
		"./RES/mainGirl/right/bump (10).bmp",
		"./RES/mainGirl/right/bump (11).bmp",
		"./RES/mainGirl/right/bump (12).bmp",
		"./RES/mainGirl/right/bump (13).bmp",
		"./RES/mainGirl/right/bump (14).bmp",
		"./RES/mainGirl/right/bump (15).bmp",
		"./RES/mainGirl/right/bump (16).bmp",
		"./RES/mainGirl/right/bump (17).bmp",
		"./RES/mainGirl/right/bump (18).bmp",
		"./RES/mainGirl/right/bump (19).bmp", },
		RGB(255, 255, 255));
	SetTopLeft(250, 250);
	SetAnimation(150, true);
	ToggleAnimation();
}

void Main_girl::Load_lose_left() {
	LoadBitmapByString({
		"./RES/mainGirl/left/lose (10).bmp",
		"./RES/mainGirl/left/lose (11).bmp",
		"./RES/mainGirl/left/lose (12).bmp",
		"./RES/mainGirl/left/lose (13).bmp",},
		RGB(255, 255, 255));
	SetTopLeft(250, 250);
	SetAnimation(150, false);
}

void Main_girl::Load_lose_right() {
	LoadBitmapByString({
		"./RES/mainGirl/right/lose (10).bmp",
		"./RES/mainGirl/right/lose (11).bmp",
		"./RES/mainGirl/right/lose (12).bmp",
		"./RES/mainGirl/right/lose (13).bmp", },
		RGB(255, 255, 255));
	SetTopLeft(250, 250);
	SetAnimation(150, false);
}