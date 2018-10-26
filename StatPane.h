//statPane.h
#ifndef __STATPANE_H__
#define __STATPANE_H__
#include "Pane.h"

class StatPane : public Pane
{
private:
	int score_;
public:
	StatPane(int x, int y, int w, int h);
	void draw();
};

#endif //__STATPANE_H__
