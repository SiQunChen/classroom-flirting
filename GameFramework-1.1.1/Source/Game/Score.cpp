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
            "./RES/UI/number/number ("+I+").bmp"},
			RGB(182, 185, 184));
    }

	for (int i = 0; i < 10; i++) {
		std::string I = std::to_string(i);
		score_end[i].LoadBitmapByString({
			"./RES/end/" + I + ".bmp" },
			RGB(255, 255, 255));
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
                score_num[j].ShowBitmap(1.2);
            }
        }
    }
}

void Score::over() {
	for (int i = 0; i < 8; i++) {
		this_num = score % static_cast<int>(pow(10, i + 1)) / static_cast<int>(pow(10, i));
		for (int j = 0; j < 10; j++) {
			if (this_num == j) {
				if (i == 0 || i == 7) {
					score_end[j].SetTopLeft(485 - 27 * i, 47);
				}
				else if (i == 1 || i == 6) {
					score_end[j].SetTopLeft(485 - 27 * i, 55);
				}
				else if (i == 2 || i == 5) {
					score_end[j].SetTopLeft(485 - 27 * i, 63);
				}
				else {
					score_end[j].SetTopLeft(485 - 27 * i, 71);
				}
				score_end[j].ShowBitmap();
			}
		}
	}
}
