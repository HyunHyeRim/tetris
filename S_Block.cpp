#include "S_Block.h"

S_Block::S_Block()
{
  strcpy(block[0], "0100");
  strcpy(block[1], "0110");
  strcpy(block[2], "0010");
  strcpy(block[3], "0000");
}

void S_Block::draw(int board[][10], int x, int y)
{
  //moving_block
  wattron(win2_, COLOR_PAIR(10));
	for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
      if(block[i][j]=='1')
        mvwhline(win2_, x+i+1, 2*(y+j)+1, ACS_CKBOARD, 2);
  wattroff(win2_, COLOR_PAIR(10));
  wrefresh(win2_);
  print_score();
}

void S_Block::rotate(int x, int y)
{
  if(block[2][2]=='1' && y>=0)
  {
    strcpy(block[0], "0110");
    strcpy(block[1], "1100");
    strcpy(block[2], "0000");
    strcpy(block[3], "0000");
  }
  else if(block[1][0]=='1' && x+2<20)
  {
    strcpy(block[0], "0100");
    strcpy(block[1], "0110");
    strcpy(block[2], "0010");
    strcpy(block[3], "0000");
  }
}
