#include "Block.h"

int Block::score = 0;

Block::Block()
{
  win2_ = newwin(22,22,1,30);
  win3_ = newwin(5,5,5,60);

  init_pair(7, COLOR_YELLOW, COLOR_BLACK);
  init_pair(8, COLOR_BLUE, COLOR_BLACK);
  init_pair(9, COLOR_GREEN, COLOR_BLACK);
  init_pair(10, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(11, COLOR_RED, COLOR_BLACK);
  init_pair(12, COLOR_CYAN, COLOR_BLACK);
  init_pair(13, COLOR_WHITE, COLOR_BLACK);
  init_pair(14, COLOR_BLACK, COLOR_BLACK);
  wattron(win2_, COLOR_PAIR(8));
	box(win2_, 0, 0);
	wattroff(win2_, COLOR_PAIR(8));
  wrefresh(win2_);
}

Block::~Block()
{
  delwin(win2_);
  delwin(win3_);
}

bool Block::init_block(int board[][10], int x, int y)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (block[i][j] != '0')
				if (board[x + i][y + j] != 0)
					return false;
}

bool Block::move_down(int board[][10], int x, int y)
{
  for(int i=0; i<4; i++)
    for(int j=3; j>=0; j--)
      if(block[i][j]=='1')
        if(board[x+i+1][y+j]!=0 || x+i+2> 20)
          return false;
        else continue;
  return true;
}

bool Block::move_left(int board[][10], int x, int y)
{
  for(int i=0; i<4; i++)
    for(int j=0; j<4; j++)
      if(block[i][j]=='1')
        if(board[x+i+1][y+j-1]!=0 || y+j-1 < 0)
          return false;
        else continue;
  return true;
}

bool Block::move_right(int board[][10], int x, int y)
{
  for(int i=0; i<4; i++)
    for(int j=3; j>=0; j--)
      if(block[i][j]=='1')
        if(board[x+i+1][y+j+1]==1 || y+j+2 > 10)
          return false;
        else continue;
  return true;
}

void Block::draw(int board[][10], int x, int y) {}
void Block::rotate(int x, int y) {}

void Block::erase(int board[][10], int x, int y)
{
  wattron(win2_, COLOR_PAIR(14));
	for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
      if(block[i][j]=='1')
        mvwhline(win2_, x+i+1, 2*(y+j)+1, ACS_CKBOARD, 2);
  wattroff(win2_, COLOR_PAIR(14));
}

void Block::save_block(int board[][10], int x, int y, int color)
{
  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
      if(block[i][j]!='0')
        board[x+i][y+j]=color;
}

void Block::check_line(int board[][10], int x, int y)
{
  int i=19;
  bool full, clear;
  while(i>0)
  {
    full=true;
    for(int j=0; j<10; j++)
      if(board[i][j]==0)
      {
        full = false;
        break;
      }

    if(full==true)
    {
      score++;
      for(int j=0; j<10; j++)
        board[i][j] = 0;
    }
    i--;
  }
  for(int i=0; i<20; i++)
  {
    clear = true;
    for(int j=0; j<10; j++)
      if(board[i][j]!=0)
      {
        clear = false;
        break;
      }
    if(clear==true)
    {
      for(int j=i; j>0; j--)
        for(int k=0; k<10; k++)
        {
          board[j][k] = board[j-1][k];
          board[0][k] = 0;
        }
    }
  }
}

void Block::print_score()
{
  init_pair(15, COLOR_RED, COLOR_BLACK);
	wattron(win3_, COLOR_PAIR(15));
	mvwprintw(win3_, 0, 0, "SCORE: %d", score);
	wattroff(win3_, COLOR_PAIR(15));
	wrefresh(win3_);
}
