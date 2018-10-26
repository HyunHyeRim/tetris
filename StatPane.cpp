#include "StatPane.h"
#include "Block.h"


StatPane::StatPane(int x, int y, int w, int h) : Pane(x,y,w,h){}

void StatPane::draw()
{
	init_pair(5, COLOR_RED, COLOR_BLACK);
	wattron(win_, COLOR_PAIR(5));
	box(win_, 0, 0);
	mvwprintw(win_, 0, 5, "STATISTICS");
	wattroff(win_, COLOR_PAIR(5));
	wrefresh(win_);
}
