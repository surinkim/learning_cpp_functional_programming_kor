// labyrinth.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* labyrinth.cpp */
#include <iostream>
#include <vector>
#include <string>

#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * x)
#endif

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

bool navigate(
	vector<vector<char>> labyrinth,
	int row,
	int col)
{
	// labyrinth 출력
	displayLabyrinth(labyrinth);

	cout << "Checking cell (";
	cout << row << "," << col << ")" << endl;

	// 미로 탐색 과정을 명확히 보여주기 위해
	// 경로 탐색 전에 1초 대기한다.
	sleep(1);
	
	if (labyrinth[row][col] == 'F')
	{
		cout << "Yeayy.. ";
		cout << "Found the finish flag ";
		cout << "at point (" << row << ",";
		cout << col << ")" << endl;
		return (true);
	}
	else if (
		labyrinth[row][col] == '#' ||
		labyrinth[row][col] == '*')
	{
		return (false);
	}
	else if (labyrinth[row][col] == ' ')
	{
		labyrinth[row][col] = '*';
	}

	if ((row + 1 < rows) &&
		navigate(labyrinth, row + 1, col))
	return (true);

	if ((col + 1 < cols) &&
		navigate(labyrinth, row, col + 1))
		return (true);
	
	if ((row - 1 >= 0) &&
		navigate(labyrinth, row - 1, col))
		return (true);
	
	if ((col - 1 >= 0) &&
		navigate(labyrinth, row, col - 1))
		return (true);
	
	return (false);
}

bool isLabyrinthSolvable(
	vector<vector<char>> labyrinth)
{
	int start_row = -1;
	int start_col = -1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (labyrinth[i][j] == 'S')
			{
				start_row = i;
				start_col = j;
				break;
			}
		}
	}

	if (start_row == -1 || start_col == -1)
	{
		cerr << "No valid starting point found!" << endl;
		return (false);
	}
	
	cout << "Starting at point (" << start_row << ",";	
	cout << start_col << ")" << endl;
	
	return navigate(labyrinth, start_row, start_col);
}

auto main() -> int
{
	vector<vector<char>> labyrinth = createLabyrinth();
	displayLabyrinth(labyrinth);

	string line;
	cout << endl << "Press enter to continue..." << endl;
	getline(cin, line);

	if (isLabyrinthSolvable(labyrinth))
		cout << "Labyrinth solved!" << endl;
	else
		cout << "Labyrinth could not be solved!" << endl;	
	return 0;
}

