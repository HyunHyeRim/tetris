CC = g++
TARGET = tetris
SOURCES = Pane.cpp\
					InfoPane.cpp\
					BoardPane.cpp\
					StatPane.cpp\
					NextPane.cpp\
					HelpPane.cpp\
					Block.cpp\
					O_Block.cpp\
					L_Block.cpp\
					J_Block.cpp\
					S_Block.cpp\
					Z_Block.cpp\
					T_Block.cpp\
					I_Block.cpp\
					Tetris.cpp\
					main.cpp

LDFLAGS = -lncurses
OPTIONS = -g

all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS) $(OPTIONS)
clean:
	rm -rf *.o $(TARGET)
