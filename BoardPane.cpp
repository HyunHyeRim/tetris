#include "BoardPane.h"

BoardPane::BoardPane(int x, int y, int w, int h) : Pane(x,y,w,h){}

void BoardPane::draw()
{
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	// init_pair(4, COLOR_BLACK, COLOR_BLACK);
	wattron(win_, COLOR_PAIR(3));
	box(win_, 0, 0);
	wattroff(win_, COLOR_PAIR(3));
	// wattron(win_, COLOR_PAIR(4));
	// for (int i=1; i<height_-1; i++)
  //     mvwhline(win_, i, 1, ACS_CKBOARD, width_-2);
	// wattroff(win_, COLOR_PAIR(4));
	wrefresh(win_);
}
