#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>
#include <string>
#include <map>

#define ll long long

using namespace std;

int N;
int info[51][10], order[10];

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 9; j++)
			cin >> info[i][j];
}

int operation(int op, int pos[], int* out)
{
	int point;

	point = 0;
	if (op == 1)
	{
		if (pos[2]) pos[2] = 0, point++;
		if (pos[1]) pos[1] = 0, pos[2] = 1;
		if (pos[0]) pos[0] = 0, pos[1] = 1;
		pos[0] = 1;
	}
	else if (op == 2)
	{
		if (pos[2]) pos[2] = 0, point++;
		if (pos[1]) pos[1] = 0, point++;
		if (pos[0]) pos[0] = 0, pos[2] = 1;
		pos[1] = 1;
	}
	else if (op == 3)
	{
		if (pos[2]) pos[2] = 0, point++;
		if (pos[1]) pos[1] = 0, point++;
		if (pos[0]) pos[0] = 0, point++;
		pos[2] = 1;
	}
	else if (op == 4)
	{
		if (pos[2]) pos[2] = 0, point++;
		if (pos[1]) pos[1] = 0, point++;
		if (pos[0]) pos[0] = 0, point++;
		point++;
	}
	else
	{
		*out += 1;
	}
	return point;
}

int play()
{
	int point, cur, out, op, pos[3];

	point = 0, cur = 1;
	for (int i = 1; i <= N; i++)
	{
		pos[0] = pos[1] = pos[2] = out = 0;
		while (1)
		{
			op = info[i][order[cur]];
			point += operation(op, pos, &out);
			cur = (cur + 1 > 9 ? 1 : cur + 1);
			if (out == 3)
				break;
		}
	}
	return point;
}

int go(int n)
{
	int ret = 0;

	if (n > 9)
		return play();
	for (int i = 1; i <= 9; i++)
	{
		if (order[i]) continue;
		order[i] = n;
		ret = max(ret, go(n + 1));
		order[i] = 0;
	}
	return ret;
}

void solution()
{
	order[4] = 1;
	cout << go(2);
}

int main()
{
	input();
	solution();

	return 0;
}