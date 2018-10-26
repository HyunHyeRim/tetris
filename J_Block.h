//J_Block.h
#ifndef __J_BLOCK_H__
#define __J_BLOCK_H__

#include "Block.h"

class J_Block : public Block
{
public:
  J_Block();
  virtual void draw(int board[][10], int x, int y);
  virtual void rotate(int x, int y);
};

#endif //__J_BLOCK_H__
