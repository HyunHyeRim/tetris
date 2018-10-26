//Z_Block.h
#ifndef __Z_BLOCK_H__
#define __Z_BLOCK_H__

#include "Block.h"

class Z_Block : public Block
{
public:
  Z_Block();
  virtual void draw(int board[][10], int x, int y);
  virtual void rotate(int x, int y);
  // virtual void save_block(int board[][10], int x, int y);
};

#endif //__Z_BLOCK_H__
