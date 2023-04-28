#include "stdafx.h"
#include "Man.h"

void Man::ShowMan(int start, int end, int map, int maingirl) {
	if (maingirl == 1) {
		girl = -5;
	}
	else if (maingirl == 2) {
		girl = -10;
	}
	else if (maingirl == 3) {
		girl = 5;
	}
	else if (maingirl == 4) {
		girl = 10;
	}
	else {
		girl = 0;
	}
	if (ManState[0].GetLeft() >= map + end + girl) {
		left = true;
	}
	else if (ManState[0].GetLeft() <= map + start + girl) {
		left = false;
	}
	if (left == true) {
		ManState[0].ShowBitmap();
		ManState[0].SetTopLeft(ManState[0].GetLeft() - 2 + girl, ManState[0].GetTop());
		ManState[1].SetTopLeft(ManState[1].GetLeft() - 2 + girl, ManState[1].GetTop());
	}
	else {
		ManState[1].ShowBitmap();
		ManState[0].SetTopLeft(ManState[0].GetLeft() + 2 + girl, ManState[0].GetTop());
		ManState[1].SetTopLeft(ManState[1].GetLeft() + 2 + girl, ManState[1].GetTop());
	}
}