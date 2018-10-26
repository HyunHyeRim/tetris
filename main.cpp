#include "Tetris.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

int main(int argc, char* argv[]) {
	Tetris t;
	std::ifstream inStream;
	bool isGameOver = false;
	char cur_key, username[8];
	int seed;
	// i) argc를 보고, 입력파일이 있으면 파일을 연다. (없으면 그냥 통과)
	if(argc > 1) inStream.open(argv[1], std::ios::in);
	// ii) 입력파일이 있으면 입력파일로부터 ‘사용자 이름’을 입력 받는다.
	if(argc > 1) inStream >> username;

	// 입력파일이 없으면 키보드로부터 ‘사용자 이름’을 입력 받는다.
	else
		std::cin >> username;
	// iii) 입력파일이 있으면 입력파일로부터 srand() 함수의 seed값을 입력 받는다.
	//입력파일이 없으면 time(NULL)을 통해 srand() 함수의 seed값을 무작위로 설정한다.
	if(argc > 1) inStream >> seed;
	else seed = time(NULL);
	srand(seed);
	// iv) 테트리스 게임의 초기 화면을 구성한다.

	t.updateScreen(username);

	// v) 종료될 때까지 게임을 진행한다.
	while(!isGameOver)
	{
		// 입력파일이 있으면 파일내용에 따라 블록의 위치를 조정한다.
		// 입력파일이 없으면 키보드 입력에 따라 블록의 위치를 조정한다.
		if (argc > 1) inStream >> cur_key;
		else cur_key = t.input_key();
		isGameOver = t.update(cur_key); // 입력 받은 키 처리를 담당한다.
		t.display(); // 키보드 처리 후의 화면을 출력한다.
		if(argc >1) usleep(300000);
	}
	// vi) 테트리스 게임에 쓰인 각종 리소스를 반환한다.
	t.finalize();
	return 0;
}
