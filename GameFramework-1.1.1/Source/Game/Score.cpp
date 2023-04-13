#include "stdafx.h"
#include "UI.h"
#include<iostream>

Score::Score() {
	score = 0;
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