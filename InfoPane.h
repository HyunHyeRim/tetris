//infoPane.h
#ifndef __INFOPANE_H__
#define __INFOPANE_H__
#include "Pane.h"

class InfoPane : public Pane
{
public:
	char username[8];
	InfoPane(int x, int y, int w, int h);
	void draw(char username[8]);
};

#endif //__INFOPANE_H__
