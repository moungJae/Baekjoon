#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>

#define ll long long

using namespace std;

int R, C;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N, M;
int Map[101][101];

class Info
{
public : 
	int robot, iter;
	char command;
	Info(int robot, char command, int iter)
	{
		this->robot = robot;
		this->command = command;
		this->iter = iter;
	}
};

class Robot
{
public :
	int x, y;
	char direction;
	Robot() {}
	Robot(int x, int y, char direction)
	{
		this->x = x;
		this->y = y;
		this->direction = direction;
	}
};

queue<Info> Query;
Robot info[101];

void input()
{
	int x, y;
	int robot, iter;
	char command, direction;

	cin >> C >> R;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> y >> x >> direction;
		Map[x][y] = i;
		info[i].x = x, info[i].y = y;
		info[i].direction = direction;
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> robot >> command >> iter;
		Query.push({ robot, command, iter });
	}
}

bool is_in(int x, int y)
{
	return (x >= 1 && x <= R && y >= 1 && y <= C);
}

void operation_L(int robot)
{
	char direction;

	direction = info[robot].direction;
	if (direction == 'N')
		direction = 'W';
	else if (direction == 'W')
		direction = 'S';
	else if (direction == 'S')
		direction = 'E';
	else if (direction == 'E')
		direction = 'N';
	info[robot].direction = direction;
}

void operation_R(int robot)
{
	char direction;

	direction = info[robot].direction;
	if (direction == 'N')
		direction = 'E';
	else if (direction == 'W')
		direction = 'N';
	else if (direction == 'S')
		direction = 'W';
	else if (direction == 'E')
		direction = 'S';
	info[robot].direction = direction;
}

bool operation_F(int robot)
{
	int x, y, next_x, next_y;
	char direction;

	x = info[robot].x, y = info[robot].y;
	direction = info[robot].direction;
	if (direction == 'N')
		next_x = x + 1, next_y = y;
	else if (direction == 'S')
		next_x = x - 1, next_y = y;
	else if (direction == 'E')
		next_x = x, next_y = y + 1;
	else if (direction == 'W')
		next_x = x, next_y = y - 1;

	if (!is_in(next_x, next_y))
	{
		cout << "Robot " << robot << " crashes into the wall" << endl;
		return false;
	}
	if (Map[next_x][next_y])
	{
		cout << "Robot " << robot << " crashes into robot " << Map[next_x][next_y] << endl;
		return false;
	}
	Map[x][y] = 0, Map[next_x][next_y] = robot;
	info[robot].x = next_x, info[robot].y = next_y;
	return true;
}

void solution()
{
	int robot, iter;
	char command;

	while (!Query.empty())
	{
		robot = Query.front().robot, iter = Query.front().iter;
		command = Query.front().command;
		Query.pop();

		while (iter--)
		{
			if (command == 'L')
				operation_L(robot);
			else if (command == 'R')
				operation_R(robot);
			else if (command == 'F')
			{
				if (!operation_F(robot))
					return;
			}
		}
	}
	cout << "OK";
}

int main()
{
	input();
	solution();

	return 0;
}