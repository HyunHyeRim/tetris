#include "J_Block.h"

J_Block::J_Block()
{
  strcpy(block[0], "0100");
  strcpy(block[1], "0100");
	strcpy(block[2], "1100");
	strcpy(block[3], "0000");
}

void J_Block::draw(int board[][10], int x, int y)
{
  //moving_block
  wattron(win2_, COLOR_PAIR(9));
	for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
      if(block[i][j]=='1')
        mvwhline(win2_, x+i+1, 2*(y+j)+1, ACS_CKBOARD, 2);
  wattroff(win2_, COLOR_PAIR(9));
  wrefresh(win2_);
  print_score();
}

void J_Block::rotate(int x, int y)
{
  if(block[2][0]=='1' && y+2<10)
  {
    strcpy(block[0], "0000");
    strcpy(block[1], "1110");
    strcpy(block[2], "0010");
    strcpy(block[3], "0000");
  }
  else if(block[2][2]=='1')
  {
    strcpy(block[0], "0110");
    strcpy(block[1], "0100");
    strcpy(block[2], "0100");
    strcpy(block[3], "0000");
  }
  else if(block[0][2]=='1'&& y+1>0)
  {
    strcpy(block[0], "1000");
    strcpy(block[1], "1110");
    strcpy(block[2], "0000");
    strcpy(block[3], "0000");
  }
  else if(block[0][0]=='1')
  {
    strcpy(block[0], "0100");
    strcpy(block[1], "0100");
  	strcpy(block[2], "1100");
  	strcpy(block[3], "0000");
  }
}
