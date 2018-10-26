//tetris.h
#ifndef __TETRIS_H__
#define __TETRIS_H__

#include "InfoPane.h"
#include "BoardPane.h"
#include "HelpPane.h"
#include "NextPane.h"
#include "StatPane.h"
#include "O_Block.h"
#include "L_Block.h"
#include "J_Block.h"
#include "S_Block.h"
#include "Z_Block.h"
#include "T_Block.h"
#include "I_Block.h"
#include <cstdlib>
#include <ctime>

#define ONE_SECOND 1000

class Tetris
{
private:
	int board[20][10];
	Pane *infoPane_, *helpPane_, *nextPane_, *boardPane_, *statPane_;
	Block *_block;
	int color;
public:
	Tetris();
	void updateScreen(char username[8]);
	char input_key();
	void move_block(char dir);
	bool update(char key);
	void display();
	void finalize();
	void NewBlock(Block *(&_block), int b_type);
	bool check_gameover();
	void print_board();
  static int x;
  static int y;
};


#endif //__TETRIS_H__
