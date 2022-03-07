#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>

#define ll long long

using namespace std;

int N, K;
int power[9];
vector<int> v;

void input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> power[i], v.push_back(i);
}

void solution()
{
	int result = 0;

	do
	{
		int p = 500;
		bool op = true;
		for (int i = 0; i < N; i++)
		{
			p = p + power[v[i]] - K;
			if (p < 500)
				op = false;
		}
		if (op) result++;
	} while (next_permutation(v.begin(), v.end()));
	cout << result;
}

int main()
{
	input();
	solution();

	return 0;
}