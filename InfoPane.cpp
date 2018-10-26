#include "InfoPane.h"

InfoPane::InfoPane(int x, int y, int w, int h) : Pane(x,y,w,h)
{}

void InfoPane::draw(char username[8])
{
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	wattron(win_, COLOR_PAIR(6));

	for (int i=0; i<height_; i++)
		mvwhline(win_, i, 0, ACS_CKBOARD, width_);

	mvwprintw(win_, 0,0, "INFO PANE");
	mvwprintw(win_, 1,0, username);
	wattroff(win_, COLOR_PAIR(6));
	wrefresh(win_);
}
