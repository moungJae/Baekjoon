#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>

#define ll long long

using namespace std;

int N;
int hill[1001];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> hill[i];
}

void solution() {
	int result = 1e9;

	for (int h = 0; h <= 83; h++)
	{
		int total = 0;
		for (int i = 0; i < N; i++)
		{
			if (hill[i] < h) 
				total += pow(h - hill[i], 2);
			else if (hill[i] > h + 17)
				total += pow(hill[i] - (h + 17), 2);
		}
		result = min(result, total);
	}
	cout << result;
}

int main()
{
	input();
	solution();

	return 0;
}