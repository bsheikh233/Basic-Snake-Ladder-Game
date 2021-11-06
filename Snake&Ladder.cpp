#include<iostream>
#include"graphics.h"
#pragma warning(disable : 4996)
#include <dos.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
void box(int number)
{
	int x = 0, xPos = 0, yPos = 0, times = 0, rowNum = 0;
	char ch[3];
	sprintf(ch, "%d", number);
	if (number % 6 == 0)
	{
		times = 5;
		rowNum = (number / 6) - 1;
	}
	else
	{
		times = (number % 6) - 1;
		rowNum = number / 6;
	}
	yPos = 600 - (rowNum * 100);
	if (number % 2 == 0)
	{
		setfillstyle(SOLID_FILL, RED);
	}
	else
	{
		setfillstyle(SOLID_FILL, GREEN);
	}
	if (rowNum % 2 == 0)
	{
		x = 150;
		xPos = x + (150 * times);
		outtextxy(xPos + 70, yPos - 55, ch);
		rectangle(xPos, yPos, xPos + 150, yPos - 100);  //x1,y1,x2,y2
		floodfill(xPos + 70, yPos - 40, WHITE);
	}
	else
	{
		x = 1050;
		xPos = x - (150 * times);
		outtextxy(xPos - 80, yPos - 55, ch);
		rectangle(xPos, yPos, xPos - 150, yPos - 100);  //x1,y1,x2,y2
		floodfill(xPos - 70, yPos - 40, WHITE);
	}
}
int position(int value, int& yPos)
{
	int leftXPos = 25, rightXPos = 1125;
	int times = 0, rowNum = 0, xPosition = 0;
	if (value % 6 == 0)
	{
		times = 6;
		rowNum = (value / 6) - 1;
	}
	else
	{
		times = (value % 6);
		rowNum = value / 6;
	}

	if (rowNum % 2 == 0)
	{
		xPosition = leftXPos + (150 * times);
	}
	else
	{
		xPosition = rightXPos - (150 * times);
	}
	yPos = 540 - (rowNum * 100);
	return xPosition;
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	char diceVal[2];
	int val1 = 0, val2 = 0, valueDice = 0;
	srand(time(NULL));
	int xPos1 = 25, yPos1 = 540, xPos2 = 25, yPos2 = 540;
	initwindow(1300, 1000);
	for (int programRun = 1;; programRun++)
	{
		initwindow(1300, 1000);
		cleardevice();


		char ch;
		for (int i = 1; i <= 30; i++)
		{
			box(i);
		}

		//ladder 3to22
		setfillstyle(SOLID_FILL, WHITE);
		rectangle(480, 250, 485, 550);//vertical left 
		floodfill(482, 251, WHITE);
		floodfill(482, 350, WHITE);
		floodfill(482, 450, WHITE);
		floodfill(482, 540, WHITE);
		rectangle(570, 250, 575, 550);//vertical right
		floodfill(572, 251, WHITE);
		floodfill(572, 350, WHITE);
		floodfill(572, 450, WHITE);
		floodfill(572, 540, WHITE);

		rectangle(485, 525, 570, 530);// 3..horizontal
		floodfill(488, 527, WHITE);
		rectangle(485, 475, 570, 480);//b/w 3 and 10..horizontal
		floodfill(488, 477, WHITE);
		rectangle(485, 420, 570, 425);//10..horizontal
		floodfill(488, 422, WHITE);
		rectangle(485, 370, 570, 375);//15... horizontal
		floodfill(488, 372, WHITE);
		rectangle(485, 315, 570, 320);//15 b/w 22..horizontal
		floodfill(488, 317, WHITE);
		rectangle(485, 265, 570, 270);//22.. horizontal
		floodfill(488, 267, WHITE);

		//ladder 5to8
		setfillstyle(SOLID_FILL, WHITE);

		line(765, 452, 835, 562);//left ftsrt
		line(770, 450, 840, 560);//left scnd
		line(765, 452, 770, 450);//upper
		line(835, 562, 840, 560);//lower
		floodfill(769, 451, WHITE);
		floodfill(836, 559, WHITE);


		line(810, 425, 880, 535);
		line(815, 423, 885, 533);
		line(815, 423, 810, 425);
		line(885, 533, 880, 535);
		floodfill(812, 427, WHITE);
		floodfill(882, 532, WHITE);

		line(782, 472, 825, 447);
		line(785, 476, 828, 451);
		floodfill(785, 472, WHITE);

		line(805, 506, 848, 485);
		line(808, 510, 851, 489);
		floodfill(808, 506, WHITE);
		floodfill(848, 489, WHITE);

		line(830, 542, 871, 517);
		line(833, 546, 873, 521);
		floodfill(833, 542, WHITE);


		/*rectangle(780, 430, 785, 570);//vertical left
		rectangle(870, 430, 875, 570);//vertical right

		rectangle(785, 460, 870, 465);//8
		rectangle(785, 500, 870, 505);//b/w 5 and 8
		rectangle(785, 530, 870, 535);//5*/

		//ladder 11to26
		rectangle(330, 130, 335, 470);//vertical left 
		floodfill(332, 133, WHITE);
		floodfill(332, 460, WHITE);
		floodfill(332, 251, WHITE);
		floodfill(332, 350, WHITE);
		rectangle(420, 130, 425, 470);//vertical right
		floodfill(423, 133, WHITE);
		floodfill(423, 460, WHITE);
		floodfill(423, 251, WHITE);
		floodfill(423, 350, WHITE);

		rectangle(335, 150, 420, 155);// 26
		floodfill(338, 152, WHITE);
		floodfill(418, 152, WHITE);
		rectangle(335, 210, 420, 215);//above 23
		floodfill(338, 212, WHITE);
		rectangle(335, 275, 420, 280);//below 23
		floodfill(338, 277, WHITE);
		rectangle(335, 325, 420, 330);//above 14
		floodfill(338, 328, WHITE);
		rectangle(335, 375, 420, 380);//below 14
		floodfill(338, 377, WHITE);
		rectangle(335, 435, 420, 440);//11
		floodfill(338, 438, WHITE);

		//ladder 20to19
		rectangle(780, 130, 785, 270);//vertical left 
		floodfill(782, 138, WHITE);
		floodfill(782, 265, WHITE);
		rectangle(870, 130, 875, 270);//vertical right
		floodfill(872, 138, WHITE);
		floodfill(872, 265, WHITE);

		rectangle(785, 140, 870, 145);//29
		floodfill(788, 142, WHITE);
		rectangle(785, 200, 870, 205);//b/w
		floodfill(788, 202, WHITE);
		rectangle(785, 255, 870, 260);//20
		floodfill(788, 257, WHITE);

		//player 2
		setfillstyle(SOLID_FILL, BLUE);
		outtextxy(xPos2 - 2, yPos2 + 18, "2");
		circle(xPos2, yPos2 + 25, 17);
		floodfill(xPos2 + 4, yPos2 + 20, WHITE);

		//player 1
		setfillstyle(SOLID_FILL, BROWN);
		outtextxy(xPos1 - 2, yPos1 - 8, "1");
		circle(xPos1, yPos1, 17);
		floodfill(xPos1 + 4, yPos1 - 10, WHITE);

		//snakes
		setfillstyle(SOLID_FILL, BLACK);
		setcolor(YELLOW);
		circle(966, 266, 3);
		floodfill(966, 266, YELLOW);
		circle(959, 262, 3);
		floodfill(959, 262, YELLOW);

		setfillstyle(SOLID_FILL, YELLOW);

		//19 to 7
		circle(962, 268, 13);
		floodfill(962, 268, YELLOW);
		circle(945, 285, 14);
		floodfill(945, 285, YELLOW);
		circle(948, 309, 13);
		floodfill(950, 307, YELLOW);
		circle(969, 319, 12);
		floodfill(969, 319, YELLOW);
		circle(986, 327, 11);
		floodfill(986, 327, YELLOW);
		circle(999, 342, 12);
		floodfill(997, 340, YELLOW);
		circle(990, 360, 11);
		floodfill(990, 360, YELLOW);
		circle(984, 381, 10);
		floodfill(985, 383, YELLOW);
		circle(980, 399, 9);
		floodfill(980, 399, YELLOW);
		floodfill(980, 402, YELLOW);
		circle(970, 410, 8);
		floodfill(970, 410, YELLOW);
		circle(965, 424, 7);
		floodfill(965, 425, YELLOW);
		circle(962, 433, 6);
		floodfill(962, 433, YELLOW);

		//21 to 9
		setfillstyle(SOLID_FILL, BLACK);
		setcolor(YELLOW);
		circle(660, 251, 3);
		floodfill(660, 251, YELLOW);
		circle(668, 257, 3);
		floodfill(668, 257, YELLOW);

		setfillstyle(SOLID_FILL, YELLOW);
		circle(662, 257, 13);
		floodfill(662, 257, YELLOW);
		circle(650, 273, 14);
		floodfill(650, 273, YELLOW);
		circle(638, 292, 13);
		floodfill(638, 292, YELLOW);
		circle(645, 309, 13);
		floodfill(645, 309, YELLOW);
		circle(662, 321, 12);
		floodfill(662, 321, YELLOW);
		circle(677, 336, 11);
		floodfill(677, 336, YELLOW);
		circle(690, 350, 12);
		floodfill(690, 350, YELLOW);
		circle(700, 365, 13);
		floodfill(702, 365, YELLOW);
		circle(692, 382, 11);
		floodfill(692, 382, YELLOW);
		circle(680, 396, 10);
		floodfill(678, 398, YELLOW);
		circle(668, 410, 9);
		floodfill(668, 410, YELLOW);
		circle(658, 422, 8);
		floodfill(658, 422, YELLOW);
		circle(650, 430, 7);
		floodfill(650, 430, YELLOW);
		circle(653, 437, 6);
		floodfill(653, 437, YELLOW);
		circle(657, 442, 5);
		floodfill(657, 442, YELLOW);


		//17 to 4
		setfillstyle(SOLID_FILL, BLACK);
		setcolor(DARKGRAY);
		circle(809, 337, 3);
		floodfill(809, 337, DARKGRAY);
		circle(815, 331, 3);
		floodfill(815, 331, DARKGRAY);
		setfillstyle(SOLID_FILL, DARKGRAY);
		circle(810, 330, 13);
		floodfill(810, 330, DARKGRAY);
		circle(795, 317, 13);
		floodfill(795, 320, DARKGRAY);
		circle(781, 307, 14);
		floodfill(783, 310, DARKGRAY);
		circle(765, 298, 14);
		floodfill(765, 298, DARKGRAY);
		circle(747, 289, 15);
		floodfill(747, 287, DARKGRAY);
		circle(730, 288, 14);
		floodfill(730, 290, DARKGRAY);
		circle(715, 291, 13);
		floodfill(715, 293, DARKGRAY);
		circle(701, 300, 12);
		floodfill(701, 300, DARKGRAY);
		circle(687, 313, 13);
		floodfill(690, 315, DARKGRAY);
		circle(675, 322, 14);
		floodfill(678, 324, DARKGRAY);
		circle(662, 338, 13);
		floodfill(665, 340, DARKGRAY);
		circle(651, 352, 12);
		floodfill(653, 352, DARKGRAY);
		circle(642, 370, 13);
		floodfill(640, 370, DARKGRAY);
		circle(642, 388, 12);
		floodfill(642, 388, DARKGRAY);
		circle(650, 408, 12);
		floodfill(650, 408, DARKGRAY);
		circle(663, 419, 13);
		floodfill(663, 419, DARKGRAY);
		circle(677, 430, 12);
		floodfill(677, 430, DARKGRAY);
		circle(693, 440, 12);
		floodfill(690, 440, DARKGRAY);
		circle(703, 450, 13);
		floodfill(703, 450, DARKGRAY);
		circle(711, 460, 14);
		floodfill(711, 460, DARKGRAY);
		circle(707, 477, 13);
		floodfill(707, 477, DARKGRAY);
		circle(697, 487, 12);
		floodfill(697, 487, DARKGRAY);
		circle(685, 497, 11);
		floodfill(685, 497, DARKGRAY);
		circle(675, 507, 10);
		floodfill(675, 507, DARKGRAY);
		circle(666, 517, 9);
		floodfill(665, 517, DARKGRAY);
		circle(657, 525, 8);
		floodfill(657, 525, DARKGRAY);

		//27 to 1
		setfillstyle(SOLID_FILL, BLACK);
		setcolor(DARKGRAY);
		circle(517, 150, 3);
		floodfill(517, 150, DARKGRAY);
		circle(511, 143, 3);
		floodfill(511, 143, DARKGRAY);
		setfillstyle(SOLID_FILL, DARKGRAY);
		circle(510, 150, 13);
		floodfill(510, 150, DARKGRAY);
		circle(497, 160, 13);
		floodfill(497, 160, DARKGRAY);
		circle(480, 170, 14);
		floodfill(480, 170, DARKGRAY);
		circle(465, 180, 13);
		floodfill(465, 180, DARKGRAY);
		circle(450, 190, 13);
		floodfill(453, 190, DARKGRAY);
		circle(435, 200, 12);
		floodfill(438, 200, DARKGRAY);
		circle(420, 210, 13);
		floodfill(420, 213, DARKGRAY);
		circle(402, 220, 14);
		floodfill(402, 220, DARKGRAY);
		circle(388, 230, 14);
		floodfill(388, 232, DARKGRAY);
		circle(377, 244, 14);
		floodfill(378, 244, DARKGRAY);
		circle(365, 258, 13);
		floodfill(365, 258, DARKGRAY);
		circle(353, 271, 13);
		floodfill(353, 270, DARKGRAY);
		circle(342, 284, 12);
		floodfill(342, 285, DARKGRAY);
		circle(333, 298, 12);
		floodfill(333, 298, DARKGRAY);
		circle(327, 315, 13);
		floodfill(322, 315, DARKGRAY);
		circle(330, 328, 13);
		floodfill(330, 328, DARKGRAY);
		circle(338, 343, 13);
		floodfill(338, 343, DARKGRAY);
		circle(343, 357, 13);
		floodfill(345, 357, DARKGRAY);
		circle(342, 370, 12);
		floodfill(342, 370, DARKGRAY);
		circle(335, 383, 12);
		floodfill(333, 383, DARKGRAY);
		circle(326, 398, 13);
		floodfill(326, 398, DARKGRAY);
		circle(318, 412, 13);
		floodfill(318, 412, DARKGRAY);
		circle(306, 427, 13);
		floodfill(306, 427, DARKGRAY);
		circle(297, 440, 12);
		floodfill(297, 440, DARKGRAY);
		circle(285, 454, 13);
		floodfill(285, 452, DARKGRAY);
		circle(273, 467, 13);
		floodfill(273, 467, DARKGRAY);
		circle(260, 480, 12);
		floodfill(260, 480, DARKGRAY);
		circle(248, 494, 12);
		floodfill(247, 495, DARKGRAY);
		circle(234, 508, 12);
		floodfill(234, 507, DARKGRAY);
		circle(222, 520, 11);
		floodfill(222, 520, DARKGRAY);
		circle(210, 533, 10);
		floodfill(210, 533, DARKGRAY);

		//text for turn
		if (programRun % 2 == 1)
		{
			outtextxy(150, 50, " it's player 1 turn. Please press any key");
			getch();
		}
		else
		{
			outtextxy(150, 50, " it's player 2 turn. Please press any key");
			getch();
		}
		valueDice = (rand() % 6) + 1;
		sprintf(diceVal, "%d", valueDice);
		outtextxy(150, 70, diceVal);
		delay(1500);
		if (programRun % 2 == 1)
		{
			xPos1 = 50, yPos1 = 540;
			val1 += valueDice;
			switch (val1)
			{
			case 3: val1 = 22;
				break;

			case 5: val1 = 8;
				break;

			case 11: val1 = 26;
				break;

			case 17: val1 = 4;
				break;

			case 19: val1 = 7;
				break;

			case 20: val1 = 29;
				break;

			case 21: val1 = 9;
				break;

			case 27: val1 = 1;
				break;
			}
			xPos1 = position(val1, yPos1);
		}
		else
		{
			xPos2 = 50, yPos2 = 540;
			val2 += valueDice;
			switch (val2)
			{
			case 3: val2 = 22;
				break;

			case 5: val2 = 8;
				break;

			case 11: val2 = 26;
				break;

			case 17: val2 = 4;
				break;

			case 19: val2 = 7;
				break;

			case 20: val2 = 29;
				break;

			case 21: val2 = 9;
				break;

			case 27: val2 = 1;
				break;
			}
			xPos2 = position(val2, yPos2);
		}

	}



	system("pause");
	return 0;
}