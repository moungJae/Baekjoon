#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>

#define ll long long

using namespace std;

int H, W, X, Y;
int A[601][601], B[601][601];

void input() 
{
	cin >> H >> W >> X >> Y;
	for (int i = 1; i <= (H + X); i++)
		for (int j = 1; j <= (W + Y); j++)
			cin >> B[i][j];
}

void solution()
{
	for (int i = 1; i <= (H + X); i++)
	{
		for (int j = 1; j <= (W + Y); j++)
		{
			if (i >= 1 + X && j >= 1 + Y)
			{
				A[i][j] = B[i][j] - A[i - X][j - Y];
			}
			else
			{
				A[i][j] = B[i][j];
			}
		}
	}
	for (int i = 1; i <= H; i++) 
	{
		for (int j = 1; j <= W; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	input();
	solution();

	return 0;
}