//I_Block.h
#ifndef __I_BLOCK_H__
#define __I_BLOCK_H__

#include "Block.h"

class I_Block : public Block
{
public:
  I_Block();
  virtual void draw(int board[][10], int x, int y);
  virtual void rotate(int x, int y);
  // virtual void save_block(int board[][10], int x, int y);
};

#endif //__I_BLOCK_H__
