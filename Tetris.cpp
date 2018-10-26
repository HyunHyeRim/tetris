#include "Tetris.h"
#include "kbhit.h"

int Tetris::x = 0;
int Tetris::y = 4;

Tetris::Tetris()
{
	initscr();
	start_color();
	cbreak();
	refresh();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();
	srand(time(NULL));
	color = rand()%7 + 1;
	infoPane_ = new InfoPane(1,1,25,5);
	helpPane_ = new HelpPane(1,6,25,12);
	nextPane_ = new NextPane(1,18,25,5);
	boardPane_ = new BoardPane(30,1,22,22);
	statPane_ = new StatPane(57,3,20,20);
	for(int i=0; i<20; i++)
		for(int j=0; j<10; j++)
			board[i][j]=0;
	NewBlock(_block, color);
}

void Tetris::NewBlock(Block *(&_block), int b_type)
{
	if(!(check_gameover()))
	  x=0, y=4;

	switch (b_type)
	{
	case 1:
		_block = new O_Block();
		break;
	case 2:
		_block = new L_Block();
		break;
	case 3:
		_block = new J_Block();
		break;
	case 4:
		_block = new S_Block();
		break;
	case 5:
		_block = new Z_Block();
		break;
	case 6:
		_block = new T_Block();
		break;
	case 7:
		_block = new I_Block();
		break;
	}
}

void Tetris::finalize()
{
	delete infoPane_;
	delete helpPane_;
	delete nextPane_;
	delete boardPane_;
	delete statPane_;
	delete _block;
	endwin();
}


void Tetris::updateScreen(char username[8])
{
	infoPane_->draw(username);
	helpPane_->draw();
	nextPane_->draw();
	boardPane_->draw();
	statPane_->draw();
	_block->draw(board, x, y);
}

char Tetris::input_key()
{
	int key;
	while(kbhit()&&key!='q') getchar();
	while(1)
	{
		if(key=='q') {sleep(3000); break;}
		if(_block->move_down(board, x, y))
		{
			_block->erase(board, x, y);
			x++;
		}
		usleep(500000);
		_block->draw(board, x, y);

		if(kbhit()!=0)
		{
			key = getch();
			switch (key)
			{
				case KEY_LEFT:
					key = 'l';
					break;
				case KEY_RIGHT:
					key = 'r';
					break;
				case KEY_DOWN:
					key = 'g';
					break;
				case KEY_SPACE:
					key = 'd';
					break;
				case KEY_UP:
					key = 't';
					break;
			}
		}
		return key;
	}
}

void Tetris::move_block(char dir)
{
	_block->erase(board, x, y);
  switch(dir)
  {
    case 'g':
      if(_block->move_down(board, x, y)) x++;
      break;
    case 'l':
      if(_block->move_left(board, x, y)) y--;
      break;
    case 'r':
      if(_block->move_right(board, x, y)) y++;
      break;
    case 'd':
      while(_block->move_down(board, x, y)) x++;
      break;
    case 't':
      _block->rotate(x, y);
      break;
  }
	if(_block->move_down(board,x,y)==false)
	{
		_block->save_block(board, x, y, color);
		if(check_gameover()) return;
		_block->check_line(board, x, y);
		color = rand()%7 + 1;
		NewBlock(_block, color);
	}
}

bool Tetris::update(char key)
{
	if (key == 'q')
	{
		sleep(3000);
		return true;
	}
	if (check_gameover()) return true;
	move_block(key);
	return false;
}

bool Tetris::check_gameover()
{
	int _x = 0;
	int _y = 4;
	if((board[0][4]!=0)||board[0][5]!=0)
		return true;
	if (!_block->init_block(board, _x, _y))
		return false;
	return true;
}

void Tetris::display()
{
	for(int i=0; i<20; i++)
		for(int j=0; j<10; j++)
			if(board[i][j]!=0)
			{
				wattron(_block->win2_, COLOR_PAIR(board[i][j] + 6));
				mvwhline(_block->win2_, i+1, 2*j+1, ACS_CKBOARD, 2);
				wattroff(_block->win2_, COLOR_PAIR(board[i][j] + 6));
			}
	_block->draw(board, x, y);
}
