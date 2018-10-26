//L_Block.h
#ifndef __L_BLOCK_H__
#define __L_BLOCK_H__

#include "Block.h"

class L_Block : public Block
{
public:
  L_Block();
  virtual void draw(int board[][10], int x, int y);
  virtual void rotate(int x, int y);
};

#endif //__L_BLOCK_H__
