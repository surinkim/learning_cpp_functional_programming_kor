// labyrinth.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* labyrinth.cpp */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int rows = 8;
const int cols = 8;

vector<vector<char>> createLabyrinth()
{
	// 다차원 벡터 labyrinth를 초기화한다.
	// #은 통과할 수 없는 벽이다.
	// S는 출발 지점, E는 도착 지점이다.
	vector<vector<char>> labyrinth =
	{
		{ '#', '#', '#', '#', '#', '#', '#', '#' },
		{ '#', 'S', ' ', ' ', ' ', ' ', ' ', '#' },
		{ '#', '#', '#', ' ', '#', '#', '#', '#' },
		{ '#', ' ', '#', ' ', '#', '#', '#', '#' },
		{ '#', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
		{ '#', ' ', '#', '#', '#', '#', '#', '#' },
		{ '#', ' ', ' ', ' ', ' ', ' ', 'F', '#' },
		{ '#', '#', '#', '#', '#', '#', '#', '#' }
	};

	return labyrinth;
}

void displayLabyrinth(vector<vector<char>> labyrinth)
{
	cout << endl;
	cout << "====================" << endl;
	cout << "The Labyrinth" << endl;
	cout << "====================" << endl;
	
	// 벡터 labyrinth를 출력한다.
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << labyrinth[i][j] << " ";
		}
		cout << endl;
	}
	cout << "====================" << endl << endl;
}

auto main() -> int
{
	vector<vector<char>> labyrinth = createLabyrinth();
	displayLabyrinth(labyrinth);

	string line;
	cout << endl << "Press enter to continue..." << endl;
	getline(cin, line);
	
	return 0;
}
