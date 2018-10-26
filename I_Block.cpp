#include "I_Block.h"

I_Block::I_Block()
{
	strcpy(block[0], "0100");
	strcpy(block[1], "0100");
	strcpy(block[2], "0100");
	strcpy(block[3], "0100");
}

void I_Block::draw(int board[][10], int x, int y)
{
  //moving_block
  wattron(win2_, COLOR_PAIR(13));
	for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
      if(block[i][j]=='1')
        mvwhline(win2_, x+i+1, 2*(y+j)+1, ACS_CKBOARD, 2);
  wattroff(win2_, COLOR_PAIR(13));
  wrefresh(win2_);
  print_score();
}


void I_Block::rotate(int x, int y)
{
  if(block[0][1]=='1' && y+3 < 10 && y>=0)
  {
    strcpy(block[0], "0000");
    strcpy(block[1], "1111");
    strcpy(block[2], "0000");
    strcpy(block[3], "0000");
  }
  else if(x+3 < 20)
  {
    strcpy(block[0], "0100");
  	strcpy(block[1], "0100");
  	strcpy(block[2], "0100");
  	strcpy(block[3], "0100");
  }
}
