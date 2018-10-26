#include "O_Block.h"

O_Block::O_Block()
{
  strcpy(block[0], "1100");
  strcpy(block[1], "1100");
  strcpy(block[2], "0000");
  strcpy(block[3], "0000");
}

void O_Block::draw(int board[][10], int x, int y)
{
  //moving_block
  wattron(win2_, COLOR_PAIR(7));
	for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
      if(block[i][j]=='1')
        mvwhline(win2_, x+i+1, 2*(y+j)+1, ACS_CKBOARD, 2);
  wattroff(win2_, COLOR_PAIR(7));
  wrefresh(win2_);
  print_score();
}

void O_Block::rotate(int x, int y)
{
  strcpy(block[0], "1100");
  strcpy(block[1], "1100");
  strcpy(block[2], "0000");
  strcpy(block[3], "0000");
}
