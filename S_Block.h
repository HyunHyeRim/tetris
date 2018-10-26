//S_Block.h
#ifndef __S_BLOCK_H__
#define __S_BLOCK_H__

#include "Block.h"

class S_Block : public Block
{
public:
  S_Block();
  virtual void draw(int board[][10], int x, int y);
  virtual void rotate(int x, int y);
  // virtual void save_block(int board[][10], int x, int y);
};

#endif //__S_BLOCK_H__
