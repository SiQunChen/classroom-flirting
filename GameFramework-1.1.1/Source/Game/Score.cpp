#include "stdafx.h"
#include "UI.h"
#include<iostream>
#include <string>
#include <valarray>

Score::Score() {
    score = 0;
}

int Score::get_score() {
    return (score);
}

void Score::load_ui_score_num() {
    for (int i = 0; i<10; i++) {
        std::string I = std::to_string(i);
        score_num[i].LoadBitmapByString({
            "./RES/UI/number/number ("+I+").bmp"});
    }
}

void Score::show_score() {
    /* all for 7
     * 0: score % (10 ** 7) / (10 ** 0)
     * 1: score % (10 ** 6) / (10 ** 1)
     */
	
    for (int i = 0; i<8; i++) {
        this_num = score % static_cast<int>(pow(10, i+1)) / static_cast<int>(pow(10, i));
        for (int j = 0; j<10; j++) {
            if (this_num == j) {
                score_num[j].SetTopLeft(650 - 25 * i, 45);
                score_num[j].ShowBitmap();
            }
        }
    }
}
