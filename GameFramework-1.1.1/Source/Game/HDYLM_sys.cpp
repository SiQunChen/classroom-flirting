#include "stdafx.h"
#include "config.h"
#include "UI.h"

bool HDYLM_sys::kill_man_earn_score(const int is_being_attack_state ,const int how_do_you_love_me_max)
{
    killed = false;
    if(cd_time < 0 || how_much_do_you_love_me >= how_do_you_love_me_max || how_much_do_you_love_me < 0) {
        if(how_much_do_you_love_me >= how_do_you_love_me_max) {
            killed = true;
        }
        cd_time = 0;
        how_much_do_you_love_me = 0;
    }
    else {
        cd_time--;
        how_much_do_you_love_me -= 5;
        if (is_being_attack_state == 4 || is_being_attack_state == 5 || is_being_attack_state == 6) {
            how_much_do_you_love_me -= 15;
        }
        if(is_being_attack_state) {
            cd_time = 1000 / GAME_CYCLE_TIME * 30;
            how_much_do_you_love_me += 50;
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

int HDYLM_sys::get_HDYLM_value()
{
    return (how_much_do_you_love_me);
}