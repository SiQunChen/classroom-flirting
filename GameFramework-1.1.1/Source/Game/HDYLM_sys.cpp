#include "stdafx.h"
#include "config.h"
#include "UI.h"

bool HDYLM_sys::kill_man_earn_score(const bool is_being_attack_state, const int how_do_you_love_me_max)
{
    killed = false;
    if(cd_time < 0 || how_much_do_you_love_me >= how_do_you_love_me_max) {
        if(how_much_do_you_love_me >= how_do_you_love_me_max) {
            killed = true;
        }
        cd_time = 0;
        how_much_do_you_love_me = 0;
    }
    else {
        cd_time--;
        if(is_being_attack_state) {
            cd_time = 1000 / GAME_CYCLE_TIME * 3;
            how_much_do_you_love_me += 5;
        }
    }
    return (killed);
}

bool HDYLM_sys::flirting_earn_score(bool not_stop_state)
{
    flirting = false;
    if(not_stop_state) {
        flirting = true;
    }
    return (flirting);
}
