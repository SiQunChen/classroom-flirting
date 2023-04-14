#include "stdafx.h"
#include "UI.h"
#include<iostream>
#include <valarray>

Score::Score() {
	score = 10323;
}

int Score::get_score() {
	return (score);
}

void Score::load_ui_score_board() {
	score_board.LoadBitmapByString({
		"./RES/UI/number/scoreBoard.bmp"});
	score_board.SetTopLeft(0, 0);
}

void Score::load_ui_score_num() {
	score_num[0].LoadBitmapByString({
		"./RES/UI/number/number (0).bmp"});
	score_num[1].LoadBitmapByString({
		"./RES/UI/number/number (1).bmp"});
	score_num[2].LoadBitmapByString({
		"./RES/UI/number/number (2).bmp"});
	score_num[3].LoadBitmapByString({
		"./RES/UI/number/number (3).bmp"});
	score_num[4].LoadBitmapByString({
		"./RES/UI/number/number (4).bmp"});
	score_num[5].LoadBitmapByString({
		"./RES/UI/number/number (5).bmp"});
	score_num[6].LoadBitmapByString({
		"./RES/UI/number/number (6).bmp"});
	score_num[7].LoadBitmapByString({
		"./RES/UI/number/number (7).bmp"});
	score_num[8].LoadBitmapByString({
		"./RES/UI/number/number (8).bmp"});
	score_num[9].LoadBitmapByString({
		"./RES/UI/number/number (9).bmp"});
}

void Score::show_score(){
	/*
	printf("%d", score);
	if (score % 100 / 10 == 2) {
		score_num[1].LoadBitmapByString({
			"./RES/UI/number/number (1).bmp"});
		score_num[1].SetTopLeft(150, 150);
		score_num[1].ShowBitmap();
	}*/

	/* all for 7
	 * 0: score % (10 ** 7) / (10 ** 0)
	 * 1: score % (10 ** 6) / (10 ** 1)
	 */

	
	for (int i = 0; i<8; i++) {
		if (score % static_cast<int>(pow(10, i+1)) / static_cast<int>(pow(10, i)) == 0) {
			score_posision[i].LoadBitmapByString({
				"./RES/UI/number/number (0).bmp"});
		}
		else if (score % static_cast<int>(pow(10, i+1)) / static_cast<int>(pow(10, i)) == 1) {
			score_posision[i].LoadBitmapByString({
				"./RES/UI/number/number (1).bmp"});
		}
		else if (score % static_cast<int>(pow(10, i+1)) / static_cast<int>(pow(10, i)) == 2) {
			score_posision[i].LoadBitmapByString({
				"./RES/UI/number/number (2).bmp"});
		}
		else if (score % static_cast<int>(pow(10, i+1)) / static_cast<int>(pow(10, i)) == 3) {
			score_posision[i].LoadBitmapByString({
				"./RES/UI/number/number (3).bmp"});
		}
		else if (score % static_cast<int>(pow(10, i+1)) / static_cast<int>(pow(10, i)) == 4) {
			score_posision[i].LoadBitmapByString({
				"./RES/UI/number/number (4).bmp"});
		}
		else if (score % static_cast<int>(pow(10, i+1)) / static_cast<int>(pow(10, i)) == 5) {
			score_posision[i].LoadBitmapByString({
				"./RES/UI/number/number (5).bmp"});
		}
		else if (score % static_cast<int>(pow(10, i+1)) / static_cast<int>(pow(10, i)) == 6) {
			score_posision[i].LoadBitmapByString({
				"./RES/UI/number/number (6).bmp"});
		}
		else if (score % static_cast<int>(pow(10, i+1)) / static_cast<int>(pow(10, i)) == 7) {
			score_posision[i].LoadBitmapByString({
				"./RES/UI/number/number (7).bmp"});
		}
		else if (score % static_cast<int>(pow(10, i+1)) / static_cast<int>(pow(10, i)) == 8) {
			score_posision[i].LoadBitmapByString({
				"./RES/UI/number/number (8).bmp"});
		}
		else {
			score_posision[i].LoadBitmapByString({
				"./RES/UI/number/number (9).bmp"});
		}
	}
	
	for (int i = 0; i<8; i++) {
		score_posision[i].SetTopLeft(650 - 25 * i, 45);
		score_posision[i].ShowBitmap();
	}

}
