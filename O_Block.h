//O_Block.h
#ifndef __O_BLOCK_H__
#define __O_BLOCK_H__

#include "Block.h"

class O_Block : public Block
{
public:
  O_Block();
  virtual void draw(int board[][10], int x, int y);
  virtual void rotate(int x, int y);
  // virtual void save_block(int board[][10], int x, int y);
};

#endif //__O_BLOCK_H__
