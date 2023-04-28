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