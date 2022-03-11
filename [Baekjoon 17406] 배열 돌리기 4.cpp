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

typedef struct query
{
	int r, c, s;
} Query;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int A[51][51], B[51][51];
int N, M, K;
Query Q[7];
int order[7];

void input()
{
	int r, c, s;

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> A[i][j];
	for (int i = 1; i <= K; i++)
	{
		cin >> r >> c >> s;
		Q[i].r = r, Q[i].c = c, Q[i].s = s;
	}
}

void dfs(int cur_r, int cur_c, int r, int c, int value, int op, int s)
{
	int tmp;

	if (cur_r == r - s && cur_c == c - s && op)
		return;
	tmp = A[cur_r][cur_c];
	A[cur_r][cur_c] = value;
	if (cur_r == r - s && cur_c == c + s)
		op = 1;
	else if (cur_r == r + s && cur_c == c + s)
		op = 2;
	else if (cur_r == r + s && cur_c == c - s)
		op = 3;
	dfs(cur_r + dx[op], cur_c + dy[op], r, c, tmp, op, s);
}

void operation(int r, int c, int s)
{
	for (int i = 1; i <= s; i++)
	{
		dfs(r - i, c - i, r, c, A[r - i + 1][c - i], 0, i);
	}
}

int get_min_row()
{
	int ret = 1e9, sum;

	for (int i = 1; i <= N; i++)
	{
		sum = 0;
		for (int j = 1; j <= M; j++)
			sum += A[i][j];
		ret = min(ret, sum);
	}
	return ret;
}

int go()
{
	int r, c, s;

	for (int i = 1; i <= K; i++)
	{
		r = Q[order[i]].r, c = Q[order[i]].c, s = Q[order[i]].s;
		operation(r, c, s);
	}
	return get_min_row();
}

void array_cpy(int dst[][51], int src[][51])
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			dst[i][j] = src[i][j];
}

int dfs(int n)
{
	int ret = 1e9;

	if (n > K)
	{
		array_cpy(B, A);
		ret = go();
		array_cpy(A, B);
		return ret;
	}
	for (int i = 1; i <= K; i++)
	{
		if (order[i]) continue;
		order[i] = n;
		ret = min(ret, dfs(n + 1));
		order[i] = 0;
	}
	return ret;
}

void solution()
{
	cout << dfs(1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}