//T_Block.h
#ifndef __T_BLOCK_H__
#define __T_BLOCK_H__

#include "Block.h"

class T_Block : public Block
{
public:
  T_Block();
  virtual void draw(int board[][10], int x, int y);
  virtual void rotate(int x, int y);
};

#endif //__T_BLOCK_H__
