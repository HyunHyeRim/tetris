#ifndef __HELP_H__
#define __HELP_H__
#include "Pane.h"

class HelpPane : public Pane
{
public:
    HelpPane(int x, int y, int w, int h);
    void draw();
};

#endif
