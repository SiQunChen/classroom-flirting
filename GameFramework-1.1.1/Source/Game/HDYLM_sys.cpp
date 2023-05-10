#include "stdafx.h"
#include "Man.h"
#include "UI.h"

bool HDYLM_sys::man_love_me_sys(const bool is_being_attack_state, const int how_do_you_love_me_max)
{
    killed = false;
    if(cd_time < 0 || how_much_do_you_love_me == how_do_you_love_me_max) {
        if(how_much_do_you_love_me >= how_do_you_love_me_max) {
            killed = true;
        }
        cd_time = 0;
        how_much_do_you_love_me = 0;
    }
    else {
        cd_time--;
        if(is_being_attack_state) {
            cd_time = 10;
            how_much_do_you_love_me += 25;
        }
    }
    return (killed);
}
