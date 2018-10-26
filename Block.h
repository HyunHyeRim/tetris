//Block.h
#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <iostream>
#include <string.h>
#include <ncurses.h>

#define KEY_SPACE 32

class Block
{
protected:
  char block[4][5];
  int b_type;
  static int score;
  static bool input;
  WINDOW *win3_;
public:
  WINDOW *win2_;
  Block();
  virtual ~Block();
  bool init_block(int board[][10], int x, int y);
  bool move_down(int board[][10], int x, int y);
  bool move_left(int board[][10], int x, int y);
  bool move_right(int board[][10], int x, int y);
  void save_block(int board[][10], int x, int y, int color);
  void check_line(int board[][10], int x, int y);
  void print_score();
  virtual void draw(int board[][10], int x, int y);
  virtual void rotate(int x, int y);
  void erase(int board[][10], int x, int y);
};

#endif //__BLOCK_H__
