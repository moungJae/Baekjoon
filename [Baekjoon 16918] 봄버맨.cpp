#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>

#define ll long long

using namespace std;

int R, C, N;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char Map[201][201], tmp[201][201];

void input() 
{
	string s;

	cin >> R >> C >> N;
	for (int i = 0; i < R; i++)
	{
		cin >> s;
		for (int j = 0; j < C; j++)
		{
			Map[i][j] = s[j];
			tmp[i][j] = 'O';
		}
	}
}

void show_map(char Map[][201])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << Map[i][j];
		cout << endl;
	}
}

void bfs(char Map[][201])
{
	queue<pair<int, int>> Q;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (Map[i][j] == 'O') Q.push({ i,j });
			else Map[i][j] = 'O';
		}
	}
	while (!Q.empty())
	{
		int x = Q.front().first, y = Q.front().second;
		Q.pop();

		Map[x][y] = '.';
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i], next_y = y + dy[i];
			if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C)
				Map[next_x][next_y] = '.';
		}
	}
}

void map_cpy(char dest[][201], char src[][201])
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			dest[i][j] = src[i][j];
}

void solution()
{
	char before[201][201], cur[201][201];
	
	if (N == 1)
	{
		show_map(Map);
		return;
	}

	map_cpy(cur, Map);
	for (int i = 2; i <= N; i++)
	{
		if (i % 4 == 2)
		{
			map_cpy(before, cur);
			map_cpy(cur, tmp);
		}
		else if (i % 4 == 3)
		{
			bfs(before);
			map_cpy(cur, before);
		}
		else if (i % 4 == 0)
		{
			map_cpy(before, cur);
			map_cpy(cur, tmp);
		}
		else
		{
			bfs(before);
			map_cpy(cur, before);
		}
	}
	show_map(cur);
}

int main()
{
	input();
	solution();

	return 0;
}